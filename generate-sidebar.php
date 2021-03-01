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

main();
function main()
{
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
      generateNavBar($allTags, $path);
  }
}
