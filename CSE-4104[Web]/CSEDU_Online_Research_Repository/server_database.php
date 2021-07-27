<?php 


    /*Server side file*/
    /*Purpose of this file is to establish database connection and also close it*/

    class Database_Connection{
        /*variables*/
        public $servername="";
        public $username="";
        public $password="";
        public $conn="";
        public $database_name="";
        public $database_connection="";
        
        
        /*private constructor*/ 
        private function __construct(){}

        /*function to get instance*/
        public static function get_instance(){
            
            $database_connection="";
            if($database_connection==""){
                $database_connection=new Database_Connection();
                $database_connection=$database_connection->initialize_database($database_connection);
                $database_connection->conn = mysqli_connect($database_connection->servername, $database_connection->username,$database_connection->password,$database_connection->database_name);
                if ($database_connection->conn->connect_error) {
                    die("Connection failed: " . $database_connection->conn->connect_error);
                } 
                if($database_connection->conn == ""){
                   echo "null connection error";
                }
            }
            return $database_connection;       
        }

        function initialize_database(Database_Connection $database_connection){
            $database_connection->servername="localhost";
            $database_connection->username="root";
            $database_connection->password="";
            $database_connection->database_name="CSEDU_Online_Research_Repository";
            return $database_connection;
        }

        
    }
?>