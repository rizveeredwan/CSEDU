<?php
    //creating directories 
    session_start();
    $fileName = $_FILES["thumbnail"]["name"]; //the name of the file 
    $fileTmpLoc = $_FILES["thumbnail"]["tmp_name"]; //where I would copy temporarily
    $fileType = $_FILES["thumbnail"]["type"]; 
    $fileSize = $_FILES["thumbnail"]["size"];
    $fileErrMsg = $_FILES["thumbnail"]["error"];

    //MY SQL Part
    /**************HUDAI*************/
    $servername = "localhost"; //my server name was rizvee-hp
    $username = "root";  //database user name 
    $password = "";  //database password
    $dbname = "ayojonsomponnamfinal";    //database name  

    // Create connection
    /***************************HUU**************************************/
    $conn = mysqli_connect($servername, $username, $password, $dbname);

    // Check connection - error checking 
    if (!$conn) {
      die("Connection failed: " . mysqli_connect_error());
    }
    if(!$fileTmpLoc){
        echo "problem";
    }
    else {
        //well for being cashed second parameters first part need to be changed 
        if(move_uploaded_file($fileTmpLoc,"/opt/lampp/htdocs/Image/$fileName")) {
         $sql = "update `tempsignup` set thumbnailLink = '/opt/lampp/htdocs/Image/$fileName'"; 
           if (mysqli_query($conn, $sql)) {
            echo "New record created successfully<br>";
        } else {
            echo "Error: " . $sql . "<br>" . mysqli_error($conn);
        } 
        echo "Image upload done";    
    }
    else {
       echo "not done";
     }
   }
?>