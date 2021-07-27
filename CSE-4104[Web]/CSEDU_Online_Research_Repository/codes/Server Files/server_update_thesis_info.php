<?php
    /*Purpose of this file is to update ThesisInfoTable
        and StudentInformation
    */
    session_start();

    /*value receive*/
    $data = $_POST["data"]; //thesis_name^

    include "general_query_make_server.php";
    include "general_query_execute_server.php";

    class Update_Thesis_Info_Student_Information{
        protected $dat;
        protected $code_to_run;
        protected $thesis_name;
        protected $supervisor_name;
        protected $research_group;
        protected $year ;
        protected $view;
        function work($main_object,$dat){
            $main_object->dat = $dat; 

            /*debug: echo "came data ". $dat. "\n"; */
            $res = $main_object->split_from_delemeter($main_object->dat,'^');
            //thesis_name
            $main_object->thesis_name = $res[0]; 
            //supervisor name
            $main_object->supervisor_name = $res[1];    
            //research_group
            $main_object->research_group = $res[2];
            //year
            $main_object->year = $res[3];  
            //view 
            $main_object->view = $res[4];  
            
            /*debug: echo $res[5]." ",$res[6]." ".$res[7]." ".$res[8]." ".$res[9]; */
            //extract student information
            $name = '';
            $roll = '';
            $program = '';
            $email = '';
            
            $idx=5;
           
            while(true){
                $ok=false;
                if($idx>=sizeof($res)) {
                    //shesh 
                    $name .=""."^";
                }
                else {
                    $name .=$res[$idx]."^"; 
                    $ok=true;
                }
                $idx=$idx+1;
                if($idx>=sizeof($res)) {
                    //shesh 
                    $roll .=""."^";
                }
                else {
                    $roll .=$res[$idx]."^"; 
                    $ok=true;
                }
                $idx=$idx+1;
                if($idx>=sizeof($res)) {
                    //shesh 
                    $program .=""."^";
                }
                else {
                    $program .=$res[$idx]."^"; 
                    $ok=true;
                }
                $idx=$idx+1;
                if($idx>=sizeof($res)) {
                    //shesh 
                    $email .=""."^";
                }
                else {
                    $email .=$res[$idx]."^"; 
                    $ok=true;
                }
                $idx=$idx+1;
                /*debug: echo $name; */
                if($idx>=sizeof($res)) {
                    break;
                }
                if(!$ok) break;
            }
            if(isset($_SESSION["page_name"])) {
                $page_name = $_SESSION["page_name"];
                //debug: echo "page_name = ".$page_name;
                if($page_name == "student_account.php") {
                    if(isset($_SESSION["account"])){
                        if($_SESSION["account"] == "Student"){
                            if(isset($_SESSION["thesis_code"])){
                                $main_object->code_to_run = $_SESSION["thesis_code"];
                                $main_object->update_data($main_object,$name,$roll,$program,$email);
                            }
                        }
                    }
                }
                else if(($page_name == "upload.php") || ($page_name == "thesis_details.php")) {
                    //debug: echo "page name ".$page_name;
                    if(isset($_SESSION["account"])){
                        if(isset($_SESSION["running_thesis_code"])){
                            $main_object->code_to_run = $_SESSION["running_thesis_code"];
                            $main_object->update_data($main_object,$name,$roll,$program,$email);
                        }
                    }
                }
                
            }
           
        }

        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }

        function update_data($main_object,$name,$roll,$program,$email){
           //first update ThesisInfoTable
            $sql = $main_object->update_thesis_group_info($main_object,$name,$roll,$program,$email);
            $result = $main_object->exeute_query($main_object,$sql);
            if($result) {
               $sql = $main_object->update_student_information($main_object,$name,$roll,$program,$email);
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
        function update_thesis_group_info($main_object,$name,$roll,$program,$email){
            $query_make = new Query_Make();
            $attributes = array("research_group","supervisor","thesis_title","thesis_code","thesis_view");
            $values = array($main_object->research_group,$main_object->supervisor_name,$main_object->thesis_name,$main_object->code_to_run,$main_object->view);
            $condition_col = array("thesis_code");
            $condition_val = array($main_object->code_to_run);
            $sql = $query_make->update_query($query_make,"ThesisGroupInfo",$attributes,$values,$condition_col,$condition_val);
            return $sql;
        }

        function update_student_information($main_object,$name,$roll,$program,$email){
            $query_make = new Query_Make();
            $attributes = array("name","roll","session","program","thesis_code","supervisor","research_group","email","thesis_view");
            $values = array($name,$roll,$main_object->year,$program,$main_object->code_to_run,$main_object->supervisor_name,$main_object->research_group,$email,$main_object->view);
            $condition_col = array("thesis_code");
            $condition_val = array($main_object->code_to_run);
            $sql = $query_make->update_query($query_make,"StudentInformation",$attributes,$values,$condition_col,$condition_val);
            return $sql;
        }

        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }
       

    }
/*work flow*/
$main_object = new Update_Thesis_Info_Student_Information();
$main_object->work($main_object,$data);


?>
