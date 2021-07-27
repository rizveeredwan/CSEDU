<?php
    /*Purpose of this file is to control admin account*/
    class Admin_Account{

        function add_teacher($main_object,$data){
            $ok = $main_object->check_validation($main_object);
            if($ok == 1) {
                $res = $main_object->split_from_delemeter($data,"^");
                $name = $res[0];
                $designation = $res[1];
                $email = $res[2];
                $phone = $res[3];
                $portfolio = $res[4];
                $status = $res[5];

                $query_make = new Query_Make();
                $attributes = array("name","designation","email","phone","portfolio","status");
                $values = array($name,$designation,$email,$phone,$portfolio,$status);
                $sql = $query_make->insertion_query($query_make,"TeacherTable",$attributes,$values);
                $result = $main_object->exeute_query($main_object,$sql);

                if($result){
                        //when a teacher is added it can also be something like update query
                        //so need to update his information in Supervisor
                        $condition_col = array("name","email");
                        $condition_val = array($name,$email);
                        $sql = $query_make->update_query($query_make,"Supervisor",$attributes,$values,$condition_col,$condition_val);
                        $result = $main_object->exeute_query($main_object,$sql);
                        if($result){
                            echo "successful";
                        }
                        else {
                            echo " not successful";
                        }
                   
                }
                else {
                    echo " not successful";
                }
                
            }
        }

        function delete_teacher($main_object,$values){
            $ok = $main_object->check_validation($main_object);
            if($ok == 1) {
                $res = $main_object->split_from_delemeter($values,"^");
                $name = $res[0];
                $designation = $res[1];
                $email = $res[2];
                $query_make = new Query_Make();
                $attributes = array("name","designation","email");
                $values = array($name,$designation,$email);
                $sql = $query_make->delete_query($query_make,"TeacherTable",$attributes,$values);
                /*debug: echo $sql; */
                $result = $main_object->exeute_query($main_object,$sql);
                if($result){
                    echo "successful";
                }
                else {
                    echo " not successful";
                }
            }
        }

        function check_validation($main_object){
            if(isset($_SESSION["account"]) && isset($_SESSION["page_name"])) {
                $page_name = $_SESSION["page_name"];
                $account = $_SESSION["account"];
                if($page_name == "admin_account.php" && $account == "Admin") {
                    return 1;
                }
            }
            return 0;
        }

        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }
        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }
        function update_admin($main_object,$values){
            $res = $main_object->split_from_delemeter($values,"^");
            $password = $res[0];
            $email = $res[1];
            $phone = $res[2];
            $result = $main_object->update_into_admin_table($main_object,$email,$phone);
            if($result) {
                $result = $main_object->update_into_log_in_table($main_object,$password);
                if($result) {
                    echo "successful";
                }
                else {
                    echo "unsuccessful";
                }
            }
            else {
                echo "unsuccessful";
            }
            
        }

        function update_into_admin_table($main_object,$email,$phone){
            $query_make = new Query_Make();
            $attributes = array("email","phone");
            $values = array($email,$phone);
            $condition_col = array("number");
            $condition_val = array("1");
            $sql = $query_make->update_query($query_make,"AdminTable",$attributes,$values,$condition_col,$condition_val);
            $result = $main_object->exeute_query($main_object,$sql);
            if($result) return $result;
        }
        function update_into_log_in_table($main_object,$password){
            $query_make = new Query_Make();
            $attributes = array("password");
            $values = array($password);
            $condition_col = array("account");
            $condition_val = array("Admin");
            $sql = $query_make->update_query($query_make,"LogInTable",$attributes,$values,$condition_col,$condition_val);
            $result = $main_object->exeute_query($main_object,$sql);
            if($result) return $result;
        }
    }

?>
