<?php
    /* To show research group files: Just need to ask which research group*/
    class Research_Group_Files{
        protected $page_name;
        protected $research_group;
        function work($main_object,$value){
             
            if(isset($_SESSION["page_name"])){
                $main_object->page_name = $_SESSION["page_name"];
                if($main_object->page_name=="research_group_account.php") {
                    $main_object->research_group = $_SESSION["research_group"]; //account page
                                                                                //log in preference
                }
                if($main_object->page_name == "research_group_files.php") {
                    //just to see research group files 
                    $main_object->research_group = $value;
                }

                $output = '<div>';
                $output .= '<!--Research Group Files-->
                            <!-- space creating div -->
                            <div style="padding: 2% 0 2% 0;"></div>

                            <div style="margin-left:2%; margin-right:2%;">
                            <div class="table-section-heading-decoration">
                                <h2>Files</h2>
                            </div>
                            <!-- Table -->
                            <div style="margin-left:5%; margin-right:5%;">
                            <table class="table table-bordered table-responsive" style="background:white;" id="file_table">
                                <thead></thead>
                                <tbody>';
                $result = $main_object->bring_research_group_files($main_object);
                $file_links = '';
                $view = '';
                while($row = mysqli_fetch_array($result)){
                    $file_links = $row["link"];
                    $view = $row['view'];
                }
                //now need to split by ^ 
                $counter=0;
                //debug: echo $main_object->research_group;
                //debug: echo "file name = ".$file_links;
                $file_links = $main_object->split_from_delemeter($file_links,'^');
               
                for($i=0;$i<sizeof($file_links);$i=$i+1){ 
                    //echo $file_links[$i];
                    if($file_links[$i] == "") continue;
                    $file_name = $main_object->split_from_delemeter($file_links[$i],'/');
                    $file_name = $main_object->split_from_delemeter($file_name[1],'`');
                    if($file_name[sizeof($file_name)-1] != "") {
                        $counter=$counter+1;
                        $output .= '<tr id="file_row_'.$counter.'">';
                        $output .= '<td>'.$file_name[sizeof($file_name)-1].'</td>';
                        $link = $file_links[$i];
                        $output .= '<td class="file_view_link"><a href="'.$link.'" target="_blank" id="file_ref_'.$counter.'">View</a></td>';
                        $output .= '<td class="file_download_link"><a href="'.$link.'" download="'.$file_name[sizeof($file_name)-1].'">Download</a></td>';
                        $output .= '<td class="table-link" id="file_link_'.$counter.'">'.$link.'</td>';
                        $output .= '<td class="hide-column"><button type="button" class="btn btn-default btn-danger file-delete-button hide-button" id="file_delete_'.$counter.'">Delete</button></td>';
                        $output .= '</tr>';
                    } 
                }


                $output .= '</tbody>
                                            </table>
                                            </div>
                                            </div>';
                $output .= '<div id="file_counter">'.$counter.'</div>';

                $output .= '<div id="view_file">'.$view.'</div>';

                $output .= '</div>';
                echo $output;
            }
        }

        function bring_research_group_files($main_object){
            $query_make = new Query_Make();
            $attribute = array("id");
            $value = array($main_object->research_group);
            $sql = $query_make->conditional_select($query_make,"Files",$attribute,$value);
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

    }

?>
