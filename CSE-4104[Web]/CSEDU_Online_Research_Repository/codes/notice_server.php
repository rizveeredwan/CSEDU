<?php
    /*A php file to deal with notice section*/
    class Notice{
        function bring_data($main_object){
            $result = $main_object->bring_all_notice($main_object);
            $notice = ' ';
            while($row = mysqli_fetch_array($result)) {
                $notice = $row["details"];
            }
            $temp_array = $main_object->split_from_delemeter($notice,"^");
            $output = ' <div> ';
            $output .= '  <!--Table links --> ';
            $output .= '  <div style="margin-left:2% ; margin-right:2%;"> ';
            $output .= ' <table class="table table-responsive" style="color:black; background:white;" id="notice_table"> ';
            $output .= ' <thead></thead> ';
            $output .= '  <tbody> ';

            for($i=0;$i<sizeof($temp_array);$i=$i+1) {
                $val = $i+1;
                $output .= ' <tr id="row_'.$val.'"> ';
                $output .= '<td id="row_num_'.$val.'"> '.$val."." .'</td>';
                $output .= '<td id="row_value_'.$val.'"> '.$temp_array[$i] .'</td>';
                $output .= ' <td><button type="button" class="btn btn-default btn-danger delete" id="delete_'.$val.'">Delete</button></td>';
                $output .= '</tr> ';
            }
            
            $output .= '   </tbody>';
            $output .= '  </table> ';
            $output .= '<div id="notice_counter" style="color:white;">'.sizeof($temp_array).'</div>';
            $output .= '  </div> ';
            $output .= '</div>'; 

            echo $output; 
        }

        function bring_all_notice($main_object){
            $query_make = new Query_Make();
		    $sql = $query_make->select_query_general($query_make,"Notice","","");
            $result = $main_object->exeute_query($main_object,$sql);
		    return $result;
        }
        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }
        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }

        function update($main_object,$value){
           $query_make = new Query_Make();
           $attrubutes = array("details");
           $values = array($value);
           $condition_col = array("id");
           $condition_val = array("1");
           $sql = $query_make->update_query($query_make,"Notice",$attrubutes,$values,$condition_col,$condition_val);
           
           $result = $main_object->exeute_query($main_object,$sql);
           if($result) {
               echo "successful";
           }
           else {
               echo "not successful"; 
           }
        }


    }
?>