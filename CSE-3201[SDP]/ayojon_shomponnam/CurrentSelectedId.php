<?php
  
  //setting the session variable to get help for book page 
  session_start();
  $_SESSION["currentSelectedId"] = $_POST["currentSelectedId"];
  //echo $_SESSION["currentSelectedId"];

?>