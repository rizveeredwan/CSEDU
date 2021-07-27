<?php
    session_start();
    if(isset($_SESSION["page_name"])) {
        echo $_SESSION["page_name"];
    }
    else {
        echo "null";
    }
?>