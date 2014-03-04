<?php

/* @WebProfiler/Profiler/base_js.html.twig */
class __TwigTemplate_322f37061a9bd5a4b70dffa5e0a3be8ddadebc7cf0e4d50e50e2529afde89404 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        echo "<script>/*<![CDATA[*/
    Sfjs = (function() {
        \"use strict\";

        var noop = function() {},

            profilerStorageKey = 'sf2/profiler/',

            request = function(url, onSuccess, onError, payload, options) {
                var xhr = window.XMLHttpRequest ? new XMLHttpRequest() : new ActiveXObject('Microsoft.XMLHTTP');
                options = options || {};
                xhr.open(options.method || 'GET', url, true);
                xhr.setRequestHeader('X-Requested-With', 'XMLHttpRequest');
                xhr.onreadystatechange = function(state) {
                    if (4 === xhr.readyState && 200 === xhr.status) {
                        (onSuccess || noop)(xhr);
                    } else if (4 === xhr.readyState && xhr.status != 200) {
                        (onError || noop)(xhr);
                    }
                };
                xhr.send(payload || '');
            },

            hasClass = function(el, klass) {
                return el.className.match(new RegExp('\\\\b' + klass + '\\\\b'));
            },

            removeClass = function(el, klass) {
                el.className = el.className.replace(new RegExp('\\\\b' + klass + '\\\\b'), ' ');
            },

            addClass = function(el, klass) {
                if (!hasClass(el, klass)) { el.className += \" \" + klass; }
            },

            getPreference = function(name) {
                if (!window.localStorage) {
                    return null;
                }

                return localStorage.getItem(profilerStorageKey + name);
            },

            setPreference = function(name, value) {
                if (!window.localStorage) {
                    return null;
                }

                localStorage.setItem(profilerStorageKey + name, value);
            };

        return {
            hasClass: hasClass,

            removeClass: removeClass,

            addClass: addClass,

            getPreference: getPreference,

            setPreference: setPreference,

            request: request,

            load: function(selector, url, onSuccess, onError, options) {
                var el = document.getElementById(selector);

                if (el && el.getAttribute('data-sfurl') !== url) {
                    request(
                        url,
                        function(xhr) {
                            el.innerHTML = xhr.responseText;
                            el.setAttribute('data-sfurl', url);
                            removeClass(el, 'loading');
                            (onSuccess || noop)(xhr, el);
                        },
                        function(xhr) { (onError || noop)(xhr, el); },
                        options
                    );
                }

                return this;
            },

            toggle: function(selector, elOn, elOff) {
                var i,
                    style,
                    tmp = elOn.style.display,
                    el = document.getElementById(selector);

                elOn.style.display = elOff.style.display;
                elOff.style.display = tmp;

                if (el) {
                    el.style.display = 'none' === tmp ? 'none' : 'block';
                }

                return this;
            }
        }
    })();
/*]]>*/</script>
";
    }

    public function getTemplateName()
    {
        return "@WebProfiler/Profiler/base_js.html.twig";
    }

    public function getDebugInfo()
    {
        return array (  91 => 35,  83 => 30,  79 => 29,  75 => 28,  70 => 26,  66 => 25,  50 => 15,  46 => 14,  42 => 12,  32 => 6,  30 => 5,  26 => 3,  24 => 2,  19 => 1,  411 => 72,  406 => 71,  402 => 75,  398 => 73,  393 => 72,  390 => 71,  384 => 70,  375 => 63,  372 => 62,  369 => 61,  354 => 59,  348 => 58,  342 => 59,  335 => 58,  331 => 76,  328 => 61,  325 => 58,  322 => 57,  317 => 53,  312 => 50,  307 => 47,  301 => 54,  299 => 53,  295 => 51,  293 => 50,  289 => 48,  287 => 47,  283 => 45,  280 => 44,  273 => 40,  270 => 39,  266 => 77,  263 => 57,  260 => 44,  257 => 39,  254 => 38,  249 => 78,  247 => 38,  242 => 37,  239 => 36,  235 => 32,  221 => 30,  216 => 29,  213 => 28,  209 => 26,  189 => 24,  184 => 20,  181 => 19,  176 => 17,  163 => 14,  158 => 13,  153 => 12,  149 => 15,  147 => 14,  143 => 13,  139 => 12,  135 => 10,  132 => 9,  128 => 33,  126 => 28,  123 => 27,  121 => 19,  116 => 17,  113 => 16,  110 => 9,  107 => 8,  102 => 34,  100 => 8,  95 => 7,  92 => 6,  88 => 80,  86 => 36,  84 => 6,  76 => 5,  68 => 4,  60 => 3,  52 => 2,  44 => 1,  74 => 25,  71 => 24,  62 => 24,  57 => 16,  53 => 15,  48 => 12,  45 => 11,  40 => 8,  37 => 7,  31 => 5,);
    }
}
