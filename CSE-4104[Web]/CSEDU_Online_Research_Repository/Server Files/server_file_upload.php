<?php

    session_start();

    /*Header Files*/
    include "general_query_make_server.php";
    include "general_query_execute_server.php";

    /*Function of this file is to upload file into server*/
    $file_name = $_FILES["file"]["name"]; //name of the file 
    $file_temp_loc = $_FILES["file"]["tmp_name"]; //file in the temporary folder
    $file_size = $_FILES["file"]["size"]; //size of the file 
    $file_type = $_FILES["file"]["type"]; //type of the file
    $file_error_msg = $_FILES["file"]["error"]; //size of the file

    if(!$file_temp_loc){
        echo "File couldn't be found.\n";
    }
    else {

        $file_upload = new File_Upload(); 
        $name = $file_upload->make_file_name($file_upload,$file_name);
        if($name) {
            if(move_uploaded_file($file_temp_loc,$name)){
                echo $name; //returning uploaded files destination
            }
            else {
                echo "unsuccessful"; 
            }
        }
        else {
            echo "error name can't be found.\n"; 
        }
        
    }

    class File_Upload{

        protected $page_name;
        protected $code_to_run;
        protected $research_group;
        protected $name;
        function make_file_name($main_object,$file_nm){
            if(isset($_SESSION["page_name"])){
                $main_object->page_name = $_SESSION["page_name"];
                if($main_object->page_name=="student_account.php") {
                    //so have a thesis code here 
                    if(isset($_SESSION["thesis_code"])){
                        $main_object->code_to_run = $_SESSION["thesis_code"]; 
                        if(isset($_SESSION["research_group"])) {
                            $main_object->research_group = $_SESSION["research_group"]; 
                            //now need to have the file count of corresponding thesis_code
                            $sql = $main_object->make_query($main_object,"id",$main_object->code_to_run);
                            $result = $main_object->exeute_query($main_object,$sql);
                            $links = $main_object->bring_single_value($result,"id");
                            $link = $main_object->split_from_delemeter($links,"^");
                            $counter = sizeof($link); 
                            $counter = $counter + 1;
                            $name = "files/".$main_object->code_to_run."`".$counter."`".$file_nm;
                            return $name; 
                        }
                    }
                }
                else if($main_object->page_name == "research_group_account.php"){
                    if(isset($_SESSION["account"]) && isset($_SESSION["research_group"])) {
                        //someone is logged in
                        if($_SESSION["account"] == "Manager" && $_SESSION["research_group"] != "Others") {
                            $main_object->research_group = $_SESSION["research_group"];
                            //Bioinformatics`1`csedu.jpg
                            $sql = $main_object->make_query($main_object,"id",$main_object->research_group);
                            $result = $main_object->exeute_query($main_object,$sql);
                            $links = $main_object->bring_single_value($result,"id");
                            $link = $main_object->split_from_delemeter($links,"^");
                            $counter = sizeof($link); 
                            $counter = $counter + 1;
                            $name = "files/".$main_object->research_group."`".$counter."`".$file_nm;
                            return $name;
                        }
                    }
                }
                else if(($main_object->page_name == "upload.php") || ($main_object->page_name == "thesis_details.php")){
                    //so we have a running thesis code here
                    //debug: echo "came page name ".$main_object->page_name;
                    if(isset($_SESSION["running_thesis_code"])) {
                       
                        $main_object->code_to_run = $_SESSION["running_thesis_code"];
                         //debug: echo "running thesis code ". $main_object->code_to_run;
                        //now file will be uploaded under running thesis code
                        $sql = $main_object->make_query($main_object,"id",$main_object->code_to_run);
                        $result = $main_object->exeute_query($main_object,$sql);
                        $links = $main_object->bring_single_value($result,"id");
                        $link = $main_object->split_from_delemeter($links,"^");
                        $counter = sizeof($link); 
                        $counter = $counter + 1;
                        $name = "files/".$main_object->code_to_run."`".$counter."`".$file_nm;
                        return $name; 
                    }
                }
                
            }
        }
        function make_query($main_object,$attr,$value){
            $query_make = new Query_Make();
            $attribute = array($attr);
            $val = array($value);
            $sql = $query_make->conditional_select($query_make,"Files",$attribute,$val);
            return $sql;
        }
        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }
        function bring_single_value($result,$attribute){
            /*debug echo "man = ".$attribute." "; */
            $value='';
            while($row=mysqli_fetch_array($result)){
                $value = $row[$attribute]; 
            }
            /*debug: echo $value; */
            return $value; 
        }
        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }
        
    }

?>
