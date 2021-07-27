/*A javascript file to control other.html*/
$(document).ready(function() {

    var mail_press = 0;
    var add_press = 0;
    var add_list = [];

    $(document).on('click', '.facility', function() {
        var id = $(this).attr('id');
        if (id == "research_group_files") {
            var path = "server_session_variable.php";
            var method = "POST";

            var operation = "set"; //make page
            var variable = "page_name";
            var value = "research_group_files.php";

            $.ajax({
                url: path,
                method: method,
                data: { operation: operation, variable: variable, value: value },
                success: function(data) {
                    window.location = "research_group_files.php";
                }

            });

        }
        if (id == "google_drive" || id == "dropbox" || id == "github" || id == "facebook") {
            //need to see if logged in and then page location 
            go_to_other_websites(id);
        }

        if (id == "mail") {
            mail();
        }

    });

    function go_to_other_websites(id) {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "bring"; //make page
        var variable = "google_dropbox_git_facebook";
        var value = id;

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug: alert(data);
                if (data != "") {
                    alert("going to " + data);
                    window.location = data;
                } else {
                    alert("No Link Provided by Research Group.");
                }
            }
        });
    }

    function mail() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "bring"; //make page
        var variable = "mail_system";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug:alert(data);
                $('#mail_section_server').html(data);
                add_press = 0;
                add_list = [];
            }
        });
    }

    function get_value_from_input(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    function parse_string_by_delim(str, delim) {
        var res = str.split(delim);
        return res;
    }
    //after pressing mail sent button
    $(document).on('click', '#mail_submit', function() {
        var person = get_value_from_input('person');
        var subject = get_value_from_input('subject');
        var message = get_value_from_input('message');

        var res = parse_string_by_delim(message, '\n');
        message = '';
        var line_cnt = 0;
        for (i = 0; i < res.length; i++) {
            if (res[i] != "") {
                line_cnt++;
                if (line_cnt > 1) {
                    message += '</br>';
                }
                message += res[i];
            }
        }

        var res = parse_string_by_delim(person, '(');
        var email = parse_string_by_delim(res[1], ')');
        email = email[0];

        //now need to mail
        var path = "PHPMailer/server_mail.php";
        var method = "POST";

        //alert(email + " " + subject + " " + message);
        $('#mail_reply').html('sending..');
        on();

        $.ajax({
            url: path,
            method: method,
            data: { email: email, subject: subject, message: message },
            success: function(data) {
                res = parse_string_by_delim(data, '\n');
                //debug: alert(res[res.length - 1]);
                var val = '<div>' + res[res.length - 1] + '</div>';
                $('#mail_reply').html(val);
                off();
            }
        });

    });

    $(document).on('click', '#group_mail', function() {

        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "bring"; //make page
        var variable = "group_mail_system";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug: alert(data);
                $('#mail_section_server').html(data);
                add_press = 0;
                add_list = [];
            }
        });
        return false;
    });

    $(document).on('click', '.add_in_group_mail', function() {


        var id = $(this).attr('id');
        var name = [];
        var email = [];
        var val = '';
        if (id == "add_supervisor") {
            val = get_value_from_input('supervisor_name');
        } else if (id == "add_student") {
            val = get_value_from_input('student_name');
        }
        var res = parse_string_by_delim(val, '('); //res[0] name , res[1] email)
        name = res[0];
        res = parse_string_by_delim(res[1], ')');
        email = res[0];

        var ok = check_into_table(name, email);
        if (ok == false) return; //will repeat if goes forward

        //now saving into table
        add_press++;
        add_list.push(1);
        var str = '<tr id="row_' + add_press + '"> ';
        str += '<td id="address_' + add_press + '_name" >' + name + '</td>';
        str += '<td id="address_' + add_press + '_email" >' + email + '</td>';
        str += '<td id="address_' + add_press + '_status" >' + "Not Sent" + '</td>';
        str += '<td><button type="button" class="btn btn-default btn-danger delete" id="delete_' + add_press + '" >Delete</button></td>';
        str += '</tr>';

        //debug: alert(str);
        $('#mail_table > tbody:last-child').append(str);

    });

    $(document).on('click', '.delete', function() {
        var id = $(this).attr('id');
        var res = parse_string_by_delim(id, '_');
        var idx = parseInt(res[1]);
        add_list[idx - 1] = 0;
        $('#row_' + idx).hide();
    });

    function get_value_from_innerHTML(id) {
        return document.getElementById(id).innerHTML;
    }

    function check_into_table(name, email) {
        for (i = 0; i < add_list.length; i++) {
            if (add_list[i] == 0) continue;
            var cnt = i + 1;
            var n = 'address_' + cnt + '_' + 'name';
            var e = 'address_' + cnt + '_' + 'email';
            n = get_value_from_innerHTML(n);
            e = get_value_from_innerHTML(e);
            //debug: alert(n + " " + e);
            if (n == name && e == email) return false;
        }
        return true;
    }

    $(document).on('click', '#group_mail_submit', function() {

        var subject = get_value_from_input('group_subject');
        var message = get_value_from_input('group_message');

        //debug: alert(add_list.length);
        var jog = 0;
        for (i = 0; i < add_list.length; i++) {
            //debug: alert("printing ");
            //debug: alert(add_list[i] + " val ");
            if (add_list[i] == 0) continue;
            var cnt = i + 1;
            var n = 'address_' + cnt + '_' + 'name';
            var e = 'address_' + cnt + '_' + 'email';
            n = get_value_from_innerHTML(n);
            e = get_value_from_innerHTML(e);
            jog++;
            if (jog == 1) {
                sent_string = e;
            } else {
                sent_string += '^' + e;
            }
        }
        if (jog == 0) return false;
        total_mail(subject, message, sent_string);

        return false;
    });

    function total_mail(subject, message, participants) {


        var res = parse_string_by_delim(message, '\n');
        message = '';
        var line_cnt = 0;
        for (i = 0; i < res.length; i++) {
            if (res[i] != "") {
                line_cnt++;
                if (line_cnt > 1) {
                    message += '<br>';
                }
                message += res[i];
            }
        }
        res = parse_string_by_delim(subject, '\n');
        subject = ' ';
        line_cnt = 0;
        for (i = 0; i < res.length; i++) {
            if (res[i] != "") {
                line_cnt++;
                if (line_cnt > 1) {
                    subject += '<br>';
                }
                subject += res[i];
            }
        }

        var email = participants;


        //now need to mail
        var path = "PHPMailer/server_mail.php";
        var method = "POST";

        //alert(email + " " + subject + " " + message);
        document.getElementById('mail_reply').innerHTML = "Sending...";
        on(); //overlay on

        $.ajax({
            url: path,
            method: method,
            data: { email: email, subject: subject, message: message },
            success: function(data) {
                res = parse_string_by_delim(data, '\n');
                //debug: alert("mail sent");
                //debug: alert(res);
                //debug: alert(res[res.length - 1]);
                reply_after_mail(res[res.length - 1], email);
                off(); //overlay off

            }
        });

    }

    function set_innerHTML(id, str) {
        document.getElementById(id).innerHTML = str;
        return;
    }

    function reply_after_mail(status, emails) {
        emails = parse_string_by_delim(emails, '^');
        status = parse_string_by_delim(status, '.');
        //debug: alert(status[0] + " " + status[1]);
        document.getElementById('mail_reply').innerHTML = "";
        var j = 0;
        for (i = 0; i < add_list.length; i++) {
            if (add_list[i] == 1) {
                var cnt = i + 1;
                var e = 'address_' + cnt + '_' + 'email';
                var n = 'address_' + cnt + '_' + 'status';
                e = get_value_from_innerHTML(e);
                //debug: alert(emails[j] + " " + e);
                if (emails[j] != "" && e == emails[j]) {
                    //alert("milse" + status[j]);
                    var val = status[j].search("Mail has been sent successfully")
                    if (val != -1) {
                        //alert("Er pore dhukse " + status[j]);
                        set_innerHTML(n, "sent");
                    }
                    j++;
                }
            }
        }
    }

});