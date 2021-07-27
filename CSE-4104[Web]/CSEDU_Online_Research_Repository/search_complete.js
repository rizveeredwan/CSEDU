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
    var sql_injection = '';
    value = get_value_from_input('supervisor');
    //sql_injection prevent
    sql_injection = check_valid_character(value);
    if (sql_injection == false) {
        alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
        input_tag_border_change('supervisor');
        return false;
    } else {
        document.getElementById('supervisor').style.borderColor = "";
    }

    send_query("supervisor", value);
}

function research_group_query() {
    value = get_value_from_input('research_group');
    //sql_injection prevent
    var sql_injection = check_valid_character(value);
    if (sql_injection == false) {
        alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
        input_tag_border_change('research_group');
        return false;
    } else {
        document.getElementById('research_group').style.borderColor = "";
    }
    send_query("research_group", value);
}

function project_thesis_query() {
    var sql_injection = '';
    //take values 
    var research_group = get_value_from_input("research_group");
    //sql_injection prevent - research_group
    sql_injection = check_valid_character(research_group);
    if (sql_injection == false) {
        alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
        input_tag_border_change('research_group');
        return false;
    } else {
        document.getElementById('research_group').style.borderColor = "";
    }

    var supervisor = get_value_from_input("supervisor");
    //sql_injection prevent - supervisor
    sql_injection = check_valid_character(supervisor);
    if (sql_injection == false) {
        alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
        input_tag_border_change('supervisor');
        return false;
    } else {
        document.getElementById('supervisor').style.borderColor = "";
    }

    var year_from = get_value_from_input("year_from");
    //sql_injection prevent - year_from
    sql_injection = check_valid_character(year_from);
    if (sql_injection == false) {
        alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
        input_tag_border_change('year_from');
        return false;
    } else {
        document.getElementById('year_from').style.borderColor = "";
    }

    var year_to = get_value_from_input("year_to");
    //sql_injection prevent - year_to
    sql_injection = check_valid_character(year_to);
    if (sql_injection == false) {
        alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
        input_tag_border_change('year_to');
        return false;
    } else {
        document.getElementById('year_to').style.borderColor = "";
    }
    var thesis_title = get_value_from_input("thesis_title");
    //sql_injection prevent - thesis_title
    sql_injection = check_valid_character(thesis_title);
    if (sql_injection == false) {
        alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
        input_tag_border_change('thesis_title');
        return false;
    } else {
        document.getElementById('thesis_title').style.borderColor = "";
    }


    var program = get_value_from_input("program");
    var student = get_value_from_input("student");
    //sql_injection prevent - thesis_title
    sql_injection = check_valid_character(student);
    if (sql_injection == false) {
        alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
        input_tag_border_change('student');
        return false;
    } else {
        document.getElementById('student').style.borderColor = "";
    }

    if (research_group == "Not Specific") research_group = "";
    if (supervisor == "Not Specific") supervisor = "";
    if (program == "Not Specific") program = "";

    /*checking year*/
    //year_from
    var year_cond = to_check_year(year_from);
    if (year_cond == false) {
        alert('not valid year');
        input_tag_border_change('year_from');
        return false;
    }
    //year_to
    year_cond = to_check_year(year_to);
    if (year_cond == false) {
        alert('not valid year');
        input_tag_border_change('year_to');
        return false;
    }
    //year correcting
    if (year_from != "" && year_to != "") {
        if (year_from > year_to) {
            var vari = year_from;
            year_from = year_to;
            year_to = vari;
        }
    }



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
            //debug: alert(data);
            $('#search_result').html(data);
        }

    });

}

function encoding(thesis_code) {
    var str = '';
    for (i = 0; i < thesis_code.length; i++) {
        var n = thesis_code.charCodeAt(i);
        if (str == '') {
            str = n;
        } else {
            str = str + '+' + n;
        }
    }
    return str;
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
            var str = encoding(id);
            //window.location = "thesis_details.php"; 1st version,total page change
            //window.location = "thesis_details.php?key=" + str; //2nd version,total page change,key value with
            window.open("thesis_details.php?key=" + str, '_blank'); //3rd version 
        }
    });
    return false;
});


function input_tag_border_change(id) {
    document.getElementById(id).style.borderColor = "red";
    return false;
}