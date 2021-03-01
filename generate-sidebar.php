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

function parseSidebar($path, $tagFile = "_tag.md")
{
    $file = path_join($path, $tagFile);
    $fp = fopen($file, 'r');
    if (false == $fp) {
        return;
    }
    while (! feof($fp)) {
        $line = trim(fgets($fp));
        $tags[] = substr($line, 2, strlen($line)-2);
    }
    fclose($fp);

    return $tags;
}
// test();
function test()
{
    $filenames = get_filenamesbydir('node');
    foreach ($filenames as $value) {
        echo $value . "\n";
    }
}

function generateNavBar($tags, $path, $navbarFile="_navbar.md")
{
    $file = path_join($path, $navbarFile);
    $contents = "";

    foreach ($tags as $tag) {
        $contents .= sprintf("* [%s]()\n", $tag);
    }
    file_put_contents($file, $contents);
}

function generateSideBar($allArticles, $path, $navbarFile="_sidebar.md")
{
    $file = path_join($path, $navbarFile);
    $contents = "";

    foreach($allArticles as $article)  {
        $title = parseTitleFromFileName($article);
        $contents .= sprintf("* [%s](%s)\n", $title, $article);
    }

    file_put_contents($file, $contents);
}

function getAllEmoji($file="_emoji.md")
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
function startsWith(string $string, string $subString) : bool{
    return substr($string, 0, strlen($subString)) === $subString;
    // 或者 strpos($s2, $s1) === 0
}

function endsWith(string $string, String $subString) : bool{
    return substr($string, strpos($string, $subString)) === $subString;
}

function getAllArticle($path) {
    $allArticles = array();

    $ignoreFiles = array(
        "_navbar.md",
        "_tag.md",
    );
    $filenames = get_filenamesbydir($path);
    foreach ($filenames as $fileName) {
        if (endsWith($fileName, ".md")) {
            $findIgnore = false;
            foreach($ignoreFiles as $ignoreFile) {
                if(endsWith($fileName,$ignoreFile)) {
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

function parseTitleFromFileName($fileName) {
    $pos1= strripos($fileName, "/");
    $pos2= strripos($fileName, ".md");
    $pos1 +=1;
    return substr($fileName, $pos1, $pos2-$pos1);
}

main();
function main()
{
    $allArticles = getAllArticle('node');
    sort($allArticles);
    var_dump($allArticles);
    generateSideBar($allArticles, "./");
    
    return;
    $emojis = getAllEmoji();

    $paths = array(
      "node/001",
      "node/002",
    );
    $allTags = array();
    foreach ($paths as $path) {
        $tags = parseSidebar($path);
        $allTags = array_merge($allTags, $tags);
    }

    for ($i=0;$i<count($allTags);$i+=1) {
        $emoji = $emojis[rand(0, count($emojis))];
        $allTags[$i] = sprintf("%s %s", $allTags[$i], $emoji);
    }



    foreach ($paths as $path) {
    //   generateNavBar($allTags, $path);
    generateSideBar(1,2,"");
  }
}
