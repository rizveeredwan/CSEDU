<?php
	session_start();
	
	$username = $_POST["username"];
	$password = $_POST["password"];
	
	/*************Rizvee Checking**************/
	//$_SESSION["username"] = $username;
	//echo "successful";
	/******************************************/
	
	/**************Real Data************************************************************/
	
    // Create connection
    $conn = mysqli_connect("localhost", "root","", "ayojonsomponnamfinal1");
	
    // Check connection - error checking 
    if (!$conn) {
		die("Connection failed: " . mysqli_connect_error());
    }

	if($username[0] == 'C'){
		$sql = "SELECT * FROM `customer` where `customerID` = '$username'";
		$result = $conn->query($sql);
		while($row = $result->fetch_assoc()){
			if($password==mysqli_real_escape_string($conn,$row['customerPassword'])){	
				$_SESSION["username"] = $username;			
				echo "successful"; 
			}
			else echo "wrong password";
		}
	}
	else echo "Nah";
	if($username[0] == 'H'){
		$sql = "SELECT * FROM `hall` where `hallID` = '$username'";
		$result = $conn->query($sql);
		while($row = $result->fetch_assoc()){
			if($password==mysqli_real_escape_string($conn,$row['hallPassword'])){	
				$_SESSION["username"] = $username;			
				echo "successful"; 
			}
			else echo "Wrong Password";
		}
	}
	if($username[0] == 'D'){
		$sql = "SELECT * FROM `decorator` where `decoratorID` = '$username'";
		$result = $conn->query($sql);
		while($row = $result->fetch_assoc()){
			if($password==mysqli_real_escape_string($conn,$row['decoratorPassword'])){
				$_SESSION["username"] = $username;				
				echo "successful"; 
			}
			else echo "Wrong Password";
		}
	}
	if($username[0] == 'T'){
		$sql = "SELECT * FROM `catering` where `cateringID` = '$username'";
		$result = $conn->query($sql);
		while($row = $result->fetch_assoc()){
			if($password==mysqli_real_escape_string($conn,$row['cateringPassword'])){
				$_SESSION["username"] = $username;				
				echo "successful"; 
			}
			else echo "Wrong Password";
		}
	}
	if($username[0] == 'M'){
		$sql = "SELECT * FROM `marriageofficiant` where `marriageofficiantID` = '$username'";
		$result = $conn->query($sql);
		while($row = $result->fetch_assoc()){
			if($password==mysqli_real_escape_string($conn,$row['marriageofficiantPassword'])){
				$_SESSION["username"] = $username;				
				echo "successful"; 
			}
			else echo "Wrong Password";
		}
	}
	if($username[0] == 'P'){
		$sql = "SELECT * FROM `photographer` where `photographerID` = '$username'";
		$result = $conn->query($sql);
		while($row = $result->fetch_assoc()){
			if($password==mysqli_real_escape_string($conn,$row['photographerPassword'])){	
				$_SESSION["username"] = $username;			
				echo "successful"; 		
			}
			else echo "Wrong Password";
		}
	}
?>
