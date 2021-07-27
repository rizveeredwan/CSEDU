<?php
use PHPMailer\PHPMailer\PHPMailer;
			use PHPMailer\PHPMailer\Exception;
			use PHPMailer\PHPMailer\SMTP;

	class mailer
	{
		var $email;
		var $username;
		var $password;
		function __construct($email,$username,$password)
		{
			$this->email = $email;
			echo $this->email;
			$this->username = $username;
			$this->password = $password;
		}
		
		function sendMail()
		{
			
		require'D:/xampp/htdocs/PHPMailer/src/PHPMailer.php';
		require'D:/xampp/htdocs/PHPMailer/src/Exception.php';
		require'D:/xampp/htdocs/PHPMailer/src/SMTP.php';
		$mail = new PHPMailer(true); // Passing `true` enables exceptions
		try 
		{
		//Server settings
		$mail->SMTPDebug = 2;                                 // Enable verbose debug output
		$mail->isSMTP();    
		$mail->SMTPAuth = true;
		$mail->SMTPSecure = 'tls';
		$mail->Host = 'smtp.gmail.com';
		$mail->Port='587';
		$mail->isHTML();
		$mail->Username='aadipto@gmail.com';
		//$mail->Username=$this->username;
		//echo $mail->Username;
		$mail->Password='bangladesh';
		//$mail->Password=$this->password;
		echo $mail->Password;
		$mail->setFrom('aadipto@gmail.com');
		$mail->Subject='Log in successful!!';
		$mail->Body="Username : " .$this->username. " and Password : " .$this->password;
		$mail->addAddress($this->email);
		$mail->Send();

		echo "SENT!!";
	}
	catch(Exception $e)
	{
		echo "NOT SENT!!";
		echo "ERROR :".$mail->ErrorInfo;
	}
	}
	}
	
?>