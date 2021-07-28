<?php
   session_start();
   $currentSelectedId = $_SESSION["currentSelectedId"];
   
   //From here you need to send a JSON object to customer account 
    //making JSON object
    $sendObject = new \stdClass();
    
    //Testing purpose 
    //initializing the object
    $sendObject->name="r";
    $sendObject->officeAddress="r";
    $sendObject->contact="r";
    $sendObject->email="r";
    $sendObject->portfolio="r";

    $sendObject->thumbnail = "provaapu6.jpg";


    //initializing the array
    $json = array(
        $sendObject->name,
        $sendObject->officeAddress,
        $sendObject->contact,
        $sendObject->email,
        $sendObject->portfolio,

        $sendObject->thumbnail
       
        
    );
    header("Content-type:application/sendJSON");
    $sendJSON = json_encode($json);
    echo $sendJSON;
?>