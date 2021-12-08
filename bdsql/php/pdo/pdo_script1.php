<?php
$dbname = "bd_vol_pil1";
// mysql, à ne plus utiliser dans les nouveaux projets
// $C = mysql_connect('localhost', 'root', '');
// mysql_select_db($dbname);
// $result = mysql_query('SELECT * FROM tablel');
// $row = mysql_fetch_assoc($result);
// echo htmlentities ($row['coll']), '<br />';

// mysqli, uniquement pour MySQL
$mysqli = new mysqli('localhost', 'root', '', $dbname);
$result = $mysqli->query('SELECT * FROM pilote');
$row = $result->fetch_assoc();
echo htmlentities ($row['nompil']), '<br />';

// PDO, pour MySQL mais aussi pour PosgresSQL, Sqlite, Oracle, ...
// $pdo = new PDO(`mysql: host=localhost; dbname=$dbname`, 'root', '');
// $statement = $pdo->query('SELECT * FROM pilote');
// $row = $statement->fetch(PDO::FETCH_ASSOC);
// echo htmlentities ($row['nompil']), '<br />';
// ?>
