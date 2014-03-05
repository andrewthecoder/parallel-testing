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
        echo "Parallel Testing";
    }

    // line 7
    public function block_body_container_header($context, array $blocks = array())
    {
        // line 8
        echo "    <h1>Parallel Test</h1>
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
\t<div id=\"output\" data-testid='";
        // line 17
        echo twig_escape_filter($this->env, (isset($context["testid"]) ? $context["testid"] : $this->getContext($context, "testid")), "html", null, true);
        echo "' >
\t\t<pre>
\t\t</pre>
\t</div>
";
    }

    // line 23
    public function block_body_container_footer($context, array $blocks = array())
    {
        // line 24
        echo "    Andrew Beveridge [ab441] 2014
";
    }

    // line 27
    public function block_body_js($context, array $blocks = array())
    {
        // line 28
        echo "\t<script src=\"http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js\" type=\"text/javascript\"></script>
\t
\t
\t<script type=\"text/javascript\">
\t\t\$(document).ready(function(){

function update_output() {
\t\t\t   \$.ajax( {
\t\t\t\t\ttype: 'POST',
\t\t\t\t\turl: '/distpar/parallel-testing/web/app_dev.php/check',
\t\t\t\t\tdata: {
\t\t\t\t\t\t'testid': \$('#output').data('testid')
\t\t\t\t\t},
\t\t\t\t\tdataType: 'json',
\t\t\t\t\tsuccess: function(result){
if (result.status == 'running') {
 setTimeout(function() { update_output(); }, 1000);
 }
\$('#output pre').text(result.output);
\t\t\t\t\t},
\t\t\t\t\terror: function(xhr, ajaxOptions, thrownError){ alert('Error: ' + thrownError); }
\t    \t   });
}

update_output();
\t\t});
\t</script>

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
        return array (  79 => 28,  76 => 27,  71 => 24,  68 => 23,  59 => 17,  53 => 14,  49 => 12,  46 => 11,  41 => 8,  38 => 7,  32 => 5,);
    }
}
