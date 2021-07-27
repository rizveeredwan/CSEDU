/*Javascript file to control home.js*/
$(document).ready(function() {

    var page_name = "home.php";

    function set_page() {
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
                if (data == "successful") {
                    change_color_of_an_id("home_option");
                }
            }

        });


    }

    set_page();

    function change_color_of_an_id(id) {
        document.getElementById(id).style.background = "black";
    }



});
