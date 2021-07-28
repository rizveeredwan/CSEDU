<?php
    session_start();
    $userName = $_POST["userName"];
    //From here you need to send a JSON object to customer account 
    //making JSON object
    $sendObject = new \stdClass();
    
    //initializing the object
    $sendObject->name="BBBBBBBBBB";
    $sendObject->username=$_SESSION["username"];
    $sendObject->officeAddress="r";
    $sendObject->secondAddress="r";
    $sendObject->contact="r";
    $sendObject->email="r";
    $sendObject->password="r";
    $sendObject->birth="r";
    $sendObject->religion="r";
    $sendObject->cast="r";
    $sendObject->gender="r";
    $sendObject->nid="r";
    $sendObject->thumbnail="r";
    $sendObject->tin="r";
    $sendObject->portfolio="r";

    //initializing the array
    $json = array(
        $sendObject->name,
        $sendObject->username,
        $sendObject->officeAddress,
        $sendObject->secondAddress,
        $sendObject->contact,
        $sendObject->email,
        $sendObject->password,
        $sendObject->birth,
        $sendObject->religion,
        $sendObject->cast,
        $sendObject->gender,
        $sendObject->nid,
        $sendObject->thumbnail,
        $sendObject->tin,
        $sendObject->portfolio
    );
    header("Content-type:application/sendJSON");
    $sendJSON = json_encode($json);
    echo $sendJSON;    
?>