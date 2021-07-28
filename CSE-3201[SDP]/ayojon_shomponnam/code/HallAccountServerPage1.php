<?php

  session_start();
  $userName = $_POST["userName"];
  //From here you need to send a JSON object to customer account 
  //making JSON object
  $sendObject = new \stdClass();


  /*****************************************/
      //need to write the queries 
    
  /****************************************/
  
  //initializing the object
  //common attribute will be sent like this 
  $sendObject->name="r";
  $sendObject->username=$_SESSION["username"];
  $sendObject->officeAddress="r";
  $sendObject->secondAddress="r";
  $sendObject->contact="r";
  $sendObject->email="r";
  $sendObject->password="r";
  $sendObject->birth="r";
  $sendObject->tin="r";
  $sendObject->nid="r";
  $sendObject->religion="r";
  $sendObject->cast="r";
  $sendObject->gender="r";
  $sendObject->portfolio="r";
  $sendObject->thumbnail="r";

  //special attributes 
  $sendObject->capacity="r";
  $sendObject->credImg1="r";
  $sendObject->credImg2="r";
  $sendObject->credImg3="r";
  $sendObject->credImg4="r";
  $sendObject->credImg5="r";
  $sendObject->fee="r";
  

  //

  //initializing the array
  $json = array(
    $sendObject->name="r",
    $sendObject->username=$_SESSION["username"],
    $sendObject->officeAddress="r",
    $sendObject->secondAddress="r",
    $sendObject->contact="r",
    $sendObject->email="r",
    $sendObject->password="r",
    $sendObject->birth="r",
    $sendObject->tin="r",
    $sendObject->nid="r",
    $sendObject->religion="r",
    $sendObject->cast="r",
    $sendObject->gender="r",
    $sendObject->portfolio="r",
    $sendObject->thumbnail="r",
    $sendObject->capacity="r",
    $sendObject->credImg1="r",
    $sendObject->credImg2="r",
    $sendObject->credImg3="r",
    $sendObject->credImg4="r",
    $sendObject->credImg5="r",
    $sendObject->fee="r"
  
  );
  header("Content-type:application/sendJSON");
  $sendJSON = json_encode($json);
  echo $sendJSON; 
  
?>