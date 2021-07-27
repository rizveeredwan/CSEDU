/*Javascript for log in page*/


$(document).ready(function() {
    /*global variables*/
    var current_page_name = "login.php";

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

            }

        });
        return false;
    }

    set_page();

    function initialize() {
        $('#part-2').hide();
    }

    initialize();

    function return_id_value(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    $(document).on('click', '#submit', function() {
        var password = return_id_value('password');
        var account = return_id_value('account');
        var research_group = return_id_value('research_group');

        var path = "server_log_in.php";
        var method = "POST";
        alert("again " + password + " " + account + " " + research_group);
        $.ajax({
            url: path,
            method: method,
            data: { account: account, password: password, research_group: research_group },
            success: function(data) {
                if (data == "successful") {
                    alert(data);
                    if (account == "Student") {
                        $('#part-2').show();
                    } else {
                        //normal person: Admin/Manager logged in
                        change_window_location();
                    }
                } else {

                    //debug: 
                    //alert("vugi " + data);

                    alert("password is not correct");
                }
            }
        });
        return false;
    });


    $(document).on('click', '#submit_two', function() {
        var code = return_id_value('code');
        var id = return_id_value('student_id');

        var path = "student_authentication_server.php";
        var method = "POST";
        alert("again " + code + " " + id + " ");
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


});
