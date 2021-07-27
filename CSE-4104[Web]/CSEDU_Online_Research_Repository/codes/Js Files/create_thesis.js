/*This javascript file is used to create thesis
  used in research_group_account.html
*/

$(document).ready(function() {

    /*global variables*/
    var student_number = 0;


    function get_value_from_input_tag(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    //function to add row for pressing 
    $(document).on('click', '#student_list_create', function() {

        student_number++;
        var str = '';
        alert("ase");
        for (i = 1; i <= 1; i++) {
            str += ' <tr id="st_row_' + student_number + '"> ';
            str += '<td><input type="text" id="st_name_' + student_number + '" class="form-control" placeholder="name"></td>';
            str += '<td><input type="text" id="st_roll_' + student_number + '" class="form-control" placeholder="roll"></td>';
            str += '<td><input type="text" id="st_email_' + student_number + '"class="form-control" placeholder="email"></td>';
            var program_tag;
            program_tag = '<td>';
            program_tag += '<select class="form-control" id="st_program_' + student_number + '" >';
            program_tag += '<option>BSc.</option>';
            program_tag += '<option>MSc.</option>';
            program_tag += '<option>Phd</option>';
            program_tag += '<option>Extra</option>';
            program_tag += '</select>';
            program_tag += '</td>';
            str += program_tag;
            //str += '<td><input type="text" id="st_program_' + student_number + '"class="form-control" placeholder="BSc./MSc"></td>';
            str += '</tr>';
        }
        alert(str);
        //appending in table
        //appending 
        $('#student_info > tbody:last-child').append(str);
        return false;
    });

    function check_validity(value) {
        if (value == "") return false;
        return true;
    }

    //function to add thesis into the database
    $(document).on('click', '#create_thesis', function() {


        var thesis_name = get_value_from_input_tag('thesis_name');
        var supervisor_name = get_value_from_input_tag('supervisor_name');

        var ok = check_validity(thesis_name);
        if (!ok) {
            alert("thesis name has to be provided");
            return false;
        }
        ok = check_validity(supervisor_name);
        if (!ok) {
            alert("supervisor name has to be provided");
            return false;
        }
        var year = get_value_from_input_tag('year');
        if (!ok) {
            alert("year has to be provided");
            return false;
        }
        /*debug alert("yo view "); */
        var view = get_value_from_input_tag('view');
        /*debug alert(view + "view "); */

        //student number
        //getting value from table
        /*debug: alert(student_number);*/
        var data = thesis_name + "^" + supervisor_name + "^" + year + "^" + view + "^";
        for (i = 1; i <= student_number; i++) {
            var value = get_value_from_input_tag("st_name_" + i);
            data += value + "^";
            value = get_value_from_input_tag("st_roll_" + i);
            data += value + "^";
            /*value = get_value_from_input_tag("st_session_" + i);
            data += value + "^";*/
            value = get_value_from_input_tag("st_email_" + i);
            data += value + "^";
            value = get_value_from_input_tag("st_program_" + i);
            data += value + "^";
            /*debug: alert("data " + data); */
        }
        //now need to sent
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "add"; //add means adding into table
        var variable = "add_into_thesis_group_info_table";
        var value = data;
        /*alert("value = " + value);*/
        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                alert(data);
            }
        });

        return false;
    });
    //function to delete last row
    $(document).on('click', '#student_list_delete', function() {
        //need to hide last row
        if (student_number >= 1) {
            alert(student_number);
            $("#st_row_" + student_number).hide();
            student_number--;
        }
        return false;
    });

});