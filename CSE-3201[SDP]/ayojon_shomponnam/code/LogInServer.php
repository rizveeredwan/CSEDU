<?php
  session_start();

  $_SESSION["username"]=$_POST["username"];
  $_SESSION["password"]=$_POST["password"];
  

  //if(isset($userName) && isset($password)) {
   // $_SESSION["username"]=$userName;
    //$_SESSION["password"]=$passWord;
  //}
  echo "successful";
?>