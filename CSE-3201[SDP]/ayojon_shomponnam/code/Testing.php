<?php
  session_start();
  //include 'LogInServer.php';
  $variable = $_SESSION["username"];
?>

<html>
   <body>
      <script type="text/javascript">
          var v = "<?php echo $variable;?>";
          window.onload = function(){
             f(v);
          }
          function f(v){
            document.write(v);
            return false;
          }
      </script>
   </body>
</html>
