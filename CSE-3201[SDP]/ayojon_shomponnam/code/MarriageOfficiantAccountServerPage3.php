<?php
  
  session_start();
  $username = $_SESSION["username"];

  $output='';
  $output.='<div id="tableSpecial">';
  $output.='<table id="scheduleTable" align="center" >
  <tr>
      <th>Date</th>
      <th>Time</th>
      <th>Customer Booked</th>
  </tr>
  <tr id="row0" class="tableView">
      <td><input type="date" name="" value="27-05-2018" id="r0" weight="1px"></td>
      <td><input type="text" name="" value="morning" id="c0"></td>
      <td><input type="text" name="" value="C02" id="b0"></td>
      <td><input type="submit" name="" class="delButton" value="Delete" id="0"></td>
  </tr>"
  </table></div>';

  echo $output;

?>