<?php
    /*session variable*/
    session_start();

    /*Get post methods*/
    $code = $_POST["code"];
    $id = $_POST["id"]; 

    /*The include section*/
    include "general_query_execute_server.php"; 

    /*Object Oriented Code*/
    class Student_Authentication{
       protected $code; //thesis code
       protected $id; //unique id
    
       function value_assign($student, $code, $id){
            $student->code = $code;
            $student->id = $id; 
       }
       function check_into_database($student){
            $sql = $student->make_query($student);
            $student->execute_log_in_query($student,$sql);
       }

       function execute_log_in_query($student, $sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql);
            $student->take_decision($student,$result);
       }
       function take_decision($student,$result){
            $count=0;
            while($row = mysqli_fetch_array($result)){
                $count=$count+1;
            }
            if($count>0) {
                //set session variables
                $_SESSION["thesis_code"] = $student->code;
                $_SESSION["thesis_id"] = $student->id;
                echo "successful";
            } 
            else  {
                echo "not successful";
            }
       }
       function funcitional_query($attribute_name,$value){
            $attr = $attribute_name;
            $sql = "$attr like '$value' ";
            return $sql; 
        }

       function make_query($student){
            $table_name = "StudentInformation";
            $sql = "SELECT * FROM $table_name WHERE ";

            $value = $student->funcitional_query("group_id",$student->id);
            $sql .= $value ." and ";

            $value = $student->funcitional_query("thesis_code",$student->code);
            $sql .= $value ." and ";
            if(isset($_SESSION["research_group"])) {
                $value = $student->funcitional_query("research_group",$_SESSION["research_group"]);
                $sql .= $value ." ";
            }
            return $sql;
       }
    

    }

    /*data flow of work */
    $student = new Student_Authentication();
    $student->value_assign($student,$code,$id); 
    $student->check_into_database($student);


?>