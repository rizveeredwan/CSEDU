<?php
    /* The Sole purpose of this PHP file is to send mail */
    $email = $_POST["email"];
    $subject = $_POST["subject"];
    $message = $_POST["message"];

    
    /*Header Files */
    use PHPMailer\PHPMailer\PHPMailer;
    use PHPMailer\PHPMailer\Exception;
    use PHPMailer\PHPMailer\SMTP;

    require 'src/PHPMailer.php';
	require 'src/Exception.php';
	require 'src/SMTP.php';
    
    class Mailer{

        protected $email;
        protected $subject;
        protected $message;

        function send_mail($main_object,$em,$su,$msg){
            $main_object->email = $em;
            $main_object->subject = $su;
            $main_object->message = $msg;


            $mail = new PHPMailer(true);

            try{
               //Server settings
				$mail->SMTPDebug = 2;  // Enable verbose debug output
				$mail->isSMTP();    
				$mail->SMTPAuth = true;
				$mail->SMTPSecure = 'tls';
				$mail->Host = 'smtp.gmail.com';
				$mail->Port='587';
                $mail->isHTML();
                
                //server sender mail
				$mail->Username='CseduResearchRepository@gmail.com';
				$mail->Password='mehreenrizvee';
				$mail->setFrom('CseduResearchRepository@gmail.com');
				$mail->Subject=$main_object->subject;
				$mail->Body=$main_object->message;
				$mail->addAddress($main_object->email);
				$mail->Send();
				return "Mail has been sent successfully.";
            }
            catch(Exception $e){
                return "Mail can't be sent";
                //echo "Error: ".$mail->ErrorInfo;
                //echo "Please try again";
            }

        }
    }

    //split by delemeter
    function split_from_delemeter($string,$delim){
        $temp_array = explode($delim,$string);
        return $temp_array;
    }

    //Flow
    $main_object = new Mailer();
    $temp_array = split_from_delemeter($email,'^');
    $string = ' ';
    for($i=0;$i<sizeof($temp_array);$i=$i+1) {
        $email = $temp_array[$i];
        $string .= $main_object->send_mail($main_object,$email,$subject,$message);
    }
    echo $string;


?>