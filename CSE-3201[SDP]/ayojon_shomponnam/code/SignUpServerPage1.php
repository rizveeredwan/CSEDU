<?php

  session_start();
  $name = $_POST["name"];
  $addressMain=$_POST["addressMain"];
  $addressSub=$_POST["addressSub"];
  $contact=$_POST["contact"];
  $email=$_POST["email"];
  $password=$_POST["password"];
  $confirmPassword=$_POST["confirmPassword"];
  $accountType=$_POST["accountType"];
  $genderType=$_POST["genderType"];
  $nid=$_POST["nid"];
  $tin=$_POST["tin"];
  $religion=$_POST["religion"];
  $cast=$_POST["cast"];
  $portfolioLink=$_POST["portfolioLink"];
  $birth = $_POST["birth"];

  /******************************JUST check**********************/
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

   $sql = "INSERT INTO `tempsignup`(
  `name`, 
  `addressMain`, 
  `addressSub`,
  `contact`,
  `email`,
  `password`,
  `confirmPassword`,
  `accountType`,
  `gender`,
  `NID`,
  `TIN`,
  `religion`,
  `cast`,
  `portfolioLink`,
  `dateBirth`
  )
  VALUES (
      '$name',
      '$addressMain', 
      '$addressSub', 
      '$contact',
      '$email',
      '$password',
      '$confirmPassword',
      '$accountType',
      '$genderType',
      '$nid',
      '$tin',
      '$religion',
      '$cast',
      '$portfolioLink',
      '$birth'
      );";  
      
         if (mysqli_query($conn, $sql)) {
         echo "successful";
         } else {
         echo "Error: " . $sql . "<br>" . mysqli_error($conn);
         }
        mysqli_close($conn);
       
?>