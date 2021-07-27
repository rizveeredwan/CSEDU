<?php
/*session variable*/
session_start();

/*This file contains about session variable and works for it */
$operation = $_POST["operation"]; 
/* Operation types: set session variable
                    get session variable
                    make page with session variablae
*/
$variable = $_POST["variable"];
$value = $_POST["value"];

/*include section*/
include "view_controller_server.php";
include "thesis_group_info_server.php";
include "delete_thesis_server.php";
include "admin_account_controller_server.php"; 
include "query_controller_server.php";
include "recent_thesis_project_server.php";
include "notice_server.php";
include "show_research_group_name_option.php";
include "show_research_group_files_server.php";
include "other_facility_server.php"; 
include "research_group_account_server.php";
include "research_group_account_button_event_server.php";

/* debug: echo $operation." ".$variable." ".$value; */

/*Object Oriented Part*/
class Session_Variable_Controller{

    function set_session_variables($session_variables,$attributs,$values){
        $attr = $session_variables->split_from_delemeter($attributs,"^");
        $vals = $session_variables->split_from_delemeter($values,"^");

        for($i=0;$i<sizeof($attr); $i = $i+1){
            $_SESSION[$attr[$i]] = $vals[$i];
            /*echo "session variable set ".$attr[$i]." ". $_SESSION[$attr[$i]];*/
        }

        echo "successful"; 
    }

    function make_page($session_variables,$object_to_make){
        $view_controller = new View_Controller();
        $view_controller->take_decision($view_controller,$object_to_make);
    }

    function split_from_delemeter($string,$delim){
        $temp_array = explode($delim,$string);
        return $temp_array;
    }

    /*Function to return desired session variable*/
    function get_session_variable_value($session_variables,$attributs,$values){
        $attr = $session_variables->split_from_delemeter($attributs,"^");

        $final_result = '';
        if(sizeof($attr) == 1) {
            //single thing is wanted
            for($i=0;$i<sizeof($attr); $i = $i+1){
                if(isset($_SESSION[$attr[$i]])) {
                    $final_result .= $_SESSION[$attr[$i]];
                }
            }
        }
        else {
            //multiple things 
            for($i=0;$i<sizeof($attr); $i = $i+1){
                if(isset($_SESSION[$attr[$i]])) {
                    $final_result .= $_SESSION[$attr[$i]]."^";
                }
                else {
                    $final_result .= ""."^";
                }
            }
        }
        echo $final_result;
    }

    /*Function to add into table*/
    function add_into_table($session_variables,$attributs,$values){
        if($attributs == "add_into_thesis_group_info_table") {
            /*will add into ThesisGroupInfo table*/
            //thesis_name^supervisor^data
            $thesis_group_info = new Thesis_Group_Info();
            $thesis_group_info->insert_into_table($thesis_group_info,$values);
        }
        if($attributs == "add_into_teacher_table") {
            /*will insert into TeacherTable*/
            $admin_account = new Admin_Account();
            $admin_account->add_teacher($admin_account,$values);
        }
        if($attributs == "new_supervisor_in_research_group") {
            /*will insert into supervisor table for a research group*/
            $object = new Research_Group_Button();
            $object->add_new_supervisor($object,$values); 
        }

    }
    /*function to delete from table*/
    function delete_from_table($session_variables,$attributs,$values){
        if($attributs == "thesis") {
            //one thesis needs to be deleted 
            $delete_thesis = new Delete_Thesis();
            $delete_thesis->work($delete_thesis);
        }
        if($attributs == "delete_from_teacher_table") {
             /*will delete from TeacherTable*/
             $admin_account = new Admin_Account();
             $admin_account->delete_teacher($admin_account,$values);
        }
        if($attributs == "delete_supervisor") {
            $object = new Research_Group_Button();
            $object->remove_supervisor($object,$values);
        }
        if($attributs == "complete_research_group") {
            $object = new Research_Group_Button();
            $object->delete_complete_research_group($object,$values);
        }
    }
    /*function to update table*/
    function update_table($session_variables,$attributs,$values){
        if($attributs == "admin_account"){
            $admin_account = new Admin_Account();
            $admin_account->update_admin($admin_account,$values);   
        }
        if($attributs == "notice"){
            $object = new Notice();
            $object->update($object,$values);   
        }
        if($attributs == "research_group_account"){
            $object = new Research_Group_Button();
            $object->update_account($object,$values,$values);   
        }
    }
    /*function to make query*/
    function query($session_variables,$attributs,$values){
        $object = new Query_Controller();
        $object->work($object,$attributs,$values);
    }
    /*function to bring some data and append*/
    function bring($session_variables,$attributs,$values){
        if($attributs == "recent_thesis_project") {
            $object = new Recent_Thesis_Project();
            $object->work($object);
        }
        if($attributs == "notice") {
            $object = new Notice();
            $object->bring_data($object);
        }
        if($attributs == "research_group_name_option") {
            $object = new Research_Group_Name_Option();
            $object->work($object);
        }
        if($attributs == "research_group_files_after_search") {
            $object = new Research_Group_Files();
            $object->work($object,$values);
        }
        if($attributs == "google_dropbox_git_facebook") {
            $object = new Other_Facility();
            $object->goto_other_website($object,$values);
        }
        if($attributs == "mail_system") {
            $object = new Other_Facility();
            $object->bring_mail_system($object,$values);
        }
        if($attributs == "research_group_account_metadata"){
            $main_class = new Research_Group_Account();
            $main_class->show_page($main_class);
        }
        if($attributs == "supervisor_section"){
            $main_class = new Research_Group_Account();
            $main_class->show_supervisor_info($main_class);
        }
        if($attributs == "create_thesis_section"){
            $main_class = new Research_Group_Account();
            $main_class->show_create_thesis($main_class);
        }
        if($attributs == "group_mail_system"){
            $object = new Other_Facility();
            $object->bring_group_mail_system($object);
        }
       
       
    }
}

/*debug
$operation = "set";
$variable = "page_name^vugi";
$value ="login.html^choltese"; */

/*Work Flow*/
$session_variables = new Session_Variable_Controller();
if($operation == "set"){
    /*set variables values */
    $session_variables->set_session_variables($session_variables,$variable,$value);
}
if($operation == "make"){
    /*Request to make a page*/
    /*make login.html*/
    $session_variables->make_page($session_variables,$variable);
}
if($operation == "get"){
    $session_variables->get_session_variable_value($session_variables,$variable,$value);
}
if($operation == "add") {
    /*Function to add into some table*/
    $session_variables->add_into_table($session_variables,$variable,$value);
}
if($operation == "delete") {
    /*Function to delete from table*/
    $session_variables->delete_from_table($session_variables,$variable,$value);
}

if($operation == "update"){
    /*Function to update table*/
    $session_variables->update_table($session_variables,$variable,$value);
}

if($operation == "query") {
    /*Function to make query*/
    $session_variables->query($session_variables,$variable,$value);
}

if($operation == "bring"){
    /*Function to bring something*/
    $session_variables->bring($session_variables,$variable,$value);

}



?>