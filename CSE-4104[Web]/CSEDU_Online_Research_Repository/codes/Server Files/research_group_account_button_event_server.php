<?php
    /*Main purpose of this file is to act on button events of research_group_account.html*/
    class Research_Group_Button{
        protected $research_group;

        function add_new_supervisor($main_object,$value){
          $temp_array = $main_object->split_from_delemeter($value,'^');
          $teacher_name = $temp_array[0];
          $teacher_email = $temp_array[1];
            
          //Class Teacher is already declared 
          $teacher = $main_object->bring_a_teachers_all_info($main_object,$teacher_name,$teacher_email);
          $main_object->insert_into_supervisor_table($main_object,$teacher);
          
        }
        //split by delemeter
        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }
        function bring_a_teachers_all_info($main_object,$teacher_name,$teacher_email){
            $query_make = new Query_Make();
            $attribute = array("name","email");
            $value = array($teacher_name,$teacher_email);
            $sql = $query_make->conditional_select($query_make,"TeacherTable",$attribute,$value);
            $result = $main_object->exeute_query($main_object,$sql);

            $teacher = new Teacher();
            while($row=mysqli_fetch_array($result)) {
                $teacher->name = $row['name'];
                $teacher->designation = $row['designation'];
                $teacher->email = $row['email'];
                $teacher->phone = $row['phone'];
                $teacher->portfolio = $row['portfolio'];
                $teacher->status = $row['status'];
            }
            return $teacher;
        }
        //executing query
        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }
        function insert_into_supervisor_table($main_object,$teacher){
            if(isset($_SESSION["account"]) && isset($_SESSION["research_group"])) {
                if($_SESSION["account"] == "Manager" && $_SESSION["research_group"] != "Others") {
                    $query_make = new Query_Make();
                    $attribute = array('name','phone','designation','email','portfolio','research_group','status');
                    $value = array($teacher->name,$teacher->phone,$teacher->designation,$teacher->email,$teacher->portfolio,$_SESSION["research_group"],$teacher->status);
                    $sql = $query_make->insertion_query($query_make,"Supervisor",$attribute,$value); 
                    echo $sql;
                    $result = $main_object->exeute_query($main_object,$sql);
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
        }

        //function remove suprevisor
        function remove_supervisor($main_object,$value){
            $temp_array = $main_object->split_from_delemeter($value,'^');
            $teacher_name = $temp_array[0];
            $teacher_email = $temp_array[1];
            if(isset($_SESSION["research_group"])) {
                if($_SESSION["research_group"] != "Others") {
                    $query_make = new Query_Make();
                    $attribute = array("name","email","research_group");
                    $value = array($teacher_name,$teacher_email,$_SESSION["research_group"]);
                    $sql = $query_make->delete_query($query_make,"Supervisor",$attribute,$value);
                    $result = $main_object->exeute_query($main_object,$sql);
                    if($result) {
                        echo "successful";
                    }
                    else {
                        echo "unsuccessful";
                    }
                }
            }
        }

        function update_account($main_object,$value){
            $res = $main_object->split_from_delemeter($value,'^');
            $main_object->research_group = $res[0]; //name 
            //name^password^email^phone^link^google^dropbox^github^facebook^password_student
            $password = $res[1];
            $email = $res[2];
            $phone = $res[3];
            $phone = $phone."^".$res[4];
            $link = $res[5];
            $google_drive = $res[6];
            $dropbox = $res[7];
            $github = $res[8];
            $facebook = $res[9];
            $password_student = $res[10]; 

            $query_make = new Query_Make();
            //update into ResearchGroupInfo  
            $attribute = array("name","password","password_student","email","phone","link","google_drive","dropbox","facebook","github");
            $value = array($main_object->research_group,$password,$password_student,$email,$phone,$link,$google_drive,$dropbox,$facebook,$github);
            $condition_col = array("name");
            $condtion_val = array($main_object->research_group);
            $sql = $query_make->update_query($query_make,"ResearchGroupInfo",$attribute,$value,$condition_col,$condtion_val);
            $result = $main_object->exeute_query($main_object,$sql);
            if($result) {
                //echo "successful 1";
                $attribute = array("account","password","research_group");
                $value = array("Manager",$password,$main_object->research_group);
                $condition_col = array("account","research_group");
                $condtion_val = array("Manager",$main_object->research_group);
                $sql = $query_make->update_query($query_make,"LogInTable",$attribute,$value,$condition_col,$condtion_val);
                $result = $main_object->exeute_query($main_object,$sql);
                if($result) {
                    //echo "successful 2";
                    $attribute = array("account","password","research_group");
                    $value = array("Student",$password_student,$main_object->research_group);
                    $condition_col = array("account","research_group");
                    $condtion_val = array("Student",$main_object->research_group);
                    $sql = $query_make->update_query($query_make,"LogInTable",$attribute,$value,$condition_col,$condtion_val);
                    $result = $main_object->exeute_query($main_object,$sql);
                    if($result) {
                        echo "successful";
                    }
                    else {
                        echo "not successful";
                    }
                }
                else {
                    echo "not successful";
                }
            }
            else {
                echo "not succesful";
            }

        }

        //function to delete complete research group 
        function delete_complete_research_group($main_object,$value){
            //delete 1
            //from log in table
            $main_object->research_group=$value;
            $query_make = new Query_Make();
            $attribute = array("research_group");
            $value = array($main_object->research_group);
            $sql = $query_make->delete_query($query_make,"LogInTable",$attribute,$value);
            $result = $main_object->exeute_query($main_object,$sql);
            if($result) {
                echo "delete 1 done ";
                //from supervisor Table 
                $attribute = array("research_group");
                $value = array($main_object->research_group);
                $sql = $query_make->delete_query($query_make,"Supervisor",$attribute,$value);
                $result = $main_object->exeute_query($main_object,$sql);
                if($result) {
                    echo "delete 2 done ";
                    //Thesis Group Info Table 
                    $attribute = array("research_group");
                    $value = array($main_object->research_group);
                    $sql = $query_make->delete_query($query_make,"ThesisGroupInfo",$attribute,$value);
                    $result = $main_object->exeute_query($main_object,$sql);
                    if($result) {
                        echo "delete 3 done ";
                        //StudentInformation Table 
                        $attribute = array("research_group");
                        $value = array($main_object->research_group);
                        $sql = $query_make->delete_query($query_make,"StudentInformation",$attribute,$value);
                        $result = $main_object->exeute_query($main_object,$sql);
                        if($result) {
                            echo "delete 4 done";
                            //ReseachGroupInfo Table 
                            $attribute = array("name");
                            $value = array($main_object->research_group);
                            $sql = $query_make->delete_query($query_make,"ResearchGroupInfo",$attribute,$value);
                            $result = $main_object->exeute_query($main_object,$sql);

                            if($result) {
                                echo "successful";
                            }
                            else {
                                echo "not successful"; 
                            }
                        }
                        else {
                            echo "unsuccessful";
                        }

                    }
                    else {
                        echo "unsuccessful";
                    }

                }

            }
            else {
                echo "unsuccessful"; 
            }
        }

    }

?>