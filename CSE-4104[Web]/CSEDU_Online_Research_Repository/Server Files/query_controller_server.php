<?php

    include "query_supervisor_server.php";
    include "query_project_thesis_server.php";
    include "query_research_group_server.php"; 

    class Query_Controller{

        function work($main_object,$type,$value){
            if($type == "supervisor") {
                $object = new Query_Supervisor();
                $object->complete_query($object,$value);
            }
            if($type == "project_thesis") {
                $object = new Query_Project_Thesis();
                $object->complete_query($object,$value);
            }
            if($type == "research_group") {
                $object = new Query_Research_Group();
                $object->complete_query($object,$value);
            }
        }
    }

?>