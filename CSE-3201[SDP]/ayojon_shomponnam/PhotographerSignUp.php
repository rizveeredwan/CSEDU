<?php
   
    //data reception part 
    $photographerName = $_POST["photographerName"];
    $photographerAddress = $_POST["photographerAddress"];
    $photographerDateBirth = $_POST["photographerDateBirth"];
    $photographerContact = $_POST["photographerContact"];
    $photographerEmail = $_POST["photographerEmail"];
    $photographerNID = $_POST["photographerNID"];
    $photographerPassword = $_POST["photographerPassword"];
    $photographerConfirmPassword = $_POST["photographerConfirmPassword"];
    $photographerPortfolio = $_POST["photographerPortfolio"];
    $photographerImg=$_POST["photographerImg"];

    echo $photographerName+$photographerAddress+$photographerDateBirth+$photographerContact;
    
    /*
    //MY SQL Part
    $servername = "localhost"; //my server name was rizvee-hp
    $username = "username";  //database user name 
    $password = "password";  //database password
    $dbname = "myDB";    //database name  

    // Create connection
    $conn = mysqli_connect($servername, $username, $password, $dbname);

    // Check connection - error checking 
    if (!$conn) {
      die("Connection failed: " . mysqli_connect_error());
    }
    
    //query pre process part will be updated
    $phphotographerID = mysqli_query($con,"SELECT COUNT(*) FROM fooTable"); 
    $phphotographerID = (int)$phphotographerID;
    $phphotographerID = $phphotographerID + 1; 
    
    //query is being made - writing into Database
    $sql = "INSERT INTO photographer(
    photographerId, 
    photographerName, 
    photographerAddress,
    photographerDateBirth,
    photographerContact,
    photographerEmail,
    photographerNID,
    photographerPassword,
    photographerConfirmPassword,
    photographerPortfolio,
    photographerImg
    )
    VALUES (
        $phphotographerID,
        $photographerName, 
        $photographerAddress, 
        $photographerDateBirth,
        $photographerContact,
        $photographerEmail,
        $photographerNID,
        $photographerPassword,
        $photographerConfirmPassword,
        $photographerPortfolio,
        $photographerImg,
        )";  
   if (mysqli_query($conn, $sql)) {
    echo "New record created successfully";
   } else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
   }
   mysqli_close($conn);
 
   */
    
?>