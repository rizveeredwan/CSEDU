<?php
		include("index.php");
		$email = 'mehreenrahmanrebab@gmail.com';
		$username = 'H1';
		$password = 'lala';
		$object = new mailer($email, $username, $password);
		$object->sendMail();
	
?>