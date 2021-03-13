<?php

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

        
        foreach ($files as $file) {
            $articleTitle = parseTitleFromFileName($file);
            if ($articleTitle) {
                $articleFile = $file;
                break;
            }
        }


        $articleMap[$articleTitle] = array(
            'title' => $articleTitle,
            'file' => $articleFile,
            'dir' => $path,
            'tags' => $articleTags,
        );
        

    }
    var_dump($articleMap);


    $sideBarContents = "";
    foreach($articleMap as $title => $article) {
        $sideBarContents .= sprintf("* [%s](%s)\n\n", $title, $article['file']);
    }
    file_put_contents("./_sidebar.md", $sideBarContents);


    $tagToArticlesMap = array();
    foreach($articleMap as $title => $article) {
        foreach($article['tags'] as $tag) {
            $tagToArticlesMap[$tag][] = $article;
        }
    }
    var_dump($tagToArticlesMap);


    $allTagsContents = "";
    foreach($tagToArticlesMap as $tag => $articles) {
        $allTagsContents .= sprintf("* ## [%s](/tags.md)\n\n", $tag);
        foreach($articles as $article) {
            $allTagsContents .= sprintf("   * [%s](%s)\n\n", $article['title'], $article['file']);
        }
    }
    file_put_contents("./tags.md", $allTagsContents);


    $sideBarContents = "";
    foreach($articleMap as $title => $article) {
        $sideBarContents .= sprintf("* [%s](%s)\n\n", $title, $article['file']);
    }
    file_put_contents("./_sidebar.md", $sideBarContents);


    foreach ($articleMap as $title => $article) {

        $contents = "";
        $emojis = getConfigEmojis();
        var_dump($article);

        var_dump($article['tag']);
        foreach($article['tags'] as $tag) {
            $articles = $tagToArticlesMap[$tag];

            $emoji = $emojis[rand(0, count($emojis))];
            $contents .= sprintf("* [%s %s](/tags.md)\n", $tag, $emoji);
            foreach($articles as $article) {
                $contents .= sprintf("   * [%s](%s)\n\n", $article['title'], $article['file']);
            }
        }
        echo "$contents\n-----------------\n";
        $navbarFile = path_join($article['dir'], "_navbar.md");
        file_put_contents($navbarFile, $contents);
    }

    return;
}

main();
function main()
{
    generateSideBarAction();
    // generateNavBarAction();
    // generateTimeLineAction();
    // generateTopArticlesAction();
}

// main_();
function main_()
{
    $allArticles = getAllArticle('node');
    sort($allArticles);
    var_dump($allArticles);
    generateSideBar($allArticles, "./");
    
    return;
}
