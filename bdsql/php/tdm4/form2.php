<?php include 'html5_page.php'; begin_html('Formulaire Données'); ?>
<!-- page PHP affichant les donnees saisies dans le formulaire
precedent -->
<h3>Affichage des variables provenant du formulaire</h3>
<p>Votre prenom est : <?php echo $_POST["prenom"] ?> </p>
<p>Votre nom est : <?php echo $_POST["nom"] ?></p>
<?php end_html(); ?>