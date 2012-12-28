<!doctype html>
	<html lang="en" dir="ltr" class="">
	<head>
		<title>C file input/output - Wikipedia, the free encyclopedia</title>
		<meta http-equiv="content-type" content="text/html; charset=utf-8" />
		<meta name="robots" content="noindex,nofollow"/>		<link rel="stylesheet" href="http://bits.wikimedia.org/en.wikipedia.org/load.php?debug=false&amp;lang=en&amp;modules=mobile%7Cmobile.production-only%2Cproduction-jquery%7Cmobile.device.default&amp;only=styles&amp;skin=mobile&amp;version=1352163471&amp;*" />
<link rel="stylesheet" href="http://bits.wikimedia.org/en.wikipedia.org/load.php?debug=false&amp;lang=en&amp;modules=mobile.site&amp;only=styles&amp;skin=mobile&amp;*" />		<meta name="viewport" content="initial-scale=1.0, user-scalable=no">
		<link rel="apple-touch-icon" href="http://en.wikipedia.org/apple-touch-icon.png" />		<script type="text/javascript">
			var _mwStart = +new Date;
			window._evq = window._evq || [];
			if ( typeof console === 'undefined' ) {
				console = { log: function() {} };
			}
			if( typeof mw === 'undefined' ) {
				mw = {};
			}
			var mwMobileFrontendConfig = {"messages":{"mobile-frontend-watchlist-add":"Added $1 to your watchlist","mobile-frontend-watchlist-removed":"Removed $1 from your watchlist","mobile-frontend-watchlist-view":"View your watchlist","mobile-frontend-ajax-random-heading":"Locating knowledge...","mobile-frontend-ajax-random-quote":"Intellectual growth should commence at birth and cease only at death","mobile-frontend-ajax-random-quote-author":"Albert Einstein","mobile-frontend-ajax-random-question":"Read this article?","mobile-frontend-ajax-random-yes":"Yes","mobile-frontend-ajax-random-retry":"Try again","mobile-frontend-ajax-page-loading":"Loading $1","mobile-frontend-page-saving":"Saving $1","mobile-frontend-ajax-page-error":"Whoops! Something went wrong there. Please try refreshing your browser window.","mobile-frontend-meta-data-issues":"This article has some issues","mobile-frontend-meta-data-issues-header":"Issues","expand-section":"Show","collapse-section":"Hide","remove-results":"Back...","mobile-frontend-search-noresults":"No article titles match your search. Change your search, or press the keyboard search button to search inside articles.","mobile-frontend-search-help":"Type search term above and matching article titles will appear here.","contents-heading":"Contents","language-heading":"Read this article in","mobile-frontend-close-section":"Close this section","mobile-frontend-language-footer":"<a href="http://en.m.wikipedia.org/wiki/\&quot;\/wiki\/Special:MobileOptions\/Language\&quot;">Note: This article may not be written in your preferred language. You can see which languages Wikipedia supports by clicking here.<\/a>","mobile-frontend-language-site-choose":"Search language","mobile-frontend-language-site-nomatches":"No matching languages"},"settings":{"action":"","authenticated":false,"scriptPath":"\/w","shim":"\/\/bits.wikimedia.org\/static-1.21wmf3\/extensions\/MobileFrontend\/stylesheets\/common\/images\/blank.gif","pageUrl":"\/wiki\/$1","beta":null,"title":"C file input\/output","useFormatCookieName":"mf_mobileFormat","useFormatCookieDuration":-1,"useFormatCookieDomain":"en.wikipedia.org","useFormatCookiePath":"\/","stopMobileRedirectCookieName":"stopMobileRedirect","stopMobileRedirectCookieDuration":15552000,"stopMobileRedirectCookieDomain":".wikipedia.org","hookOptions":""}};
			function _mwLogEvent( data, additionalInformation ) {
				var timestamp = + new Date;
				var ev = { event_id: 'mobile', delta: timestamp - _mwStart, data: data, beta: mwMobileFrontendConfig.settings.beta,
					session: _mwStart, page: mwMobileFrontendConfig.settings.title, info: additionalInformation || '' };
				_evq.push( ev );
				console.log( typeof JSON === 'undefined' ? ev : JSON.stringify( ev ) );
			}
		</script>
				<link rel="canonical" href="http://en.wikipedia.org/wiki/C_file_input/output" >
	</head>
	<body class="mobile live">
				<div id="mw-mf-viewport">
		<div id="mw-mf-page-left">
		<div id='mw-mf-content-left'>
		<ul id="mw-mf-menu-main">
			<li class='icon'><a href="Main_Page"
				title="Home">
				Home</a></li>
			<li class='icon2'><a href="Special:Random#mw-mf-page-left" id="randomButton"
				title="Random"
				class="button">Random</a></li>
						<li class='icon5'>
				<a href="http://en.m.wikipedia.org/w/index.php?title=Special:MobileOptions&amp;returnto=C+file+input%2Foutput"
					title="Settings">
				Settings				</a>
			</li>
					</ul>
		</div>
		</div>
		<div id='mw-mf-page-center'>
									<div id="mw-mf-header">
		<a title="Open main menu" href="Special:MobileMenu#mw-mf-page-left" id="mw-mf-main-menu-button">				<img alt="menu"
				src="http://bits.wikimedia.org/static-1.21wmf3/extensions/MobileFrontend/stylesheets/common/images/blank.gif">
		</a>			<form id="mw-mf-searchForm" action="http://en.m.wikipedia.org/w/index.php" class="search_bar" method="get">
			<input type="hidden" value="Special:Search" name="title" />
			<div id="mw-mf-sq" class="divclearable">
				<input type="search" name="search" id="mw-mf-search" size="22" value="" autocomplete="off" maxlength="1024" class="search"
					placeholder="Search Wikipedia"
					/>
				<img src="http://bits.wikimedia.org/static-1.21wmf3/extensions/MobileFrontend/stylesheets/common/images/blank.gif" alt="Clear" class="clearlink" id="mw-mf-clearsearch" title="Clear"/>
				<input class='searchSubmit' type="submit" value="Go">
			</div>
		</form>
	</div>
	<div id="results"></div>
		<div class='show ' id='content_wrapper'>
						<h1 id="firstHeading">C file input/output</h1>			
<table class="vertical-navbox nowraplinks" cellspacing="5" style="float: right; clear: right; background-color: #f9f9f9; border: 1px solid #aaa; width:22em; margin: 0 0 1em 1em; padding: 0.2em; border-spacing: 0.4em 0; text-align: center; line-height: 1.4em; font-size: 88%;" cellpadding="0">
<tr>
<th class="" style="padding: 0.2em 0.4em 0.2em; font-size: 145%; line-height: 1.2em;"><a href="http://en.m.wikipedia.org/wiki/C_Standard_Library" title="C Standard Library" class="mw-redirect">C Standard Library</a></th>
</tr>
<tr>
<td class="" style="padding-top: 0.2em; padding-bottom: 0.2em; text-align: left;">
<ul>
<li><a href="C_data_types" title="C data types">Data types</a></li>
<li><a href="http://en.m.wikipedia.org/wiki/C_character_classification" title="C character classification">Character classification</a></li>
<li><a href="http://en.m.wikipedia.org/wiki/C_string_handling" title="C string handling">Strings</a></li>
<li><a href="http://en.m.wikipedia.org/wiki/C_mathematical_functions" title="C mathematical functions">Mathematics</a></li>
<li><strong class="selflink">File input/output</strong></li>
<li><a href="http://en.m.wikipedia.org/wiki/C_date_and_time_functions" title="C date and time functions">Date/time</a></li>
<li><a href="http://en.m.wikipedia.org/wiki/C_localization_functions" title="C localization functions">Localization</a></li>
<li><a href="http://en.m.wikipedia.org/wiki/C_dynamic_memory_allocation" title="C dynamic memory allocation">Memory allocation</a></li>
<li><a href="http://en.m.wikipedia.org/wiki/C_process_control" title="C process control">Process control</a></li>
<li><a href="http://en.m.wikipedia.org/wiki/C_signal_handling" title="C signal handling">Signals</a></li>
<li><a href="http://en.m.wikipedia.org/wiki/C_alternative_tokens" title="C alternative tokens">Alternative tokens</a></li>
</ul>
<dl>
<dd>
<b>Miscellaneous headers</b>:</dd>
</dl>
<ul>
<li><code>&lt;<a href="http://en.m.wikipedia.org/wiki/Assert.h" title="Assert.h">assert.h</a>&gt;</code></li>
<li><code>&lt;<a href="http://en.m.wikipedia.org/wiki/Errno.h" title="Errno.h">errno.h</a>&gt;</code></li>
<li><code>&lt;<a href="http://en.m.wikipedia.org/wiki/Setjmp.h" title="Setjmp.h">setjmp.h</a>&gt;</code></li>
<li><code>&lt;<a href="http://en.m.wikipedia.org/wiki/Stdarg.h" title="Stdarg.h">stdarg.h</a>&gt;</code></li>
</ul>
</td>
</tr>
<tr>
<td style="text-align: right; font-size: 115%;">
<div class="noprint plainlinks hlist navbar mini" style="">
<ul>
<li class="nv-view"><a href="http://en.m.wikipedia.org/wiki/Template:C_Standard_Library" title="Template:C Standard Library"><span title="View this template" style="">v</span></a></li>
<li class="nv-talk"><a href="http://en.m.wikipedia.org/wiki/Template_talk:C_Standard_Library" title="Template talk:C Standard Library"><span title="Discuss this template" style="">t</span></a></li>
<li class="nv-edit"><a class="external text" href="http://en.wikipedia.org/w/index.php?title=Template:C_Standard_Library&amp;action=edit"><span title="Edit this template" style="">e</span></a></li>
</ul>
</div>
</td>
</tr>
</table>
<table class="metadata plainlinks ambox ambox-style ambox-Prose" style=""><tr>
<td class="mbox-image">
<div style="width: 52px;"><img alt="" src="http://upload.wikimedia.org/wikipedia/en/thumb/f/f2/Edit-clear.svg/40px-Edit-clear.svg.png" width="40" height="40" srcset="//upload.wikimedia.org/wikipedia/en/thumb/f/f2/Edit-clear.svg/60px-Edit-clear.svg.png 1.5x, //upload.wikimedia.org/wikipedia/en/thumb/f/f2/Edit-clear.svg/80px-Edit-clear.svg.png 2x"></div>
</td>
<td class="mbox-text" style=""><span class="mbox-text-span">This article <b>is in a list format that may be better presented using <a href="http://en.m.wikipedia.org/wiki/Wikipedia:Proseline" title="Wikipedia:Proseline">prose</a>.</b> <span class="hide-when-compact">You can help by converting this article to prose, if <a href="http://en.m.wikipedia.org/wiki/Wikipedia:Embedded_list" title="Wikipedia:Embedded list" class="mw-redirect">appropriate</a>. <a href="http://en.m.wikipedia.org/wiki/Help:Editing" title="Help:Editing">Editing help</a> is available.</span> <small><i>(December 2011)</i></small> </span></td>
</tr></table>
<p>The <a href="http://en.m.wikipedia.org/wiki/C_(programming_language)" title="C (programming language)">C programming language</a> provides many <a href="http://en.m.wikipedia.org/wiki/Standard_library" title="Standard library">standard library</a> <a href="Subroutine" title="Subroutine">functions</a> for <a href="http://en.m.wikipedia.org/wiki/Computer_file" title="Computer file">file</a> <a href="Input/output" title="Input/output">input and output</a>. These functions make up the bulk of the <a href="C_standard_library" title="C standard library">C standard library</a> <a href="Header_file" title="Header file">header</a> <code>&lt;stdio.h&gt;</code>.<sup id="cite_ref-0" class="reference"><a href="Stdio.h#cite_note-0"><span>[</span>1<span>]</span></a></sup> The functionality descends from a "portable I/O package" written by <a href="http://en.m.wikipedia.org/wiki/Mike_Lesk" title="Mike Lesk">Mike Lesk</a> at Bell Labs in the early 1970s.<sup id="cite_ref-1" class="reference"><a href="Stdio.h#cite_note-1"><span>[</span>2<span>]</span></a></sup></p>
<p>The I/O functionality of C is fairly low-level by modern standards; C abstracts all file operations into operations on <a href="http://en.m.wikipedia.org/wiki/Stream_(computing)" title="Stream (computing)">streams</a> of <a href="Byte" title="Byte">bytes</a>, which may be "input streams" or "output streams". Unlike some earlier programming languages, C has no direct support for <a href="http://en.m.wikipedia.org/wiki/Random-access" title="Random-access" class="mw-redirect">random-access</a> data files; to read from a record in the middle of a file, the programmer must create a stream, <a href="http://en.m.wikipedia.org/wiki/Fseek" title="Fseek" class="mw-redirect">seek</a> to the middle of the file, and then read bytes in sequence from the stream.</p>
<p>The stream model of file I/O was popularized by the <a href="Unix" title="Unix">Unix</a> <a href="Operating_system" title="Operating system">operating system</a>, which was developed concurrently with the C programming language itself. The vast majority of modern operating systems have inherited streams from Unix, and many languages in the <a href="Category:C_programming_language_family" title="Category:C programming language family">C programming language family</a> have inherited C's file I/O interface with few if any changes (for example, <a href="PHP" title="PHP">PHP</a>). The <a href="C++" title="C++">C++</a> standard library reflects the "stream" concept in its syntax; see <a href="http://en.m.wikipedia.org/wiki/Iostream" title="Iostream" class="mw-redirect">iostream</a>.</p>
<h2> <span class="mw-headline" id="Overview_of_functions">Overview of functions</span>
</h2>
<p>Most of the C file input/output functions are defined in <code>stdio.h</code> (<code>cstdio</code> header in C++).</p>
<p><br></p>
<table class="wikitable" style="font-size:0.85em">
<tr>
<th></th>
<th>Byte<br>
character</th>
<th>Wide<br>
character</th>
<th>Description</th>
</tr>
<tr>
<th rowspan="7">File access</th>
<td colspan="2" style="text-align:center">
<span id="fopen"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fopen">fopen</a></code>
</td>
<td>opens a file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="freopen"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/freopen">freopen</a></code>
</td>
<td>opens a different file with an existing stream</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="fflush"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fflush">fflush</a></code>
</td>
<td>synchronizes an output stream with the actual file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="fclose"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fclose">fclose</a></code>
</td>
<td>closes a file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="setbuf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/setbuf">setbuf</a></code>
</td>
<td>sets the buffer for a file stream</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="setvbuf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/setvbuf">setvbuf</a></code>
</td>
<td>sets the buffer and its size for a file stream</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="fwide"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fwide">fwide</a></code>
</td>
<td>switches a file stream between wide character I/O and narrow character I/O</td>
</tr>
<tr>
<th rowspan="2">Direct<br>
input/output</th>
<td colspan="2" style="text-align:center">
<span id="fread"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fread">fread</a></code>
</td>
<td>reads from a file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="fwrite"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fwrite">fwrite</a></code>
</td>
<td>writes to a file</td>
</tr>
<tr>
<th rowspan="9">Unformatted<br>
input/output</th>
<td>
<span id="fgetc"></span><span id="getc"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fgetc">fgetc</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/getc">getc</a></code>
</td>
<td>
<span id="fgetwc"></span><span id="getwc"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fgetwc">fgetwc</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/getwc">getwc</a></code>
</td>
<td>reads a byte/<code>wchar_t</code> from a file stream</td>
</tr>
<tr>
<td>
<span id="fgets"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fgets">fgets</a></code>
</td>
<td>
<span id="fgetws"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fgetws">fgetws</a></code>
</td>
<td>reads a byte/<code>wchar_t</code> line from a file stream</td>
</tr>
<tr>
<td>
<span id="fputc"></span><span id="putc"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fputc">fputc</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/putc">putc</a></code>
</td>
<td>
<span id="fputwc"></span><span id="putwc"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fputwc">fputwc</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/putwc">putwc</a></code>
</td>
<td>writes a byte/<code>wchar_t</code> to a file stream</td>
</tr>
<tr>
<td>
<span id="fputs"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fputs">fputs</a></code>
</td>
<td>
<span id="fputws"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fputws">fputws</a></code>
</td>
<td>writes a byte/<code>wchar_t</code> string to a file stream</td>
</tr>
<tr>
<td>
<span id="getchar"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/getchar">getchar</a></code>
</td>
<td>
<span id="getwchar"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/getwchar">getwchar</a></code>
</td>
<td>reads a byte/<code>wchar_t</code> from stdin</td>
</tr>
<tr>
<td>
<span id="gets"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/gets">gets</a></code>
</td>
<td style="background: #ececec; color: grey; vertical-align: middle; text-align: center;" class="table-na"><small>N/A</small></td>
<td>reads a byte string from stdin (deprecated in C99, obsoleted in C11)</td>
</tr>
<tr>
<td>
<span id="putchar"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/putchar">putchar</a></code>
</td>
<td>
<span id="putwchar"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/putwchar">putwchar</a></code>
</td>
<td>writes a byte/<code>wchar_t</code> to stdout</td>
</tr>
<tr>
<td>
<span id="puts"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/puts">puts</a></code>
</td>
<td style="background: #ececec; color: grey; vertical-align: middle; text-align: center;" class="table-na"><small>N/A</small></td>
<td>writes a byte string to stdout</td>
</tr>
<tr>
<td>
<span id="ungetc"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/ungetc">ungetc</a></code>
</td>
<td>
<span id="ungetwc"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/ungetwc">ungetwc</a></code>
</td>
<td>puts a byte/<code>wchar_t</code> back into a file stream</td>
</tr>
<tr>
<th rowspan="4">Formatted<br>
input/output</th>
<td>
<span id="scanf"></span><span id="fscanf"></span><span id="sscanf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/scanf">scanf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fscanf">fscanf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/sscanf">sscanf</a></code>
</td>
<td>
<span id="wscanf"></span><span id="fwscanf"></span><span id="swscanf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/wscanf">wscanf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fwscanf">fwscanf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/swscanf">swscanf</a></code>
</td>
<td>reads formatted byte/<code>wchar_t</code> input from stdin,<br>
a file stream or a buffer</td>
</tr>
<tr>
<td>
<span id="vscanf"></span><span id="vfscanf"></span><span id="vsscanf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vscanf">vscanf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vfscanf">vfscanf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vsscanf">vsscanf</a></code>
</td>
<td>
<span id="vwscanf"></span><span id="vfwscanf"></span><span id="svwscanf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vwscanf">vwscanf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vfwscanf">vfwscanf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vswscanf">vswscanf</a></code>
</td>
<td>reads formatted input byte/<code>wchar_t</code> from stdin,<br>
a file stream or a buffer using variable argument list</td>
</tr>
<tr>
<td>
<span id="printf"></span><span id="fprintf"></span><span id="sprintf"></span><span id="snprintf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/printf">printf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fprintf">fprintf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/sprintf">sprintf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/snprintf">snprintf</a></code>
</td>
<td>
<span id="wprintf"></span><span id="fwprintf"></span><span id="swprintf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/wprintf">wprintf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fwprintf">fwprintf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/swprintf">swprintf</a></code>
</td>
<td>prints formatted byte/<code>wchar_t</code> output to stdout,<br>
a file stream or a buffer</td>
</tr>
<tr>
<td>
<span id="vprintf"></span><span id="vfprintf"></span><span id="vspritf"></span><span id="vsnprintf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vprintf">vprintf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vfprintf">vfprintf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vsprintf">vsprintf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vsnprintf">vsnprintf</a></code>
</td>
<td>
<span id="vwprintf"></span><span id="vfwprintf"></span><span id="vswprintf"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vwprintf">vwprintf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vfwprintf">vfwprintf</a></code><br><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/vswprintf">vswprintf</a></code>
</td>
<td>prints formatted byte/<code>wchar_t</code> output to stdout,<br>
a file stream, or a buffer using variable argument list</td>
</tr>
<tr>
<th rowspan="5">File positioning</th>
<td colspan="2" style="text-align:center">
<span id="ftell"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/ftell">ftell</a></code>
</td>
<td>returns the current file position indicator</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="fgetpos"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fgetpos">fgetpos</a></code>
</td>
<td>gets the file position indicator</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="fseek"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fseek">fseek</a></code>
</td>
<td>moves the file position indicator to a specific location in a file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="fsetpos"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/fsetpos">fsetpos</a></code>
</td>
<td>moves the file position indicator to a specific location in a file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="rewind"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/rewind">rewind</a></code>
</td>
<td>moves the file position indicator to the beginning in a file</td>
</tr>
<tr>
<th rowspan="4">Error<br>
handling</th>
<td colspan="2" style="text-align:center">
<span id="clearerr"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/clearerr">clearerr</a></code>
</td>
<td>clears errors</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="feof"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/feof">feof</a></code>
</td>
<td>checks for the end-of-file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="ferror"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/ferror">ferror</a></code>
</td>
<td>checks for a file error</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="perror"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/perror">perror</a></code>
</td>
<td>displays a character string corresponding of the current error to stderr</td>
</tr>
<tr>
<th rowspan="4">Operations<br>
on files</th>
<td colspan="2" style="text-align:center">
<span id="remove"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/remove">remove</a></code>
</td>
<td>erases a file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="rename"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/rename">rename</a></code>
</td>
<td>
<a href="http://en.m.wikipedia.org/wiki/Rename_(computing)" title="Rename (computing)">renames</a> a file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="tmpfile"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/tmpfile">tmpfile</a></code>
</td>
<td>returns a pointer to a temporary file</td>
</tr>
<tr>
<td colspan="2" style="text-align:center">
<span id="tmpnam"></span><code><a rel="nofollow" class="external text" href="http://en.cppreference.com/w/c/io/tmpnam">tmpnam</a></code>
</td>
<td>returns a unique filename</td>
</tr>
</table>
<h2> <span class="mw-headline" id="Constants">Constants</span>
</h2>
<p>Constants defined in the <code>stdio.h</code> header include:</p>
<table class="wikitable">
<tr>
<th>Name</th>
<th>Notes</th>
</tr>
<tr>
<td><code><a href="http://en.m.wikipedia.org/wiki/End-of-file" title="End-of-file">EOF</a></code></td>
<td>a negative integer of type <code>int</code> used to indicate end-of-file conditions</td>
</tr>
<tr>
<td><code><a rel="nofollow" class="external text" href="http://c-p-p.net/c/stdio.h/bufsiz">BUFSIZ</a></code></td>
<td>an integer which is the size of the buffer used by the <code>setbuf()</code> function</td>
</tr>
<tr>
<td><code>FILENAME_MAX</code></td>
<td>the size of a <code>char</code> array which is large enough to store the name of any file that can be opened</td>
</tr>
<tr>
<td><code>FOPEN_MAX</code></td>
<td>the number of files that may be open simultaneously; will be at least 8</td>
</tr>
<tr>
<td><code>_IOFBF</code></td>
<td>an abbreviation for "input/output fully buffered"; it is an integer which may be passed to the <code>setvbuf()</code> function to request <i>block buffered</i> input and output for an open stream</td>
</tr>
<tr>
<td><code>_IOLBF</code></td>
<td>an abbreviation for "input/output line buffered"; it is an integer which may be passed to the <code>setvbuf()</code> function to request <i>line buffered</i> input and output for an open stream</td>
</tr>
<tr>
<td><code>_IONBF</code></td>
<td>an abbreviation for "input/output not buffered"; it is an integer which may be passed to the <code>setvbuf()</code> function to request <i>unbuffered</i> input and output for an open stream</td>
</tr>
<tr>
<td><code>L_tmpnam</code></td>
<td>the size of a <code>char</code> array which is large enough to store a temporary filename generated by the <code>tmpnam()</code> function</td>
</tr>
<tr>
<td><code>NULL</code></td>
<td>a macro expanding to the <a href="Null_pointer" title="Null pointer" class="mw-redirect">null pointer</a> constant; that is, a constant representing a pointer value which is guaranteed <b>not</b> to be a valid address of an object in memory</td>
</tr>
<tr>
<td><code>SEEK_CUR</code></td>
<td>an integer which may be passed to the <code>fseek()</code> function to request positioning relative to the current file position</td>
</tr>
<tr>
<td><code>SEEK_END</code></td>
<td>an integer which may be passed to the <code>fseek()</code> function to request positioning relative to the end of the file</td>
</tr>
<tr>
<td><code>SEEK_SET</code></td>
<td>an integer which may be passed to the <code>fseek()</code> function to request positioning relative to the beginning of the file</td>
</tr>
<tr>
<td><code>TMP_MAX</code></td>
<td>the maximum number of unique filenames generable by the <code>tmpnam()</code> function; will be at least 25</td>
</tr>
</table>
<h2> <span class="mw-headline" id="Variables">Variables</span>
</h2>
<p>Variables defined in the <code>stdio.h</code> header include:</p>
<table class="wikitable">
<tr>
<th>Name</th>
<th>Notes</th>
</tr>
<tr>
<td><code><a href="http://en.m.wikipedia.org/wiki/Standard_streams#Standard_input_.28stdin.29" title="Standard streams">stdin</a></code></td>
<td>a pointer to a <code>FILE</code> which refers to the standard input stream, usually a keyboard.</td>
</tr>
<tr>
<td><code><a href="http://en.m.wikipedia.org/wiki/Standard_streams#Standard_output_.28stdout.29" title="Standard streams">stdout</a></code></td>
<td>a pointer to a <code>FILE</code> which refers to the standard output stream, usually a display terminal.</td>
</tr>
<tr>
<td><code><a href="http://en.m.wikipedia.org/wiki/Standard_streams#Standard_error_.28stderr.29" title="Standard streams">stderr</a></code></td>
<td>a pointer to a <code>FILE</code> which refers to the standard error stream, often a display terminal.</td>
</tr>
</table>
<h2> <span class="mw-headline" id="Member_types">Member types</span>
</h2>
<p>Data types defined in the <code>stdio.h</code> header include:</p>
<ul>
<li>
<code><a rel="nofollow" class="external text" href="http://c-p-p.net/c/keywords/file">FILE</a></code> - a structure containing the information about a file or text stream needed to perform input or output operations on it, including:
<ul>
<li>a <a href="http://en.m.wikipedia.org/wiki/File_descriptor" title="File descriptor">file descriptor</a>
</li>
<li>the current stream position</li>
<li>an end-of-file indicator</li>
<li>an error indicator</li>
<li>a pointer to the stream's buffer, if applicable</li>
</ul>
</li>
<li>
<code>fpos_t</code> - a non-array type capable of uniquely identifying the position of every byte in a file.</li>
<li>
<code>size_t</code> - an <a href="http://en.m.wikipedia.org/wiki/Unsigned_integer" title="Unsigned integer" class="mw-redirect">unsigned integer</a> type which is the type of the result of the <code><a href="Sizeof" title="Sizeof">sizeof</a></code> operator.</li>
</ul>
<h2> <span class="mw-headline" id="Example">Example</span>
</h2>
<p>The following C program opens a binary file called <i>myfile</i>, reads five bytes from it, and then closes the file.</p>
<div dir="ltr" class="mw-geshi mw-code mw-content-ltr">
<div class="c source-c">
<pre class="de1">
<span class="co2">#include &lt;stdio.h&gt;</span>
<span class="co2">#include &lt;stdlib.h&gt;</span>
 
<span class="kw4">int</span> main<span class="br0">(</span><span class="kw4">void</span><span class="br0">)</span>
<span class="br0">{</span>
    <span class="kw4">char</span> buffer<span class="br0">[</span><span class="nu0">5</span><span class="br0">]</span> <span class="sy0">=</span> <span class="br0">{</span><span class="nu0">0</span><span class="br0">}</span><span class="sy0">;</span>  <span class="coMULTI">/* initialized to zeroes */</span>
    <span class="kw4">int</span> i<span class="sy0">,</span> rc<span class="sy0">;</span>
    FILE <span class="sy0">*</span>fp <span class="sy0">=</span> <span class="kw3">fopen</span><span class="br0">(</span><span class="st0">"myfile"</span><span class="sy0">,</span> <span class="st0">"rb"</span><span class="br0">)</span><span class="sy0">;</span>
 
    <span class="kw1">if</span> <span class="br0">(</span>fp <span class="sy0">==</span> NULL<span class="br0">)</span> <span class="br0">{</span>
        <span class="kw3">perror</span><span class="br0">(</span><span class="st0">"Failed to open file <span class="es1">\"</span>myfile<span class="es1">\"</span>"</span><span class="br0">)</span><span class="sy0">;</span>
        <span class="kw1">return</span> EXIT_FAILURE<span class="sy0">;</span>
    <span class="br0">}</span>
 
    <span class="kw1">for</span> <span class="br0">(</span>i <span class="sy0">=</span> <span class="nu0">0</span><span class="sy0">;</span> <span class="br0">(</span>rc <span class="sy0">=</span> <span class="kw3">getc</span><span class="br0">(</span>fp<span class="br0">)</span><span class="br0">)</span> <span class="sy0">!=</span> EOF <span class="sy0">&amp;&amp;</span> i <span class="sy0">&lt;</span> <span class="nu0">5</span><span class="sy0">;</span> buffer<span class="br0">[</span>i<span class="sy0">++</span><span class="br0">]</span> <span class="sy0">=</span> rc<span class="br0">)</span> <span class="br0">{</span> <span class="br0">}</span>
 
    <span class="kw3">fclose</span><span class="br0">(</span>fp<span class="br0">)</span><span class="sy0">;</span>
 
    <span class="kw1">if</span> <span class="br0">(</span>i <span class="sy0">==</span> <span class="nu0">5</span><span class="br0">)</span> <span class="br0">{</span>
        <span class="kw3">puts</span><span class="br0">(</span><span class="st0">"The bytes read were..."</span><span class="br0">)</span><span class="sy0">;</span>
        <span class="kw3">printf</span><span class="br0">(</span><span class="st0">"%x %x %x %x %x<span class="es1">\n</span>"</span><span class="sy0">,</span> buffer<span class="br0">[</span><span class="nu0">0</span><span class="br0">]</span><span class="sy0">,</span> buffer<span class="br0">[</span><span class="nu0">1</span><span class="br0">]</span><span class="sy0">,</span> buffer<span class="br0">[</span><span class="nu0">2</span><span class="br0">]</span><span class="sy0">,</span> buffer<span class="br0">[</span><span class="nu0">3</span><span class="br0">]</span><span class="sy0">,</span> buffer<span class="br0">[</span><span class="nu0">4</span><span class="br0">]</span><span class="br0">)</span><span class="sy0">;</span>
    <span class="br0">}</span> 
    <span class="kw1">else</span>
        <span class="kw3">fputs</span><span class="br0">(</span><span class="st0">"An error occurred while reading the file.<span class="es1">\n</span>"</span><span class="sy0">,</span> stderr<span class="br0">)</span><span class="sy0">;</span>
 
    <span class="kw1">return</span> EXIT_SUCCESS<span class="sy0">;</span>
<span class="br0">}</span>
</pre>
</div>
</div>
<h2> <span class="mw-headline" id="See_also">See also</span>
</h2>
<ul>
<li><a href="http://en.m.wikipedia.org/wiki/Printf_format_string" title="Printf format string">printf format string</a></li>
</ul>
<h2> <span class="mw-headline" id="References">References</span>
</h2>
<div class="reflist" style="list-style-type: decimal;">
<ol class="references">
<li id="cite_note-0">
<span class="mw-cite-backlink"><b><a href="Stdio.h#cite_ref-0">^</a></b></span> <span class="reference-text"><span class="citation book"><a rel="nofollow" class="external text" href="http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf"><i>ISO/IEC 9899:1999 specification</i></a>. p. 274, § 7.19<span class="printonly">. <a rel="nofollow" class="external free" href="http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf">http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf</a></span>.</span><span class="Z3988" title="ctx_ver=Z39.88-2004&amp;rft_val_fmt=info%3Aofi%2Ffmt%3Akev%3Amtx%3Abook&amp;rft.genre=book&amp;rft.btitle=ISO%2FIEC+9899%3A1999+specification&amp;rft.pages=p.+274%2C+%C2%A7+7.19&amp;rft_id=http%3A%2F%2Fwww.open-std.org%2Fjtc1%2Fsc22%2Fwg14%2Fwww%2Fdocs%2Fn1124.pdf&amp;rfr_id=info:sid/en.wikipedia.org:C_file_input/output"><span style="display: none;"> </span></span></span>
</li>
<li id="cite_note-1">
<span class="mw-cite-backlink"><b><a href="Stdio.h#cite_ref-1">^</a></b></span> <span class="reference-text"><span class="citation book"><a href="Brian_Kernighan" title="Brian Kernighan">Kernighan, Brian</a>; <a href="http://en.m.wikipedia.org/wiki/Rob_Pike" title="Rob Pike">Rob Pike</a> (1984). <i><a href="http://en.m.wikipedia.org/wiki/The_UNIX_Programming_Environment" title="The UNIX Programming Environment" class="mw-redirect">The UNIX Programming Environment</a></i>. <a href="http://en.m.wikipedia.org/wiki/Englewood_Cliffs" title="Englewood Cliffs" class="mw-redirect">Englewood Cliffs</a>: <a href="Prentice_Hall" title="Prentice Hall">Prentice Hall</a>. p. 200.</span><span class="Z3988" title="ctx_ver=Z39.88-2004&amp;rft_val_fmt=info%3Aofi%2Ffmt%3Akev%3Amtx%3Abook&amp;rft.genre=book&amp;rft.btitle=%5B%5BThe+UNIX+Programming+Environment%5D%5D&amp;rft.aulast=Kernighan&amp;rft.aufirst=Brian&amp;rft.au=Kernighan%2C%26%2332%3BBrian&amp;rft.date=1984&amp;rft.pages=p.%26nbsp%3B200&amp;rft.place=%5B%5BEnglewood+Cliffs%5D%5D&amp;rft.pub=%5B%5BPrentice+Hall%5D%5D&amp;rfr_id=info:sid/en.wikipedia.org:C_file_input/output"><span style="display: none;"> </span></span></span>
</li>
</ol>
</div>
<h2> <span class="mw-headline" id="External_links">External links</span>
</h2>
<table class="metadata mbox-small plainlinks" style="border:1px solid #aaa; background-color:#f9f9f9;"><tr>
<td class="mbox-image"><img alt="" src="http://upload.wikimedia.org/wikipedia/commons/thumb/d/df/Wikibooks-logo-en-noslogan.svg/40px-Wikibooks-logo-en-noslogan.svg.png" width="40" height="40" srcset="//upload.wikimedia.org/wikipedia/commons/thumb/d/df/Wikibooks-logo-en-noslogan.svg/60px-Wikibooks-logo-en-noslogan.svg.png 1.5x, //upload.wikimedia.org/wikipedia/commons/thumb/d/df/Wikibooks-logo-en-noslogan.svg/80px-Wikibooks-logo-en-noslogan.svg.png 2x"></td>
<td class="mbox-text plainlist" style="">The Wikibook <i><a href="http://en.wikibooks.org/wiki/C_Programming" class="extiw" title="wikibooks:C Programming">C Programming</a></i> has a page on the topic of: <i><b><a href="http://en.wikibooks.org/wiki/C_Programming/C_file_input_and_output" class="extiw" title="wikibooks:C Programming/C file input and output">C Programming/C Reference</a></b></i>
</td>
</tr></table>

						<div class="section" id="mw-mf-language-section">
				<h2 id="section_language" class="section_heading">Read in another language</h2>
				<div id="content_language" class="content_block">
					<p>This article is available in 4 languages</p>
					<ul id="mw-mf-language-selection"><li><a href="http://cs.m.wikipedia.org/wiki/Vstup_a_v%C3%BDstup_v_jazyce_C" lang="cs" hreflang="cs">česky</a></li><li><a href="http://el.m.wikipedia.org/wiki/C_%CE%B5%CE%AF%CF%83%CE%BF%CE%B4%CE%BF%CF%82/%CE%AD%CE%BE%CE%BF%CE%B4%CE%BF%CF%82_%CE%B1%CF%81%CF%87%CE%B5%CE%AF%CF%89%CE%BD" lang="el" hreflang="el">Ελληνικά</a></li><li><a href="http://it.m.wikipedia.org/wiki/Stdio.h" lang="it" hreflang="it">italiano</a></li><li><a href="http://ru.m.wikipedia.org/wiki/%D0%A4%D0%B0%D0%B9%D0%BB%D0%BE%D0%B2%D1%8B%D0%B9_%D0%B2%D0%B2%D0%BE%D0%B4/%D0%B2%D1%8B%D0%B2%D0%BE%D0%B4_%D0%B2_%D1%8F%D0%B7%D1%8B%D0%BA%D0%B5_%D0%A1%D0%B8" lang="ru" hreflang="ru">русский</a></li></ul>
				</div>
			</div>			</div><!-- close #content_wrapper -->
			<div id="footer">
			<h2 class="section_heading" id="section_footer">
		<img src="http://bits.wikimedia.org/static-1.21wmf3/extensions/MobileFrontend/stylesheets/common/images/logo-copyright-en.png" class="license" alt="Wikipedia ®" />	</h2>
	<div class="content_block" id="content_footer">
		<ul class="settings">
			<li>
				<span class="left separator"><a id="mw-mf-display-toggle" href="http://en.wikipedia.org/w/index.php?title=Stdio.h&amp;mobileaction=toggle_view_desktop">Desktop</a></span><span class="right">Mobile</span>
			</li>
			<li class="notice">
				Article by <a href="http://en.m.wikipedia.org/w/index.php?title=Stdio.h&amp;action=history">contributors</a> like you<br>
				Content available under <a href="Wikipedia:Text_of_Creative_Commons_Attribution-ShareAlike_3.0_Unported_License?useformat=mobile">CC BY-SA 3.0</a>				<span>| <a href="http://wikimediafoundation.org/wiki/Terms_of_use?useformat=mobile">Terms of Use</a></span>
			</li>
		</ul>
		<ul class="links">
						<li>
			<a href='http://en.m.wikipedia.org/w/index.php?title=Special:MobileFeedback&amp;returnto=C+file+input%2Foutput&amp;feedbacksource=MobileFrontend'>
				Contact Wikipedia			</a>
			</li><li>
						<a href="http://wikimediafoundation.org/wiki/Privacy_policy" title="wikimedia:Privacy policy">Privacy</a></li><li>
			<a href="Wikipedia:About" title="Wikipedia:About">About</a></li><li>
			<a href="Wikipedia:General_disclaimer" title="Wikipedia:General disclaimer">Disclaimers</a></li>
		</ul>
	</div><!-- close footer.div / #content_footer -->
	</div><!-- close #footer -->
					</div><!-- close #mw-mf-page-center -->
		</div><!-- close #mw-mf-viewport -->
		
					</body>
	</html>