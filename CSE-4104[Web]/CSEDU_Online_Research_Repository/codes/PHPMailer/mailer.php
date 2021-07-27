<?php
	class mailer
	{
		var $email = 'mehreenrahmanrebab@gmail.com';
		var $username = 'H1';
		var $password = 'MehreenRizvee';
		
		
		use PHPMailer\PHPMailer\PHPMailer;
			use PHPMailer\PHPMailer\Exception;
			use PHPMailer\PHPMailer\SMTP;
			require'D:/xampp/htdocs/PHPMailer/src/PHPMailer.php';
			require'D:/xampp/htdocs/PHPMailer/src/Exception.php';
			require'D:/xampp/htdocs/PHPMailer/src/SMTP.php';
				
		$mail = new PHPMailer(true);
		function __construct($email,$username,$password){
			$this->email = $email;
			$this->username = $username;
			$this->password = $password;
		}
		
		function sendMail()
		{
			                              // Passing `true` enables exceptions
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
		//$mail->Username='aadipto@gmail.com';
		$mail->Username=$this->username;
		//$mail->Password='bangladesh';
		$mail->Password=$this->password;
		$mail->setFrom($this->username);
		$mail->Subject='Log in successful!!';
		$mail->Body="Username : " .$mail->Username. " and Password : " .$mail->Password;
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