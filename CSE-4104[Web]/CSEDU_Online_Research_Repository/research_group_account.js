/*This javascript file is used to make research_group_account.html
  and supervisor section  
*/
$(document).ready(function() {

    var teacher_counter = 0;
    var add_teacher_press = 0;
    var teacher_list = [];

    //global variables -sql_injection
    var sql_injection = '';

    //function to make the page 
    function bring_meta_data() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "bring"; //make page
        var variable = "research_group_account_metadata";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug:alert("account page section");
                //debug: alert(data);
                $('#research_group_metadata_server').html(data);
            }
        });
    }
    bring_meta_data();
    bring_research_group_supervisors();
    bring_research_group_files();

    //function will bring this groups supervisors wholely made for supervisor add delete section
    function bring_research_group_supervisors() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "bring"; //make page
        var variable = "supervisor_section";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug: alert("research group supervisors");
                teacher_list = [];
                add_teacher_press = 0;
                //debug:alert(data);
                $('#supervisor_add_section').html(data);
                $('#teacher_counter').hide();
                bring_create_thesis_section();
            }
        });
    }

    //function bring create thesis section 
    function bring_create_thesis_section() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "bring"; //make page
        var variable = "create_thesis_section";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug: alert("create thesis section");
                //debug:alert(data);
                $('#create_thesis_section_server').html(data);
            }
        });

    }

    //function bring research group files
    function bring_research_group_files() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "set"; //make page
        var variable = "page_name";
        var value = "research_group_account.php";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //now need to bring the files 
                operation = "bring";
                variable = "research_group_files_after_search";
                value = "";

                $.ajax({
                    url: path,
                    method: method,
                    data: { operation: operation, variable: variable, value: value },
                    success: function(data) {
                        //alert("file bring is complete");
                        //alert(data);
                        $('#files_from_server').html(data);
                        $('#file_counter').hide();
                        $('#view_file').hide();
                        $('.table-link').hide();
                    }
                });

            }
        });

    }



    function get_value_from_input(id) {
        return document.getElementById(id).value;
    }

    //update button
    $(document).on('click', '#update', function() {

        //debug:alert("update button pressed");

        var password = get_value_from_input('password');
        var confirm_password = get_value_from_input('confirm_password');
        if (password != confirm_password) return false;
        if (password == "") return false;

        sql_injection = check_valid_character(password);
        //debug: alert(sql_injection);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('password').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('password').style.borderColor = "";
        }


        //debug: alert("password check korsi");

        var research_group = get_value_from_input('name');

        //password_student
        var password_student = get_value_from_input('password_student');
        sql_injection = check_valid_character(password_student);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('password_student').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('password_student').style.borderColor = "";
        }

        //debug: alert("data neya shesh name ");
        var email = get_value_from_input('email');
        sql_injection = check_valid_character(email);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('email').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('email').style.borderColor = "";
        }


        //debug:alert("data neya shesh email ");
        var phone_1 = get_value_from_input('phone_1');
        sql_injection = check_valid_character(phone_1);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('phone_1').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('phone_1').style.borderColor = "";
        }

        var phone_2 = get_value_from_input('phone_2');
        sql_injection = check_valid_character(phone_2);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('phone_2').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('phone_2').style.borderColor = "";
        }
        var phone = phone_1 + "^" + phone_2;
        //debug:alert("data neya shesh phone  ");
        var link = get_value_from_input('link');
        sql_injection = check_valid_character(link);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('link').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('link').style.borderColor = "";
        }
        //debug:alert("data neya shesh link ");
        var google_drive = get_value_from_input('google_drive');
        sql_injection = check_valid_character(google_drive);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('google_drive').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('google_drive').style.borderColor = "";
        }

        var dropbox = get_value_from_input('dropbox');
        sql_injection = check_valid_character(dropbox);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('dropbox').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('dropbox').style.borderColor = "";
        }
        var github = get_value_from_input('github');
        sql_injection = check_valid_character(github);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('github').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('github').style.borderColor = "";
        }
        var facebook = get_value_from_input('facebook');
        sql_injection = check_valid_character(facebook);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' ` ' + ' ^ ' + ' ^ characters');
            document.getElementById('facebook').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('facebook').style.borderColor = "";
        }



        //debug: alert("data neya shesh ");

        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "update"; //make page
        var variable = "research_group_account";
        var value = research_group + "^" + password + "^" + email + "^" + phone + "^" + link + "^" + google_drive + "^" + dropbox + "^" + github + "^" + facebook + "^" + password_student;

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

    //delete button
    //this will delete the complete thesis 
    $(document).on('click', '#delete', function() {

        //debug: alert("delete button pressed for all thesis");

        var val = confirm("Are you sure?");
        if (val == false) return;


        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "delete"; //make page
        var variable = "complete_research_group";
        var value = get_value_from_input('name');

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //now we will log out and session destroy 
                //debug: alert(data);
                log_out();
            }
        });
        return false;
    });

    //add teacher 
    //add button 
    $(document).on('click', '#add_teacher', function() {
        var value = get_value_from_input('teacher_name');
        var res = parse_string_by_delim(value, '('); //res[0] = name, res[1] = email)
        var teacher_name = res[0];
        res = parse_string_by_delim(res[1], ')'); //res[0] will be  
        var teacher_email = res[0];
        teacher_counter = parseInt(get_value_from_innerHTML('teacher_counter'));
        while ((teacher_counter + add_teacher_press) > teacher_list.length) {
            teacher_list.push(1);
        }
        alert(teacher_name + " " + teacher_email + " " + teacher_counter);
        var ok = check_teacher_name(teacher_name, teacher_email);
        if (ok == true) {
            add_teacher_press++;
            teacher_list.push(1);
            add_new_supervisor(teacher_name, teacher_email);

        } else {
            alert("this supervisor already exists");
        }

    });

    //remove teacher 
    $(document).on('click', '.remove_teacher', function() {
        teacher_counter = parseInt(get_value_from_innerHTML('teacher_counter'));
        while ((teacher_counter + add_teacher_press) > teacher_list.length) {
            teacher_list.push(1);
        }
        var id = $(this).attr('id');
        //teacher number
        var res = parse_string_by_delim(id, '_');
        //remove_teacher_1
        var idx = parseInt(res[2]);
        teacher_list[idx - 1] = 0;
        //now need to hide and remove 
        var teacher_name = get_value_from_innerHTML('teacher_name_' + idx);
        var teacher_email = get_value_from_innerHTML('teacher_email_' + idx);

        //debug: alert("deleting = " + teacher_name + " " + teacher_email);
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "delete"; //make page
        var variable = "delete_supervisor";
        var value = teacher_name + "^" + teacher_email;

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //now we will bring the supervisors and create_thesis_section 
                alert(data);
                bring_research_group_supervisors();
            }

        });

    });

    //now log out 
    function log_out() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "set"; //make page
        var variable = "account^research_group^page_name";
        var value = "^^";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                path = "server_session_destroy.php";
                method = "POST";

                $.ajax({
                    url: path,
                    method: method,
                    data: {},
                    success: function(data) {
                        window.location = "home.php";
                    }
                });
            }
        });

    }

    function parse_string_by_delim(str, delim) {
        var res = str.split(delim);
        return res;
    }

    function get_value_from_innerHTML(id) {
        var res = document.getElementById(id).innerHTML;
        return res;
    }

    //teacher name already exists or not 
    function check_teacher_name(teacher_name, teacher_email) {
        for (i = 0; i < teacher_list.length; i++) {
            if (teacher_list[i] == 1) {
                var cnt = i + 1;
                var t_name = get_value_from_innerHTML('teacher_name_' + cnt);
                var t_email = get_value_from_innerHTML('teacher_email_' + cnt);
                if (t_name == teacher_name && t_email == teacher_email) return false;
            }
        }
        return true;
    }
    //bring a teacher's total information
    function add_new_supervisor(teacher_name, teacher_email) {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "add"; //make page
        var variable = "new_supervisor_in_research_group";
        var value = teacher_name + "^" + teacher_email;

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                alert("adding a new teacher");
                alert(data);
                bring_research_group_supervisors();
            }
        });
    }
    //now the file section 

});