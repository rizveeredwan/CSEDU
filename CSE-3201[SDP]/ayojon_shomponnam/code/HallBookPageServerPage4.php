<?php
  session_start();
  $currentSelectedId = $_SESSION["currentSelectedId"];
  $form = $_POST["from"];
  $to = $_POST["to"];
  //function of this page is to give a table which will say from which date to which there is booked
  $output=".";
  $output .= '<div id="result">
             <table id="bookedTable" align="center">
            <tr>
            <th>Date</th>
            <th>Time</th>
            </tr>
            <tr>
             <td>12-02-1996</td>
            <td>Morning</td>
            </tr>
            </table>
            </div>';
echo $output;

?>