<?php

class Query_Project_Thesis
{
    function complete_query($main_object,$value)
	{		
        
            $output = '<div>
            <div class="table-design">
                <!--Searched Projects/Thesis -->
            <div class="simple-form">
            
            <!-- heading decoration -->
            <div class="table-section-heading-decoration">
                <h2>Search Result </h2>
            </div>';
		
		
            $temp_array = $main_object->split_from_delemeter($value, '^');
            $temp_array = $main_object->to_make_lower($main_object,$temp_array);
			//research_group^supervisor^year_from^to^thesis_title^program^student
			
			$result = $main_object->bring_attr($main_object);
			
			while($row = mysqli_fetch_array($result))
			{
                //research group
                if($temp_array[0] != "") {
					$val2 = strtolower($row["research_group"]);
					if(strpos($val2,$temp_array[0]) !== false){}
                    else {
						continue;
					}
                }
                //supervisor
                if($temp_array[1] != "") {
					$val2 = strtolower($row["supervisor"]);
                    if(strpos($val2,$temp_array[1]) !== false){}
					else {
						continue;
					}
                }

                //year from 
				if($temp_array[2] != "")
				{
					//debug:echo $row["session"]." ".$temp_array[2]; 
					if($row["session"] < $temp_array[2])continue;
                }
                //year to 
				if($temp_array[3] != "")
				{
					if($row["session"] > $temp_array[3]) continue;
				}
				
				$result1 = $main_object->fetch_title($main_object, $row["thesis_code"]);
                
                //thesis title 
				$thesis_title = "";
				while($row1 = mysqli_fetch_array($result1))
				{
					$thesis_title = $row1["thesis_title"];
				}
				
				if($temp_array[4] != "")
				{
                    $val = strtolower($temp_array[4]);
                    $val2 = strtolower($thesis_title);
					if(strpos($val2,$val) !== false ) {}
					else continue;
				}
				
				if($temp_array[5] != "")
				{
					$flag = 0;
					$temp1_array = split_from_delemeter($row["program"], '^');
					
					for($i = 0; $i<size_of($temp1_array); $i=$i+1)
					{
                        $val = strtolower($temp_array[5]);
                        $val2 = strtolower($temp1_array[$i]);
						if(strpos($val2,$val) !== false) {
							$flag = 1;
							break;
						}	
						else
						{
							continue;
						}
					}
					
					if($flag==0)continue;
					
				}
				
				if($temp_array[6] != "")
				{
					$flag = 0;
					$temp2_array = $main_object->split_from_delemeter($row["name"], '^');
					
					for($i = 0; $i<sizeof($temp2_array); $i=$i+1)
					{
                        $val = strtolower($temp_array[6]);
						$val2 = strtolower($temp2_array[$i]); 
						//echo $val2." debug ".$val." size ".sizeof($val2)." ".sizeof($val);
                        if(strpos($val2,$val) !== false) {
							$flag = 1;
							break;
						}	
						else
						{
							continue;
						}
					}
					if($flag == 0) continue;
					
				}
				
				$output .= '<table class="table table-responsive table-bordered" style="background:white;">';
                
				$output .= '<!--Research Group -->
                <tr>
					<td style="width:25%;">Research Group</td>';
				$output .= '<td style="width:75%;">' .$row["research_group"].'</td>
                </tr>';
                    
                $output .= '<!--Supervisor-->
                <tr>
					<td>Supervisor</td>';
                $output .= '<td>'.$row["supervisor"].'</td>
                </tr>';
				
				$output .= '<!--Year-->
                <tr>
					<td>Year</td>';
                $output .= '<td>'.$row["session"].'</td>
                </tr>';
                
				$output .= '<!--Title-->
                <tr>
                    <td>Title</td>';
                $output .= '<td>'.$thesis_title.'</td>
                </tr>';
                
				$output .= '<!--Student-->
                <tr>
                    <td>Student</td>';
					
				//cat(name1, name2)
				$cat_name = "";
				$name_array = $main_object->split_from_delemeter($row["name"], '^');
				$cat_name .= $name_array[0];
					for($i = 1; $i<sizeof($name_array); $i=$i+1)
					{
                        if($name_array[$i] != "") {
						    $cat_name .= ',';
                            $cat_name .= $name_array[$i];
                        }
					}
				
                $output .= '<td>'.$cat_name.'</td>
                </tr>';
				
                $output .= '<!--Student-->
                <tr>
                    <td>Details</td>
                    <td style="color:blue;" class="view_details change_cursor" id="'.$row["thesis_code"].'">View</td>
                </tr>
            </table>';
			}
			
            $output .= '</div>
            </div>
    </div>';
	
	echo $output;
	
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
	
	function bring_attr($main_object)
	{
		$query_make = new Query_Make();
		$sql = $query_make->select_query_general($query_make,"StudentInformation","","");
        $result = $main_object->exeute_query($main_object,$sql);
		return $result;
	}
	
	function split_from_delemeter($string,$delim){
        $temp_array = explode($delim,$string);
        return $temp_array;
    }
	
	function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
    }

    function to_make_lower($main_object,$temp_arr){
        for($i=0;$i<sizeof($temp_arr);$i=$i+1){
            $temp_arr[$i] = strtolower($temp_arr[$i]);
        }
        return $temp_arr;
    }
}
?>
