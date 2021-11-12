<?php include 'html5_page.php'; begin_html("Exercice 1.1"); ?>
<h2>Script 1.1 : Écriture dans la sortie standard</h2>
Exemple 1 :<br/>
<?php
echo "Salut le monde <br/> <br/>";
?>

Exemple 2 :<br/>
<?php
$salut="Salut le monde";
echo "<b>$salut</b><br/><br/>";
echo '<b>$salut</b><br/><br/>';
?>

Exemple 3 : <br/>
<?php
$salut="Salut \"le monde\" !";
print "<span style='color:#0099FF;'>$salut</span><br/>";
?>
<br/>
<?php end_html(); ?>