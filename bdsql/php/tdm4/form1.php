<?php include 'html5_page.php'; begin_html('Formulaire Saisie'); ?>
<br/><br/>
<h3>Formulaire de saisie</h3>
<form method="post" action="form2.php">
<p>Prenom : <input type="text" name="prenom"></p>
<p>Nom : <input type="text" name="nom"></p>
<p><input type="submit" value="Valider"></p>
</form>
<?php end_html(); ?>