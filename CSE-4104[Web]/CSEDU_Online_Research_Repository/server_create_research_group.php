<?php
   

    /*Function to create research group */
    $name = $_POST["name"];
    $account = $_POST["account"];
    $password = $_POST["password"];
    $email = $_POST["email"];
    $phone = $_POST["phone"];
    $link = $_POST["link"];

    /*Include part*/
    include "general_query_execute_server.php";
    include "general_query_make_server.php";

    class Create_Research_Group{
        protected $name;
        protected $account;
        protected  $password;
        protected $email;
        protected $phone;
        protected $link;

        function initialize($reseach_group, $name, $account, $password, $email,$phone, $link) {
            $reseach_group->name = $name;
            $reseach_group->account = $account;
            $reseach_group->password = $password;
            $reseach_group->email = $email;
            $reseach_group->phone = $phone;
            $reseach_group->link = $link;
        }

        function funcitional_query($attribute_name,$value){
            $attr = $attribute_name;
            $sql = "$attr like '$value' ";
            return $sql; 
        }

        function entry_into_database($reseach_group){
           
            $sql = $reseach_group->make_query_see_if_exists($reseach_group);
            $result = $reseach_group->execute_query($sql);
            $counter = $reseach_group->count_row_in_table($result);
            if($counter>0) {
                /*Entry already exists */
                echo "Research Group Already Exists";
            }
            else if($counter == 0) {
                $sql = $reseach_group->make_query_to_entry_into_ResearchGroupInfo($reseach_group);
                $result = $reseach_group->execute_query($sql);
                if($result){
                    /*Now need to insert into log in table*/
                    $sql = $reseach_group->make_query_to_entry_into_LogInTable($reseach_group);
                    $result = $reseach_group->execute_query($sql);
                    if($result){
                        echo "successful";
                    }   
                }
                else {
                    echo "unsucessful";
                }
            }
            else {
                echo "Error";
            }
        }

        function make_query_see_if_exists($reseach_group){
            //global variable for this scope
            $table_name = "ResearchGroupInfo"; 
            $sql = "SELECT * FROM $table_name WHERE ";

            //attr
            $value = $reseach_group->funcitional_query('name',$reseach_group->name);
            $sql .= $value;
            return $sql;
        }

        function execute_query($sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql);
            return $result; 
        }

        function count_row_in_table($result){
            $counter=0;
            while($row=mysqli_fetch_array($result)) {
                $counter=$counter+1;
            }
            return $counter;
        }

        function make_query_to_entry_into_ResearchGroupInfo($reseach_group){

            $query_make = new Query_Make();
            $attributes = array("name","password","email","phone","link");
            $values = array($reseach_group->name,$reseach_group->password,$reseach_group->email,$reseach_group->phone,$reseach_group->link);
            $table_name = "ResearchGroupInfo";

            $sql = $query_make->insertion_query($query_make,$table_name,$attributes,$values);
            return $sql;
        }

        function make_query_to_entry_into_LogInTable($reseach_group){
            $query_make = new Query_Make();
            $attributes = array("account","password","research_group");
            $values = array("Manager",$reseach_group->password,$reseach_group->name);
            $table_name = "LogInTable";

            $sql = $query_make->insertion_query($query_make,$table_name,$attributes,$values);
            return $sql;
        }



    }

    $reseach_group = new Create_Research_Group();
    $reseach_group->initialize($reseach_group,$name, $account, $password, $email,$phone, $link);
    $reseach_group->entry_into_database($reseach_group);

    //echo $name." ".$account." ".$password." ".$email." ". $phone." ". $link;
?>