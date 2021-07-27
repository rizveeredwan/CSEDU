<?php
/*The Purpose of this file is to delete thesis*/

class Delete_Thesis{

    protected $code_to_run;
    function work($main_object){
        if(isset($_SESSION["page_name"])){
            $page_name = $_SESSION["page_name"];
            if($page_name == "student_account.php") {
                if(isset($_SESSION["thesis_code"])){
                    $main_object->code_to_run = $_SESSION["thesis_code"];
                    $result = $main_object->delete_thesis_from_table($main_object);
                    if($result == "successful") {
                        $result = $main_object->delete_from_studentinfo($main_object);
                        if($result) {
                            echo  "deleted";
                        }
                    }
                }
            }
            if($page_name == "upload.php" || $page_name == "thesis_details.php") {
                if(isset($_SESSION["running_thesis_code"])){
                    $main_object->code_to_run = $_SESSION["running_thesis_code"];
                    $result = $main_object->delete_thesis_from_table($main_object);
                    /*debug: echo "result " .$result; */
                    if($result == "successful") {
                        /*debug: echo "main object pau nai ". $main_object->code_to_run;*/
                        $result = $main_object->delete_from_studentinfo($main_object);
                        if($result == "successful") {
                            echo  "deleted";
                        }
                   }
                }
            }
        }
    }

    function delete_thesis_from_table($main_object){
        $query_make = new Query_Make();
        $attribute = array("thesis_code");
        $value = array($main_object->code_to_run);
        $sql = $query_make->delete_query($query_make,"ThesisGroupInfo",$attribute,$value);
        $result = $main_object->execute_query($main_object,$sql);
        return $result;
    }

    function execute_query($main_object,$sql){
        $sql_query = new SQL_Query();
        $result = $sql_query->query_execute_return_result($sql_query,$sql);
        if($result) {
            return "successful";
        }
        else {
            return "unsuccessful";
        }
    }
    function delete_from_studentinfo($main_object){
        /*debug: echo "kichu hoi ";*/
        $query_make = new Query_Make();
        $attribute = array("thesis_code");
        $value = array($main_object->code_to_run);
        $sql = $query_make->delete_query($query_make,"StudentInformation",$attribute,$value);
        $result = $main_object->execute_query($main_object,$sql);
        return $result;
    }
}

?>
