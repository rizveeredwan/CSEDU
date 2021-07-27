<?php

    /*Purpose of this file is to make admin_account.html*/
    class Make_Admin_Account{

        protected $email;
        protected $phone;
        function start_view($main_object){
            $page_name="";
            if(isset($_SESSION["page_name"]) && isset($_SESSION["account"])) {
                $page_name = $_SESSION["page_name"];
                $account = $_SESSION["account"];
                if($page_name == "admin_account.php" && $account == "Admin") {
                    $main_object->make_page($main_object);
                }
            }
        }

        function make_page($main_object){
            $output = ' ';
            $output .= ' <!--The Admin Account Part --> ';
            $output .=  ' <div class="table-design"> ';

            $output .=  '  <!-- heading decoration --> ';
            $output .=  '  <div class="table-section-heading-decoration"> ';
            $output .=  ' <h2>Admin Account </h2> ';
            $output .=  '  </div> ';  
            //account type, password and confirm password 
            $output .=  ' <div class="simple-form">
                            <!--Account Type-->
                        <div class="form-group">
                            <label for="Account Type">Account Type</label>
                            <input type="text" class="form-control" value="Admin" readonly>
                        </div>
                        <!--Password-->
                        <div class="form-group">
                            <label for="Password">Password</label>
                            <input type="password" class="form-control" id="password" placeholder="password">
                        </div>
                        <!--Confirm Password-->
                        <div class="form-group">
                            <label for="Confirm Password">Confirm Password</label>
                            <input type="password" class="form-control" id="confirm_password" placeholder="">
                        </div>'; 
            //Now we need email and phone number
            $sql = $main_object->select_all_from_admin_table($main_object);
            $result = $main_object->exeute_query($main_object,$sql);
            $main_object->email = ""; //initialize
            $main_object->phone = ""; //initialize
            while($row = mysqli_fetch_array($result)) {
                $main_object->email = $row["email"];
                $main_object->phone = $row["phone"];
            }
           $output .= '  <!--Email --> ';
           $output .= ' <div class="form-group"> ';
           $output .= '  <label for="Email">Email</label> ';
           $output .= '   <input type="email" class="form-control" id="email" value="'.$main_object->email.'"placeholder="someone@gmail.com"> ';
           $output .= '  </div> '; 
           
           $output .= '<!--Phone --> ';
           $output .= '  <div class="form-group">';
           $output .= '  <label for="Phone">Phone</label> ';
           $output .= '  <input type="text" class="form-control" id="phone" value="'.$main_object->phone.'" placeholder="01758545903">';
           $output .= '  </div> ';
           $output .= '  </div> ';

           $output .= ' <!--Supervisors Section -->
                        <div class="table-section-heading-decoration">
                            <h2>Teachers Section </h2>
                        </div>';
           $output .= ' <!--Input Field-->
                            <div class="simple-form"> ';
           $output .= '  <table class="table table-bordered table-responsive" style="background:white;">';
           $output .= '  <thead></thead>';
           $output .= '  <tbody>';
           $output .= '  <tr>
                            <td>Name</td>
                            <td><input type="text" class="input-field-design" placeholder="name" id="t_name" ></td>
                        </tr>';
           $output .= '  <tr>
                            <td>Designation</td>
                            <td><input type="text" class="input-field-design" placeholder="professor/lecturer" id="t_designation"></td>
                        </tr>
                        <tr>
                            <td>Email</td>
                            <td><input type="email" class="input-field-design" placeholder="someone@gmail.com" id="t_email"></td>
                        </tr>
                        <tr>
                            <td>Phone</td>
                            <td><input type="text" class="input-field-design" placeholder="017........" id="t_phone"></td>
                        </tr>
                        <tr>
                            <td>Portfolio</td>
                            <td><input type="text" class="input-field-design" placeholder="link of profile" id="t_portfolio"></td>
                        </tr>
                        <tr>
                            <td>Current Status</td>
                            <td><input type="text" class="input-field-design" placeholder="Active/On leave" id="t_status"></td>
                        </tr>
                    </tbody>
                    </table>';
           $output .= ' <!--Add supervisor -->
                        <div class="form-group">
                            <button type="button" class="btn btn-default btn-success" id="add_teacher" >Add New Teacher</button>
                        </div>
                        </div>';
           $output .= ' <!--Existing Teachers--> ';
           $output .= '  <div class="simple-form"> ';
           $output .= ' <table class="table table-bordered table-responsive" style="background:white;" id="teacher_table"> ';
           $output .= ' <thead>
                            <tr>
                                <td>Name</td>
                                <td>Designation</td>
                                <td>Email</td>
                                <td>Phone</td>
                                <td>Portfolio</td>
                                <td>Status</td>
                                <td></td>
                            </tr>
                        </thead>';
           $output .= ' <tbody>';
           //now need to gather all the teachers information
           $sql = $main_object->select_all_teachers($main_object);
           $result = $main_object->exeute_query($main_object,$sql);
           $teacher=0;
           while($row = mysqli_fetch_array($result)){
               $teacher = $teacher + 1;
               $output .= ' <tr id="t_row_'.$teacher.'">';
               $var = "name";
               $output .= '<td id="t_name_'.$teacher.'">'.$row[$var]. '</td>';
               $var = "designation";
               $output .= '<td id="t_designation_'.$teacher.'">'.$row[$var]. '</td>';
               $var = "email";
               $output .= '<td id="t_email_'.$teacher.'">'.$row[$var]. '</td>';
               $var = "phone";
               $output .= '<td id="t_phone_'.$teacher.'">'.$row[$var]. '</td>';
               $var = "portfolio";
               $output .= '<td id="t_portfolio_'.$teacher.'">'.'<a href="'.$row[$var].'">'.$row[$var].'</a></td>';
               $var = "status";
               $output .= '<td id="t_status_'.$teacher.'">'.$row[$var]. '</td>';
               $output .= '<td><button type="button" class="btn btn-default btn-danger teacher_delete" id="t_delete_'.$teacher.'">Delete</button></td>';
               $output .= ' </tr>'; 
             
           }

           $output .= ' </tbody>
                        </table>
                        </div>';

           $output .= ' 
                        <!--Create New Research Group , show Existing Research Groups-->
                        <div class="simple-form">
                            <div class="form-group">
                                <button type="button" class="btn btn-default btn-primary" id="create_research_group">Create New Research Group</button>
                                <button type="button" class="btn btn-default btn-danger" id="show_research_group">Show Existing Research Groups</button>
                            </div>
                        </div>';

            $output .= '<div id="existing_research_group">';

            $output .= '</div>';

           
           $output .= ' <!--Update-->
                        <div class="simple-form">
                            <div class="form-group">
                                <button type="button" class="btn btn-default btn-warning" id="update">Update</button>
                            </div>
                        </div>';
           $output .= '<div id="teacher_counter"> '.$teacher.'</div>';
           $output .= ' </div>'; 
           echo $output;
        }

        function select_all_from_admin_table($main_object){
            $query_make = new Query_Make();
            $sql = $query_make->select_query_general($query_make,"AdminTable","","");
            return $sql; 
        }
        function exeute_query($main_object,$sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql); 
            return $result; 
        }
        function select_all_teachers($main_object){
            $query_make = new Query_Make();
            $sql = $query_make->select_query_general($query_make,"TeacherTable","","");
            return $sql; 
        }

        function show_existing_reasearch_group($main_object){
           
            $output = ' <div class="simple-form"> ';
            $output .= ' <!--Show Existing Research Groups -->';
            $output .= ' <!--Research Group Showing Section -->
                        <div class="table-section-heading-decoration">
                            <h2>Existing Research Groups </h2>
                        </div>';
            $output .= '<table class="table table-bordered table-responsive" style="background:white;">';
            $output .= '<thead>';

            $output .= '<tr>';
            $output .= '<td>Research Group</td>';
            $output .= '</tr>';

            $output .= '</thead>';

            $output .= '<tbody>';
            $temp_arr = $main_object->bring_research_groups($main_object);
            for($i=0;$i<sizeof($temp_arr);$i=$i+1){
                $output .= '<tr>';
                $output .= '<td>'.$temp_arr[$i] .'</td>';
                $output .= '</tr>';
            }
            $output .= '</tbody>';
            $output .= '</table>';

            $output .= '</div>';
            echo $output;
        }

        function bring_research_groups($main_object){
            $query_make = new Query_Make();
            $sql = $query_make->select_query_general($query_make,"ResearchGroupInfo","","");
            $result = $main_object->exeute_query($main_object,$sql);
            $temp_arr = array();
            $ptr = -1;
            if($result) {
                while($row = mysqli_fetch_array($result)){
                    if($ptr == -1) {
                        $ptr=$ptr+1;
                        $temp_arr[$ptr] = $row["name"];
                    }
                    else {
                        $ok = 0;
                        for($i=0;$i<=$ptr;$i=$i+1){
                            if($row["name"] == $temp_arr[$i]) {
                                $ok=1;
                                break;
                            }
                        }
                        if($ok == 0) {
                            $ptr=$ptr+1;
                            $temp_arr[$ptr] = $row["name"];
                        }
                    }
                }
            }
            return $temp_arr;
        }

    }

?>
