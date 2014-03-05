<?php

namespace AB\ParallelTestingBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\Filesystem\Exception\IOException;
use Symfony\Component\Process\Process;
use Zend\Json\Expr;
use Ob\HighchartsBundle\Highcharts\Highchart;
use AB\ParallelTestingBundle\Entity\Test;

class DefaultController extends Controller
{
    public function indexAction()
    {
		$testTempDirectory = $this->container->getParameter('kernel.cache_dir') . '/ABParallelTestingBundle';
		
		$fs = new Filesystem();
		if( $fs->exists($testTempDirectory) === false ) {
			try {
				$fs->mkdir($testTempDirectory);
			} catch (IOException $e) {
				echo "An error occurred while attempting to create temporary directory $testTempDirectory";
			}
		}
		
		$fs->copy($this->get('kernel')->getRootDir()."/../src/AB/ParallelTestingBundle/Resources/code/queue.json", "$testTempDirectory/queue.json", true);
		
		return $this->render('ABParallelTestingBundle:Default:index.html.twig', array(
			'debugMessage' => isset($debugMessage) ? $debugMessage : ''
        ));
    }
	
    public function updateAction()
    {
		$response = new Response();
		$queueStatus = 'running';
		
		// Browser has fired off an	update poll, let's figure out how to deal with it.
		// Firstly, let's check if we're already doing something or not
		$ready = $this->systemReadyForTest();
		if( $ready !== true && $ready !== false ) {
			$updateOutput = $ready;
		} elseif( $ready === false ) {
			$testRepository = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test');
			$runningTest = $testRepository->findOneByStatus('running');
			
			$testStatus = $this->checkTestFinished( $runningTest->getId() );
			if( $testStatus === true ) {
				$updateOutput = "Successfully finished test ID ".$runningTest->getId().": Calculated totients from ".$runningTest->getLowerLimit()."-".$runningTest->getUpperLimit()." in ".$runningTest->getClockRunTime()." seconds.";
			} else {
				$updateOutput = $testStatus;
			}			
		} elseif( $ready === true ) {
			$testQueue = $this->readTestQueue();
			if( empty($testQueue) === false ) {
				$newTestParameters = array_shift($testQueue);
				$this->writeTestQueue($testQueue);
				
				$testID = $this->createTest($newTestParameters->type, $newTestParameters->lowerLimit, $newTestParameters->upperLimit);
				
				$testPrepared = $this->prepareTest($testID);
				if( $testPrepared === true ) {
					$testStarted = $this->startTest($testID);
					if( $testStarted === true ) {
						$updateOutput = "Started test ID $testID";
					} else {
						$updateOutput = $testStarted;
					}
				} else {
					$updateOutput = $testPrepared;
				}
			} else {
				$queueStatus = 'finished';
				$updateOutput = 'All tests in queue have been completed';
			}
		}
		
		$response->setContent(json_encode(array(
				'queue' => $queueStatus,
				'output' => $updateOutput
		)));
		$response->setStatusCode(Response::HTTP_OK);
		$response->headers->set('Content-Type', 'application/json');
		return $response;
    }
	
	public function chartsAction($type) {
		$repository = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test');
		
		$slowsequential = $repository->findAveragedResults('slowsequential');
		$sequential = $repository->findAveragedResults('sequential');
		$openmp = $repository->findAveragedResults('openmp');
		$mpi = $repository->findAveragedResults('mpi');
		
		if($type==1) {
			
			$ob = new Highchart();
			$ob->chart->renderTo('linechart');  // The #id of the div where to render the chart
			$ob->title->text('Comparison of Sequential Algorithms and Parallel Programming APIs with respect to efficiency on a 10 core CPU');
			
			$sequentialData = array();
			foreach($sequential as $result) {
				if(!is_null($result['averageTime']))
					$sequentialData[] = array($result['upperLimit'], (float)$result['averageTime']);
			}
			$slowSequentialData = array();
			foreach($slowsequential as $result) {
				if(!is_null($result['averageTime']))
					$slowSequentialData[] = array($result['upperLimit'], (float)$result['averageTime']);
			}
			$openmpData = array();
			foreach($openmp as $result) {
				if(!is_null($result['averageTime']))
				$openmpData[] = array($result['upperLimit'], (float)$result['averageTime']);
			}
			$mpiData = array();
			foreach($mpi as $result) {
				if(!is_null($result['averageTime']))
				$mpiData[] = array($result['upperLimit'], (float)$result['averageTime']);
			}
			
			$xData = array(
				array(
					'title' => array(
						'text'  => 'Totient Range Upper Limit',
						'style' => array('color' => '#000000')
					),
					'opposite' => true
				)
			);
			$ob->xAxis($xData);
			
			$yData = array(
				array(
					'labels' => array(
						'formatter' => new Expr('function () { return this.value + " s" }')
					),
					'title' => array(
						'text'  => 'Execution Time',
						'style' => array('color' => '#000000')
					)
				)
			);
			$ob->yAxis($yData);
			
			$formatter = new Expr('function () {
					 return "<b>Execution Type:</b> "+this.series.name+"<br /><br /><b>Totient Range:</b> 1 to " + this.x + "<br /><b>Average Time:</b> " + this.y + " seconds";
				 }');
			$ob->tooltip->formatter($formatter);
			$ob->series(array(
				array('type' => 'spline','color' => '#000000','name' => 'Bad Sequential', 'data' => $slowSequentialData),
				array('type' => 'spline','color' => '#AA4643','name' => 'Good Sequential', 'data' => $sequentialData),
				array('type' => 'spline','color' => '#89A54E','name' => 'OpenMP', 'data' => $openmpData),
				array('type' => 'spline','color' => '#4572A7','name' => 'MPI', 'data' => $mpiData)
			));
			
		} else {
			$ob = new Highchart();
			$ob->chart->renderTo('linechart');  // The #id of the div where to render the chart
			$ob->title->text('OpenMP vs Sequential Speedup: 10 Threads');
			
			$sequentialData = array();
			foreach($sequential as $result) {
				if(!is_null($result['averageTime']))
					$sequentialData[] = array($result['upperLimit'], (float)$result['averageTime']);
			}
			$openmpData = array();
			foreach($openmp as $result) {
				if(!is_null($result['averageTime']))
				$openmpData[] = array($result['upperLimit'], (float)$result['averageTime']);
			}
			$idealSpeedupData = array();
			foreach($sequential as $result) {
				if(!is_null($result['averageTime']))
					$idealSpeedupData[] = array($result['upperLimit'], (float)$result['averageTime']/10);
			}
			
			$xData = array(
				array(
					'title' => array(
						'text'  => 'Totient Range Upper Limit',
						'style' => array('color' => '#000000')
					),
					'opposite' => true
				)
			);
			$ob->xAxis($xData);
			
			$yData = array(
				array(
					'labels' => array(
						'formatter' => new Expr('function () { return this.value + " s" }')
					),
					'title' => array(
						'text'  => 'Execution Time',
						'style' => array('color' => '#000000')
					)
				)
			);
			$ob->yAxis($yData);
			
			$formatter = new Expr('function () {
					 return "<b>Execution Type:</b> "+this.series.name+"<br /><br /><b>Totient Range:</b> 1 to " + this.x + "<br /><b>Average Time:</b> " + this.y + " seconds";
				 }');
			$ob->tooltip->formatter($formatter);
			$ob->series(array(
				array('type' => 'spline','color' => '#AA4643','name' => 'Good Sequential', 'data' => $sequentialData),
				array('type' => 'spline','color' => '#89A54E','name' => 'OpenMP', 'data' => $openmpData),
				array('type' => 'spline','color' => '#4572A7','name' => 'Ideal Speedup (10x)', 'data' => $idealSpeedupData)
			));
		}
		
		return $this->render('ABParallelTestingBundle:Default:charts.html.twig', array(
            'chart' => $ob,
        ));
	}
	
	public function readTestQueue() {
		$testTempDirectory = $this->container->getParameter('kernel.cache_dir') . '/ABParallelTestingBundle';
		return json_decode( file_get_contents("$testTempDirectory/queue.json") );
	}
	
	public function writeTestQueue($testQueue) {
		$testTempDirectory = $this->container->getParameter('kernel.cache_dir') . '/ABParallelTestingBundle';
		file_put_contents("$testTempDirectory/queue.json", json_encode($testQueue) );
	}
	
	public function createTest($type, $lowerLimit, $upperLimit)
	{
		$test = new Test();
		$test->setType($type);
		$test->setLowerLimit($lowerLimit);
		$test->setUpperLimit($upperLimit);
		$test->setStatus('new');
		
		
		$em = $this->getDoctrine()->getManager();
		$em->persist($test);
		$em->flush();

		return $test->getId();
	}
	
	public function prepareTest($testID) {
		$testTempDirectory = $this->container->getParameter('kernel.cache_dir') . '/ABParallelTestingBundle';
		$test = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test')->find($testID);
		if (!$test) {
			throw $this->createNotFoundException(
				'No test found for id '.$testID
			);
			return false;
		}
		
		if($testStatus = $test->getStatus() !=='new') {
			return "Test with ID $testID is not 'new', it is $testStatus. As such, it cannot be prepared.";
		}
		
		$fs = new Filesystem();
		try {
			$fs->touch($timeOutputPath = "$testTempDirectory/testID-$testID-timeOutput.txt");
			$fs->touch($programOutputPath = "$testTempDirectory/testID-$testID-programOutput.txt");
		} catch (IOException $e) {
			return "An error occurred while attempting to create output file $testTempDirectory/testID-$testID-timeOutput.txt";
		}
		
		$binDir = $this->get('kernel')->getRootDir()."/../src/AB/ParallelTestingBundle/Resources/code/totient";
		$lowerLimit = $test->getLowerLimit();
		$upperLimit = $test->getUpperLimit();
		
		switch($test->getType()) {
			case 'sequential':
				$testCommand = "$binDir/ab-totient-sequential $lowerLimit $upperLimit";
				break;
			case 'openmp':
				$testCommand = "$binDir/ab-totient-omp $lowerLimit $upperLimit";
				break;
			case 'mpi':
				$testCommand = "mpirun -np 8 $binDir/ab-totient-mpi $lowerLimit $upperLimit";
				break;
		}
		
		$test->setFullCommand("/usr/bin/time -v -o $timeOutputPath $testCommand > $programOutputPath 2>&1");
		$test->setStatus('ready');
		
		$em = $this->getDoctrine()->getManager();
		$em->flush();
		return true;
	}
	
	public function systemReadyForTest() {
		// Perform a basic check to see if any tests are "running" according to our database. 
		// If so, return false, as we only want to run one test at a time.
		$testRepository = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test');
		$runningTests = $testRepository->findByStatus('running');
		if( count( $runningTests ) > 0 ) {
			return false;
		}
		
		// Our database thinks no tests are running. Let's double check process names for good measure.
		$pidOfAnyTotientProgramsProcess = new Process("pidof ab-totient-sequential ab-totient-omp ab-totient-mpi mpirun 2>&1");
		$pidOfAnyTotientProgramsProcess->run();
		$pidOfAnyTotientPrograms = $pidOfAnyTotientProgramsProcess->getOutput();
		if( empty($pidOfAnyTotientPrograms) !== true ) {
			return "The database thinks there are no tests running, but these PIDs still exist: $pidOfAnyTotientPrograms.";
		}
		
		// Check CPU load in the last minute to make sure nothing intensive is running. 
		// This will be a different factor on any system it is run on, based on the number of cores.
		// Assuming a modern system with 4 to 12 cores, this does a good enough estimate
		// If we have 75% CPU available that's good enough for me.
		// Because this is a one minute load average, this will probably introduce a bit of delay between processes while the average drops.
		$load = sys_getloadavg();
		if ($load[0] > 1) {
			return "System load is too high to start a new test yet, waiting for it to drop. 1 minute load average: {$load[0]}";
		}
		
		// No tests seem to be running, and the CPU isn't stressed. We're ready!
		return true;
	}
	
	public function startTest($testID) {
		$test = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test')->find($testID);
		if (!$test) {
			throw $this->createNotFoundException(
				'No test found for id '.$testID
			);
			return false;
		}
		
		if($testStatus = $test->getStatus() !=='ready') {
			return "Test with ID $testID is not 'ready', it is $testStatus. As such, it cannot be started.";
		}
		
		$process = new Process($test->getFullCommand());
		$process->start();
		
		$pidOfAnyTotientProgramsProcess = new Process("pidof ab-totient-sequential ab-totient-omp ab-totient-mpi mpirun 2>&1");
		$pidOfAnyTotientProgramsProcess->run();
		$pidOfAnyTotientPrograms = $pidOfAnyTotientProgramsProcess->getOutput();
		
		$test->setProcessPID($pidOfAnyTotientPrograms ? $pidOfAnyTotientPrograms : 54321);
		$test->setStatus('running');
		
		$em = $this->getDoctrine()->getManager();
		$em->flush();
		return true;
	}
	
	public function checkTestFinished($testID) {
		$testTempDirectory = $this->container->getParameter('kernel.cache_dir') . '/ABParallelTestingBundle';
		$test = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test')->find($testID);
		if (!$test) {
			throw $this->createNotFoundException(
				'No test found for id '.$testID
			);
			return false;
		}
		
		if($testStatus = $test->getStatus() !=='running') {
			return "Test with ID $testID is not 'running', it is $testStatus. As such, it cannot be checked.";
		}
		
		$pid = $test->getProcessPID();
		$psProcess = new Process("ps -p $pid 2>&1");
		$psProcess->run();
		$psOutput = $psProcess->getOutput(); 
		if(strpos($psOutput, ':') !== false) {
			// There's a colon in the ps output, so the test must still be running.
			return $psOutput;
		} else {
			// Process seems to have finished, load output files into database and set status
			$programOutputPath = "$testTempDirectory/testID-$testID-programOutput.txt";
			$test->setProgramOutput( file_get_contents($programOutputPath) );
			unlink($programOutputPath);
			
			$timeOutputPath = "$testTempDirectory/testID-$testID-timeOutput.txt";
			$timeOut = file_get_contents($timeOutputPath);
			
			$cpuPercent = preg_replace("|.+CPU.+?([0-9.]+%).+|s", '$1', $timeOut);
			$systemRunTime = preg_replace("|.+User time.+?([0-9.]+).+|s", '$1', $timeOut);
			
			$clockRunTime = preg_replace("|.+Elapsed.+?: (.+?)\n.+|s", '$1', $timeOut);
			sscanf($clockRunTime, "%d:%d.%d", $minutes, $seconds, $deciSeconds); 
			$clockRunTime = $minutes * 60 + $seconds + ($deciSeconds/100);
			
			$test->setCpuPercent($cpuPercent);
			$test->setSystemRunTime($systemRunTime);
			$test->setClockRunTime($clockRunTime);
			unlink($timeOutputPath);
			
			$test->setStatus('finished');
			$em = $this->getDoctrine()->getManager();
			$em->flush();
			return true;
		}
	}
	
}
