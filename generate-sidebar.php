<?php
date_default_timezone_set('Asia/Shanghai');

function get_allfiles($path, &$files)
{
    if (is_dir($path)) {
        $dp = dir($path);
        while ($file = $dp->read()) {
            if ($file != '.' && $file != '..') {
                get_allfiles($path . '/' . $file, $files);
            }
        }
        $dp->close();
    }
    if (is_file($path)) {
        $files[] =  $path;
    }
}
$ignoreFiles = array(
    ".gitignore",
    ".git",
    ".DS_Store",
    "_tag.md",
    "_sidebar.md",
    "_navbar.md",
    "_summary.md",
);

function dfsDir($pathName)
{
    global $ignoreFiles;
    //将结果保存在result变量中
    $result = array();
    $temp = array();
    //判断传入的变量是否是目录
    if (!is_dir($pathName) || !is_readable($pathName)) {
        return null;
    }
    //取出目录中的文件和子目录名,使用scandir函数
    $allFiles = scandir($pathName);
    //遍历他们
    foreach ($allFiles as $fileName) {
        //判断是否是.和..因为这两个东西神马也不是。。。
        if (in_array($fileName, array('.', '..'))) {
            continue;
        }
        if (in_array($fileName, $ignoreFiles)) {
            continue;
        }
        //路径加文件名
        $fullName = $pathName.'/'.$fileName;
        //如果是目录的话就继续遍历这个目录
        if (is_dir($fullName)) {
            //将这个目录中的文件信息存入到数组中
            $result[$fullName] = dfsDir($fullName);
        } else {
            //如果是文件就先存入临时变量
            $temp[] = $fullName;
        }
    }
    //取出文件
    if ($temp) {
        foreach ($temp as $f) {
            $result[] = $f;
        }
    }
    return $result;
}

function parseAllTagFiles($path)
{
}

function get_filenamesbydir($dir)
{
    $files =  array();
    get_allfiles($dir, $files);
    return $files;
}

function path_join($base, $path)
{
    return rtrim($base, '/') . '/' . ltrim($path, '/');
}

function parseTagFile($path, $tagFile = "_tag.md")
{
    $tags = array();
    $file = path_join($path, $tagFile);
    $fp = fopen($file, 'r');
    if (false == $fp) {
        return array();
    }
    while (! feof($fp)) {
        $line = trim(fgets($fp));
        $tags[] = substr($line, 2, strlen($line)-2);
    }
    fclose($fp);

    return $tags;
}

function parseSummaryFile($path, $tagFile = "_summary.md")
{
    $summaryContent = "";
    $file = path_join($path, $tagFile);
    $fp = fopen($file, 'r');
    if (false == $fp) {
        return "this is just a summary";
    }
    while (! feof($fp)) {
        $summaryContent .= trim(fgets($fp));
    }
    fclose($fp);

    return $summaryContent;
}


function generateNavBar($tagToArticlesMap, $titleToArticleMap, $tags, $path, $navbarFile="_navbar.md")
{
}

function generateSideBar($allArticles, $path, $navbarFile="_sidebar.md")
{
    $file = path_join($path, $navbarFile);
    $contents = "";

    foreach ($allArticles as $article) {
        $title = parseTitleFromFileName($article);
        $contents .= sprintf("* [%s](%s)\n", $title, $article);
    }

    file_put_contents($file, $contents);
}

function getConfigEmojis($file="_emoji.md")
{
    $emojis = array();
    $fp = fopen($file, 'r');
    if (false == $fp) {
        return;
    }
    while (! feof($fp)) {
        $line = trim(fgets($fp));
        if ($line == "") {
            break;
        }
        $emojis[] = $line;
    }
    fclose($fp);
    return $emojis;
}
function startsWith(string $string, string $subString) : bool
{
    return substr($string, 0, strlen($subString)) === $subString;
    // 或者 strpos($s2, $s1) === 0
}

function endsWith(string $string, String $subString) : bool
{
    return substr($string, strpos($string, $subString)) === $subString;
}

function getAllArticle($path)
{
    $allArticles = array();

    $ignoreFiles = array(
        "_navbar.md",
        "_tag.md",
    );
    $filenames = get_filenamesbydir($path);
    foreach ($filenames as $fileName) {
        if (endsWith($fileName, ".md")) {
            $findIgnore = false;
            foreach ($ignoreFiles as $ignoreFile) {
                if (endsWith($fileName, $ignoreFile)) {
                    $findIgnore = true;
                    break;
                }
            }
            if (!$findIgnore) {
                $allArticles[] = $fileName;
            }
        }
    }
    return $allArticles;
}

function parseTitleFromFileName($fileName)
{
    $pos1= strripos($fileName, "/");
    $pos2= strripos($fileName, ".md");
    if (!$pos1 || !$pos2) {
        return "";
    }
    $pos1 +=1;
    return substr($fileName, $pos1, $pos2-$pos1);
}

function parseLastModifiedFromFile($fileName)
{
    return date("F d Y H:i:s.",filemtime($fileName));
}


function generateDocToc($file)
{
    $shell = "doctoc $file";
    exec($shell);
}

class Article{
    public $title;
    public $dir;
    public $file;
    public $tags;
}

function generateSideBarAction()
{
    $articleMap = array();
    $paths = dfsDir("node");
    foreach ($paths as $path => $files) {
        
        $articleFile = "";
        $articleTitle = "";
        $articleTags = array();
        $articleTags = parseTagFile($path);
        $articleSummary = parseSummaryFile($path);

        
        foreach ($files as $file) {
            $articleTitle = parseTitleFromFileName($file);
            if ($articleTitle) {
                $articleFile = $file;
                $lastModified = parseLastModifiedFromFile($file);
                break;
            }
        }

        $articleMap[$articleTitle] = array(
            'title' => $articleTitle,
            'file' => $articleFile,
            'dir' => $path,
            'tags' => $articleTags,
            'summary' => $articleSummary,
            'lastModified' => $lastModified,
        );

    }
    // var_dump($articleMap);


    // 在文章目录下面生成全量文章的sidebar
    $sidebarContents = "";
    array_multisort(array_column($articleMap,'dir'),SORT_DESC,$articleMap);
    foreach($articleMap as $title => $article) {
        $sidebarContents .= sprintf("* [%s](%s)\n\n", $title, $article['file']);
    }
    foreach ($articleMap as $title => $article) {
        // echo "$contents\n-----------------\n";
        $sidebarFile = path_join($article['dir'], "/_sidebar.md");
        // file_put_contents($sidebarFile, $sidebarContents);
    }
    file_put_contents("node/_sidebar.md", $sidebarContents);


    // 在根目录下生成一个大的归类sidebar
    $rootSidebarContents = "* [⚡  快速浏览](/node/099/如何快速用docsify写一篇文章及各种工具插件.md)\n";
    $rootSidebarContents .= "* [💻  文章存档](/arch.md)\n";
    $rootSidebarContents .= "* [📎  文章分类](/tags.md)\n";
    $rootSidebarContents .= "* [👀  精品外站](/blogs.md)\n";
    file_put_contents("_sidebar.md", $rootSidebarContents);
    


    $tagToArticlesMap = array();
    foreach($articleMap as $title => $article) {
        foreach($article['tags'] as $tag) {
            $tagToArticlesMap[$tag][] = $article;
        }
    }
    // var_dump($tagToArticlesMap);


    // 生成文章归档页面
    $archContents = "# 文章存档\n\n";
    foreach($articleMap as $title => $article) {
        $archContents .= generateArticleArchInfo($article);
    }
    file_put_contents("./arch.md", $archContents);


    // 生成tags页面
    $allTagsContents = "";
    foreach($tagToArticlesMap as $tag => $articles) {
        $allTagsContents .= sprintf("* ## %s\n\n", $tag);
        foreach($articles as $article) {
            $allTagsContents .= sprintf("   * [%s](%s)\n\n", $article['title'], $article['file']);
        }
    }
    file_put_contents("./tags.md", $allTagsContents);


    // 在每篇文章的目录下生成自己的navbar
    foreach ($articleMap as $title => $article) {

        $contents = "";
        $emojis = getConfigEmojis();
        // var_dump($article);

        // var_dump($article['tag']);
        foreach($article['tags'] as $tag) {
            $articles = $tagToArticlesMap[$tag];

            $emoji = $emojis[(int)hash('md4',$tag)%count($emojis)];
            $contents .= sprintf("* [%s %s](/tags.md)\n", $tag, $emoji);
            foreach($articles as $article) {
                $contents .= sprintf("   * [%s](%s)\n\n", $article['title'], $article['file']);
            }
        }
        // echo "$contents\n-----------------\n";
        $navbarFile = path_join($article['dir'], "/_navbar.md");
        file_put_contents($navbarFile, $contents);
    }


    
    return;
}

function generateArticleArchInfo($article) {

    $tag_str = "";
    foreach($article['tags'] as $tag) {
        $tag_str .= sprintf("[%s]() ", $tag);
    }
    
    $content = "";
    $content .= sprintf("## %s\n\n", $article['title']);
    $content .= sprintf("> [!ATTENTION|style:callout|label:摘要]\n> %s [阅读全文](%s)\n\n", $article['summary'], $article['file']);

    $content .= sprintf("📌  %s\n\n", $tag_str);

    $content .= sprintf("🗓  %s\n\n", $article['lastModified']);
    $content .= "---\n\n";
    return $content;
}

main();
function main()
{
    generateSideBarAction();
    // generateNavBarAction();
    // generateTimeLineAction();
    // generateTopArticlesAction();
}