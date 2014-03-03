<?php

namespace AB\Bundle\ParallelTestingBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;

class DefaultController extends Controller
{
    public function indexAction($name)
    {
        return $this->render('ABParallelTestingBundle:Default:index.html.twig', array('name' => $name));
    }
}
