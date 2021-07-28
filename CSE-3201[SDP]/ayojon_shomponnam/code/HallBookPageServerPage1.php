<?php
  //the purpose of this file is to see if currentSelectedId is available or not 
  //echo yes if that date and time is available
  //otherwise echo no 
  session_start();
  $currentSelectedId = $_SESSION["currentSelectedId"];
  $date=$_POST["date"];
  $time=$_POST["time"];

  echo "yes";
?>