<?php

/*Files to be added*/
include "general_query_execute_server.php"; //query execute
include "general_query_make_server.php"; //query make 

/*One File One View*/
include "make_log_in_form_server.php";
include "make_thesis_detail_section_server.php";
include "make_admin_account_server.php";
include "make_search_server.php";




/*This page basically control views requested from sessio_variable_server.php make function*/
class View_Controller{

    function take_decision($view_controller,$object_to_make){
        /*This call will make log in form*/
       if($object_to_make == "login.php"){
           $main_class = new Make_Log_In_Form();
           $main_class->start_view($main_class);
       }
       if($object_to_make=="student_account.php"){
            $main_class = new Make_Thesis_Detail_Section();
            $main_class->start_view($main_class,"thesis_code");
       }
        if($object_to_make=="upload.php"){
            $main_class = new Make_Thesis_Detail_Section();
            $main_class->start_view($main_class,"running_thesis_code");
        }
        if($object_to_make=="thesis_details.php"){
            $main_class = new Make_Thesis_Detail_Section();
            $main_class->start_view($main_class,"running_thesis_code");
        }
        if($object_to_make=="admin_account.php"){
            $main_class = new Make_Admin_Account();
            $main_class->start_view($main_class);
        }
        if($object_to_make == "existing_research_group"){
            $main_class = new Make_Admin_Account();
            $main_class->show_existing_reasearch_group($main_class);
        }
        if($object_to_make == "search.php"){
            //debug: echo "hu hu"; 
            $main_class = new Make_Search();
            $main_class->make_page($main_class);
        }

      

       


    }

}




?>
