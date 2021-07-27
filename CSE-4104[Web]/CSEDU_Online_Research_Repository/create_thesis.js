/*This javascript file is used to create thesis
  used in research_group_account.html
*/

$(document).ready(function() {

    /*global variables*/
    var student_number = 0;
    var supervisor_email = '';
    var all_emails = [];
    var subject = '';
    var message = '';

    //sql injection part 
    var sql_injection = '';


    function get_value_from_input_tag(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    //function to add row for pressing 
    $(document).on('click', '#student_list_create', function() {

        student_number++;
        var str = '';
        //debug: alert("ase");
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
        //debug: alert(str);
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
        //thesis_name
        sql_injection = check_valid_character(thesis_name);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            document.getElementById('thesis_name').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('thesis_name').style.borderColor = "";
        }

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
        ok = check_validity(year);
        if (!ok) {
            alert("year has to be provided");
            return false;
        }

        //year
        sql_injection = check_valid_character(year);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            document.getElementById('year').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('year').style.borderColor = "";
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
                //debug: alert("kichu hoise mama");
                //debug: alert(data);
                var res = parse_string_by_delim(data, '^');
                if (res[0] == "successful") {
                    alert(res[0]);
                    var thesis_code = res[1];
                    var student_code = res[2];
                    mail(thesis_name, supervisor_name, year, thesis_code, student_code);
                }

            }
        });

        return false;
    });
    //function to delete last row
    $(document).on('click', '#student_list_delete', function() {
        //need to hide last row
        if (student_number >= 1) {
            //debug: alert(student_number);
            $("#st_row_" + student_number).hide();
            student_number--;
        }
        return false;
    });

    //function to parse string by delim
    function parse_string_by_delim(str, delim) {
        var res = str.split(delim);
        return res;
    }

    //functions to mail
    function mail(thesis_title, supervisor, year, thesis_code, student_code) {
        var research_group = get_value_from_input_tag('name');
        //subject
        subject = 'New thesis/project created under CSEDU Research Repository.';
        //message
        message = 'A New Poject/Thesis  Created under ' + research_group + '. In the following you will find the details.<br>';
        message = message + 'Research Group: ' + research_group + '<br>';
        message = message + 'Thesis title: ' + thesis_title + '<br>';
        message = message + 'Supervisor name: ' + supervisor + '<br>';
        message = message + 'Year: ' + year + '<br>';
        message = message + 'Thesis Code ' + thesis_code + '<br>';
        message = message + 'Student Code: ' + student_code + '<br>';
        message = message + 'Thesis partners:<br>';

        //debug: alert("string = " + message);
        all_emails = [];
        for (i = 1; i <= student_number; i++) {
            var st_name = get_value_from_input_tag("st_name_" + i);
            message = message + 'Name: ' + st_name + '<br>';
            var st_mail = get_value_from_input_tag("st_email_" + i);
            message = message + 'Email: ' + st_mail + '<br>';
            all_emails.push(st_mail);
        }
        alert("string = " + message);

        //modal text 
        var str = '<div>';
        str += '<h2>Mail to be sent</h2>';
        str += 'Supervisor: <input type="text" id="supervisor_email" value="' + supervisor_email + '">';
        for (i = 0; i < all_emails.length; i++) {
            var cnt = i + 1;
            str += 'Student ' + cnt + ': <input type="text" value="' + all_emails[i] + '">';
        }
        str += '<div>';

        //debug: alert("string = " + str);
        $('#modal_description').html(str);
        $('#my_modal').modal('show');

    }

    $(document).on('click', '#send_mail', function() {
        $('#my_modal').modal('hide');
        supervisor_email = get_value_from_input_tag('supervisor_email');
        all_emails.push(supervisor_email);
        var email = '';
        var cnt = 0;
        for (i = 0; i < all_emails.length; i++) {
            if (all_emails[i] != "") {
                cnt++;
                if (cnt != 1) {
                    email += '^';
                }
                email = email + all_emails[i];
            }
        }
        //debug: alert(email + " " + subject + " " + message);
        on();

        var path = "PHPMailer/server_mail.php";
        var method = "POST";

        $.ajax({
            url: path,
            method: method,
            data: { email: email, subject: subject, message: message },
            success: function(data) {
                //debug: alert(data);
                var res = parse_string_by_delim(data, '\n');
                off();
                //debug: alert(res[res.length - 1]);
                show_which_mail_were_successful(res[res.length - 1]);
            }
        });

    });

    function show_which_mail_were_successful(res) {
        res = parse_string_by_delim(res, '.');
        //make a string for modal
        var str = '<div>';
        str += '<h2>Mail Sent Results</h2>';
        str += 'Supervisor: <input type="text" id="supervisor_email" value="' + supervisor_email + '">';
        str += '<br>';
        for (i = 0; i < all_emails.length; i++) {
            if (all_emails[i] == supervisor_email) {
                str += '<label>' + "status: " + res[i] + '</label><br>';
                break;
            }
        }
        temp_list = [];
        for (i = 0; i < all_emails.length; i++) {
            if (all_emails[i] != "" && all_emails[i] == supervisor_email) continue;
            var v = res[i].search("Mail has been sent successfully");
            if (v == -1) {
                //mail couldn't be sent to this email address
                temp_list.push(all_emails[i]);
                str += '<label>' + "Email: " + all_emails[i] + '</label><br>';
                str += '<label>' + "status: " + res[i] + '</label><br>';
            }
        }
        str += '</div>';

        //modal on
        $('#modal_description').html(str);
        $('#my_modal').modal('show');

    }

});