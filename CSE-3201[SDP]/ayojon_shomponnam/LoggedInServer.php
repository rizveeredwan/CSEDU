<?php
  $var = $_POST["query"];
  //The sole purpose of this file is to see who is logged in this moment
  $username = "root";  //database user name 
  $password = NULL;  //database password
  $dbname = "ayojonsomponnam";    //database name
  // Create connection
  $conn = mysqli_connect("localhost", $username, $password, $dbname);

  // Check connection - error checking 
  if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
  }
  else {
      GetUserName::query($conn);
  }

  //A class with double function
  class GetUserName{
    
     function query(mysqli $conn) {
             //taking the userName 
             
             //taking the password 
			 $sql = "SELECT * FROM CurrentUser";  
			 $result = mysqli_query($conn, $sql); 


			//$row = mysqli_fetch_array($result);	 
             //$passWord = "SELECT * From `CurrentUser` ";
			 //echo $passWord;
             //$userName = $row["userName"];
             //$passWord = $row["password"];;
			 
             //making JSON object
             $sendObject = new \stdClass();;
             
             while($row = mysqli_fetch_array($result)){
                 $sendObject->userName = $row["userName"];
					
				         $sendObject->passWord = $row["password"]; 
             }

             $json = array(
                $sendObject->userName,
                $sendObject->passWord 
             );
			 //header("Content-type:application/json");
             
			 //JSON endocing   
			 
			//var myJSON = JSON.stringify(sendObject);


			 //$sql = "SELECT * FROM CurrentUser";  
			 //$result = mysqli_query($conn, $sql); 


			//$row = mysqli_fetch_array($result);	 

             $sendJSON = json_encode($json);
             echo $sendJSON;
			  header("Content-type:application/sendJSON");
			 
			 //$decoded = json_decode($sendJSON);
			 //echo $decoded[0];
			// echo $decoded->userName; ***********
			 //echo $decoded->passWord; ***********
   //var_dump(json_decode($sendJSON));
	//var_dump(json_decode($sendJSON, true));
	
			 
     }
  }

?>
