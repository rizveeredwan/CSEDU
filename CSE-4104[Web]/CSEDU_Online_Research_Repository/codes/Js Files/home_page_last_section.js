//purpose to go to page 
//research_group_file.html
//others.html
//about_us.html
$(document).on('click', '.home_page_last_section', function() {
    var id = $(this).attr("id");

    var path = "server_session_variable.php";
    var method = "POST";

    var operation = "set"; //setting set operation
    var variable = "page_name";
    var value = id;
    $.ajax({
        url: path,
        method: method,
        data: { operation: operation, variable: variable, value: value },
        success: function(data) {
            location.href = id;
        }
    });
    return false;
});