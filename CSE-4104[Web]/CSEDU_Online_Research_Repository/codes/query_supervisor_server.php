<?php
 class Query_Supervisor
 {
	 function complete_query($main_object, $value)
	 {
		$output = '<div>';
		$output .= '<div class="table-design">
        	<!--One Supervisor-->
        		<div class="simple-form">
            		<!-- heading decoration -->
            	<div class="table-section-heading-decoration">
                	<h2>Searched Supervisor</h2>
            	</div>';
         
		$result = $main_object->bring_supervisor($main_object, $value);
		
		while($row = mysqli_fetch_array($result))
		{
			$output .= '<table class="table table-bordered table-responsive" style="background:white;">
                <thead></thead>
                <tbody>';
                    
			$output .= '<tr>
                        <td style="width:25%;">Name</td>';
			$output .= '<td width:75%;>'.$row['name'].'</td>
						</tr>';
            
			$output .= '<tr>
                        <td>Designation</td>';
			$output .= '<td>'.$row['designation'].'</td>
						</tr>';
                    
			$output .= '<tr>
                        <td>Email</td>';
			$output .= '<td>'.$row['email'].'</td>
						</tr>';
			
			$output .= '<tr>
                        <td>Phone</td>';
			$output .= '<td>'.$row['phone'].'</td>
						</tr>';
						
			$output .= '<tr>
                        <td>Portfolio</td>';
			$output .= '<td><a href="'.$row['portfolio'].'">'.$row['portfolio'].'</a></td>
						</tr>';
						
			$output .= '<tr>
                        <td>Current Status</td>';
			$output .= '<td>'.$row['status'].'</td>
						</tr>';
						
			$output .= '</tbody>
            </table>';
        
		}
		$output .= '</div>
    		</div>';
    		$output .= '</div>'; 
		
		
		echo $output;
	 }
	 
	 function bring_supervisor($main_object, $value)
	{
		$query_make = new Query_Make();
		$attribute_name = array("name");
		$attribute_value = array($value);
        	$sql = $query_make->conditional_select($query_make,"TeacherTable",$attribute_name,$attribute_value);
        	$result = $main_object->exeute_query($main_object,$sql);
		return $result;
	}
	
	function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }
 }
?>