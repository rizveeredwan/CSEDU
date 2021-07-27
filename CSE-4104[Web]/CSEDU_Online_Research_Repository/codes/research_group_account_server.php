<?php
    //make research_group_account.html 
	class Teacher
    {
	    public $name;
	    public $designation;
	    public $email;
	    public $phone;
        public $portfolio;
	    public $status; 
	    public $position;
    }



    //teacher information 
    class Research_Group_Account{
        protected $research_group;

        //checking of session variable 
        function check_session_variable($main_object) {
			if(isset($_SESSION["account"])) {
				if($_SESSION["account"] == "Manager") {
					if(isset($_SESSION["research_group"])){
						$main_object->research_group = $_SESSION["research_group"];
						return true;
					}
					return false;
				}
			}
			else return false;
        }

        //executing query
        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }
        
        //split by delemeter
        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }

        function bring_research_group_info($main_object)
	    {
		    $attribute = array("name");
		    $attribute_value = array($main_object->research_group);
		
		    $query_make = new Query_Make();
		    $sql = $query_make->conditional_select($query_make,"ResearchGroupInfo",$attribute,$attribute_value);
            $result = $main_object->exeute_query($main_object,$sql);
		    return $result;
        }
        
        function bring_teacher_info($main_object)
	    {
		    $teacher = array();
		
		    $index = 0;
	
		    $query_make = new Query_Make();
		    $sql = $query_make->select_query_general($query_make,"TeacherTable","", "");
            $result = $main_object->exeute_query($main_object,$sql);
		
		
		
		    while($row = mysqli_fetch_array($result))
		    {
			    $teach = new Teacher();
			    $teach->name = $row["name"];
			    $teach->designation = $row["designation"];
			    $pos = $main_object->set_position($teach->designation);
			
			    $teach->position = $pos;
			    $teach->email = $row["email"];
			    $teach->phone = $row["phone"];
			    $teach->portfolio = $row["portfolio"];
			    $teach->status = $row["status"];
			    $teacher[$index] = $teach;
			    $index = $index+1;
		    }
		
		    return $teacher;
		
        }
        
        function bring_supervisor_info($main_object)
	    {
		
		    $teacher = array();
		    $index = 0;
		
		    $attribute = array("research_group");
		    $attribute_value = array($main_object->research_group);
		
		    $query_make = new Query_Make();
		    $sql = $query_make->conditional_select($query_make,"Supervisor",$attribute,$attribute_value);
            $result = $main_object->exeute_query($main_object,$sql);
		
		    while($row = mysqli_fetch_array($result))
		    {
			    $teach = new Teacher();
			    $teach->name = $row["name"];
			
			    $teach->designation = $row["designation"];
			
			    $pos = $main_object->set_position($teach->designation);
			
			    $teach->position = $pos;
			
			    $teach->email = $row["email"];
			    $teach->phone = $row["phone"];
			    $teach->portfolio = $row["portfolio"];
			    $teach->status = $row["status"];
			    $teacher[$index] = $teach;
			    $index = $index+1;
		    }
		    return $teacher;
        }
        
        function match_supervisor($main_object)
	    {
		    $supevisor = $main_object->bring_supervisor_info($main_object);
		    $teacher = $main_object->bring_teacher_info($main_object);
		
		    //debug: echo "size of arrays ".sizeof($supevisor)." ".sizeof($teacher)."\n";
		
		    $final = array();
		    $ind = 0;
		
		
		    for($i = 0; $i<sizeof($teacher); $i=$i+1)
		    {
			    $flag = 0;
			    for($j = 0; $j<sizeof($supevisor); $j=$j+1)
			    {
				    //debugecho " ".$teacher[$i]->email." ".$supevisor[$j]->email." ";
				    if($teacher[$i]->email == $supevisor[$j]->email)
				    {
					
					    $flag = 1;
					    break;
				    }
					
			    }
			    if($flag == 0)
			    {
				    $output = $teacher[$i]->name;
				    $output .= "(".$teacher[$i]->email.")";
				    $final[$ind] = $output;
				    $ind = $ind + 1;
			    }
		    }
		
		    return $final;
        }
        
        //function 
	
	    function set_position($str)
	    {
			    if($str == "Pofessor")return 4;
		    	else if($str == "Associate Professor")return 3;
			    else if($str == "Assistant Professor")return 2;
			    else if($str == "Lecturer")return 1;
        }
        
        //To Show Create Thesis Section 
        function show_create_thesis($main_object)
	    {
		    $ok = $main_object->check_session_variable($main_object);
		    if($ok == true)
		    {
			    //$result = $main_object-> 
			    $result = $main_object->bring_research_group_info($main_object);
			    $output = "";	
			    while($row = mysqli_fetch_array($result))
			    {
			        //first part of the form
			        $output .= '<div class="table-design">
                    <!-- heading decoration -->
                    <div class="table-section-heading-decoration">
                        <h2>Creating Thesis/Project</h2>
                    </div>
                    <div class="simple-form">
                        <form>
                        <!--Thesis/Project Name-->
                        <div class="form-group">
                        <label for="thesis_name">Thesis/Project Name</label>';
			            //now thesis_name
			            $output .= '<input type="text" class="form-control" id="thesis_name" placeholder="Designing an efficient..">
                </div>';
			//supervisor name
			$output .= '<!--Supervisor Name-->
                <div class="form-group">
                    <label for="supervisor_name">Supervisor Name</label>
                    <select id="supervisor_name" class="form-control">';
                  
				  $temp = $main_object->bring_supervisor_info($main_object);
				//suggestion supervisor
				
				for($i=0; $i<sizeof($temp); $i=$i+1)
				{
					$output .= '<option>'.$temp[$i]->name.'</option>';
				}    
						
            $output .= '</select>
                </div>';
			//year
			$output .= '<!--Year of this thesis-->
                <div class="form-group">
                    <label for="year">Year</label>
                    <input type="text" class="form-control" id="year" placeholder="2018">
                </div>';
			//view
			$output .= '<!--View -->
                <div class="form-group">
                    <label for="general_view">General View</label>
                    <select id="view" class="form-control">
                        <option>Yes</option>
                        <option>No</option>
                    </select>
                </div>';
			

            $output .= '<!--Student Number-->
                <div class="form-group">
                    <label for="num_student">Add Student</label>
                </div>

                <div class="space-creator-from-top" id="student_list">
                    <table class="table table-bordered table-responsive" style="background:white;" id="student_info">
                        <thead>
                            <tr>
                                <td>Name</td>
                                <td>Roll</td>
                                <td>Email</td>
                                <td>Program</td>
                            </tr>
                        </thead>
                        <tbody>
                            <!-- 
                            <tr>
                                <td><input type="text" id="" class="form-control" placeholder="name"></td>
                                <td><input type="text" id="" class="form-control" placeholder="roll"></td>
                                <td><input type="text" id="" class="form-control" placeholder="session"></td>
                                <td><input type="text" id="" class="form-control" placeholder="email"></td>
                                <td><input type="text" id="" class="form-control" placeholder="password"></td>
                            </tr>
                        -->
                        </tbody>
                    </table>

                    <!--Add new row, Thesis group create button-->
                    <div class="form-group">
                        <button type="button" class="btn btn-default btn-success" id="student_list_create">Add Student</button>
                        <button type="button" class="btn btn-default btn-danger" id="student_list_delete">Delete Student</button>
                        <button type="button" class="btn btn-default btn-warning" id="create_thesis">Create Thesis/Project</button>
                    </div>
                </div>


                </form>
                </div>
                </div>';
	            echo $output;
		    }
        }
        }

        //To show Supervisor Section
        function show_supervisor_info($main_object)
        {
	        $ok1 = $main_object->check_session_variable($main_object);
		    if($ok1 == true)
		    {
				//supervisor info starting
				$output = ' <div>';
				$output .= '<!--Table Design -->
					<div class="table-design">

					<!-- heading decoration -->
					<div class="table-section-heading-decoration">
						<h2>Supervisors Informations</h2>
					</div>

				    <div class="simple-form">
					<!--Supervisor Suggestion-->
				    	<div class="form-group">
							<label for="supervisor_suggestion">Faculty Members</label>
							<select class="form-control" id="teacher_name">';
				
				$temp = $main_object->match_supervisor($main_object);
				//suggestion supervisor
				
				for($i=0; $i<sizeof($temp); $i=$i+1)
				{
					$output .= '<option>'.$temp[$i].'</option>';
				}
				$output .= 	' </select>';
				$output .= 	'</div>';
				
				//add button
				$output .= '<!--Add Button -->
					<div class="button-center">
					<div></div>
					<div>
						<button type="submit" class="btn btn-default btn-success btn-block" id="add_teacher">Add</button>
					</div>
					<div></div>
					</div>';
				
				
				$result1 = $main_object->bring_supervisor_info($main_object);
				$output .= '<div>';
			
                $teacher_counter = 0; 
				for($i = 0; $i<sizeof($result1); $i = $i + 1)
				{
					$teacher_counter=$teacher_counter+1;
					$output .= '	<table class="table table-bordered table-responsive" style="background:white;">
									<thead></thead>
									<tbody>';
					$output .='
					<tr>
                        <td style="width:25%;">Name</td>
                        <td style="width:75%;" id="teacher_name_'.$teacher_counter.'" >'.$result1[$i]->name.'</td>
                    </tr>
                    <tr>
                        <td>Designation</td>
                        <td>'.$result1[$i]->designation.'</td>
                    </tr>
                    <tr>
                        <td>Email</td>
                        <td id="teacher_email_'.$teacher_counter.'" >'.$result1[$i]->email.'</td>
                    </tr>
                    <tr>
                        <td>Phone</td>
                        <td>'.$result1[$i]->phone.'</td>
                    </tr>
                    <tr>
                        <td>Portfolio</td>
                        <td><a href="'.$result1[$i]->portfolio.'">'.$result1[$i]->portfolio.'</a></td>
                    </tr>
                    <tr>
                        <td>Status</td>
                        <td>'.$result1[$i]->status.'</td>
					</tr>';
					$output .= '</tbody>
							</table>
							<div class="form-group">
								<button class="btn btn-default btn-danger remove_teacher" type="submit" id="remove_teacher_'.$teacher_counter.'">Remove</button>
							</div>';
				      
				}
				
				$output .= '</div>';

				$output .='<div id="teacher_counter">'.$teacher_counter.'</div>';
				$output .= '</div></div>';
					echo $output;
		    }
		
        }

        //to show the metadata section
        function show_page($main_object)
	    {
		    $ok = $main_object->check_session_variable($main_object);
		    if($ok == true)
		    {
			    $result = $main_object->bring_research_group_info($main_object);
			    $output = "";	
			    while($row = mysqli_fetch_array($result))
			    {
			    //first part of the form
			    $output .= '

                <!--The Reseach Group Information Section -->
                <div class="form" id="part-1">
                <div></div>
            <div>
            <form class="form-container">
                <h1>Research Group Information</h1>
                <!--Research Group Name-->
                <div class="form-group">
                    <label for="name">Research Group Name</label>';
			//now research group name
			$output .= '<input type="text" class="form-control" id="name" value="'.$row["name"].'" readonly>
                </div>';
			//account type
			$output .= '<!--Account Type-->
                <div class="form-group">
                    <label for="account_type">Account</label>
                    <select class="form-control" id="account">
                            <option>Manager</option>
                    </select>
                </div>';
			//password
			$output .= '<!--Password -->
                <div class="form-group">
                    <label for="password">Password</label>
                    <input type="password" class="form-control" id="password" value="">
                </div>';
			//confirm password
			$output .= '<!--Confirm Password -->
                <div class="form-group">
                    <label for="confirm password">Confirm Password</label>
                    <input type="password" class="form-control" id="confirm_password" placeholder="Confirm Password">
				</div>';

			//password for student 
			$output .= '<!--Confirm Password -->
			<div class="form-group">
				<label for="password_student">Password For Student</label>
				<input type="text" class="form-control" id="password_student" placeholder="Password For Student" value="'.$row["password_student"].'" >
			</div>';
			
			//email
			$output .= '<!--Email -->
                <div class="form-group">
                    <label for="email">Email</label>
                    <input type="email" class="form-control" id="email" value="'.$row["email"].'">
                </div>';
			//phone number
			
			
					$temp = $main_object->split_from_delemeter($row["phone"], '^');
					$output .= '<!--Phone Number-->
					<div class="form-group">
                    <label for="phone">Phone</label>
                    <input type="text" class="form-control" id="phone_1" value="'.$temp[0].'">
                    <input type="text" class="form-control" id="phone_2" value="'.$temp[1].'">
					</div>';
			
			
			//website link
			$output .= '<!--Website Link-->
                <div class="form-group">
                    <label for="link">Website Link</label>
                    <input type="text" class="form-control" id="link" value="'.$row["link"].'">
                </div>';
			//drive link
            $output .= '<!--Google Drive Link-->
                <div class="form-group">
                    <label for="link">Google Drive Link</label>
                    <input type="text" class="form-control" id="google_drive" value="'.$row["google_drive"].'">
                </div>';
			//dropbox link
            $output .= '<!--Dropbox Link-->
                <div class="form-group">
                    <label for="link">Dropbox Link</label>
                    <input type="text" class="form-control" id="dropbox" value="'.$row["dropbox"].'">
                </div>';
			//github link
			$output .= '<!--Github Link-->
                <div class="form-group">
                    <label for="link">Github Link</label>
                    <input type="text" class="form-control" id="github" value="'.$row["github"].'">
                </div>';
			//facebook
			$output .= '<!--Facebook Link-->
                <div class="form-group">
                    <label for="link">Facebook Profile</label>
                    <input type="text" class="form-control" id="facebook" valuer="'.$row["facebook"].'">
                </div>';
			//update
			$output .= '<!--Update button-->
                <button type="submit" class="btn btn-default" id="update">Update</button>
                <button type="submit" class="btn btn-default" id="delete">Delete</button>
                <!--Alert Message-->
                <div>
                    </br>
                    </br>
                </div>';
			//warning
			$output .= '<div class="alert alert-warning">
                    <strong>Warning!</strong> Very Careful while deleting.Delete operation will clear everything related to this research group.
                </div>
            </form>
        </div>
        <div> </div>
        </div>';
	    echo $output;
		
		}
		}
		
			
	}


    
    }
?>