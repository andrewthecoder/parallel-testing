<?php

use Symfony\Component\Routing\Exception\MethodNotAllowedException;
use Symfony\Component\Routing\Exception\ResourceNotFoundException;
use Symfony\Component\Routing\RequestContext;

/**
 * appProdUrlMatcher
 *
 * This class has been auto-generated
 * by the Symfony Routing Component.
 */
class appProdUrlMatcher extends Symfony\Bundle\FrameworkBundle\Routing\RedirectableUrlMatcher
{
    /**
     * Constructor.
     */
    public function __construct(RequestContext $context)
    {
        $this->context = $context;
    }

    public function match($pathinfo)
    {
        $allow = array();
        $pathinfo = rawurldecode($pathinfo);
        $context = $this->context;
        $request = $this->request;

        if (0 === strpos($pathinfo, '/run')) {
            // ab_parallel_testing_run
            if ($pathinfo === '/run') {
                return array (  '_controller' => 'AB\\ParallelTestingBundle\\Controller\\DefaultController::runAction',  '_route' => 'ab_parallel_testing_run',);
            }

            // ab_parallel_testing_run_existing_queue
            if ($pathinfo === '/runExistingQueue') {
                return array (  '_controller' => 'AB\\ParallelTestingBundle\\Controller\\DefaultController::runExistingQueueAction',  '_route' => 'ab_parallel_testing_run_existing_queue',);
            }

        }

        // ab_parallel_testing_update
        if ($pathinfo === '/update') {
            return array (  '_controller' => 'AB\\ParallelTestingBundle\\Controller\\DefaultController::updateAction',  '_route' => 'ab_parallel_testing_update',);
        }

        // ab_parallel_testing_charts
        if (preg_match('#^/(?P<type>[^/]++)?(?:/(?P<numberOfCoresList>[^/]++))?$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ab_parallel_testing_charts')), array (  '_controller' => 'AB\\ParallelTestingBundle\\Controller\\DefaultController::chartsAction',  'type' => 'time',  'numberOfCoresList' => '1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16',));
        }

        throw 0 < count($allow) ? new MethodNotAllowedException(array_unique($allow)) : new ResourceNotFoundException();
    }
}
