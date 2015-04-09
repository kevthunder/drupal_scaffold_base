<h1><?php echo t("Do you really want to delete the model_name_human : @title", array('@title' => $model_name->number)); ?></h1>
<form method="post">
<input type="submit" name="confirm" value="Yes"> <?php echo l('No','model_name_plural'); ?>
</form>