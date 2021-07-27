<?php 

/*session start part*/
session_start();

/*Data Receival Part*/
$password = $_POST["password"];
$account = $_POST["account"];
$research_group = $_POST["research_group"];

/*Include part*/
include "general_query_execute_server.php"; 

/*Object oriented part*/
class Logged_Person{
   protected $account;
   protected $password;
   protected $research_group;

   function value_assign($logged_person, $acc, $pass, $res) {
       $logged_person->account = $acc;
       $logged_person->password = $pass;
       $logged_person->research_group = $res;
   }

   function modify_attributes($logged_person){
        if($logged_person->account == "Viewer" || $logged_person->account == "Admin"  ){
            $logged_person->research_group = "others"; 
        }
   }

   function check_into_database($logged_person){
        $logged_person->modify_attributes($logged_person);
        $sql = $logged_person->make_query($logged_person);
        $logged_person->execute_log_in_query($logged_person,$sql);
   }

   function execute_log_in_query($logged_person, $sql){
        $sql_query = new SQL_Query();
        $result = $sql_query->query_execute_return_result($sql_query,$sql);
        $logged_person->take_decision($logged_person,$result);
   }

   function take_decision($logged_person,$result){
        $count=0;
        while($row = mysqli_fetch_array($result)){
            $count=$count+1;
        }
        if($count>0) {
            /*Session variables are set*/
            $_SESSION["account"] = $logged_person->account;
            $_SESSION["password"] = $logged_person->password;
            $_SESSION["research_group"] = $logged_person->research_group;
            echo "successful";
        } 
        else echo "not successful";
   }

   function funcitional_query($attribute_name,$value){
        $attr = $attribute_name;
        $sql = "$attr like '$value' ";
        return $sql; 
   }

   function make_query($logged_person){
     //global variable for this scope
     $table_name = "LogInTable"; 
     $sql = "SELECT * FROM $table_name WHERE ";
     
     //attributes 
     $value = $logged_person->funcitional_query("account",$logged_person->account);
     $sql .= $value." and "; 
    
     $value = $logged_person->funcitional_query("research_group", $logged_person->research_group);
     $sql .= $value." and "; 

     $value = $logged_person->funcitional_query("password", $logged_person->password);
     $sql .= $value." "; 
     
     return $sql; 
   }

}

/*Data Flow Part*/
$logged_person = new Logged_Person();
$logged_person->value_assign($logged_person,$account,$password,$research_group);
$logged_person->check_into_database($logged_person);

?>