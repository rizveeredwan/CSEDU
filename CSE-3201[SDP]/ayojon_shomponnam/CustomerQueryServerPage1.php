<?php
   //getting the request 
   $userName = $_POST["userName"];
   $passWord = $_POST["passWord"];

   //make the query and bring the location
   /**********************A Query will be done****************/
 
      //function to bring all the informations of the customer 
      //and save into a JSON object 
      //object name = $sendObject
   /*********************************************************/
   
   //variable initialization from previous query 
   //having the object 
   $sendObject = Send::getInstace(); 
   
   //will initialize from prvious query 
   $sendObject->id="C01"; //customer ID 
   $sendObject->name="Azwad Anjum Dipto"; //name
   $sendObject->address1="47/5 Mia Fazil Chisti";
   $sendObject->address2="124/A North Jatrabari"; 
   $sendObject->dateBirth="23-08-1996";
   $sendObject->religion="Islam";
   $sendObject->cast="sunni";
   $sendObject->contact="01758545903";
   $sendObject->email="otpid.is@gmail.com";
   $sendObject->nid="11111111";
   $sendObject->password="123444444";
   $sendObject->thumbnail="here I am"; 

   //$sendJSON = json_encode($sendObject);
   //echo $sendJSON; 
   
   //Now will send 
   $sendObject->send($sendObject);

   //Implementation of Singleton Pattern 
   class Send{
     public $id;//id or username 
     public $name;//name
     public $address1; //address1
     public $address2; //address2
     public $dateBirth; //birth
     public $religion; //religion
     public $cast; //cast 
     public $contact;//contact 
     public $email;//email
     public $nid; //nid 
     public $password; //password 
     public $thumbnail; //thumbnail image link 

     public $sendObject; //the singleton object  
     private function __send(){} //private constructor
     
     //work creating object 
     function getInstace(){
        $sendObject = new Send();
        return $sendObject;
     }
     //work sending to requested page 
     function send(Send $sendObject){
        
        //Json make
        $sendJSON = json_encode($sendObject);
        echo $sendJSON; 
     }
   }
?>