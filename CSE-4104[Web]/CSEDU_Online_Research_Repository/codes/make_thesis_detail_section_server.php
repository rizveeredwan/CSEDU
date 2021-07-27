<?php
    /*Function to bring thesis detail section*/
    class Make_Thesis_Detail_Section{
        
        protected $thesis_code_here="";
        protected $research_group ="";

        function start_view($main_object,$code_to_run){
            if(isset($_SESSION[$code_to_run])){
                $main_object->thesis_code_here = $_SESSION[$code_to_run]; 
                $main_object->make_view($main_object); 
            }
            else $main_object->thesis_code_here=""; 
        }
        function make_view($main_object){
            $output = ''; 
            $output = '  <!--Show Section--> '; 
            $output .= ' <div class="table-design"> ';
            $output .= ' <!-- heading decoration --> ';
            $output .= ' <div class="table-section-heading-decoration">
                            <h2>Thesis/Project Information</h2>
                        </div>';
            $output .= ' <!--Thesis basic Information part--> ';
            $output .= ' <div class="simple-form">';
            $output .= ' <!--Thesis name-->';
            $output .= ' <div class="form-group">
                            <label for="thesis_name">Thesis/Project Name</label>';
            //thesis_title
            $sql = $main_object->make_query_thesis_title($main_object); 
            $result = $main_object->exeute_query($main_object,$sql);
            $thesis_name= $main_object->bring_single_value($result,"thesis_title");
            /*debug: echo "thesis_name = " .$thesis_name; */

            $output .= '<input type="text" class="form-control make-input-readonly" id="thesis_name" value="';
            $output .= $thesis_name.'" ';
            $output .= 'placeholder="Designing an efficient.. ">';
            $output .= '</div>';

            $output .= '  <!--Supervisor Name--> ';            
            $output .= '  <div class="form-group"> '; 
            $output .= ' <label for="supervisor_name">Supervisor Name</label> '; 
            $output .= '  <select class="form-control" id="supervisor_name"> '; 

            //bringing research_group
            $sql = $main_object->make_query_thesis_title($main_object); 
            $result = $main_object->exeute_query($main_object,$sql);
            $value = $main_object->bring_single_value($result,"research_group");
            $main_object->research_group = $value;

            //bring students whole data 
            $sql = $main_object->make_query_student_information($main_object);
            $result = $main_object->exeute_query($main_object,$sql); 

            $supervisor = ''; 
            $year = ''; 
            $name='';
            $roll='';
            $program='';
            $email=''; 
            $view='';

            while($row = mysqli_fetch_array($result)) {
                $supervisor = $row["supervisor"];
                $year = $row["session"];
                $view = $row["thesis_view"]; 

                $name = $row["name"];
                $roll = $row["roll"];
                $program = $row["program"];
                $email = $row["email"]; 
            }

            //supervisor
            $output .= '<option>'.$supervisor.'</option>';
            $output .= '  </select> '; 
            $output .= ' </div> ';   

            //research group
            $output .= '<!--Research Group -->';
            $output .= '  <div class="form-group"> '; 
            $output .= ' <label for="research_group">Research Group</label> '; 
            $output .= ' <input type="text" class="form-control" id="research_group" value="'.$main_object->research_group.'" readonly> ';
            $output .= ' </div>' ; 

            //year 
            $output .= '  <!--Year --> '; 
            $output .= '   <div class="form-group"> '; 
            $output .= '     <label for="year">Year</label> '; 
            $output .= ' <input type="text" class="form-control" id="year" value="'.$year.'" readonly >'; 
            $output .= ' </div>' ;  

            
            /*$output .= ' <!--View --> ';
            $output .= '    <div class="form-group">';
            $output .= '  <label for="general_view">General View</label> ';
            $output .= '      <select id="view" class="form-control">';
            if($view == "Yes") {
                $output .= ' <option>Yes</option>';
                $output .= ' <option>No</option>';
            }
            else {
                $output .= ' <option>No</option>';
                $output .= ' <option>Yes</option>';
            }

            $output .= '   </select> ';
            $output .= ' </div> '; */


            $output .= '  </div> ';
            $output .= ' ';

            //student information part 
            $output .= ' <!-- heading decoration -->
            <div class="table-section-heading-decoration">
                <h2>Student Information Part</h2>
            </div> ';

            //parsing 
            $name_arr = $main_object->split_from_delemeter($name,"^");
            $roll_arr =  $main_object->split_from_delemeter($roll,"^");
            $program_arr = $main_object->split_from_delemeter($program,"^");
            $email_arr =   $main_object->split_from_delemeter($email,"^"); 
            $tot_row=$main_object->not_empty_table_row($main_object,$name_arr,$roll_arr,$program_arr,$email_arr);
            //now common format
            //row_total row_number i am working on
            //student information
            $output .= ' <div class="simple-form"> ';
            $output .= ' <!--Student Information Part --> ';

            $output .= '<div id="student_information">';
            $idx=0;
            $student_counter=0;
            for($i=0;$i<$tot_row;$i=$i+1){
                $student_counter=$student_counter+1;
                $idx = $i+1;
                //this students div
                $output .= '<div id="student_'.$idx.'" >';

                //label 
                $output .= '    <div class="form-group">';
                $output .= '        <label for="student" id="student_label_'.$idx.'"> Student '.$idx .' </label>';
                $output .= '    </div>';

                $output .= '<div>';
                //st_row_1 
                $output .= '   <table class="table table-bordered table-responsive" style="background:white;" id="st_row_"'.$idx.'">';
                $output .= '  <thead></thead> ';
                $output .= '  <tbody> ';
               
                //name 
                $value='';
                $add="name"; 
                if($i<sizeof($name_arr)){
                    $value=$name_arr[$i]; 
                }
                $output .= '  <tr> ';
                $output .= '   <td style="width:25%;">'.$add.'</td> ';
                $output .= '   <td style="width:75%;"><input type="text" class="input-field-design make-input-readonly" name="" placeholder="'.$add.'" id="st_'.$add.'_'.$idx.'" value="'.$value.'" ></td>';
                $output .= ' </tr> '; 

                //roll
                $value='';
                $add="roll"; 
                if($i<sizeof($roll_arr)){
                    $value=$roll_arr[$i]; 
                }
                $output .= '  <tr> ';
                $output .= '   <td>'.$add.'</td> ';
                $output .= '   <td><input type="text" class="input-field-design make-input-readonly" name="" placeholder="'.$add.'" id="st_'.$add.'_'.$idx.'" value="'.$value.'" ></td>';
                $output .= ' </tr> '; 

                //program part 
                $output .= '<tr>';
                $output .= '<td>Program</td>';
                $output .= '<td>';
                $output .= ' <select class="form-control" id="st_prog_'.$idx.'" >  '; 
                $output .=  $main_object->sort_program($main_object,$program_arr[$i]); 
                $output .= ' </select> ';
                $output .= '   </td> ';
                $output .= '  </tr> '; 
                        
                //email
                $value='';
                $add="email"; 
                if($i<sizeof($email_arr)){
                    $value=$email_arr[$i]; 
                }
                $output .= '  <tr> ';
                $output .= '   <td>'.$add.'</td> ';
                $output .= '   <td><input type="text" class="input-field-design make-input-readonly" name="" placeholder="'.$add.'" id="st_'.$add.'_'.$idx.'" value="'.$value.'" ></td>';
                $output .= ' </tr> '; 

                $output .= '</tbody>';
                $output .=  '</table>';
                $output .=  ' </div>' ;

                $output .= '<!-- -->';
                $output .= '<!-- Delete Button -->';
                $output .=  ' <div class="form-group"> ';
                $output .=  '<button type="button" class="btn btn-default btn-danger student-delete hide-button" id="st_delete_'.$idx.'" >Delete</button>';
                $output .= '</div>'; 

                $output .= '</div>'; 

            }
            //student info part completed
            $output .= '</div>';

            $output .= '<!-- Add Button --> ';
            $output .= '<div class="form-group"> ';
            $output .= '<button type="button" class="btn btn-default btn-success hide-button" id="add_student'.'">Add New Student</button>
            </div>';

            //File Uploading Section 
            $output .= '<!--File Uploading Section-->
            <!-- heading decoration -->
            <div class="table-section-heading-decoration">
                <h2>File Section</h2>
            </div>'; 

            $output .=  '<!--File Showing/Provoking option-->
            <div class="form-group">
                <label for="file_viewing">File Showing Option</label>
                    <select class="form-control" id="view" >';
            if($view == "Yes") {
                $output .= '<option>Yes</option> '; 
                $output .= ' <option>No</option> '; 
            }
            else {
                $output .= ' <option>No</option> '; 
                $output .= '<option>Yes</option> ';
            }
            $output.= '</select>
                    </div>';

            $output.= '<!--File Type option-->';
            $output .= '<div class="form-group">';
            $output .= '<label for="file_type">File Showing Option</label>';
            $output .= '<select class="form-control" id="file_type">';
            $output .= '<option>Thesis File</option>';
            $output .= '</select>';
            $output .= '</div>';

            $output .= '<!--Form Input -->';
            $output .= '<div class="form-group">
                <form enctype="multipart/form-data">'; 
            $output .= '<input type="file" class="hide-div" name="file" id="file_input">';
            $output .= '</form>';
            $output .= '</div>';

            $output .= '<!--Upload Secion-->';
            $output .= '<div class="form-group">';
            $output .= '<button type="button" class="btn btn-default btn-success hide-div" id="file_submit">upload</button>';
            $output .= '</div>';

            
            //File query
            $sql = $main_object->to_bring_file_query($main_object);
            $result=$main_object->exeute_query($main_object,$sql); 
            $files = $main_object->bring_single_value($result,"link");
            $files = $main_object->split_from_delemeter($files,"^"); 

            $output .= '<!--Show Files--> ';
            $output .= ' <div>';
            $output .= '<table class="table table-bordered table-responsive" style="background:white;" id="file_table">';
            $output .= '<thead></thead>';
            $output .= '<tbody>';
            $counter=0;
            for($i=0;$i<sizeof($files);$i=$i+1){
                if($files[$i] != "") {
                    $link=$files[$i]; 
                    $counter=$counter+1;
                    $output .= '<tr id="file_row_'.$counter.'">';
                    $file_name = $main_object->split_from_delemeter($files[$i],"/"); 
                    $file_name =  $main_object->split_from_delemeter($file_name[sizeof($file_name)-1],"`");
                    $output .= '<td>'.$file_name[sizeof($file_name)-1].'</td>';
                    $output .= '<td><a href="'.$link.'" target="_blank" id="file_ref_'.$counter.'">View</a></td>';
                    $output .= '<td><a href="'.$link.'" download="'.$file_name[sizeof($file_name)-1].'">Download</a></td>';
                    $output .= '<td class="table-link" id="file_link_'.$counter.'">'.$link.'</td>';
                    $output .= '<td><button type="button" class="btn btn-default btn-danger file-delete-button hide-button" id="file_delete_'.$counter.'">Delete</button></td>';
                    
                    $output .= '</tr>';
                }
            }   
            $output .= '</tbody>';
            $output .= '</table>';
            $output .= '</div>';

            $output .= '<div class="form-group"> '; //update_total student_total file number
            $output .= '<button type="button" class="btn btn-default btn-success hide-button" id="update'.'">Update</button>
                        <button type="button" class="btn btn-default btn-danger hide-button" id="delete_thesis">Delete thesis</button>';
            $output .= '</div>';

            $output .= '</div>
                       </div>';


            /*This part is mainly for saving information of how many rows in the table*/
            $output .= '<div id="file_counter">'.$counter.'</div>';
            $output .= '<div id="student_counter">'.$student_counter.'</div>';
            echo $output; 
           
        }

        function make_query_student_information($main_object){
            $query_make = new Query_Make();
            $attribute = array("thesis_code");
            $value = array($main_object->thesis_code_here); 
            $sql = $query_make->conditional_select($query_make,"StudentInformation",$attribute,$value);
            return $sql; 
        }
        function make_query_thesis_title($main_object){
            $query_make = new Query_Make();
            $attributes = array("thesis_code");
            $values = array($main_object->thesis_code_here);
            $sql = $query_make->conditional_select($query_make,"ThesisGroupInfo",$attributes,$values);
            return $sql; 
        }
        function make_query_bring_all_supervisors($main_object){
            $query_make = new Query_Make();
            $attributes = array("research_group");
            $values = array($main_object->research_group); 
            $sql = $query_make->conditional_select($query_make,"Supervisor",$attributes,$values);
            return $sql; 
        }
        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }

        function bring_single_value($result,$attribute){
            /*debug echo "man = ".$attribute." "; */
            $value='';
            while($row=mysqli_fetch_array($result)){
                $value = $row[$attribute]; 
            }
            /*debug: echo $value; */
            return $value; 
        }
        function to_append_in_select_tag($result,$attribute){
            $output = ' ';
            while($row=mysqli_fetch_array($result)){
                $output .= '<option> '. $row[$attribute]  .' </option> ';
            }
            return $output; 
        }

        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }

        function not_empty_table_row($main_object,$name,$roll,$program,$email){
            $c1=0;
            for($i=0;$i<sizeof($name);$i=$i+1) {
                if($name[$i] != "") $c1=$c1+1; 
            }
            $c2=0;
            for($i=0;$i<sizeof($roll);$i=$i+1) {
                if($roll[$i] != "") $c2=$c2+1; 
            }
            $c3=0;
            for($i=0;$i<sizeof($program);$i=$i+1) {
                if($program[$i] != "") $c3=$c3+1; 
            }
            $c4=0;
            for($i=0;$i<sizeof($email);$i=$i+1) {
                if($email[$i] != "") $c4=$c4+1; 
            }
            $answer=0;
            if($answer<$c1) $answer=$c1;
            if($answer<$c2) $answer=$c2;
            if($answer<$c3) $answer=$c3;
            if($answer<$c4) $answer=$c4;

            return $answer;
        }

        function sort_program($main_object,$main_program){
            $temp = " ";
            $output = ''; 
            if($main_program == "BSc") {
               $temp = array("BSc", "MSc", "Phd", "Extra"); 
            }
            else if($main_program == "MSc") {
                $temp = array("MSc", "BSc", "Phd", "Extra"); 
            }
            else if($main_program == "Phd") {
                $temp = array("Phd","BSc", "MSc", "Extra"); 
            }
            else if($main_program == "Extra") {
                $temp = array("Extra","Phd","BSc", "MSc"); 
            }
            else {
                $temp = array("Phd","BSc", "MSc", "Extra"); 
            }
            for($i=0;$i<4;$i=$i+1){
                $output .= '<option> '. $temp[$i] .' </option>'; 
            }
            return $output; 
        }
        function to_bring_file_query($main_object){
            $query_make = new Query_Make();
            $attributes = array("id");
            $values = array($main_object->thesis_code_here);
            $sql = $query_make->conditional_select($query_make,"Files",$attributes,$values);
            return $sql; 
        }
    }
?>