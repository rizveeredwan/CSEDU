<?php
   session_start();
   $check = $_POST["check"];
   $_SESSION["check"];
   if(isset($check)) {
       $_SESSION["check"] = "done Man";
   } 

?>

<html>
<html>
