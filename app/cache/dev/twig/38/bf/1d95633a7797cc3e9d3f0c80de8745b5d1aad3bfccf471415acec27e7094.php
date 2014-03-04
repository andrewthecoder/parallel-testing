<?php

/* OryzoneBoilerplateBundle::html5.html.twig */
class __TwigTemplate_38bf1d95633a7797cc3e9d3f0c80de8745b5d1aad3bfccf471415acec27e7094 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
            'all' => array($this, 'block_all'),
            'head_outer' => array($this, 'block_head_outer'),
            'head' => array($this, 'block_head'),
            'head_meta' => array($this, 'block_head_meta'),
            'head_meta_description' => array($this, 'block_head_meta_description'),
            'head_meta_keywords' => array($this, 'block_head_meta_keywords'),
            'head_meta_viewport_tag' => array($this, 'block_head_meta_viewport_tag'),
            'head_meta_viewport_tag_content' => array($this, 'block_head_meta_viewport_tag_content'),
            'head_title' => array($this, 'block_head_title'),
            'head_css' => array($this, 'block_head_css'),
            'head_js' => array($this, 'block_head_js'),
            'body_outer' => array($this, 'block_body_outer'),
            'body' => array($this, 'block_body'),
            'body_chromeframe' => array($this, 'block_body_chromeframe'),
            'body_container' => array($this, 'block_body_container'),
            'body_container_header' => array($this, 'block_body_container_header'),
            'body_container_main' => array($this, 'block_body_container_main'),
            'body_container_footer' => array($this, 'block_body_container_footer'),
            'body_js' => array($this, 'block_body_js'),
            'body_js_jquery' => array($this, 'block_body_js_jquery'),
            'body_js_jquery_onlineSrc' => array($this, 'block_body_js_jquery_onlineSrc'),
            'body_js_jquery_offlineSrc' => array($this, 'block_body_js_jquery_offlineSrc'),
            'body_js_analytics' => array($this, 'block_body_js_analytics'),
            'body_js_analytics_extra' => array($this, 'block_body_js_analytics_extra'),
            'body_js_analytics_track' => array($this, 'block_body_js_analytics_track'),
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        $this->displayBlock('all', $context, $blocks);
    }

    public function block_all($context, array $blocks = array())
    {
        echo "<!doctype html>
<!--[if lt IE 7]><html class=\"no-js lt-ie9 lt-ie8 lt-ie7 ";
        // line 2
        echo twig_escape_filter($this->env, ((array_key_exists("bp_html_classes", $context)) ? (_twig_default_filter((isset($context["bp_html_classes"]) ? $context["bp_html_classes"] : $this->getContext($context, "bp_html_classes")), "")) : ("")), "html", null, true);
        echo "\" lang=\"";
        echo twig_escape_filter($this->env, ((array_key_exists("bp_language", $context)) ? (_twig_default_filter((isset($context["bp_language"]) ? $context["bp_language"] : $this->getContext($context, "bp_language")), "en")) : ("en")), "html", null, true);
        echo "\" ";
        echo ((array_key_exists("bp_html_attributes", $context)) ? (_twig_default_filter((isset($context["bp_html_attributes"]) ? $context["bp_html_attributes"] : $this->getContext($context, "bp_html_attributes")), "")) : (""));
        echo "><![endif]-->
<!--[if IE 7]><html class=\"no-js lt-ie9 lt-ie8 ";
        // line 3
        echo twig_escape_filter($this->env, ((array_key_exists("bp_html_classes", $context)) ? (_twig_default_filter((isset($context["bp_html_classes"]) ? $context["bp_html_classes"] : $this->getContext($context, "bp_html_classes")), "")) : ("")), "html", null, true);
        echo "\" lang=\"";
        echo twig_escape_filter($this->env, ((array_key_exists("bp_language", $context)) ? (_twig_default_filter((isset($context["bp_language"]) ? $context["bp_language"] : $this->getContext($context, "bp_language")), "en")) : ("en")), "html", null, true);
        echo "\" ";
        echo ((array_key_exists("bp_html_attributes", $context)) ? (_twig_default_filter((isset($context["bp_html_attributes"]) ? $context["bp_html_attributes"] : $this->getContext($context, "bp_html_attributes")), "")) : (""));
        echo "><![endif]-->
<!--[if IE 8]><html class=\"no-js lt-ie9 ";
        // line 4
        echo twig_escape_filter($this->env, ((array_key_exists("bp_html_classes", $context)) ? (_twig_default_filter((isset($context["bp_html_classes"]) ? $context["bp_html_classes"] : $this->getContext($context, "bp_html_classes")), "")) : ("")), "html", null, true);
        echo "\" lang=\"";
        echo twig_escape_filter($this->env, ((array_key_exists("bp_language", $context)) ? (_twig_default_filter((isset($context["bp_language"]) ? $context["bp_language"] : $this->getContext($context, "bp_language")), "en")) : ("en")), "html", null, true);
        echo "\" ";
        echo ((array_key_exists("bp_html_attributes", $context)) ? (_twig_default_filter((isset($context["bp_html_attributes"]) ? $context["bp_html_attributes"] : $this->getContext($context, "bp_html_attributes")), "")) : (""));
        echo "><![endif]-->
<!--[if gt IE 8]><!--><html class=\"no-js ";
        // line 5
        echo twig_escape_filter($this->env, ((array_key_exists("bp_html_classes", $context)) ? (_twig_default_filter((isset($context["bp_html_classes"]) ? $context["bp_html_classes"] : $this->getContext($context, "bp_html_classes")), "")) : ("")), "html", null, true);
        echo "\" lang=\"";
        echo twig_escape_filter($this->env, ((array_key_exists("bp_language", $context)) ? (_twig_default_filter((isset($context["bp_language"]) ? $context["bp_language"] : $this->getContext($context, "bp_language")), "en")) : ("en")), "html", null, true);
        echo "\" ";
        echo ((array_key_exists("bp_html_attributes", $context)) ? (_twig_default_filter((isset($context["bp_html_attributes"]) ? $context["bp_html_attributes"] : $this->getContext($context, "bp_html_attributes")), "")) : (""));
        echo "><!--<![endif]-->
";
        // line 6
        $this->displayBlock('head_outer', $context, $blocks);
        // line 36
        $this->displayBlock('body_outer', $context, $blocks);
        // line 80
        echo "</html>";
    }

    // line 6
    public function block_head_outer($context, array $blocks = array())
    {
        // line 7
        echo "    <head ";
        echo ((array_key_exists("bp_head_attributes", $context)) ? (_twig_default_filter((isset($context["bp_head_attributes"]) ? $context["bp_head_attributes"] : $this->getContext($context, "bp_head_attributes")), "")) : (""));
        echo ">
        ";
        // line 8
        $this->displayBlock('head', $context, $blocks);
        // line 34
        echo "    </head>
";
    }

    // line 8
    public function block_head($context, array $blocks = array())
    {
        // line 9
        echo "            ";
        $this->displayBlock('head_meta', $context, $blocks);
        // line 16
        echo "
            <title>";
        // line 17
        $this->displayBlock('head_title', $context, $blocks);
        echo "</title>

            ";
        // line 19
        $this->displayBlock('head_css', $context, $blocks);
        // line 27
        echo "
            ";
        // line 28
        $this->displayBlock('head_js', $context, $blocks);
        // line 33
        echo "        ";
    }

    // line 9
    public function block_head_meta($context, array $blocks = array())
    {
        // line 10
        echo "                <meta charset=\"utf-8\">
                <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">
                <meta name=\"description\" content=\"";
        // line 12
        $this->displayBlock('head_meta_description', $context, $blocks);
        echo "\">
                <meta name=\"keywords\" content=\"";
        // line 13
        $this->displayBlock('head_meta_keywords', $context, $blocks);
        echo "\">
                ";
        // line 14
        $this->displayBlock('head_meta_viewport_tag', $context, $blocks);
        // line 15
        echo "            ";
    }

    // line 12
    public function block_head_meta_description($context, array $blocks = array())
    {
    }

    // line 13
    public function block_head_meta_keywords($context, array $blocks = array())
    {
    }

    // line 14
    public function block_head_meta_viewport_tag($context, array $blocks = array())
    {
        echo "<meta name=\"viewport\" content=\"";
        $this->displayBlock('head_meta_viewport_tag_content', $context, $blocks);
        echo "\">";
    }

    public function block_head_meta_viewport_tag_content($context, array $blocks = array())
    {
        echo "width=device-width, initial-scale=1";
    }

    // line 17
    public function block_head_title($context, array $blocks = array())
    {
    }

    // line 19
    public function block_head_css($context, array $blocks = array())
    {
        // line 20
        echo "                ";
        if (isset($context['assetic']['debug']) && $context['assetic']['debug']) {
            // asset "8b58cc4_0"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_8b58cc4_0") : $this->env->getExtension('assets')->getAssetUrl("_controller/css/8b58cc4_normalize_1.css");
            // line 24
            echo "            <link rel=\"stylesheet\"  href=\"";
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" >
                ";
            // asset "8b58cc4_1"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_8b58cc4_1") : $this->env->getExtension('assets')->getAssetUrl("_controller/css/8b58cc4_main_2.css");
            echo "            <link rel=\"stylesheet\"  href=\"";
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" >
                ";
        } else {
            // asset "8b58cc4"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_8b58cc4") : $this->env->getExtension('assets')->getAssetUrl("_controller/css/8b58cc4.css");
            echo "            <link rel=\"stylesheet\"  href=\"";
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\" >
                ";
        }
        unset($context["asset_url"]);
        // line 26
        echo "            ";
    }

    // line 28
    public function block_head_js($context, array $blocks = array())
    {
        // line 29
        echo "                ";
        if (isset($context['assetic']['debug']) && $context['assetic']['debug']) {
            // asset "10fc496_0"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_10fc496_0") : $this->env->getExtension('assets')->getAssetUrl("_controller/js/10fc496_modernizr_1.js");
            // line 30
            echo "                <script src=\"";
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\"></script>
                ";
        } else {
            // asset "10fc496"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_10fc496") : $this->env->getExtension('assets')->getAssetUrl("_controller/js/10fc496.js");
            echo "                <script src=\"";
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
            echo "\"></script>
                ";
        }
        unset($context["asset_url"]);
        // line 32
        echo "            ";
    }

    // line 36
    public function block_body_outer($context, array $blocks = array())
    {
        // line 37
        echo "    <body ";
        echo ((array_key_exists("bp_body_attributes", $context)) ? (_twig_default_filter((isset($context["bp_body_attributes"]) ? $context["bp_body_attributes"] : $this->getContext($context, "bp_body_attributes")), "")) : (""));
        echo ">
    ";
        // line 38
        $this->displayBlock('body', $context, $blocks);
        // line 78
        echo "    </body>
";
    }

    // line 38
    public function block_body($context, array $blocks = array())
    {
        // line 39
        echo "        ";
        $this->displayBlock('body_chromeframe', $context, $blocks);
        // line 44
        echo "        ";
        $this->displayBlock('body_container', $context, $blocks);
        // line 57
        echo "        ";
        $this->displayBlock('body_js', $context, $blocks);
        // line 77
        echo "    ";
    }

    // line 39
    public function block_body_chromeframe($context, array $blocks = array())
    {
        // line 40
        echo "            <!--[if lt IE 7]>
                <p class=\"chromeframe\">You are using an <strong>outdated</strong> browser. Please <a href=\"http://browsehappy.com/\">upgrade your browser</a> or <a href=\"http://www.google.com/chromeframe/?redirect=true\">activate Google Chrome Frame</a> to improve your experience.</p>
            <![endif]-->
        ";
    }

    // line 44
    public function block_body_container($context, array $blocks = array())
    {
        // line 45
        echo "            <div id=\"container\">
                <header>
                    ";
        // line 47
        $this->displayBlock('body_container_header', $context, $blocks);
        // line 48
        echo "                </header>
                <div role=\"main\">
                    ";
        // line 50
        $this->displayBlock('body_container_main', $context, $blocks);
        // line 51
        echo "                </div>
                <footer>
                    ";
        // line 53
        $this->displayBlock('body_container_footer', $context, $blocks);
        // line 54
        echo "                </footer>
            </div>
        ";
    }

    // line 47
    public function block_body_container_header($context, array $blocks = array())
    {
    }

    // line 50
    public function block_body_container_main($context, array $blocks = array())
    {
    }

    // line 53
    public function block_body_container_footer($context, array $blocks = array())
    {
    }

    // line 57
    public function block_body_js($context, array $blocks = array())
    {
        // line 58
        echo "            ";
        $this->displayBlock('body_js_jquery', $context, $blocks);
        // line 61
        echo "            ";
        $this->displayBlock('body_js_analytics', $context, $blocks);
        // line 76
        echo "        ";
    }

    // line 58
    public function block_body_js_jquery($context, array $blocks = array())
    {
        echo "<script src=\"";
        $this->displayBlock('body_js_jquery_onlineSrc', $context, $blocks);
        echo "\"></script>
                <script>window.jQuery || document.write('<script src=\"";
        // line 59
        $this->displayBlock('body_js_jquery_offlineSrc', $context, $blocks);
        echo "\"><\\/script>')</script>
            ";
    }

    // line 58
    public function block_body_js_jquery_onlineSrc($context, array $blocks = array())
    {
        echo "//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js";
    }

    // line 59
    public function block_body_js_jquery_offlineSrc($context, array $blocks = array())
    {
        if (isset($context['assetic']['debug']) && $context['assetic']['debug']) {
            // asset "9900a82_0"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_9900a82_0") : $this->env->getExtension('assets')->getAssetUrl("_controller/js/9900a82_jquery.min_1.js");
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
        } else {
            // asset "9900a82"
            $context["asset_url"] = isset($context['assetic']['use_controller']) && $context['assetic']['use_controller'] ? $this->env->getExtension('routing')->getPath("_assetic_9900a82") : $this->env->getExtension('assets')->getAssetUrl("_controller/js/9900a82.js");
            echo twig_escape_filter($this->env, (isset($context["asset_url"]) ? $context["asset_url"] : $this->getContext($context, "asset_url")), "html", null, true);
        }
        unset($context["asset_url"]);
    }

    // line 61
    public function block_body_js_analytics($context, array $blocks = array())
    {
        // line 62
        echo "                ";
        if (((array_key_exists("bp_analytics_id", $context)) ? (_twig_default_filter((isset($context["bp_analytics_id"]) ? $context["bp_analytics_id"] : $this->getContext($context, "bp_analytics_id")), null)) : (null))) {
            // line 63
            echo "                    <script>
                        (function(b,o,i,l,e,r){b.GoogleAnalyticsObject=l;b[l]||(b[l]=
                        function(){(b[l].q=b[l].q||[]).push(arguments)});b[l].l=+new Date;
                        e=o.createElement(i);r=o.getElementsByTagName(i)[0];
                        e.src='//www.google-analytics.com/analytics.js';
                        r.parentNode.insertBefore(e,r)}(window,document,'script','ga'));
                        var gao=gao||{};
                        ";
            // line 70
            if (((array_key_exists("bp_analytics_domain", $context)) ? (_twig_default_filter((isset($context["bp_analytics_domain"]) ? $context["bp_analytics_domain"] : $this->getContext($context, "bp_analytics_domain")), null)) : (null))) {
                echo "gao.cookieDomain='";
                echo twig_escape_filter($this->env, (isset($context["bp_analytics_domain"]) ? $context["bp_analytics_domain"] : $this->getContext($context, "bp_analytics_domain")), "html", null, true);
                echo "';";
            }
            // line 71
            echo "                        ";
            $this->displayBlock('body_js_analytics_extra', $context, $blocks);
            // line 72
            echo "                        ga('create','";
            echo twig_escape_filter($this->env, (isset($context["bp_analytics_id"]) ? $context["bp_analytics_id"] : $this->getContext($context, "bp_analytics_id")), "html", null, true);
            echo "',gao);";
            $this->displayBlock('body_js_analytics_track', $context, $blocks);
            // line 73
            echo "                    </script>
                ";
        }
        // line 75
        echo "            ";
    }

    // line 71
    public function block_body_js_analytics_extra($context, array $blocks = array())
    {
    }

    // line 72
    public function block_body_js_analytics_track($context, array $blocks = array())
    {
        echo "ga('send','pageview');";
    }

    public function getTemplateName()
    {
        return "OryzoneBoilerplateBundle::html5.html.twig";
    }

    public function getDebugInfo()
    {
        return array (  411 => 72,  406 => 71,  402 => 75,  398 => 73,  393 => 72,  390 => 71,  384 => 70,  375 => 63,  372 => 62,  369 => 61,  354 => 59,  348 => 58,  342 => 59,  335 => 58,  331 => 76,  328 => 61,  325 => 58,  322 => 57,  317 => 53,  312 => 50,  307 => 47,  301 => 54,  299 => 53,  295 => 51,  293 => 50,  289 => 48,  287 => 47,  283 => 45,  280 => 44,  273 => 40,  270 => 39,  266 => 77,  263 => 57,  260 => 44,  257 => 39,  254 => 38,  249 => 78,  247 => 38,  242 => 37,  239 => 36,  235 => 32,  221 => 30,  216 => 29,  213 => 28,  209 => 26,  189 => 24,  184 => 20,  181 => 19,  176 => 17,  163 => 14,  158 => 13,  153 => 12,  149 => 15,  147 => 14,  143 => 13,  139 => 12,  135 => 10,  132 => 9,  128 => 33,  126 => 28,  123 => 27,  121 => 19,  116 => 17,  113 => 16,  110 => 9,  107 => 8,  102 => 34,  100 => 8,  95 => 7,  92 => 6,  88 => 80,  86 => 36,  84 => 6,  76 => 5,  68 => 4,  60 => 3,  52 => 2,  44 => 1,  74 => 25,  71 => 24,  62 => 18,  57 => 16,  53 => 15,  48 => 12,  45 => 11,  40 => 8,  37 => 7,  31 => 5,);
    }
}
