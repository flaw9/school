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
$result = $mysqli->query('SELECT * FROM avion');
$row = $result->fetch_assoc();
echo htmlentities ($row['nomav']), '<br/>';

// while ($row = $result->fetch_assoc())  {
//     echo htmlentities ($row['nompil']), '<br />';
// }

// PDO, pour MySQL mais aussi pour PosgresSQL, Sqlite, Oracle, ...
$user = 'root'; $pass = '';
$pdo = new PDO("mysql: host=localhost; dbname={$dbname}", $user, $pass);
$statement = $pdo->query('SELECT * FROM vol');
$row = $statement->fetch(PDO::FETCH_ASSOC);
echo htmlentities ($row['villedep']), '<br />';

// while ($row = $statement->fetch(PDO::FETCH_ASSOC))  {
//     echo htmlentities ($row['numpil']), '<br />';
// }
?>
