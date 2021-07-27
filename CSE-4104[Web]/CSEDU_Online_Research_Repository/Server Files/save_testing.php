<?php
    session_start();
    $_SESSION["page_name"]="mehreen";
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="bootstrap-3.3.7-dist/css/bootstrap.min.css">
    <script src="Jquery/jquery-3.3.1.js"></script>
    <script src="bootstrap-3.3.7-dist/js/bootstrap.min.js"></script>
</head>

<body>
    <div id="obj">
        <button type="button" id="butt">Press</button>
    </div>
    <div id="jog"><div>
</body>
<script>
    var id=0;
    $(document).ready(function(){
        $(document).on('click','#butt',function(){
            alert("asi");
            id=(id+1)%2;
            if(id%2 == 0) {
                $('#jog').html("<div>jog</div>");
            }
        else {
            $('#jog').append("<div>biyog</div>");
        }
        return false;
        });
    });
   
</script>

</html>
