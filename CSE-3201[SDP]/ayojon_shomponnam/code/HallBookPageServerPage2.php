<?php
  //purpose of this function is to to book a schedule
  //checks $_SESSION["username"] ok or not logged in as cutomer or not 
  session_start();
  //getting session variable 
  $currentSelectedId = $_SESSION["currentSelectedId"];
  $currentuser = $_SESSION["username"];

  //echo  $_SESSION["currentSelectedId"]." ".$_SESSION["username"];
  if(!isset($currentuser)){
       echo "Log In First as Customer";
  }
  else if($currentuser[0] != 'C'){
    echo "Log In First as Customer";
  }
  else {
      echo "successful";
      //now need to make query and update in the table 
  }

?>
