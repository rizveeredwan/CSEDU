/*purpose of this javascript file is to bring recent thesis/project and append */
$(document).ready(function() {

    var path = "server_session_variable.php";
    var method = "POST";

    var operation = "bring"; //bring data
    var variable = "recent_thesis_project";
    var value = "";

    $.ajax({
        url: path,
        method: method,
        data: { operation: operation, variable: variable, value: value },
        success: function(data) {
            //debug: alert(data);
            $('#recent_thesis_project_server').html(data);
        }
    });

});

$(document).on('click', '.recent_thesis_project', function(e) {
    e.preventDefault();
    var id = $(this).attr("id");
    var path = "server_session_variable.php";
    var method = "POST";
    if (id == "") return false;

    var operation = "set"; //make page
    var variable = "running_thesis_code^page_name";
    var value = id + "^" + "thesis_details.php";

    $.ajax({
        url: path,
        method: method,
        data: { operation: operation, variable: variable, value: value },
        success: function(data) {
            window.location = "thesis_details.php";
        }
    });

    return false;
});
