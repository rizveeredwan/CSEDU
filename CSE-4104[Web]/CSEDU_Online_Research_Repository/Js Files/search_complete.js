/*Javascript file to complete search*/


function check_radio_button() {
    if (document.getElementById('project_thesis_radio').checked) {
        return "project_thesis";
    } else if (document.getElementById('research_group_radio').checked) {
        return "research_group";
    } else if (document.getElementById('supervisor_radio').checked) {
        return "supervisor";
    }
    return "";
}

$(document).on('click', '#search', function() {
    var query_type = check_radio_button();
    if (query_type == "supervisor") {
        supervisor_query();
    }
    if (query_type == "project_thesis") {
        project_thesis_query();
    }
    if (query_type == "research_group") {
        research_group_query();
    }
});

function get_value_from_input(id) {
    var value = document.getElementById(id).value;
    return value;
}

function supervisor_query() {
    value = get_value_from_input('supervisor');
    send_query("supervisor", value);
}

function research_group_query() {
    value = get_value_from_input('research_group');
    send_query("research_group", value);
}

function project_thesis_query() {
    //take values 
    var research_group = get_value_from_input("research_group");
    var supervisor = get_value_from_input("supervisor");
    var year_from = get_value_from_input("year_from");
    var year_to = get_value_from_input("year_to");
    var thesis_title = get_value_from_input("thesis_title");
    var program = get_value_from_input("program");
    var student = get_value_from_input("student");

    if (research_group == "Not Specific") research_group = "";
    if (supervisor == "Not Specific") supervisor = "";
    if (program == "Not Specific") program = "";


    var str = research_group + "^" + supervisor + "^" + year_from + "^" + year_to + "^" + thesis_title + "^" + program + "^" + student;
    send_query("project_thesis", str);
}

function send_query(query_type, given_value) {
    var path = "server_session_variable.php";
    var method = "POST";

    var operation = "query"; //make page
    var variable = query_type;
    var value = given_value;

    $.ajax({
        url: path,
        method: method,
        data: { operation: operation, variable: variable, value: value },
        success: function(data) {
            alert(data);
            $('#search_result').html(data);
        }

    });

}




$(document).on('click', '.view_details', function() {
    var id = $(this).attr('id');

    var path = "server_session_variable.php";
    var method = "POST";

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
});
