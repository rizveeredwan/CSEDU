<?php
  $name = $_POST["name"];
  $addressMain = $_POST["addressMain"]; 
  $_SESSION["tempName"]="rafik";
  $_SESSION["tempAddressMain"]="keno";
  if(isset($name)){
  $_SESSION["tempName"] = $name; 
  }
  else if(isset($addressMain)) {
       $_SESSION["tempAddressMain"] = $addressMain;
       echo  $_SESSION["tempName"]." ". $_SESSION["tempAddressMain"];
  }
 
?>