<?php
  session_destroy();
  header("Location: LogInClient.php"); /* Redirect browser */
  exit;
?>