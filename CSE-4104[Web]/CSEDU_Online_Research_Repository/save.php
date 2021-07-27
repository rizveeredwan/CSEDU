<?php
    session_start();
    $var = 'null';
    if(isset($_REQUEST['key'])){
        $var = $_REQUEST['key'];
    }
?>

<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="bootstrap-3.3.7-dist/css/bootstrap.min.css">
    <script src="Jquery/jquery-3.3.1.js"></script>
    <script src="bootstrap-3.3.7-dist/js/bootstrap.min.js"></script>
</head>

<body>
  <div>I am testing request method now.</div>
</body>
<script>
    var id=0;
    $(document).ready(function(){
       var vari= '<?php echo $var;?>';
       alert(vari);
    });
   
</script>

</html>