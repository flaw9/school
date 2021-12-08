<?php
class Vol { //définition de la classe Vol
 public $numvol; //numvol est une variable. Corrigez les erreurs
 public $numpil;
 public $numav;
 public $villedep;
 public $villearr;
 public $heuredep;
 public $heurearr;
} // autres erreurs à corriger ?
$host='localhost'; $db='bd_vol_pil1'; $user='root'; $pass='';
try{
 $pdo = new PDO("mysql:host={$host};dbname={$db}", $user, $pass);
 $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
 $sql = 'select * from vol';
 $st = $pdo->query($sql);
 $resultArray = $st->fetchALL(PDO::FETCH_CLASS,'Vol');
 //var_dump($resultArray);
 foreach($resultArray as $vol){
 echo $vol->villedep,' ',$vol->villearr,' ',$vol->heuredep,'<br/>';
 }
 $sql = 'select * from vol WHERE villedep = :ville';
 $st = $pdo->prepare($sql);
 $result_bool = $st->execute(array(':ville' =>'Nice'));
 while ($row = $st->fetch(PDO::FETCH_NUM, PDO::FETCH_ORI_NEXT)) {
 $data = 'Destination '.$row[4].'à'.$row[5].'<br/>';
 echo $data;
 }
 $st = null;
 $pdo = null;
}
catch(PDOException $e){
 echo $e->getMessage();
}
?>
