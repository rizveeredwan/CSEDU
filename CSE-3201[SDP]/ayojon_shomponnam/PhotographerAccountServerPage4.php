<?php
  //The functionality of this page is to add schedule data in table 
  session_start();
  $username = $_SESSION["username"];
  $date = $_POST["date"];
  $time = $_POST["time"];
  $customerId = $_POST["customerId"];

  //Here will be the code to update into database 

  echo "data addes successfully"
?>