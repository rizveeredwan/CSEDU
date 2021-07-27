/*This is a common js file*/
$(document).ready(function() {


    /*global variables*/
    var log_button_link = "";
    var account_button_link = "";

    /*going to new page*/
    $(document).on('click', '.menu-per-option-decoration', function() {
        /*debug: alert("yes");*/
        var selected_menu_option = $(this).attr("id");

        var page_name = "";
        if (selected_menu_option == "home_option") {
            page_name = "home.php";
        }
        if (selected_menu_option == "upload_option") {
            page_name = "upload.php";
        }
        if (selected_menu_option == "search_option") {
            page_name = "search.php";
        }
        if (selected_menu_option == "faq_option") {
            page_name = "faq.php";
        }
        if (selected_menu_option == "other_option") {
            page_name = "other.php";
        }
        /*debug: alert(page_name); */
        /*setting page name and going to that page*/
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "set"; //setting set operation
        var variable = "page_name";
        var value = page_name;

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                /*debug: alert("done");*/
                window.location = page_name;
            }

        });
        return false;
    });

    /*Action on coloring depending on present page*/
    function coloring_option() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "get"; //setting set operation
        var variable = "page_name";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                /*This basically finds page name and color the options*/
                //debug:alert("came to color " + data);
                var opt = "";
                if (data == "home.php") {
                    opt = "home_option";
                }
                if (data == "upload.php") {
                    opt = "upload_option";
                }
                if (data == "search.php") {
                    opt = "search_option";
                }
                if (data == "faq.php") {
                    opt = "faq_option";
                }
                if (data == "other.php") {
                    opt = "other_option";
                }
                if (opt != "") change_color_of_an_id(opt);
            }
        });

    }

    /*calls to color a menu bar option*/
    coloring_option();

    function change_color_of_an_id(id) {
        document.getElementById(id).style.background = "black";
    }

    /*part to see log in or not*/
    function check_log_in() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "get"; //setting set operation
        var variable = "account";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                activity_based_on_log_in(data);
            }


        });

    }
    /*calls to check log in condition*/
    check_log_in();

    function to_change_innerHTML(id, string) {
        document.getElementById(id).innerHTML = string;
    }

    function activity_based_on_log_in(data) {
        if (data == "") {
            /*no one is logged in */
            log_button_link = "login.php";
            $('#account_button').hide();
        } else {
            /*logged in*/
            to_change_innerHTML('log_button', 'Log Out');
            log_button_link = "";
            $('#account_button').show();
            /*account button*/
            if (data == "Admin") {
                account_button_link = "admin_account.php";
            }
            if (data == "Student") {
                account_button_link = "student_account.php";
            }
            if (data == "Manager") {
                account_button_link = "research_group_account.php";
            }
        }
    }

    $(document).on('click', '#log_button', function() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "";
        var variable = "";
        var value = "";

        if (log_button_link == "") {

            account_button_link = "";
            //need to log out
            operation = "set";
            variable = "account^password^research_group^thesis_code";
            value = "^^^"
            $.ajax({
                url: path,
                method: method,
                data: { operation: operation, variable: variable, value: value },
                success: function(data) {
                    alert("succesfully logged out");
                    //need to set home.html as page_name
                    operation = "set";
                    variable = "page_name";
                    value = "home.php";

                    //sending
                    $.ajax({
                        url: path,
                        method: method,
                        data: { operation: operation, variable: variable, value: value },
                        success: function(data) {
                            path = "server_session_destroy.php";
                            method = "";
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
            });


            return false; //need to refresh

        } else {
            //go to log in page
            operation = "set";
            variable = "page_name";
            value = "login.php";

            $.ajax({
                url: path,
                method: method,
                data: { operation: operation, variable: variable, value: value },
                success: function(data) {
                    //will go to log in page
                    window.location = log_button_link;
                }

            });
            return false; //need not to
        }

    });

    //the account button
    $(document).on('click', '#account_button', function() {
        //as logged in
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "set";
        var variable = "page_name";
        var value = account_button_link;
        /*debug: alert("value = " + value);*/
        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //will go to log in page
                window.location = account_button_link;
            }
        });
        return false;
    });

});
