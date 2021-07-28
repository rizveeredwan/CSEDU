<?php
  session_start();
  //$_SESSION["name"] = "Rizvee";
?>

<!doctype html>
<html>
     <script>
         var x = "<?php echo $_SESSION['name'];?>";
         document.write(x);
     </script>
</html>


