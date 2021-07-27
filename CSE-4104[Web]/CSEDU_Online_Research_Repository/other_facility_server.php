<?php
    /*A server side file to control the work of other.html */
    class Other_Facility{

        protected $research_group;
        protected $website_name;
        function goto_other_website($main_object,$value){
            if(isset($_SESSION["account"]) && isset($_SESSION["research_group"])){
                if($_SESSION["research_group"] != "Others" && $_SESSION["research_group"] != "") {
                    //logged in fulfill
                    //and some valid research group exists
                    $main_object->research_group = $_SESSION["research_group"];
                    $main_object->website_name = $value; 
                    $main_object->bring_other_website_link($main_object);

                }
                else {
                    echo "";
                }
            }
            else {
                echo "";
            }
        }

        //this function will bring other website links 
        function bring_other_website_link($main_object){
            $query_make = new Query_Make();
            $attribute = array("name");
            $value = array($main_object->research_group);
            $sql = $query_make->conditional_select($query_make,"ResearchGroupInfo",$attribute,$value);
            $result = $main_object->exeute_query($main_object,$sql);
            $link = '';
            while($row = mysqli_fetch_array($result)) {
                $link = $row[$main_object->website_name];
            }
            echo $link;
        }

        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }

        function bring_mail_system($main_object){
            $output = '<div class="table-design">
            <!-- heading decoration -->
            <div class="table-section-heading-decoration">
                <h2>Mail</h2>
            </div>
    
            <!--The bar under Menu decoration-->
            <div style="margin-left:2%; margin-right:2%;">
                <div class="bar-under-menu">
                    <div class="bar-under-menu-main-part"></div>
                </div>
            </div>
            <!-- To Create Space -->
            <div style="height:50px;"></div>';
            
            $output .= ' <div style="margin-left:2%; margin-right:2%;">';
            
            if(isset($_SESSION["account"]) && isset($_SESSION["research_group"])) {
                if($_SESSION["research_group"] != "") {
                    $output .= '<!--Supervisor -->
                                <div class="form-group">';
                    $output .= ' <label for="supervisor">Supervisor</label>';
                    $output .= ' <select class="form-control" id="person">';

                    $main_object->research_group = $_SESSION["research_group"];
                    $result = $main_object->bring_supervisor_name_email($main_object);

                    while($row=mysqli_fetch_array($result)){
                        $value = $row['name'].'('.$row['email'].')';
                        $output .='<option>'.$value.'</option>';
                    }

                    $output .= '</select>';
                    $output .= ' </div>';

                    $output .= '<!--subject -->
                                <div class="form-group">
                                    <label for="subject">Subject</label>
                                    <input class="form-control" id="subject" placeholder="subject">
                                </div>';
                    $output .= '<!--Message -->
                                <div class="form-group">
                                    <label for="subject">Message</label>
                                    <textarea id="message" class="form-control" rows="5"></textarea>
                                </div>';
                    $output .= '<!--Button -->
                                <div class="form-group">
                                    <button type="button" id="mail_submit" class="btn btn-default">Mail</button>
                                </div>';  
                    $output .= '<!--Button -->
                                <div class="form-group">
                                    <button type="button" id="group_mail" class="btn btn-default btn-success">Switch to Group Mail</button>
                                </div>';       
                }
                else {
                    $output .='<div>Please Log in Under Some valid research group first</div>';
                }
            }
            else {
                //not found any valid 
                $output .='<div>Please Log in Under Some valid research group first</div>';
            }
            $output .='</div></div>';
            echo $output;
        }

        //purpose of this function is to bring all the teachers for group mail system
        //suitable for admins
        function bring_all_teachers_name_email($main_object){
            $query_make = new Query_Make();
            $sql = $query_make->select_query_general($query_make,"TeacherTable","","");
            $result = $main_object->exeute_query($main_object,$sql);
            return $result;
        }
        
        function bring_supervisor_name_email($main_object){

            //debug: echo "research_group ".$main_object->research_group;
            if($main_object->research_group == "Others" || $main_object->research_group == "others" ){
                return $main_object->bring_all_teachers_name_email($main_object);
            }
            $query_make = new Query_Make();
            $attribute = array("research_group");
            $value = array($main_object->research_group);
            $sql = $query_make->conditional_select($query_make,"Supervisor",$attribute,$value);
            $result = $main_object->exeute_query($main_object,$sql);
            return $result;
        }

        function bring_students($main_object){

            $query_make = new Query_Make();
            $result='';
            $final_result=array();
            $idx = 0;
            if($main_object->research_group == "others"){
                $sql = $query_make->select_query_general($query_make,"StudentInformation","","");
                $result=$main_object->exeute_query($main_object,$sql);
            }
            else {
                $attribute = array("research_group");
                $value = array($main_object->research_group);
                $sql = $query_make->conditional_select($query_make,"StudentInformation",$attribute,$value);
                $result=$main_object->exeute_query($main_object,$sql);
            }
            
            
            while($row=mysqli_fetch_array($result)){
                $name=$row['name'];
                $email=$row['email'];
                $temp_name = $main_object->split_from_delemeter($name,'^');
                $temp_email = $main_object->split_from_delemeter($email,'^');
                for($i=0;$i<sizeof($temp_name);$i=$i+1){
                    if($temp_name[$i] != "" && $temp_email[$i] != ""){
                        $str = $temp_name[$i]."(".$temp_email[$i].')';
                        $final_result[$idx] = $str;
                        $idx=$idx+1;
                        //debug: echo $str;
                    }
                }
            }
            return $final_result;
        }
        //split by delemeter
        function split_from_delemeter($string,$delim){
            $temp_array = explode($delim,$string);
            return $temp_array;
        }
        function bring_group_mail_system($main_object){
            if(isset($_SESSION["account"]) && isset($_SESSION["research_group"])) {
                if($_SESSION["research_group"] != ""){
                    $main_object->research_group = $_SESSION["research_group"];
                    //Now the mail system
                    $output = ' ';
                    $output .= '<div class="table-design">
                            <!-- heading decoration -->
                            <div class="table-section-heading-decoration">
                                <h2> Group Mail System</h2>
                            </div>';
                    $output .= '<!--border -->
                    <div style="margin-left:2%; margin-right:2%;">
                        <div class="bar-under-menu">
                            <div class="bar-under-menu-main-part"></div>
                        </div>
                    </div>
                    <!-- To Create Space-->
                    <div style="height:50px;"></div>
                    <div style="margin-left:2%; margin-right:2%;">
                        <!--Supervisor -->
                        <div class="form-group">
                            <label for="supervisor">Supervisor</label>';
                    $output .= '  <select class="form-control" id="supervisor_name"> ';
                    //supervisors
                    $result = $main_object->bring_supervisor_name_email($main_object);
                    while($row=mysqli_fetch_array($result)){
                        $name = $row['name'];
                        $email = $row['email'];
                        $value = $name.'('.$email.')';
                        $output .= '<option>'.$value.'</option>';
                    }
                    $output .= '</select>
                                </div>';

                    $output .=' <div class="form-group">
                                    <button type="button" class="btn btn-default btn-primary add_in_group_mail" id="add_supervisor">Add Supervisor</button>
                                </div>
                                <!--Students -->
                                <div class="form-group">
                                    <label for="student">Student</label>
                                <select class="form-control" id="student_name">';
                    $result = $main_object->bring_students($main_object);
                    for($i=0;$i<sizeof($result);$i=$i+1){
                        $output .='<option>'.$result[$i].'</option>';
                    }
                    $output .='    </select>
                                    </div>';
                    $output .=' <div class="form-group">
                                    <button type="button" class="btn btn-default btn-success add_in_group_mail" id="add_student">Add Student</button>
                                </div>
                            </div>';

                    $output .='<!--Receipent table -->
                    <div style="margin-left:2%; margin-right:2%;">
            
                        <!-- heading decoration -->
                        <div class="table-section-heading-decoration">
                            <h2> Receipent Name</h2>
                        </div>
            
                        <table class="table table-bordered table-responsive" style="background:white;" id="mail_table" >
                            <thead>
                                <tr>
                                    <td>Name</td>
                                    <td>Email</td>
                                    <td>Mail Status</td>
                                    <td></td>
                                </tr>
                            </thead>
                            <tbody>';

                    $output .='</tbody>
                                </table>
                            </div>';
                    $output .='<!--subject -->
                    <div style="margin-left:2%; margin-right:2%;">
                        <div class="form-group">
                            <label for="subject">Subject</label>
                            <input class="form-control" placeholder="group_subject" id="group_subject">
                        </div>
                        <!--Message -->
                        <div class="form-group">
                            <label for="subject">Message</label>
                            <textarea class="form-control" rows="5" id="group_message"></textarea>
                        </div>
                        <!--button -->
                        <div class="form-group">
                            <button type="button" class="btn btn-default" id="group_mail_submit">Mail</button>
                        </div>
                    </div>
                </div>';
                echo $output;
                }
            }
        }

    }
?>