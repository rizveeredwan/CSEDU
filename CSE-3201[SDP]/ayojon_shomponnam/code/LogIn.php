<?php
    session_start();
    $userName=$_POST["username"];
    $passWord=$_POST["password"];

    $_SESSION["username"]="";
    $_SESSION["password"]="";
   
    //My database 
    $servername = "rizvee-hp"; //my server name was rizvee-hp
    $username = "root";  //database user name 
    $password = NULL;  //database password
    $dbname = "ayojonsomponnam";    //database name
    // Create connection
    $conn = mysqli_connect($servername, $username, $password, $dbname);
    
    // Check connection - error checking 
    if (!$conn) {
      die("Connection failed: " . mysqli_connect_error());
    }
    else {
        //connection established 
        //Now need to save things to table of currentUser
        //so that I can extract things every moment 
        //checking if the variables are set 
        if (!empty($userName) && !empty($passWord)) {
          $login = LogIn::getInstance();
          if(!empty($login)) {
              //the object is not empty 
              $login->useQueryImplementor($userName,$passWord);
          }
        }
    }

    /***********************Implementation of the classes************************/
    
    
    /*Design Pattern: singleton pattern
    function: to check if the given user name is valid or not  
    after that work will move on*/
    class LogIn{

      private static $login; // a variable to get the object of this private class 
      public $queryimplementor; // this is a object of facade pattern to get the queries 
      private function __construct(){
         /* 
          constructor is being made private so only one object can be initiated
         */
      }

      public static function getInstance(){
          //function:: first create object of this class
          //returns it 
          //also making QueryImplementor object 
          $login = new LogIn();
          return $login;
      }

      public function useQueryImplementor($userName,$passWord){
          //    function: this function uses $queryimplementor object
          //    and perform all type of queries 
          //    calls QueryImplementor class methods 
          //    calls makeAllQuery function()
          //    before first creating object 
          $queryimplementor = new QueryImplementor();
          if(!empty($queryimplementor)) {
            //function making the all quereis 
            $queryimplementor->list = $queryimplementor->makeAllQuery($userName,$passWord);
            $it = new IteratorPattern();
            $it->iterate($queryimplementor->list);
          }
      }
    }

    /*
        Design Pattern: Strategy Pattern Implementation 
        function: to have the queries 
        and extract the condition to see if userName and password belongs to which table */
     abstract class Query{
      public $inTable; //this variable says if this table has this userName or not 
      public abstract function makeQuery($un,$pass); //this function will have
      //two parameters username and password and check if the table has them or not 
     }

    class Restaurant extends Query {
      
      //function to make query if this account belongs to a restaurant service provider or not 
      public function makeQuery($un,$pass){
          $inTable=0; 
          /*
             make query on restaurant table 
          */
          //echo "came into restaurant";
          return $inTable;
      }
    }
    class Decorator extends Query {
        
        //function to make query if this account belongs to a decorator service provider or not 
        public function makeQuery($un,$pass){
            $inTable=0; 
            /*
               make query on decorator table 
            */
            //echo "came into decorator";
            return $inTable;
        }
    }
    class Catering extends Query {
        
        //function to make query if this account belongs to a catering service provider or not 
        public function makeQuery($un,$pass){
            $inTable=0; 
            /*
               make query on catering table 
            */
            //echo "came into catering";
            return $inTable;
        }
    }
    class Photographer extends Query {
        
        //function to make query if this account belongs to a photographer or not 
        public function makeQuery($un,$pass){
            $inTable=1; 
            /*
               make query on photographer table 
            */
            return $inTable;; 
        }
      }
      class Officiant extends Query {
        
        //function to make query if this account belongs to a marriage officiant or not 
        public function makeQuery($un,$pass){
            $inTable=0; 
            /*
               make query on marraiange officiant table 
            */
            //echo "came into officiant";
            return $inTable;
        }
      }
      class Customer extends Query {
        
        //function to make query if this account belongs to a customer or not 
        public function makeQuery($un,$pass){
            $inTable=0; 
            /*
               make query on customer table 
            */
            //echo "came into customer";
            return $inTable;
        }
        
      }
    
      
      /*
          Design: Facade pattern implementation 
          Function:The sole purpose of this class is to use all typed of Query classes and make 
          queries.Basically from LogIn class I will call this class object. And this class will
          automatically perform all type of queries and give me results.  
      */
      class QueryImplementor{
         public $restaurant; //restaurant type object 
         public $catering; //catering type object 
         public $decorator; //decorator type object
         public $photographer; //photographer type object
         public $officiant; //officiant type object
         public $customer; //customer type object
         public $list; 

         function makeAllQuery($un,$pass){
        //function: implementation of falacid pattern
        //one function to do all type of queries

        //creating an array 
        $list = array(); 

             //restaurant part 
             $restaurant = new Restaurant(); 
             if(!empty($restaurant)){
                $restaurant->inTable =  $restaurant->makeQuery($un,$pass);
                $list[] =  $restaurant->inTable;  //taking the intable value to see if the value is
                                                 //true or not 
             }
             //catering part 
             $catering = new Catering();
             if(!empty($catering)){
                $catering->inTable =  $catering->makeQuery($un,$pass);
                $list[] =  $catering->inTable;
                
             }
             //decorator part 
             $decorator = new Decorator();
             if(!empty($decorator)){
                $decorator->inTable =  $decorator->makeQuery($un,$pass);
                $list[] =  $decorator->inTable;
                
             }
             //photographer part 
             $photographer = new Photographer(); 
             if(!empty($photographer)){
                $photographer->inTable =  $photographer->makeQuery($un,$pass);
                $list[] =  $photographer->inTable;
                
             }
             //officiant part
             $officiant = new Officiant();
             if(!empty($officiant)){
                $officiant->inTable = $officiant->makeQuery($un,$pass);
                $list[] =  $officiant->inTable;
                
             }
             //customer part 
             $customer = new Customer(); 
             if(!empty($customer)){
                $customer->inTable = $customer->makeQuery($un,$pass);
                $list[] =  $customer->inTable;
             }
             return $list;    
         }
        
      }

      /*
        Design: Iterator Design patten
        Function: To check if any of the query have found the value or not 
      */
      class IteratorPattern{
          //function: Iterate and to see if any query has found value 
          public function iterate($list){
              $counting=0;
              for($i=0;$i<count($list); $i++){
                 if($list[$i] == 1) {
                     $counting++;
                 } 
              }
              if($counting == 1){
                 //only one table has found value 
                
                 echo "successful";  
              }
              else {
                  //no table has found this userName and password 
                  echo "not successful"; 
              }
          }
          
      }


?>