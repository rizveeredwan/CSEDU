<?php
/*This file makes common queries */


class Query_Make{

    public function insertion_query($query_make, $table_name,$attributes,$values){
        $sql = ' ';
        $sql = " INSERT INTO $table_name  ( ";

        //attributes
        for($i=0;$i<sizeof($attributes);$i=$i+1){
            $sql .= "`".$attributes[$i]."`". " ";
            if($i!=(sizeof($attributes)-1)){
                $sql .= ' , ';
            }
        }

        $sql .= ' ) ';
        //values
        $sql .= " VALUES ( ";
        for($i=0;$i<sizeof($values);$i=$i+1){
            $sql .= "'".$values[$i]."'"." ";
            if($i!=(sizeof($values)-1)){
                $sql .= ' , ';
            }
        }

        $sql .= ' ) ';
        return $sql;
    }

    public function select_query_general($query_make, $table_name,$attributes,$values){
        $sql = "SELECT * FROM $table_name ";
        return $sql; 
    }
    public function select_query_some_column($query_make, $table_name,$attributes,$values){
        $sql = "SELECT ";
        //attributes
        for($i=0;$i<sizeof($attributes);$i=$i+1){
            $sql .= ' '.$attributes[$i].' ';
            if($i!=(sizeof($attributes)-1)){
                $sql .= ',';
            }
        }
        $sql .= " FROM $table_name ";
        return $sql;
    }
   
    function conditional_select($query_make, $table_name,$attributes,$values){
         //this function will select all the columns
        //but conditional attributes will be given in attributes
        //and conditional values will be given in values
        $sql = "SELECT * FROM $table_name WHERE ";
        //attrubutes 
        for($i=0;$i<sizeof($attributes);$i=$i+1){
            $sql .= ' `'. $attributes[$i].'` '.'  like '." '".$values[$i]."'";
            if($i != (sizeof($attributes)-1)){
                //there is more conditions
                $sql .= ' AND '; 
            }
        }
        return $sql;
    }

    function update_query($query_make, $table_name,$attributes,$values,$condition_col, $condition_val){
        //update query 
        //table_name
        //attributes / column name
        //values = column value  
        //condition_column
        //condition_value
        $sql = ' '; 
        $sql .= ' UPDATE '.$table_name.' SET  ';

        for($i=0;$i<sizeof($attributes);$i=$i+1) {
            $sql .= '`'.$attributes[$i].'`'.' = '."'".$values[$i]."' " ;
            if($i !=(sizeof($attributes)-1)){
                $sql .= ' , '; 
            }

        }
        $sql .= ' ';
        $sql .= ' WHERE '; 

        for($i = 0; $i<sizeof($condition_col); $i=$i+1){
            $sql .= "`".$condition_col[$i]."`".' like  '."'".$condition_val[$i]."' ";
            if($i != (sizeof($condition_val)-1)){
                $sql .= ' AND '; 
            }
        }
        return $sql; 
    }

    function delete_query($query_make, $table_name,$attributes,$values){
        $sql = 'DELETE FROM '. $table_name .' WHERE ';
        for($i=0;$i<sizeof($attributes);$i=$i+1){
            $sql .= ' `'.$attributes[$i].'`'.' like  '."'".$values[$i]."' ";
            if($i != (sizeof($attributes)-1)){
                $sql .= ' AND '; 
            }
        }
        return $sql; 
    }
}

?>