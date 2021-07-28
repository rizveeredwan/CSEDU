<?php
   
   //data receive 
   $cateringFullName=$_POST["cateringFullName"];
   $cateringAddress = $_POST["cateringAddress"];
   $cateringContact=$_POST["cateringContact"];
   $cateringEmail=$_POST["cateringEmail"]; 
   $cateringTIN=$_POST["cateringTIN"];
   $cateringPassword=$_POST["cateringPassword"];
   $cateringConfirmPassword = $_POST["cateringConfirmPassword"];
   $tableDataSend = $_POST["tableDataSend"]; //A JSON object 
                    //" " nai so porar jonno stripcslahes deya ache 
   //Decode the JSON Array
   $cateringImg = $_POST["cateringImg"];  
   $tableDataSend = json_decode($tableDataSend,TRUE);
      
   //now normally access 
   echo JSON.stringify($tableDataSend); 
      
?>