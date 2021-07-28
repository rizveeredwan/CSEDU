<?php 
session_start();
include("class_lib.php");
?>


<?php
session_start();
//Azwad Anjum Islam
//THIS CODE TAKES A ROW FROM THE TEMPORARY TABLE AND INSERTS THEM INTO THE CORRECT ACCOUNT TYPE TABLE IN THE DB
//WORKS WITH class_lib.php FILE
	
	//MY SQL Part
    $servername = "localhost"; //my server name was rizvee-hp
    $username = "root";  //database user name 
    $password = "";  //database password
    $dbname = "ayojonsomponnamfinal";    //database name  

    // Create connection
    $conn = mysqli_connect($servername, $username, $password, $dbname);

    // Check connection - error checking 
    if (!$conn) {
		die("Connection failed: " . mysqli_connect_error());
    }
    
    $sql = "SELECT * FROM `tempsignup`";  
    $result = $conn->query($sql);
 
	if($result->num_rows > 0){
		while($row = $result->fetch_assoc()){
			if(mysqli_real_escape_string($conn,$row['accountType'])=="customer"){
				$object = new customer($row);
				$object->insert($conn);
			}
			else if(mysqli_real_escape_string($conn,$row['accountType'])=="photographer"){
				$object = new photographer($row);
				$object->insert($conn);
			}
			else if(mysqli_real_escape_string($conn,$row['accountType'])=="hall"){
				$object = new hall($row);
				$object->insert($conn);
			}
			else if(mysqli_real_escape_string($conn,$row['accountType'])=="catering"){
				$object = new catering($row);
				$object->insert($conn);
			}
			else if(mysqli_real_escape_string($conn,$row['accountType'])=="officiant"){
				$object = new marriageofficiant($row);
				$object->insert($conn);
			}
			else if(mysqli_real_escape_string($conn,$row['accountType'])=="decorator"){
				$object = new decorator($row);
				$object->insert($conn);
			}
			else {
				echo "The account Type is not right";
			}
		}
		mysqli_query($conn,"DELETE FROME `tempsignup`");
    }
	
	else echo "No result";
	
	mysqli_close($conn);

   mysqli_close($conn);
?>
