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
    if(!$pos1 || !$pos2) {
        return "";
    }
    $pos1 +=1;
    return substr($fileName, $pos1, $pos2-$pos1);
}


function generateDocToc($file) {
    $shell = "doctoc $file";
    exec($shell);
}

function generateSideBarAction() {

    $dfs = function($files, $depth) use (&$dfs){
        $contents = "";

        if ($depth >= 1) {
            // return;
        }
        $prefix = "";
        for($i=0;$i<$depth;$i+=1) {
            $prefix .= "  ";
        }
        $prefix .= "- ";

        foreach($files as $key => $value) {
            $message = "";
            if(!is_array($value)) {
                // 文件
                $title = parseTitleFromFileName($value);
                if ($title) {
                    $message = sprintf("* [%s](%s)\n\n", $title, $value);
                    // echo "---$message\n";
                }
            } else {
                // 路径
                $message = $dfs($value, $depth + 1);
            }
            $contents = $contents . $message;
            // echo "$message\n";
        }

        return $contents;
    };

    $files = dfsDir("node");
    $depth = 0;
    $contents = $dfs($files, $depth);
    file_put_contents("./_sidebar.md", $contents);
    return;
}

function generateNavBarAction() {
    $tagToArticlesMap = array();
    $articleToTagsMap = array();
    $titleToArticleMap = array();

    $dfs = function($files, $depth) use (&$dfs, &$tagToArticlesMap, &$articleToTagsMap, &$titleToArticleMap){

        if ($depth >= 1) {
            // return;
        }

        foreach($files as $key => $value) {
            if(!is_array($value)) {
                $title = parseTitleFromFileName($value);
                if ($title) {
                    $titleToArticleMap[$title] = $value;
                }
            } else {
                $tags = parseTagFile($key);
                $articleToTagsMap[$key] = $tags;
                $dfs($value, $depth+1);
            }
        }
    };


    $files = dfsDir("node");
    $depth = 0;
    $dfs($files, $depth);

    // var_dump($articleToTagsMap);
    // var_dump($titleToArticleMap);


    foreach($articleToTagsMap as $article => $tags) {
        foreach($tags as $tag) {
            $tagToArticlesMap[$tag][] = $article;
        }
    }

    foreach($articleToTagsMap as $path => $tags) {
        $navbarFile="_navbar.md";
        $file = path_join($path, $navbarFile);
        $contents = "";
        $emojis = getConfigEmojis();
        foreach ($tags as $tag) {
            $emoji = $emojis[rand(0, count($emojis))];
            $contents .= sprintf("* [%s %s]()\n", $tag, $emoji);
            $paths = $tagToArticlesMap[$tag];
            foreach($paths as $path) {
                $contents .= sprintf("  * [%s]()\n", $path);
            }
        }
        file_put_contents($file, $contents);
    }

    return;
}

function generateTimeLineAction() {

}

function generateTopArticlesAction() {

}

main();
function main() {
    generateSideBarAction();
    generateNavBarAction();
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

    $paths = array(
      "node/001",
      "node/002",
    );
    $allTags = array();
    foreach ($paths as $path) {
        $tags = parseTagFile($path);
        $allTags = array_merge($allTags, $tags);
    }

    for ($i=0;$i<count($allTags);$i+=1) {
        $allTags[$i] = sprintf("%s %s", $allTags[$i], $emoji);
    }



    foreach ($paths as $path) {
        //   generateNavBar($allTags, $path);
        generateSideBar(1, 2, "");
    }
}
