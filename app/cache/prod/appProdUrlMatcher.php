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

        // ab_parallel_testing_homepage
        if (rtrim($pathinfo, '/') === '') {
            if (substr($pathinfo, -1) !== '/') {
                return $this->redirect($pathinfo.'/', 'ab_parallel_testing_homepage');
            }

            return array (  '_controller' => 'AB\\ParallelTestingBundle\\Controller\\DefaultController::indexAction',  '_route' => 'ab_parallel_testing_homepage',);
        }

        // ab_parallel_testing_update
        if ($pathinfo === '/update') {
            return array (  '_controller' => 'AB\\ParallelTestingBundle\\Controller\\DefaultController::updateAction',  '_route' => 'ab_parallel_testing_update',);
        }

        // ab_parallel_testing_charts
        if (0 === strpos($pathinfo, '/charts') && preg_match('#^/charts/(?P<type>[^/]++)$#s', $pathinfo, $matches)) {
            return $this->mergeDefaults(array_replace($matches, array('_route' => 'ab_parallel_testing_charts')), array (  '_controller' => 'AB\\ParallelTestingBundle\\Controller\\DefaultController::chartsAction',));
        }

        throw 0 < count($allow) ? new MethodNotAllowedException(array_unique($allow)) : new ResourceNotFoundException();
    }
}
