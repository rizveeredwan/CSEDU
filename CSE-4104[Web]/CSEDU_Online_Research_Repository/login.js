/*Javascript for log in page*/


$(document).ready(function() {

    /*global variables*/
    var current_page_name = "login.php";
    var sql_injection;

    /*Function to set page names*/
    function set_page() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = ""; //setting set operation
        var variable = "";
        var value = current_page_name;

        /*Now need to bring the log in form*/
        operation = "make";
        variable = "login.php";
        value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                /*debug: alert(data); */
                $('#came_from_server_log_in_form').html(data);
                $('#create_new').hide();

            }

        });
        return false;
    }

    set_page();

    function initialize() {
        $('#part-2').hide();
        $('#forgot_log_in_section').hide();
    }

    initialize();

    function return_id_value(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    $(document).on('click', '#submit', function() {
        var password = return_id_value('password');
        //checking validity
        sql_injection = check_valid_character(password);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            input_tag_border_change('password');
            return false;
        } else {
            document.getElementById('password').style.borderColor = "";
        }

        var account = return_id_value('account');
        var research_group = return_id_value('research_group');



        var path = "server_log_in.php";
        var method = "POST";
        //debug: alert("again " + password + " " + account + " " + research_group);
        $.ajax({
            url: path,
            method: method,
            data: { account: account, password: password, research_group: research_group },
            success: function(data) {
                if (data == "successful") {
                    alert(data);
                    if (account == "Student") {
                        $('#came_from_server_log_in_form').hide();
                        $('#part-2').show();
                    } else {
                        //normal person: Admin/Manager logged in
                        change_window_location();
                    }
                } else {

                    //debug: 
                    //alert("vugi " + data);
                    alert("password is not correct");
                    input_tag_border_change('password');
                }
            }
        });
        return false;
    });


    $(document).on('click', '#submit_two', function() {
        var code = return_id_value('code');

        //sql_injection prevent
        sql_injection = check_valid_character(code);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            input_tag_border_change('code');
            return false;
        } else {
            document.getElementById('code').style.borderColor = "";
        }


        var id = return_id_value('student_id');
        //sql_injection prevent
        sql_injection = check_valid_character(id);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            input_tag_border_change('student_id');
            return false;
        } else {
            document.getElementById('student_id').style.borderColor = "";
        }

        var path = "student_authentication_server.php";
        var method = "POST";
        //debug: alert("again " + code + " " + id + " ");
        $.ajax({
            url: path,
            method: method,
            data: { code: code, id: id },
            success: function(data) {
                if (data == "successful") {
                    alert(data);
                    change_window_location();
                } else {
                    alert("Student Authentication information is not correct");
                    input_tag_border_change('code');
                    input_tag_border_change('student_id');
                }
            }
        });
        return false;
    });

    $(document).on('click', '#create_new', function() {
        window.location = 'create_research_group.html';
        return false;
    });

    function change_window_location() {
        window.location = "home.php";
        return false;
    }

    //function to process on log in credential
    $(document).on('click', '.forgot', function() {
        $('#forgot_log_in_section').show();
        $('#part-2').hide();
        $('#came_from_server_log_in_form').hide();
        return false;
    });

    //function to parse string by delimeter
    function parse_string_by_delim(str, delim) {
        var res = str.split(delim);
        return res;
    }

    function add_something_in_id(id, str) {
        $('#' + id).html(str);
    }


    //function to mail
    $(document).on('click', '#mail', function() {
        var mail_person_type = return_id_value('mail_person_type');
        var subject = return_id_value('subject');
        var address = return_id_value('address');
        var message = return_id_value('message');

        var ok = 1;
        if (message == "") {
            document.getElementById('message').style.borderColor = "red";
            add_something_in_id('message_msg', '<div>can not be empty</div>');
            ok = 0;
        } else {
            document.getElementById('message').style.borderColor = "";
            add_something_in_id('message_msg', "")
        }
        if (subject == "") {
            document.getElementById('subject').style.borderColor = "red";
            add_something_in_id('subject_msg', '<div>can not be empty</div>');
            ok = 0;
        } else {
            document.getElementById('subject').style.borderColor = "";
            add_something_in_id('subject_msg', '');
        }
        if (address == "") {
            document.getElementById('address').style.borderColor = "red";
            add_something_in_id('address_msg', '<div>can not be empty</div>');
            ok = 0;
        } else {
            document.getElementById('address').style.borderColor = "";
            add_something_in_id('address_msg', '');
        }
        if (ok == 0) return false;

        //debug: alert(mail_person_type + " " + subject + " " + address + " " + message);
        subject = to_add_br_tag(subject);
        subject = mail_person_type + ": " + subject; //subject done 
        message = to_add_br_tag(message);
        message = message + '<br>' + 'Reply Address will be: ' + address;
        //debug: alert(subject + " " + message);

        on(); //overlay on

        var path = "PHPMailer/server_mail.php";
        var method = "POST";

        var email = "CseduResearchRepository@gmail.com";
        $.ajax({
            url: path,
            method: method,
            data: { email: email, subject: subject, message: message },
            success: function(data) {
                res = parse_string_by_delim(data, '\n');
                off(); //overlay off 
                alert(res[res.length - 1]);

            }
        });


        return false;
    });

    function to_add_br_tag(str) {
        var res = parse_string_by_delim(str, '\n');
        var cnt = 0;
        var reply = '';
        for (i = 0; i < res.length; i++) {
            if (res[i] != "") {
                cnt++;
                if (cnt == 1) {
                    reply = res[i];
                } else {
                    reply = reply + '<br>' + res[i];
                }
            }
        }
        return reply;
    }

    function input_tag_border_change(id) {
        document.getElementById(id).style.borderColor = "red";
    }



});