<?php
    $host='localhost'; $db='bd_vol_pil1'; $user='root'; $pass='';
    try{
        $pdo = new PDO("mysql:host={$host};dbname={$db}", $user, $pass);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    }
        catch(PDOException $e){
        echo $e->getMessage();
    }
?>