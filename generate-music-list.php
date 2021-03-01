<?php
  $data = json_decode($str, true);

foreach($data as $tmp) {
    echo '<iframe frameborder="no" border="0" marginwidth="0" marginheight="0" width=502 height=86 src="//music.163.com/outchain/player?type=2&id='.$tmp['id'].'&auto=1&height=66"></iframe>';
    echo "\n";
}

echo count($data);