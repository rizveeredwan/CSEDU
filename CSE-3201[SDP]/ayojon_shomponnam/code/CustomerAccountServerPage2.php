<?php   
session_start();             
$name = $_POST["name"];
$username=$_POST["username"];
$officeAddress=$_POST["officeAddress"];
$secondAddress=$_POST["secondAddress"];
$contact=$_POST["contact"];
$email=$_POST["email"];
$password=$_POST["password"];
$confirmPassword=$_POST["confirmPassword"];
$birth=$_POST["birth"];
$religion=$_POST["religion"];
$cast=$_POST["cast"];
$gender=$_POST["gender"];
$nid=$_POST["nid"];
$thumbnail=$_POST["thumbnail"];
$tin=$_POST["tin"];
$portfolio=$_POST["portfolio"];

//Now our main work will be updating existing database 
//Take the values from the row and then update the row seeing which row needs to be update

 echo "done";



?>