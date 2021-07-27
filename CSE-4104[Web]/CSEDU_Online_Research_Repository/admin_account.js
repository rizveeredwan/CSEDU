/*Purpose of this file is to write a javascript file
  for admin_account.html
*/
$(document).ready(function() {

    //global variables 
    var sql_injection = '';

    var teacher_list = [];
    var add_press = 0;
    //First need to bring the whole page
    bring_page();

    //purpose of this function is to bring the page 
    function bring_page() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "make"; //make page
        var variable = "admin_account.php";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug: alert(data);
                $('#will_come_from_server').html(data);
                things_to_hide();
            }

        });
    }

    //function to add new teacher
    $(document).on('click', '#add_teacher', function() {
        //now need to get the values 
        var t_name = get_value_from_input_tage('t_name');
        var t_designation = get_value_from_input_tage('t_designation');
        var t_email = get_value_from_input_tage('t_email');
        var t_phone = get_value_from_input_tage('t_phone');
        var t_portfolio = get_value_from_input_tage('t_portfolio');
        var t_status = get_value_from_input_tage('t_status');


        /* debug: alert(t_name + " " + t_designation + " " + t_email + " " + t_phone + " " + t_portfolio + " " + t_status); */
        if (t_name == "" || t_designation == "" || t_email == "") {
            alert("name,designation and email all of them has to be filled.");
        }

        /* Need to insert into teacher table */
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "add"; //make page
        var variable = "add_into_teacher_table";
        var value = t_name + "^" + t_designation + "^" + t_email + "^" + t_phone + "^" + t_portfolio + "^" + t_status;

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                alert(data);
                if (data == "successful") {
                    add_row_in_table();
                }
            }
        });


    });

    function get_inner_html(id) {
        var value = document.getElementById(id).innerHTML;
        return value;
    }

    function add_row_in_table() {
        add_press++;
        var val = get_inner_html('teacher_counter');
        val = parseInt(val);
        while ((val + add_press) > teacher_list.length) {
            teacher_list.push(1);
        }
        //now need to get the values 
        var t_name = get_value_from_input_tage('t_name');
        var t_designation = get_value_from_input_tage('t_designation');
        var t_email = get_value_from_input_tage('t_email');
        var t_phone = get_value_from_input_tage('t_phone');
        var t_portfolio = get_value_from_input_tage('t_portfolio');
        var t_status = get_value_from_input_tage('t_status');
        var teacher = teacher_list.length;
        var output = ' ';
        output = ' <tr id="t_row_' + teacher + '">';
        var val = "name";
        output += '<td id="t_name_' + teacher + '">' + t_name + '</td>';
        val = "designation";
        output += '<td id="t_designation_' + teacher + '">' + t_designation + '</td>';
        val = "email";
        output += '<td id="t_email_' + teacher + '">' + t_email + '</td>';
        val = "phone";
        output += '<td id="t_phone_' + teacher + '">' + t_phone + '</td>';
        val = "portfolio";
        output += '<td id="t_portfolio_' + teacher + '">' + '<a href="' + t_portfolio + '">' + t_portfolio + '</a></td>';
        val = "status";
        output += '<td id="t_status_' + teacher + '">' + t_status + '</td>';
        output += '<td><button type="button" class="btn btn-default btn-danger teacher_delete" id="t_delete_' + teacher + '">Delete</button></td>';
        output += ' </tr>';
        $('#teacher_table > tbody:last-child').append(output);
    }

    function get_value_from_input_tage(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    function things_to_hide() {
        $('#teacher_counter').hide();
    }


    //function to delete teacher
    $(document).on('click', '.teacher_delete', function() {
        var id = $(this).attr("id");
        var res = parse_string_by_delim(id, "_");
        var idx = parseInt(res[2]); //t_delete_1
        /*debug alert("idx " + idx); */

        var val = get_inner_html('teacher_counter');
        val = parseInt(val);
        while ((val + add_press) > teacher_list.length) {
            teacher_list.push(1);
        }
        teacher_list[idx - 1] = 0;



        /*to delete from teacher table*/
        var t_name = get_inner_html('t_name_' + idx);
        var t_designation = get_inner_html('t_designation_' + idx);
        var t_email = get_inner_html('t_email_' + idx);

        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "delete"; //make page
        var variable = "delete_from_teacher_table";
        var value = t_name + "^" + t_designation + "^" + t_email;
        //debug: alert("value = " + value);

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                alert(data);
                if (data == "successful") {
                    $('#t_row_' + idx).hide();
                }
            }
        });

    });

    function parse_string_by_delim(str, delim) {
        var res = str.split(delim);
        return res;
    }

    //function to create new research groups
    $(document).on('click', '#create_research_group', function() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "set"; //make page
        var variable = "page_name";
        var value = "create_research_group.php";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                window.location = "create_research_group.php";
            }
        });
    })

    //function to show existing research groups
    $(document).on('click', '#show_research_group', function() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "make"; //make page
        var variable = "existing_research_group";
        var value = "";

        /*debug: alert("ase"); */

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                $('#existing_research_group').html(data);
            }
        });

    });

    //update
    $(document).on('click', '#update', function() {
        /*debug: alert("ase"); */
        var password = get_value_from_input_tage('password');

        //sql_injection prevent
        sql_injection = check_valid_character(password);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            document.getElementById('password').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('password').style.borderColor = "";
        }

        var confirm_pass = get_value_from_input_tage('confirm_password');
        if (password != confirm_pass) {
            alert("password confirmation is must");
            return false;
        }
        var email = get_value_from_input_tage('email');
        //sql_injection prevent
        sql_injection = check_valid_character(email);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            document.getElementById('email').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('email').style.borderColor = "";
        }

        var phone = get_value_from_input_tage('phone');
        //sql_injection prevent
        sql_injection = check_valid_character(phone);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            document.getElementById('phone').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('phone').style.borderColor = "";
        }

        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "update"; //make page
        var variable = "admin_account";
        var value = password + "^" + email + "^" + phone;

        /*debug alert("ase"); */
        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                alert(data);
            }
        });

    });


});