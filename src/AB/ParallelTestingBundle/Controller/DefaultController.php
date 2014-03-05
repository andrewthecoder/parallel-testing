<?php

namespace AB\ParallelTestingBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\Filesystem\Exception\IOException;
use Symfony\Component\Process\Process;
use Ob\HighchartsBundle\Highcharts\Highchart;
use AB\ParallelTestingBundle\Entity\Test;

class DefaultController extends Controller
{
	private $testTempDirectory;

    public function indexAction()
    {
		$fs = new Filesystem();
		if( $fs->exists($testTempDirectory = $this->container->getParameter('kernel.cache_dir') . '/ABParallelTestingBundle') === false ) {
			try {
				$fs->mkdir($testTempDirectory);
			} catch (IOException $e) {
				echo "An error occurred while attempting to create temporary directory $testTempDirectory";
			}
		}
		
		return $this->render('ABParallelTestingBundle:Default:index.html.twig', array(
			'debugMessage' => isset($debugMessage) ? $debugMessage : ''
        ));
    }
	
    public function updateAction()
    {
		$updateOutput = "hello world";
		
		$response = new Response();
		$response->setContent(json_encode(array(
				'queue' => 'running',
				'output' => $updateOutput
		)));
		$response->setStatusCode(Response::HTTP_OK);
		$response->headers->set('Content-Type', 'application/json');
		return $response;
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

		return $product->getId();
	}
	
	public function prepareTest($testID) {
		$test = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test')->find($testID);
		if (!$test) {
			throw $this->createNotFoundException(
				'No test found for id '.$testID
			);
			return false;
		}
		
		if($testStatus = $test->getStatus() !=='new') {
			echo "Test with ID $testID is not 'new', it is $testStatus. As such, it cannot be prepared.";
			return false;
		}
		
		$fs = new Filesystem();
		try {
			$fs->touch($timeOutputPath = "$testTempDirectory/testID-$testID-timeOutput.txt");
			$fs->touch($programOutputPath = "$testTempDirectory/testID-$testID-programOutput.txt");
		} catch (IOException $e) {
			echo "An error occurred while attempting to create output file $testTempDirectory/testID-$testID-timeOutput.txt";
			return false;
		}
		
		$binDir = $this->get('kernel')->getRootDir()."/src/AB/ParallelTestingBundle/Resources/code/totient";
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
		
		$em->flush();
		return true;
	}
	
	public function systemReadyForTest() {
		// Perform a basic check to see if any tests are "running" according to our database. 
		// If so, return false, as we only want to run one test at a time.
		$testRepository = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test');
		$runningTests = $testRepository->findByStatus('running');
		if( count( $runningTests ) > 0 ) {
			return count( $runningTests )." test(s) are already running.";
		}
		
		// Our database thinks no tests are running. Let's double check process names for good measure.
		$pidOfAnyTotientPrograms = new Process("pidof ab-totient-sequential ab-totient-omp ab-totient-mpi 2>&1")->run()->getOutput();
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
			echo "Test with ID $testID is not 'ready', it is $testStatus. As such, it cannot be started.";
			return false;
		}
		
		$process = new Process($test->getFullCommand);
		$process->start();
		
		$pidOfAnyTotientPrograms = new Process("pidof ab-totient-sequential ab-totient-omp ab-totient-mpi 2>&1")->run()->getOutput();
		$test->setProcessPID($pidOfAnyTotientPrograms);
		$test->setStatus('running');
		
		$em->flush();
		return true;
	}
	
	public function checkTestFinished($testID) {
		$test = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test')->find($testID);
		if (!$test) {
			throw $this->createNotFoundException(
				'No test found for id '.$testID
			);
			return false;
		}
		
		if($testStatus = $test->getStatus() !=='running') {
			echo "Test with ID $testID is not 'running', it is $testStatus. As such, it cannot be checked.";
			return false;
		}
		
		$pid = $test->getProcessPID();
		$psOutput = new Process("ps -p $pid 2>&1")->run()->getOutput(); 
		if(strstr(':', $psOutput) !== false) {
			// There's a colon in the pc output, so the test must still be running.
			return $psOutput;
		} else {
			// Process seems to have finished, load output files into database and set status
			$programOutputPath = "$testTempDirectory/testID-$testID-programOutput.txt");
			$test->setProgramOutput( file_get_contents($programOutputPath) );
			unlink($programOutputPath);
			
			$timeOutputPath = "$testTempDirectory/testID-$testID-timeOutput.txt");
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
			$em->flush();
			return true;
		}
	}
	
}
