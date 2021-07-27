<?php

class Make_Search
{
	
	function make_page($main_object)
	{
		$output = ' <div> ';
		$output .= '<!--Search Query Part -->
						<div class="table-design">
						<!-- heading decoration -->
					    <div class="table-section-heading-decoration">
						    <h2>Search</h2>
					    </div>
		<!-- Search Box-->
        <!--Thesis/Project Search -->
        <div class="simple-form">
            <!--Research Group-->
            <div class="form-group">
                <label for="Research Group" id="research_group_label">Research Group</label>
                <input class="form-control" id="research_group" list="suggestion_research_group">
                <datalist id="suggestion_research_group" >';
				
		$result = $main_object->bring_research_groups($main_object);
				
		while($row = mysqli_fetch_array($result))
		{
				$output .= '<option>'.$row['name'].'</option>';
        }
        $output .= '<option>'.'Not Specific'.'</option>';
        //$output .= '<option>'.'<input type="text" placeholder="research group">'.'</option>';
        
        $output .=   '</datalist>
            </div>';
			
		$output .= '<!--Supervisors-->
            <div class="form-group">
                <label for="supervisor" id="supervisor_label">Supervisors</label>
                <input class="form-control" id="supervisor" list="suggestion_supervisor">
                <datalist id="suggestion_supervisor" >';
				
            
		$result = $main_object->bring_supervisor($main_object);
				
		while($row = mysqli_fetch_array($result))
		{
				$output .= '<option>'.$row['name'].'</option>';
        }
        $output .= '<option>'.'Not Specific'.'</option>';
        //$output .= '<option>'.'<input type="text" placeholder="supervisor">'.'</option>';
        
		$output .=         '</datalist>
            </div>';
			
		$output .= '<!--Year  -->
            <form class="form-inline form-group">
                <!-- Year -->
                <div class="form-group">
                    <label for="Year" id="year_label" > Year</label>
                </div>
                <div class="form-group">
                    <label for="From" id="year_from_label">From</label>
                    <input type="text" class="form-control" id="year_from" placeholder="2017">
                </div>
                <div class="form-group">
                    <label for="To" id="year_to_label">To</label>
                    <input type="text" class="form-control" id="year_to" placeholder="2018">
                </div>
            </form>

            <!--Thesis title-->
            <div class="form-group">
                <label for="title" id="thesis_title_label" >Title</label>
                <input type="text" placeholder="thesis title" id="thesis_title" class="form-control">
            </div>

            <!--Program-->
            <div class="form-group">
                <label for="program" id="program_label">Program</label>
                <select class="form-control" id="program">
                    <option>Not Specific</option>
                    <option>BSc</option>
                    <option>MSc</option>
                    <option>Phd</option>
                    <option>Extra</option>
                </select>
            </div>

            <!--Student Name-->
            <div class="form-group">
                <label for="Student Name" id="student_label">Student Name</label>
                <input type="text" placeholder="Student Name" id="student" class="form-control">
            </div>

            <!--Search-->
            <div class="form-group">
                <button type="button" class="btn btn-default btn-primary" id="search">Search</button>
            </div>
        </div>

    </div>
    </div>';
			
			
		
		echo $output;


	}
	
	function bring_supervisor($main_object)
	{
		$query_make = new Query_Make();
        $sql = $query_make->select_query_general($query_make,"TeacherTable","","");
        $result = $main_object->exeute_query($main_object,$sql);
		return $result;
	}
	function bring_research_groups($main_object)
	{
		$query_make = new Query_Make();
        $sql = $query_make->select_query_general($query_make,"ResearchGroupInfo","","");
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