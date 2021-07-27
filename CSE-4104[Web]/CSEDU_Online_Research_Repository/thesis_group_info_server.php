<?php
    /*This page is used to control thesis group information
      using ThesisGroupInfo
    */
    
    class Thesis_Group_Info{
        protected $account;
        protected $research_group;
        protected $supervisor;
        protected $thesis_title;

        function insert_into_table($main_object,$values){
            $ok = $main_object->check_session($main_object);
            if($ok) {
                //can be added into table
                //debug: echo $values." yes\n ";
                $arr = $main_object->split_from_delemeter($values,"^");
                $main_object->thesis_title = $arr[0];
                $main_object->supervisor = $arr[1];
                $session = $arr[2]; //thesis name^supervisor name^year^...
                $view = $arr[3]; //thesis view open or notc
                //name^roll^session^email^phone
                
                //student code: st_research group name_tot thesis count
                //thesis code format: TH_research group name_total thesis number_research group thesis count_supervisor's thesis count
                
                 //first need to count total thesis number
                 $total_thesis_count=0;
                 $total_thesis_count = $main_object->count_total_thesis_number($main_object);
                 $total_thesis_count=$total_thesis_count+1;
                 //second this research groups thesis count 
                 $research_group_thesis_count = 0;
                 $research_group_thesis_count = $main_object-> count_research_group_thesis_number($main_object);
                 $research_group_thesis_count = $research_group_thesis_count + 1;
                 //count supervisor's thesis count
                 $sup_thesis_count = 0;
                 $sup_thesis_count = $main_object->count_sup_thesis_number($main_object,$main_object->supervisor);
                 $sup_thesis_count = $sup_thesis_count + 1;
                 //research group short name
                 $short_name = $main_object->find_group_name_short_form($main_object,$main_object->research_group);
                 
                 //generated thesis code
                 $thesis_code = "TH".$short_name.$total_thesis_count.$research_group_thesis_count.$sup_thesis_count;
                 //THGNR753
                 $student_code = "ST".$short_name.$total_thesis_count.$sup_thesis_count.$research_group_thesis_count;
                 //STGNR753_Roll numbers
                 
                 //need to check if two save thesis_code exists or not
                 $extra_add = $main_object->check_repeat($main_object,$thesis_code);
                 if($extra_add == 0) {
                     //everything is ok 
                 }
                 else {
                     $extra_add = $extra_add + 1;
                     $thesis_code = $thesis_code."*".$extra_add;
                     $student_code = $student_code.'*'.$extra_add;
                 }

                 $end_flag = 0;
                 $i=4;
                 $name='';
                 $roll='';
                 $email='';
                 $program='';
                 while($end_flag==0){
                    //name
                    if($i>=sizeof($arr)){
                        $name .='';
                        $end_flag=1;
                    }
                    else {
                        $name .= $arr[$i]."^";
                    }
                    $i=$i+1;
                    //roll
                    if($i>=sizeof($arr)){
                        $roll .='';
                        $end_flag=1;
                    }
                    else {
                        $roll .= $arr[$i]."^";
                    }
                    $i=$i+1;
                    //email
                     if($i>=sizeof($arr)){
                        $email .='';
                        $end_flag=1;
                    }
                    else {
                        $email .= $arr[$i]."^";
                    }
                    $i=$i+1;
                    //program
                     if($i>=sizeof($arr)){
                        $program .='';
                        $end_flag=1;
                    }
                    else {
                        $program .= $arr[$i]."^";
                    }
                    $i=$i+1;
                 }
                 //debug: echo "name = ".$name."\n";
                 //debug: echo "roll = ".$roll."\n";
                 //debug: echo "session = ".$session."\n";
                 //debug: echo "email = ".$email."\n";
                 //debug: echo "program = ".$program."\n";

                 //Now need to insert into table
                 //first insert into ThesisGroupInfo
                 $sql = $main_object->insert_into_thesis_group_info($main_object,$thesis_code,$student_code,$view);
                 $result = $main_object->execute_query($main_object,$sql);
                 if($result){
                    $sql = $main_object->insert_into_student_information($main_object,$name,$roll,$session,$program,$thesis_code,$email,$student_code,$view);
                    $result = $main_object->execute_query($main_object,$sql);
                    if($result){
                        echo "successful"."^".$thesis_code."^".$student_code."^New Thesis created.";
                    }
                    else {
                        echo "unsuccessful";
                    }
                 }
                 else {
                     echo "unsuccessful";
                 }
            }
            else {
                echo "Log In as Manager First";
            }
        }
        function check_session($main_object){
            if(isset($_SESSION["account"]) && isset($_SESSION["research_group"])){
                //someone is logged in
                if($_SESSION["account"] == "Manager") {
                    $main_object->account = $_SESSION["account"];
                    $main_object->research_group = $_SESSION["research_group"];
                    return true;
                }
                return false;
            }
            return false;
        }

        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }
        function count_total_thesis_number($main_object){
            $query_make = new Query_Make();
            $sql = $query_make->select_query_general($query_make,"ThesisGroupInfo","","");
            $result = $main_object->execute_query($main_object,$sql);
            $count = $main_object->count_row_number_in_query_result($result);
            return $count; 
        }
        function execute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql);
            if($result){
                return $result;
            }
            else {
                echo "Error Found while executing query In ThesisGroupInfo";
            }
        }
        function count_row_number_in_query_result($result){
            $count = 0;
            while($row=mysqli_fetch_array($result)){
                $count=$count+1;
            }
            return $count;
        }
        function count_research_group_thesis_number($main_object){
            $query_make = new Query_Make();
            $attributes = array("research_group");
            $values = array( $main_object->research_group);
            $sql = $query_make->conditional_select($query_make,"ThesisGroupInfo",$attributes,$values);
            $result = $main_object->execute_query($main_object,$sql);
            $count = $main_object->count_row_number_in_query_result($result);
            return $count;
        }
        
        function count_sup_thesis_number($main_object,$parameter){
            //parameter is supervisor name
            $query_make = new Query_Make();
            $attributes = array("supervisor");
            $values = array($parameter);
            $sql = $query_make->conditional_select($query_make,"ThesisGroupInfo",$attributes,$values);
            $result = $main_object->execute_query($main_object,$sql);
            $count = $main_object->count_row_number_in_query_result($result);
            return $count;
        }
        function find_group_name_short_form($main_object,$value){
            $temp = $main_object->split_from_delemeter($value," ");
            $res='';
            for($i=0;$i<sizeof($temp);$i=$i+1){
                $res .=$temp[$i][0];
            }
            return $res;
        }
        function insert_into_thesis_group_info($main_object,$thesis_code,$group_id,$thesis_view){
            //research_group supervisor thesis_title thesis_code group_id
            //group_id = student_id
            $query_make = new Query_Make();
            $attributes = array("research_group","supervisor","thesis_title","thesis_code","group_id","thesis_view");
            $values = array($main_object->research_group,$main_object->supervisor,$main_object->thesis_title,$thesis_code,$group_id,$thesis_view);
            $sql = $query_make->insertion_query($query_make,"ThesisGroupInfo",$attributes,$values);
            return $sql;
        }

        function insert_into_student_information($main_object,$name,$roll,$session,$program,$thesis_code,$email, $student_code,$thesis_view){
            //name roll session program thesis_code supervisor research group email group_id
            $query_make = new Query_Make();
            $attributes = array("name","roll","session","program","thesis_code","supervisor","research_group","email","group_id","thesis_view");
            $values = array($name,$roll,$session,$program,$thesis_code,$main_object->supervisor,$main_object->research_group,$email,$student_code,$thesis_view);
            $sql = $query_make->insertion_query($query_make,"StudentInformation",$attributes,$values);
            return $sql;
        }

        function check_repeat($main_object,$thesis_code){
            $query_make = new Query_Make();
            $attributes = array("thesis_code");
            $values = array($thesis_code);
            $sql = $query_make->conditional_select($query_make,"ThesisGroupInfo",$attributes,$values);
            $result = $main_object->execute_query($main_object,$sql);
            if($result) {
                $val = $main_object->count_row_number_in_query_result($result);
                return $val;
            }
        }

        

    }

?>