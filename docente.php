<html>

  <h>Bienvenido </h> <?php echo htmlspecialchars($_POST['nombre']); ?><h>.<h>
  <h>Su DNI es </h> <?php echo (int)$_POST['DNI']; ?> <h>años<h>.

  <p>
    <?php
     $arreglo=array();
     $arreglo["a"]="hola";
     echo $arreglo["a"];
    ?>
  </p>

</html>
