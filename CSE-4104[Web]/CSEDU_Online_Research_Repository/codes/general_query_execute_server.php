<?php
   

    /*Server side file*/
    /*Purpose of this file is to perform INSERT DELETE UPDATE operation*/
    

    /*Included files*/
    //to bring database connection
    include "server_database.php";


    /*function of this class is to perform insert delete update operations*/
    class SQL_Query{

        public $database_connection; 

        public function query_execute($sql_query,$sql){
            $sql_query->database_connection = Database_Connection::get_instance();
            $result = mysqli_query($sql_query->database_connection->conn, $sql);
            if($result){
                echo "successful";
            }
            else {
                echo "error in insert-delete-update operation"; 
            }
        }
        public function query_execute_return_result($sql_query,$sql){
            $sql_query->database_connection = Database_Connection::get_instance();
            $result = mysqli_query($sql_query->database_connection->conn, $sql);
            if($result){
                return $result;
            }
            else {
                echo "error in select/return operation"; 
            }
        }
    }

    
    
?>