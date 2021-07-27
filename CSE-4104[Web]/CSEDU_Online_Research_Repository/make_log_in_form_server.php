<?php

    

    /*View File: Makes Log In*/
    Class Make_Log_In_Form{

        function start_view($main_class){
            $attributes = array("account");
            $sql = $main_class->make_select_query_with_attribute($main_class,$attributes);
            $result = $main_class->execute_query($sql);

            $attributes[0]="research_group";
            $sql = $main_class->make_select_query_with_attribute($main_class,$attributes);
            $result2 = $main_class->execute_query($sql);

            //view mading being started
            $final_result = ' <div class="form" id="part-1"> ';
            $final_result .= ' <div></div> ';
            $final_result .= ' <div> ';
            $final_result .= '      <form class="form-container"> ';
            $final_result .= '          <h1>Log in</h1> ';
            $final_result .= '          <!--Account Type--> ';
            $final_result .= '          <div class="form-group"> ';
            $final_result .= '              <label for="account_type">Account</label>';
            $final_result .= '<select class="form-control" id="account">';
            //adding account
            //duplicate will not be added
            $final_variable = $main_class->remove_duplicate($main_class,$result,"account");
            for($i=0;$i<sizeof($final_variable);$i=$i+1){
                $final_result .= ' <option> ' .$final_variable[$i] .' </option>';
            }
            $final_result .= ' </select> ';
            $final_result .= ' </div> '; 
            
            $final_result .= ' <!--Research Group Selection--> ';
            $final_result .= '  <div class="form-group"> ';
            $final_result .= ' <label for="research_group">Research Group</label> ';
            $final_result .= ' <select class="form-control" id="research_group"> ';
            //adding Research Group
            //duplicate will not be added
            //$ptr is pointer here
            $final_variable = $main_class->remove_duplicate($main_class,$result2,"research_group");
            for($i=0;$i<sizeof($final_variable);$i=$i+1){
                $final_result .= ' <option> ' .$final_variable[$i] .' </option>';
            }
            $final_result .= ' </select> ';
            $final_result .= ' </div> '; 
            
            $final_result .= ' <!--Password -->';
            $final_result .=  '<div class="form-group">
                                    <label for="password">Password</label>
                                    <input type="password" class="form-control" id="password" placeholder="Password">
                            </div>';
            $final_result .= '<!--Submit button-->
                                <button type="submit" class="btn btn-default" id="submit">Submit</button>
                                <!--Create New Research group-->
                                <button type="submit" class="btn btn-default" id="create_new">Create New Research Group</button>
                                <button type="button" class="btn btn-default forgot">Forgot Log In</button>
                                </form> ';

            $final_result .= '  </div> ';
            $final_result .=  '<div> </div>';
            $final_result .= ' </div>';
            
            echo $final_result;
        }

        /*Function will make select query to bring the whole table: LogInTable*/
        function make_select_query($main_class) {
            $query_make = new Query_Make();
            $sql = $query_make->select_query_general($query_make,"LogInTable","","");
            return $sql;
        }
        function make_select_query_with_attribute($main_class,$attributes) {
            $query_make = new Query_Make();
            $sql = $query_make->select_query_some_column($query_make,"LogInTable",$attributes,"");
            return $sql;
        }
        /*Function to execute query*/
        function execute_query($sql){
            $sql_query = new SQL_Query();
            $result = $sql_query->query_execute_return_result($sql_query,$sql);
            return $result;
        }
        /*function process_query*/
        function remove_duplicate($main_class,$result,$attribute){
            /*find unique*/
            $final_account = array();
            $ptr=0;

            while($row=mysqli_fetch_array($result)){
                $value = $row[$attribute];
                if($ptr==0){
                    $final_account[$ptr] = $value;
                    $ptr=$ptr+1;
                }
                else {
                    $ok = 0;
                    for($i=0;$i<$ptr;$i=$i+1){
                        if($final_account[$i] == $value) {
                            $ok=1;
                            break;
                        }
                    }
                    if($ok==0){
                        $final_account[$ptr] = $value;
                        $ptr=$ptr+1;
                    }
                }

            }
            return $final_account;
        }

    }
?>