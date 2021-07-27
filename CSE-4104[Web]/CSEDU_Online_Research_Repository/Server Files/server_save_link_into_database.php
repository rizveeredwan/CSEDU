<?php

    /*session start*/
    session_start();

    /*First save values*/
    $link = $_POST["link"];

    /*Header Files*/
    include "general_query_make_server.php";
    include "general_query_execute_server.php";
    
    class Link_Updata_In_Table{

        protected $link;
        protected $page_name;
        protected $view;
        protected $research_group;
        function start_work($main_object, $link){
            $main_object->link = $link;
            $main_object->page_name = "";
            $main_object->view = "";
            if(isset($_SESSION["page_name"])){
                $main_object->page_name = $_SESSION["page_name"];
            }
            if(isset($_SESSION["view"])){
                $main_object->view = $_SESSION["view"];
            }
            if(isset($_SESSION["research_group"])){
                $main_object->research_group = $_SESSION["research_group"];
            }
            if($main_object->page_name != "" && $main_object->view != "") {
                $main_object->work($main_object);
            }
        }
        function work($main_object){


            if($main_object->page_name == "student_account.php") {
                //student_account.html
                //work will be based on thesis_code 
                $code_to_run = "";
                if(isset($_SESSION["thesis_code"])) {
                    $code_to_run = $_SESSION["thesis_code"];
                }
                else {
                    echo "Log in as student first";
                    return; 
                }

                $query_make = new Query_Make();
                $attributes = array("id","research_group","link","view");
                $value = array($code_to_run,$main_object->research_group,$main_object->link,$main_object->view);
                $condition_col = array("id");
                $condition_val = array($code_to_run);
                $sql = $query_make->update_query($query_make,"Files",$attributes,$value,$condition_col,$condition_val);
                /*debug: echo $sql; */
                $result = $main_object->exeute_query($main_object,$sql);
                if($result) {
                    echo "successful";
                }
                else {
                    echo "unsuccessful";
                }
            }

            if(($main_object->page_name == "upload.php") ||($main_object->page_name == "thesis_details.php") ){
                $code_to_run = "";
                if(isset($_SESSION["running_thesis_code"])) {
                    $code_to_run = $_SESSION["running_thesis_code"];
                    $query_make = new Query_Make();
                    $attributes = array("id","link","view");
                    $value = array($code_to_run,$main_object->link,$main_object->view);
                    $condition_col = array("id");
                    $condition_val = array($code_to_run);
                    $sql = $query_make->update_query($query_make,"Files",$attributes,$value,$condition_col,$condition_val);
                    $result = $main_object->exeute_query($main_object,$sql);
                    if($result) {
                        echo "successful";
                    }
                    else {
                        echo "unsuccessful";
                    }
                }
                else {
                    echo "ambiguous thesis code";
                    return; 
                }
            }
            if($main_object->page_name == "research_group_account.php") {
                if(isset($_SESSION["research_group"]) && isset($_SESSION["account"])) {
                    if($_SESSION["research_group"] != "Others") {
                        //only managar can upload files 
                        $main_object->research_group = $_SESSION["research_group"];
                        $query_make = new Query_Make();
                        $attributes = array("id","research_group","link","view");
                        $value = array($main_object->research_group,$main_object->research_group,$main_object->link,$main_object->view);
                        $condition_col = array("id");
                        $condition_val = array($main_object->research_group);
                        $sql = $query_make->update_query($query_make,"Files",$attributes,$value,$condition_col,$condition_val);
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

        }
        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }
    }

    /*Work Flow section */
    $main_object = new Link_Updata_In_Table();
    $main_object->start_work($main_object,$link);

?>
