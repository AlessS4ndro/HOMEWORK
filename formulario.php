<html>
  <head><title>UNSA</title>
  </head>
  <body>
    <p>
    Hola <?php echo htmlspecialchars($_POST['nombre']); ?>.
    Usted tiene <?php echo (int)$_POST['edad']; ?> años.
    Su carrera es <?php echo htmlspecialchars($_POST['escuela']); ?> de la unsa.
    Dentro de 10 años tendra <?php echo (int )$_POST['edad']+10; ?> años.
    <h5>AULA DE DOCENTES</h5>
<tr>
  <form action ="docente.php" method="post">
    <p> Su nombre: <input type="text" name="nombre" /></p>
    <p> Su edad: <input type="text" name="edad" /></p>
    <p> Su escuela es: <input type="text" name="escuela" /></p>
    <p><input type="submit" /></p>
  </form>
</tr>

<h5>AULA DE ALUMNOS</h5>
<th>
  <form action ="alumno.php" method="post">
    <p> Su nombre: <input type="text" name="nombre" /></p>
    <p> Su edad: <input type="text" name="edad" /></p>
    <p> Su escuela es: <input type="text" name="escuela" /></p>
    <p><input type="submit" /></p>
  </form>
</th>
  </body>
</html>
