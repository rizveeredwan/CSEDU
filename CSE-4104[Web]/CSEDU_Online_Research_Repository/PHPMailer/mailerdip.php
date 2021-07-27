<?php
    include("typeDecider.php");
	include("database.php");

	use PHPMailer\PHPMailer\PHPMailer;
	use PHPMailer\PHPMailer\Exception;
	use PHPMailer\PHPMailer\SMTP;

	class mailer{
		
		public static function sendMail($email,$username,$password){
			
			require'D:/xampp/htdocs/PHPMailer/src/PHPMailer.php';
			require'D:/xampp/htdocs/PHPMailer/src/Exception.php';
			require'D:/xampp/htdocs/PHPMailer/src/SMTP.php';
			$mail = new PHPMailer(true); // Passing `true` enables exceptions
			try 
			{
				//Server settings
				$mail->SMTPDebug = 2;  // Enable verbose debug output
				$mail->isSMTP();    
				$mail->SMTPAuth = true;
				$mail->SMTPSecure = 'tls';
				$mail->Host = 'smtp.gmail.com';
				$mail->Port='587';
				$mail->isHTML();

				//server sender mail
				$mail->Username='aadipto@gmail.com';
				$mail->Password='bangladesh';
				$mail->setFrom('aadipto@gmail.com');
				$mail->Subject='Welcome to AyojonSomponnam!';
				$mail->Body="Please Find your Log In Credentials.<br>Username : " .$username. "<BR>Password : " .$password."<BR>";
				$mail->addAddress($email);
				$mail->Send();
				echo "Mail has been sent successfully.";
			}
			catch(Exception $e)
			{
				echo "<br>ERROR<br>Mail not sent.<br>";
				echo "ERROR :".$mail->ErrorInfo;
			}
		}
		
		public function bookMail($customerID, $serviceID, $date){
			
			//Getting Database Access
			$mydb = database::getDatabase();
			$conn = $mydb->getConnection();
			$date = date($date);
			
			$sql = "SELECT customerName, customerEmail FROM customer where customerID = '$customerID'";

			$result = $conn->query($sql);
			if($result->num_rows==1){
				$row=$result->fetch_assoc();
				$customerName= $row['customerName'];
				$customerEmail=$row['customerEmail'];
			}
			else echo "UNEXPECTED QUERY RESULT";
			
			
			$table=type::decider($serviceID);
			
			$attributeName= $table."Name";
			$attributeEmail= $table."Email";
			$attributeID= $table."ID";
			
			$sql = "SELECT $attributeName,$attributeEmail FROM $table where $attributeID='$serviceID'";
			
			$result = $conn->query($sql);
			if($result->num_rows==1){
				$row=$result->fetch_assoc();
				$serviceName=$row[$attributeName];
				$serviceEmail=$row[$attributeEmail];
			}
			else echo "UNEXPECTED QUERY RESULT 2";
			
			echo $customerName." books ".$serviceName." on date: ".$date." ".$customerEmail." ".$serviceEmail;
			
			require'D:/xampp/htdocs/PHPMailer/src/PHPMailer.php';
			require'D:/xampp/htdocs/PHPMailer/src/Exception.php';
			require'D:/xampp/htdocs/PHPMailer/src/SMTP.php';
			$mail = new PHPMailer(true); // Passing `true` enables exceptions
			try 
			{
				//Server settings
				$mail->SMTPDebug = 2;  // Enable verbose debug output
				$mail->isSMTP();    
				$mail->SMTPAuth = true;
				$mail->SMTPSecure = 'tls';
				$mail->Host = 'smtp.gmail.com';
				$mail->Port='587';
				$mail->isHTML();

				//server sender mail
				$mail->Username='aadipto@gmail.com';
				$mail->Password='bangladesh';
				$mail->setFrom('aadipto@gmail.com');
				
				//mail to client
				$mail->Subject='New Booking!';
				$mail->Body="Dear ".$customerName.",<BR>You have booked the service of ".$serviceName." on the following day: ".$date.".<br>You can cancel this booking from your account in AyojonSomponnam.<br><br><br>Regards,<br>AyojonSomponnam Team.<br>";
				$mail->addAddress($customerEmail);
				$mail->Send();
				echo "Client mail has been sent successfully.";
				
				//mail to service
				$mail->Subject='New Booking!';
				$mail->Body="Dear ".$serviceName.",<BR>Client ".$customerName." has booked your service on the following day: ".$date.".<br>You can cancel this booking from your account in AyojonSomponnam.<br><br><br>Regards,<br>AyojonSomponnam Team.<br>";
				$mail->addAddress($serviceEmail);
				$mail->Send();
				echo "Service mail has been sent successfully.";

			}
			catch(Exception $e)
			{
				echo "<br>ERROR<br>Mail not sent.<br>";
				echo "ERROR :".$mail->ErrorInfo;
			}
		}
	}
?>

