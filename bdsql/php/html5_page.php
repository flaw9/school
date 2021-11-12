<?php

function begin_html($title) {
  print('<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>'.$title.'</title>
</head>
<body>');
}

function end_html(){
  print('</body>
</html>');
}

?>