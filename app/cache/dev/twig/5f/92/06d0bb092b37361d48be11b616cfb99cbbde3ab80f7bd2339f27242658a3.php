<?php

/* ABParallelTestingBundle:Default:charts.html.twig */
class __TwigTemplate_5f9206d0bb092b37361d48be11b616cfb99cbbde3ab80f7bd2339f27242658a3 extends Twig_Template
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
            'body_js' => array($this, 'block_body_js'),
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
        echo "    <h1>Parallel Charts</h1>
";
    }

    // line 11
    public function block_body_container_main($context, array $blocks = array())
    {
        // line 12
        echo "\t<div id=\"debug\">
\t\t<pre>
\t\t\t";
        // line 14
        echo twig_escape_filter($this->env, (isset($context["debugMessage"]) ? $context["debugMessage"] : $this->getContext($context, "debugMessage")), "html", null, true);
        echo "
\t\t</pre>
\t</div>
\t
\t<div id=\"linechart\" style=\"min-width: 400px; height: 400px; margin: 0 auto\"></div>
";
    }

    // line 21
    public function block_body_container_footer($context, array $blocks = array())
    {
        // line 22
        echo "    Andrew Beveridge [ab441] 2014
";
    }

    // line 25
    public function block_body_js($context, array $blocks = array())
    {
        // line 26
        echo "\t<script src=\"http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js\" type=\"text/javascript\"></script>

\t<script src=\"";
        // line 28
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("bundles/obhighcharts/js/highcharts/highcharts.js"), "html", null, true);
        echo "\"></script>
\t<script src=\"";
        // line 29
        echo twig_escape_filter($this->env, $this->env->getExtension('assets')->getAssetUrl("bundles/obhighcharts/js/highcharts/modules/exporting.js"), "html", null, true);
        echo "\"></script>
\t<script type=\"text/javascript\">
\t";
        // line 31
        echo $this->env->getExtension('highcharts_extension')->chart((isset($context["chart"]) ? $context["chart"] : $this->getContext($context, "chart")));
        echo "
\t</script>
";
    }

    public function getTemplateName()
    {
        return "ABParallelTestingBundle:Default:charts.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  87 => 31,  82 => 29,  78 => 28,  74 => 26,  71 => 25,  66 => 22,  63 => 21,  53 => 14,  49 => 12,  46 => 11,  41 => 8,  38 => 7,  32 => 5,);
    }
}
