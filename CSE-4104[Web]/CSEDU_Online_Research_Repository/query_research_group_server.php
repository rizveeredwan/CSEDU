<?php
    /*Php file to search by research group*/


    class Teacher_All{
        public $name;
        public $designation;
        public $phone;
        public $email;
        public $portfolio;
        public $status;
        public $int_designation;

    }

    class Query_Research_Group{
        protected $research_group;
        function complete_query($main_object,$value){
            $main_object->research_group = $value;
            //echo $main_object->research_group;
            //header
            $output = '  <!-- Testing -> ';
            $output .= ' <!--Research Group Details -->';
            $output .= ' <div class="table-design"> ';
            $output .= '  <!-- heading decoration -->
                        <div class="table-section-heading-decoration">
                            <h2>Search Result</h2>
                        </div>';
            $output .= '  <!-- Research Group Details -->';
            $output .= '  <div class="simple-form">
                            <!--Simple Information --> ';
            $output .= ' <table class="table table-bordered table-responsive" style="background:white;"> ';
            $output .= ' <thead></thead> ';
            $output .= ' <tbody> ';
            $result = $main_object->bring_research_group_info($main_object);
            while($row=mysqli_fetch_array($result)) {
                //name 
                $output .='<tr>';
                $output .= '<td>Name</td> ';
                $output .= '<td>'.$row['name'].'</td>';
                $output .='</tr>';

                //email
                $output .='<tr>';
                $output .= '<td>Email</td> ';
                $output .= '<td>'.$row['email'].'</td>';
                $output .='</tr>';


                $phone = $main_object->split_from_delemeter($row['phone'],'^');
                $val = '';
                if($phone[0] != "" && $phone[1] != "") {
                    $val = $phone[0].",".$phone[1];
                }
                else if($phone[0] != "") {
                    $val = $phone[0];
                }
                else if($phone[1] != "") {
                    $val = $phone[1];
                }
                //phone
                $output .='<tr>';
                $output .= '<td>Phone</td> ';
                $output .= '<td>'.$val.'</td>';
                $output .='</tr>';

                //website link
                $output .='<tr>';
                $output .= '<td>Website</td> ';
                $output .= '<td>'.'<a href="'.$row['link'].'">'.$row['link'].'</a></td>';
                $output .='</tr>';

                //website link
                $output .='<tr>';
                $output .= '<td>Facebook</td> ';
                $output .= '<td>'.'<a href="'.$row['facebook'].'">'.'Facebook'.'</a></td>';
                $output .='</tr>';
            }

            $output .= '   </tbody>
                        </table>';

            $output .= ' <!-- heading decoration -->
                    <div class="table-section-heading-decoration">
                        <h2>Supervisors Under Research Group</h2>
                    </div> ';
            $output .= ' <!--Supervisor Informations --> ';
            $output .= ' <div> ';

            $result = $main_object->supervisor_of_a_research_group($main_object);
            $teacher_array = $main_object->sort_supervisors($main_object,$result);

            $idx = 0;
            while($idx<sizeof($teacher_array)) {

                if($teacher_array[$idx] != "") {
                    $output .=' <table class="table table-bordered table-responsive" style="background:white;"> ';
                    $output .= '  <thead></thead> ';
                    $output .= ' <tbody>';

                    //name
                    $output .= '   <tr> ';
                    $output .= '<td style="width:25%;">'.'Name'.'</td>';
                    $output .= '<td style="width:75%;">'.$teacher_array[$idx]->name.'</td>';
                    $output .= ' </tr>';

                    //designation
                    $output .= '   <tr> ';
                    $output .= '<td>'.'Designation'.'</td>';
                    $output .= '<td>'.$teacher_array[$idx]->designation.'</td>';
                    $output .= ' </tr>';

                    //phone
                    $output .= '   <tr> ';
                    $output .= '<td>'.'Phone'.'</td>';
                    $output .= '<td>'.$teacher_array[$idx]->phone.'</td>';
                    $output .= ' </tr>';

                    //email
                    $output .= '   <tr> ';
                    $output .= '<td>'.'Portfolio'.'</td>';
                    $output .= '<td>'.$teacher_array[$idx]->portfolio.'</td>';
                    $output .= ' </tr>';

                    //status
                    $output .= '   <tr> ';
                    $output .= '<td>'.'Status'.'</td>';
                    $output .= '<td>'.$teacher_array[$idx]->status.'</td>';
                    $output .= ' </tr>';


                    $output .= ' </tbody>';
                    $output .='  </table>';
                }
                $idx=$idx+1;

                
            }
            //for each  supervisor


           

            $output .= '  </div>';
            $output .= '   </div>
                            </div>';
            $output .= ' ';

            echo $output;

        }

        function bring_research_group_info($main_object){
            $query_make = new Query_Make();
            $attribute = array('name');
            $value = array($main_object->research_group);
            $sql = $query_make->conditional_select($query_make,"ResearchGroupInfo",$attribute,$value);
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

        function supervisor_of_a_research_group($main_object){
            $query_make = new Query_Make();
            $attribute = array('research_group');
            $value = array($main_object->research_group);
            $sql = $query_make->conditional_select($main_object,"Supervisor",$attribute,$value);
            $result = $main_object->exeute_query($main_object,$sql);
            return $result;
        }

        function designation_rank($designation){
            if($designation == "Professor") return 1;
            if($designation == "Associate Professor") return 2;
            if($designation == "Assistant Professor") return 3;
            if($designation == "Lecturer") return 4;
        }

        function sort_supervisors($main_object,$result){
            $teacher_array = array();
            $idx = 0;
            while($row=mysqli_fetch_array($result)) {
                $teach = new Teacher_All();
                $teach->name = $row['name'];
                $teach->designation = $row['designation'];
                $teach->phone = $row['phone'];
                $teach->email = $row['email'];
                $teach->portfolio = $row['portfolio'];
                $teach->status = $row['status'];
                $teach->int_designation = $main_object->designation_rank($row['designation']);

                $teacher_array[$idx] = $teach;
                $idx = $idx+1;
            }

            //sort
            for($i=0;$i<$idx;$i=$i+1) {
                for($j=$i+1;$j<$idx;$j=$j+1){
                    if($teacher_array[$i]->int_designation > $teacher_array[$j]->int_designation) {
                        $temp = $teacher_array[$i];
                        $teacher_array[$i] = $teacher_array[$j];
                        $teacher_array[$j] = $temp; 
                    }
                }
            }
            return $teacher_array;
        }

        

    }

?>