/*Javascript file to control research_group_file_show_controller*/
$(document).ready(function() {
    //first need to bring research group names
    var path = "server_session_variable.php";
    var method = "POST";

    var operation = "bring"; //make page
    var variable = "research_group_name_option";
    var value = "";

    $.ajax({
        url: path,
        method: method,
        data: { operation: operation, variable: variable, value: value },
        success: function(data) {
            $('#research_group_name_option_from_server').html(data);
        }
    });

    function get_value_from_input(id) {
        return document.getElementById(id).value;
    }

    function get_value_from_innerHTML(id) {
        return document.getElementById(id).innerHTML;
    }

    //now after pressed on search button
    $(document).on('click', '#search', function() {
        var name = get_value_from_input('name');
        //now need to bring research group files

        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "bring"; //make page
        var variable = "research_group_files_after_search";
        var value = name;

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug: alert(data);
                $('#research_group_files_server').html(data);
                make_on_off();
                authority_based_decision(name);
            }
        });

    })

    //need to make off
    function make_on_off() {
        $('#file_counter').hide();
        $('.hide-button').hide();
        $('.table-link').hide();
        $('.hide-column').hide(); //delete button's column is hided
        $('#view_file').hide(); //files view is hided
    }

    function authority_based_decision(name) {
        //here name = research_group name 
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "get"; //make page
        var variable = "account^research_group";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //alert(data);
                var res = parse_string_by_delim(data, '^');
                if (res[0] == "Admin") {
                    //so okay everything
                } else if (res[0] == "Manager" || res[0] == "Student") {
                    //now check research group
                    if (res[1] == name) {
                        //research group matched, ok everything
                    } else {
                        //check view 
                        var val_authority = get_value_from_innerHTML(id);
                        if (val_authority == "Yes") {
                            //so everything is ok
                        } else {
                            //no outside of research group can't watch 
                            $('.file_view_link').hide(); //file can't be viewed
                            $('.file_download_link').hide(); //file can't be downloaded
                        }
                    }
                } else {
                    $('.file_view_link').hide(); //file can't be viewed
                    $('.file_download_link').hide(); //file can't be downloaded
                }
            }
        });
    }

    function parse_string_by_delim(str, delim) {
        var res = str.split(delim);
        return res;
    }
});