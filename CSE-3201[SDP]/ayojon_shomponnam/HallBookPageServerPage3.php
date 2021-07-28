<?php
   session_start();
   $currentSelectedId = $_SESSION["currentSelectedId"];
   
   //From here you need to send a JSON object to HallBookPage and show  
    //making JSON object
    $sendObject = new \stdClass();
    
    //Testing purpose 
    //initializing the object
    $sendObject->name="r";
    $sendObject->officeAddress="r";
    $sendObject->contact="r";
    $sendObject->email="r";
    $sendObject->capacity="r";
    $sendObject->fee="r";
    $sendObject->portfolio="r";

    $sendObject->thumbnail = "provaapu6.jpg";
    $sendObject->credImg1 = "provaapu6.jpg";
    $sendObject->credImg2 = "provaapu6.jpg";
    $sendObject->credImg3 ="provaapu6.jpg";
    $sendObject->credImg4 ="provaapu6.jpg";
    $sendObject->credImg5 = "provaapu6.jpg";


    //initializing the array
    $json = array(
        $sendObject->name,
        $sendObject->officeAddress,
        $sendObject->contact,
        $sendObject->email,
        $sendObject->capacity,
        $sendObject->fee,
        $sendObject->portfolio,

        $sendObject->thumbnail,
        $sendObject->credImg1,
        $sendObject->credImg2,
        $sendObject->credImg3,
        $sendObject->credImg4,
        $sendObject->credImg5
        
    );
    header("Content-type:application/sendJSON");
    $sendJSON = json_encode($json);
    echo $sendJSON;
?>