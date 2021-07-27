<?php
    /*Php file to bring research group names */
    class Research_Group_Name_Option{
        protected $name;

        function work($main_object){
          $result = $main_object->bring_all_research_group($main_object);
          $output = ' ';
          $output .= '  <!--Files Section -->
          <div>
              <!-- Heading Section -->
              <!-- heading decoration -->
              <div class="table-section-heading-decoration">
                  <h2>Research Group Files</h2>
              </div>
      
              <!--The bar under Header Section -->
              <div class="bar-under-menu" style="margin-left:2%; margin-right:2%;">
                  <div class="bar-under-menu-main-part"></div>
              </div>
      
              <!-- space creating div -->
              <div style="padding: 2% 0 2% 0;"></div>
      
              <!-- Input section -->
              <div style="margin-left:2%; margin-right:2%;">
                  <div class="form-group">
                      <select class="form-control" id="name">';
        while($row = mysqli_fetch_array($result)){
            $output .= '<option>'.$row["name"].'</option>';
        }           
        $output .=' </select>
                  </div>
                  <div class="form-group">
                      <button type="button" class="btn btn-default btn-danger" id="search">Search</button>
                  </div>
              </div>';
              echo $output;
        }

        function bring_all_research_group($main_object){
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