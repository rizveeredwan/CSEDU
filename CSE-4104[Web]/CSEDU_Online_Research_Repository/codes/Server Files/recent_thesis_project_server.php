<?php

    //purpose of this file is to bring recent thesis and projects 

    class Thesis_Description{
        public $thesis_code;
        public $research_group;
        public $supervisor;
        public $student;
        public $thesis_title;
    }

    class Recent_Thesis_Project{

        function work($main_object){
            $result = $main_object->bring_all_thesis($main_object);
            //now save into array all the thesis 
            $temp_array = array();
            $idx = 0;
            while($row = mysqli_fetch_array($result)) {
                $object = new Thesis_Description();
                $object->thesis_code = $row["thesis_code"];
                $object->research_group = $row["research_group"];
                $object->supervisor = $row["supervisor"];
                $object->student = $row["name"];
                $temp_array[$idx] = $object;
                $idx=$idx+1; 
            }

            $temp_array = $main_object->take_the_current_thesis_project($main_object,$temp_array);
            for($i=0;$i<sizeof($temp_array);$i=$i+1) {
                $result = $main_object->fetch_title($main_object,$temp_array[$i]->thesis_code);
                $temp_array[$i]->thesis_title = $main_object->bring_single_value($main_object,$result,"thesis_title");
            }

            $main_object->show_data($main_object,$temp_array);
        
        }

        function bring_all_thesis($main_object) {
            $query_make = new Query_Make();
            $sql = $query_make->select_query_general($query_make,"StudentInformation","","");
            $result = $main_object->exeute_query($main_object,$sql);
            return $result;
        }

        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }

        function take_the_current_thesis_project($main_object,$temp_array) {
            $size = min(sizeof($temp_array),5);
            $result_arr = array();
            $idx = 0;
            for($i=0;$i<sizeof($temp_array);$i=$i+1) {
                $choice = rand(0,1);
                if($choice==1 && $idx<$size) {
                    $result_arr[$idx] = $temp_array[$i]; 
                    $idx=$idx+1;
                }
            }
            if($idx==0) {
                //nothing was selected 
                $result_arr[$idx] = $temp_array[0]; 
            }
            return $result_arr;
        }

        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }

        function fetch_title($main_object, $value)
	    {
		    $query_make = new Query_Make();
		    $attribute = array("thesis_code");
		    $attribute_value = array($value); 
		    $sql = $query_make->conditional_select($query_make,"ThesisGroupInfo",$attribute,$attribute_value);
            $result = $main_object->exeute_query($main_object,$sql);
		    return $result;
        }
        function bring_single_value($main_object,$result,$attr) {
            $value = '';
            while($row = mysqli_fetch_array($result)) {
                $value = $row[$attr];
            }
            return $value;
        }        

        function show_data($main_object,$temp_array){
            $output = ' ';
            $output .= '<div>';
            $output .= '  <!--Table links --> ';
            $output .= '   <div style="margin-left:2% ; margin-right:2%;"> ';
            $output .= '  <table class="table table-responsive" style="color:black; background:white;"> ';
            $output .= '  <thead></thead>';
            $output .= '  <tbody> ';
            for($i=0;$i<sizeof($temp_array);$i=$i+1) {
                $output .= ' <tr class="recent_thesis_project" id="'.$temp_array[$i]->thesis_code.'"> ';
                $val=$i+1;
                $output .= '<td>'.$val.'.</td>';
                $output .= '<td><a href="">'.$main_object->make_title($main_object,$temp_array[$i]).'</a></td>'; 
                $output .= '</tr>';

            }
            $output .= ' </tbody> ';
            $output .= '  </table>';
            $output .= '</div>';

            $output .= '</div>';
            echo $output;
        }

        function make_title($main_object,$object) {
            $output = ' ';
            if($object->thesis_title == '') {
                $output .= 'An untitled Project by ';
            }
            else {
                $output .= $object->thesis_title." by ";
            }
            $output .= ' '.$object->supervisor." ";
            $name = $main_object->split_from_delemeter($object->student,"^");
            for($i=0;$i<sizeof($name);$i=$i+1) {
                if($name[$i] != "") {
                    $output .= ','.$name[$i];
                }
            }
            return $output;
        }

    }

?>