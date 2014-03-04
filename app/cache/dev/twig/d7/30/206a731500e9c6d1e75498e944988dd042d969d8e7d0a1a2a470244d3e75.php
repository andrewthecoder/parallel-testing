<?php

/* ABParallelTestingBundle:Default:index.html.twig */
class __TwigTemplate_d730206a731500e9c6d1e75498e944988dd042d969d8e7d0a1a2a470244d3e75 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("OryzoneBoilerplateBundle::html5.html.twig");

        $this->blocks = array(
            'head_title' => array($this, 'block_head_title'),
            'body_container_header' => array($this, 'block_body_container_header'),
            'body_container_main' => array($this, 'block_body_container_main'),
            'body_container_footer' => array($this, 'block_body_container_footer'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "OryzoneBoilerplateBundle::html5.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 5
    public function block_head_title($context, array $blocks = array())
    {
        echo "Parallel Testing: Charts";
    }

    // line 7
    public function block_body_container_header($context, array $blocks = array())
    {
        // line 8
        echo "    <h1>Highchart Test</h1>
";
    }

    // line 11
    public function block_body_container_main($context, array $blocks = array())
    {
        // line 12
        echo "\t<!-- Load jQuery from Google's CDN if needed -->
\t<script src=\"http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js\" type=\"text/javascript\"></script>

\t<script src=\"";
        // line 15
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("bundles/obhighcharts/js/highcharts/highcharts.js"), "html", null, true);
        echo "\"></script>
\t<script src=\"";
        // line 16
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("bundles/obhighcharts/js/highcharts/modules/exporting.js"), "html", null, true);
        echo "\"></script>
\t<script type=\"text/javascript\">
\t";
        // line 18
        echo $this->env->getExtension('highcharts_extension')->chart((isset($context["chart"]) ? $context["chart"] : $this->getContext($context, "chart")));
        echo "
\t</script>

\t<div id=\"linechart\" style=\"min-width: 400px; height: 400px; margin: 0 auto\"></div>
";
    }

    // line 24
    public function block_body_container_footer($context, array $blocks = array())
    {
        // line 25
        echo "    Andrew Beveridge [ab441] 2014
";
    }

    public function getTemplateName()
    {
        return "ABParallelTestingBundle:Default:index.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  74 => 25,  71 => 24,  62 => 18,  57 => 16,  53 => 15,  48 => 12,  45 => 11,  40 => 8,  37 => 7,  31 => 5,);
    }
}
