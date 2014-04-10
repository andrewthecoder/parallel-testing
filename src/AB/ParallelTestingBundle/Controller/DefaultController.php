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
    public function runAction()
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

        // Generate queue of tests to perform from ranges and multipliers etc
        // For each entry, if the range min and max are equal exactly one test will be performed
        // otherwise, test at the lower limit range value then increment by the increment value until reaching the upper value
        // therefore, a test will always be performed at both the lower and upper range values
        $testsToPerform = array(
            /*array(
                'types' => 'sequential,openmp,mpi,sac,haskell',
                'cores' => '1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16',
                'runs' => '3',
                'lowerLimit' => 1,
                'upperLimitRangeMin' => 1000,
                'upperLimitRangeMax' => 9000,
                'upperLimitRangeIncrement' => 1000
            ),
            array(
                'types' => 'sequential,openmp,mpi,sac,haskell',
                'cores' => '1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16',
                'runs' => '3',
                'lowerLimit' => 1,
                'upperLimitRangeMin' => 10000,
                'upperLimitRangeMax' => 10000,
                'upperLimitRangeIncrement' => false
            ),*/
            array(
                'types' => 'sequential,openmp,mpi,sac',
                'cores' => '1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16', // 
                'runs' => '3',
                'lowerLimit' => 1,
                'upperLimitRangeMin' => 100000,
                'upperLimitRangeMax' => 900000,
                'upperLimitRangeIncrement' => 100000
            ),
            array(
                'types' => 'sequential,openmp,mpi,sac',
                'cores' => '1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16', // 
                'runs' => '3',
                'lowerLimit' => 1,
                'upperLimitRangeMin' => 1000000,
                'upperLimitRangeMax' => 9000000,
                'upperLimitRangeIncrement' => 1000000
            )
        );

        $cachedTestQueue = array();
        
        foreach($testsToPerform as $testRange) {
            $types = explode(',',$testRange['types']);
            $cores = explode(',',$testRange['cores']);
            $runs = $testRange['runs'];
            
            $lowerLimit = $testRange['lowerLimit'];
            $upperLimitRangeMin = $testRange['upperLimitRangeMin'];
            $upperLimitRangeMax = $testRange['upperLimitRangeMax'];
            $upperLimitRangeIncrement = $testRange['upperLimitRangeIncrement'];
            
            // Iterate through each upperLimit value in the specified range, including min and max range values
            while( $upperLimitRangeMin <= $upperLimitRangeMax ) {
                // Iterate number of times specified by runs for duplicate testing to get averages
                for($testRun=1; $testRun <= $runs; $testRun++) {
                    // Iterate through each type of test specified
                    foreach($types as $type) {
                        // Iterate through each number of cores specified
                        foreach($cores as $numberOfCores) {
                            $cachedTestQueue[] = array(
                                'type' => $type,
                                'lowerLimit' => $lowerLimit,
                                'upperLimit' => $upperLimitRangeMin,
                                'cores' => $numberOfCores
                            );
                        }
                    }
                }
                
                // Increment upperLimitRangeMin by specified increment, or if the increment is false/0 then this is an entry for 
                // a single upperLimit value rather than an incremented range so we double the current value to break out of the while loop
                $upperLimitRangeMin = $upperLimitRangeIncrement ? $upperLimitRangeMin + $upperLimitRangeIncrement : $upperLimitRangeMin*2;
            }
        }
        
        //echo "<pre>"; print_r($cachedTestQueue); echo "</pre>"; die();
        $this->writeTestQueue($cachedTestQueue);

        $testsInQueue = count($cachedTestQueue);

        return $this->render('ABParallelTestingBundle:Default:run.html.twig', array(
            'debugMessage' => isset($debugMessage) ? $debugMessage : '',
            'queueLength' => $testsInQueue
        ));
    }
    
    // This just starts running the existing cached queue, in case for some reason the test connection got interrupted
    public function runExistingQueueAction()
    {
        $testQueue = $this->readTestQueue();
        $testsInQueue = count($testQueue);
        
        return $this->render('ABParallelTestingBundle:Default:run.html.twig', array(
            'debugMessage' => isset($debugMessage) ? $debugMessage : '',
            'queueLength' => $testsInQueue
        ));
    }
    
    public function updateAction()
    {
		$response = new Response();
		$queueStatus = 'running';
        
        $testQueue = $this->readTestQueue();
        $testsInQueue = count($testQueue);
        
		// Browser has fired off an	update poll, let's figure out how to deal with it.
		// Firstly, let's check if we're already doing something or not
		$ready = $this->systemReadyForTest();
		if( $ready !== true && $ready !== false ) {
			$updateOutput = $ready;
            $currentTestStatus = 'systemNotReady';
		} elseif( $ready === false ) {
			$testRepository = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test');
			$runningTest = $testRepository->findOneByStatus('running');
                
			$testStatus = $this->checkTestFinished( $runningTest->getId() );
			if( $testStatus === true ) {
                $currentTestStatus = 'finished';
                $programOutputText = trim( $runningTest->getProgramOutput() );
				$updateOutput = "Program output: '{$programOutputText}'\nTest {$runningTest->getId()} complete: Calculated totients from {$runningTest->getLowerLimit()}-{$runningTest->getUpperLimit()} using {$runningTest->getCores()} cores in {$runningTest->getClockRunTime()} seconds.\n\n";
			} else {
                $currentTestStatus = 'running';
				$updateOutput = $testStatus;
			}
		} elseif( $ready === true ) {
			$testQueue = $this->readTestQueue();
			if( empty($testQueue) === false ) {
				$newTestParameters = array_shift($testQueue);
                $testsInQueue--;
				$this->writeTestQueue($testQueue);
				
				$testID = $this->createTest($newTestParameters->type, $newTestParameters->lowerLimit, $newTestParameters->upperLimit, $newTestParameters->cores);
				
				$testPrepared = $this->prepareTest($testID);
				if( $testPrepared === true ) {
					$testStarted = $this->startTest($testID);
					if( $testStarted === true ) {
                        $currentTestStatus = 'started';
						$updateOutput = "Started test ID: $testID";
					} else {
                        $currentTestStatus = 'startTestFailed';
						$updateOutput = $testStarted;
					}
				} else {
                    $currentTestStatus = 'prepareTestFailed';
					$updateOutput = $testPrepared;
				}
			} else {
				$queueStatus = 'finished';
                $currentTestStatus = 'finished';
				$updateOutput = 'All tests in queue have been completed';
			}
		}
        
        // get load average to show regularly in box
        $load = sys_getloadavg();
        $oneMinuteLoad = $load[0];
        
		// queue possible values: 'running','finished'
		// test possible values: 'systemNotReady', 'prepareTestFailed', 'startTestFailed', 'started', 'running', 'finished'
		$response->setContent(json_encode(array(
				'queueStatus' => $queueStatus,
                'queueLength' => $testsInQueue,
                'testStatus' => $currentTestStatus,
                'testID' => isset($testID) ? $testID : 0,
                'loadAverage' => $oneMinuteLoad,
				'message' => $updateOutput
		)));
		$response->setStatusCode(Response::HTTP_OK);
		$response->headers->set('Content-Type', 'application/json');
		return $response;
    }
	
	public function chartsAction($type, $numberOfCoresList) {
		$repository = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test');

        $numberOfCoresList = explode(',',$numberOfCoresList);

        $allChartsToDisplay = array();
        
        // Loop through all requested number of cores and show a graph for each
        foreach( $numberOfCoresList as $numberOfCores ) {
            
            $slowsequential = $repository->findMedianResults('slowsequential', $numberOfCores);
            $haskell = $repository->findMedianResults('haskell', $numberOfCores);
            $sequential = $repository->findMedianResults('sequential', $numberOfCores);
            $openmp = $repository->findMedianResults('openmp', $numberOfCores);
            $mpi = $repository->findMedianResults('mpi', $numberOfCores);
            $sac = $repository->findMedianResults('sac', $numberOfCores);
                
            switch($type) {
                case 'time':
                    $currentChart = new Highchart();
                    
                    // Set numberOfCores in this chart variable so twig can display it
                    $currentChart->numberOfCores = $numberOfCores;
                    $currentChart->type = $type;
                    
                    // Tell chart which div it should render inside and give it a heading
                    $currentChart->chart->renderTo("chart_{$type}_{$numberOfCores}");  // The #id of the div where to render the chart
                    $currentChart->title->text("Time graph with {$numberOfCores} threads");

                    // Allow zooming
                    $currentChart->chart->zoomType('xy');

                    $sequentialData = array();
                    foreach($sequential as $result) {
                        if(!is_null($result['clockRunTimeMedian']))
                            $sequentialData[] = array($result['upperLimit'], (float)$result['clockRunTimeMedian']);
                    }
                    /*$slowSequentialData = array();
                    foreach($slowsequential as $result) {
                        if(!is_null($result['clockRunTimeMedian']))
                            $slowSequentialData[] = array($result['upperLimit'], (float)$result['clockRunTimeMedian']);
                    }*/
                    $openmpData = array();
                    foreach($openmp as $result) {
                        if(!is_null($result['clockRunTimeMedian']))
                        $openmpData[] = array($result['upperLimit'], (float)$result['clockRunTimeMedian']);
                    }
                    $mpiData = array();
                    foreach($mpi as $result) {
                        if(!is_null($result['clockRunTimeMedian']))
                        $mpiData[] = array($result['upperLimit'], (float)$result['clockRunTimeMedian']);
                    }
                    $sacData = array();
                    foreach($sac as $result) {
                        if(!is_null($result['clockRunTimeMedian']))
                        $sacData[] = array($result['upperLimit'], (float)$result['clockRunTimeMedian']);
                    }
                    $haskellData = array();
                    foreach($haskell as $result) {
                        if(!is_null($result['clockRunTimeMedian']))
                        $haskellData[] = array($result['upperLimit'], (float)$result['clockRunTimeMedian']);
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
                    $currentChart->xAxis($xData);
                    
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
                    $currentChart->yAxis($yData);
                    
                    $formatter = new Expr('function () {
                             return "<b>Execution Type:</b> "+this.series.name+"<br /><br /><b>Totient Range:</b> 1 to " + this.x + "<br /><b>Average Time:</b> " + this.y + " seconds";
                         }');
                    $currentChart->tooltip->formatter($formatter);
                    $currentChart->series(array(
                        //array('type' => 'spline','color' => '#000000','name' => 'Bad Sequential', 'data' => $slowSequentialData),
                        array('type' => 'spline','color' => '#AA4643','name' => 'Sequential', 'data' => $sequentialData),
                        array('type' => 'spline','color' => '#89A54E','name' => 'OpenMP', 'data' => $openmpData),
                        array('type' => 'spline','color' => '#4572A7','name' => 'MPI', 'data' => $mpiData),
                        array('type' => 'spline','color' => '#C49C45','name' => 'SAC', 'data' => $sacData),
                        array('type' => 'spline','color' => '#8045A7','name' => 'GPH', 'data' => $haskellData)
                    ));
                    
                    // Add the chart we just built to the output
                    $allChartsToDisplay[] = $currentChart;
                break;
                
                case 'speedup':
                    $currentChart = new Highchart();

                    // Set numberOfCores in this chart variable so twig can display it
                    $currentChart->numberOfCores = $numberOfCores;
                    $currentChart->type = $type;

                    // Tell chart which div it should render inside and give it a heading
                    $currentChart->chart->renderTo("chart_{$type}_{$numberOfCores}");  // The #id of the div where to render the chart
                    $currentChart->title->text("Speedup graph with {$numberOfCores} threads");

                    // Allow zooming
                    $currentChart->chart->zoomType('xy');
                    
                    $sequentialData = array();
                    foreach($sequential as $result) {
                        if(!is_null($result['clockRunTimeMedian']))
                            $sequentialData[] = array($result['upperLimit'], (float)$result['clockRunTimeMedian']);
                    }
                    $openmpData = array();
                    foreach($openmp as $result) {
                        if(!is_null($result['clockRunTimeMedian']))
                        $openmpData[] = array($result['upperLimit'], (float)$result['clockRunTimeMedian']);
                    }
                    $idealSpeedupData = array();
                    foreach($sequential as $result) {
                        if(!is_null($result['clockRunTimeMedian']))
                            $idealSpeedupData[] = array($result['upperLimit'], (float)$result['clockRunTimeMedian']/10);
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
                    $currentChart->xAxis($xData);
                    
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
                    $currentChart->yAxis($yData);
                    
                    $formatter = new Expr('function () {
                             return "<b>Execution Type:</b> "+this.series.name+"<br /><br /><b>Totient Range:</b> 1 to " + this.x + "<br /><b>Average Time:</b> " + this.y + " seconds";
                         }');
                    $currentChart->tooltip->formatter($formatter);
                    $currentChart->series(array(
                        array('type' => 'spline','color' => '#AA4643','name' => 'Good Sequential', 'data' => $sequentialData),
                        array('type' => 'spline','color' => '#89A54E','name' => 'OpenMP', 'data' => $openmpData),
                        array('type' => 'spline','color' => '#4572A7','name' => 'Ideal Speedup (10x)', 'data' => $idealSpeedupData)
                    ));
                    
                    // Add the chart we just built to the output
                    $allChartsToDisplay[] = $currentChart;
                break;
            } // end switch of graph type
        } // end looping through $numberOfCoresList
        
		return $this->render('ABParallelTestingBundle:Default:charts.html.twig', array(
            'allChartsToDisplay' => $allChartsToDisplay,
        ));
	}
	
	public function readTestQueue($cached = true) {
        if($cached) {
            $queuePath = $this->container->getParameter('kernel.cache_dir') . '/ABParallelTestingBundle/queue.json';
        } else {
            $queuePath = $this->get('kernel')->getRootDir()."/../src/AB/ParallelTestingBundle/Resources/code/queue.json";
        }
        
		return json_decode( file_get_contents($queuePath) );
	}
	
	public function writeTestQueue($testQueue) {
		$testTempDirectory = $this->container->getParameter('kernel.cache_dir') . '/ABParallelTestingBundle';
		file_put_contents("$testTempDirectory/queue.json", json_encode($testQueue) );
	}
	
	public function createTest($type, $lowerLimit, $upperLimit, $cores)
	{
		$test = new Test();
		$test->setType($type);
		$test->setLowerLimit($lowerLimit);
		$test->setUpperLimit($upperLimit);
		$test->setCores($cores);
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
        $cores = $test->getCores();
		
		switch($test->getType()) {
			case 'sequential':
				$testCommand = "$binDir/ab-totient-sequential $lowerLimit $upperLimit";
				break;
			case 'openmp':
				$testCommand = "$binDir/ab-totient-omp/ab-totient-omp-$cores $lowerLimit $upperLimit";
				break;
			case 'mpi':
				$testCommand = "mpirun -np $cores $binDir/ab-totient-mpi $lowerLimit $upperLimit";
				break;
            case 'sac':
                $testCommand = "$binDir/ab-totient-sac $lowerLimit $upperLimit -mt $cores";
                break;
            case 'haskell':
                $testCommand = "$binDir/ab-totient-gph $lowerLimit $upperLimit $cores +RTS -N$cores";
                break;
		}
		
		$test->setFullCommand("/usr/bin/time -v -o $timeOutputPath $testCommand > $programOutputPath 2>&1");
		$test->setStatus('ready');
		
		$em = $this->getDoctrine()->getManager();
		$em->flush();
		return true;
	}
	
	public function systemReadyForTest() {
        $totientProgramNames = "ab-totient-sequential ab-totient-omp ab-totient-mpi ab-totient-sac ab-totient-gph mpirun";
        
		// Perform a basic check to see if any tests are "running" according to our database. 
		// If so, return false, as we only want to run one test at a time.
		$testRepository = $this->getDoctrine()->getRepository('ABParallelTestingBundle:Test');
		$runningTests = $testRepository->findByStatus('running');
		if( count( $runningTests ) > 0 ) {
			return false;
		}
		
		// Our database thinks no tests are running. Let's double check process names for good measure.
		$pidOfAnyTotientProgramsProcess = new Process("pidof $totientProgramNames 2>&1");
		$pidOfAnyTotientProgramsProcess->run();
		$pidOfAnyTotientPrograms = $pidOfAnyTotientProgramsProcess->getOutput();
		if( empty($pidOfAnyTotientPrograms) !== true ) {
			return "The database thinks there are no tests running, but these PIDs still exist: $pidOfAnyTotientPrograms.";
		}
		
		// Check CPU load in the last minute to make sure nothing intensive is running. 
		// This will be a different factor on any system it is run on, based on the number of cores.
		// Assuming a modern system with 4 to 12 cores, this does a good enough estimate
		// If we have 75% CPU available that's good enough for me.
		// Because this is a one minute load average, this will probably introduce a bit of unnecessary delay between processes while the average drops.
		$load = sys_getloadavg();
		if ($load[0] > 2) {
			return "System load is too high to start a new test yet, waiting for it to drop. 1 minute load average: {$load[0]}";
		}
		
		// No tests seem to be running, and the CPU isn't stressed. We're ready!
		return true;
	}
	
	public function startTest($testID) {
        $totientProgramNames = "ab-totient-sequential ab-totient-omp ab-totient-mpi ab-totient-sac ab-totient-gph mpirun";
        
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
		
		$pidOfAnyTotientProgramsProcess = new Process("pidof $totientProgramNames 2>&1");
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
            $test->setTimeOutput( $timeOut );
			
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
