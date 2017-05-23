
<html>
	<head><title>UNSA</title>
	</head>
	<body>
		<h3>BIENVENIDO A LA PLATAFORMA VIRTUAL DE LA UNSA</h3>
		<table>
			<tr>
			<p2>AULA DE DOCENTES</p2>
			<form action ="docente.php" method="post">
			   <p> Su nombre: <input type="text" name="nombre" /></p>
			   <p> Su DNI: <input type="text" name="DNI" /></p>
			   <p><input type="submit" /></p>
			</form>
			<tr>
				<p2>AULA DE ALUMNOS</p2>
				<form action ="alumno.php" method="post">
				   <p> Su nombre: <input type="text" name="nombre" /></p>
				   <p> Su CUI: <input type="text" name="cui" /></p>
				   <p> Su escuela es: <input type="text" name="escuela" /></p>
				   <p><input type="submit" /></p>
				</form>
			</tr>
		</table>



	</body>
</html>
