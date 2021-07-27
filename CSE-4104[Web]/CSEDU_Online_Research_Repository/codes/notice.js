/*Javascript file to handle the notice part */
$(document).ready(function() {

    //global variables 
    var notice_list = [];
    var add_press = 0;


    var path = "server_session_variable.php";
    var method = "POST";

    var operation = "bring"; //bring data
    var variable = "notice";
    var value = "";

    $.ajax({
        url: path,
        method: method,
        data: { operation: operation, variable: variable, value: value },
        success: function(data) {
            //debug: alert(data);
            $('#notice_server').html(data);
            $('#notice_counter').hide();
            make_on_off();
        }
    });

    function get_value_from_input(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    function get_value_from_innerHTML(id) {
        var value = document.getElementById(id).innerHTML;
        return value;
    }

    function set_inner_html(id, value) {
        document.getElementById(id).innerHTML = value;
        return;
    }
    //function to add notice
    $(document).on('click', '#add_notice', function() {
        var value = get_value_from_input('new_notice');
        if (value == "") return;
        add_press = add_press + 1;
        var prev = parseInt(get_value_from_innerHTML('notice_counter'));
        while ((add_press + prev) > notice_list.length) {
            notice_list.push(1);
        }
        var str = '';
        str += '<tr id="row_' + notice_list.length + '">';
        str += '<td id="row_num_' + notice_list.length + '"> ' + 0 + '</td>';
        str += '<td id="row_value_' + notice_list.length + '"> ' + value + '</td>';
        str += ' <td><button type="button" class="btn btn-default btn-danger delete" id="delete_' + notice_list.length + '">Delete</button></td>';
        str += '</tr>';

        $('#notice_table > tbody:last-child').append(str);
        fix_row_num();

        return false;
    });

    //function fix row number 
    function fix_row_num() {
        var counter = 0;
        for (var i = 0; i < notice_list.length; i++) {
            if (notice_list[i] == 1) {
                var val = i + 1;
                counter = counter + 1;
                set_inner_html("row_num_" + val, counter);
            }
        }
    }

    //function to delete
    $(document).on('click', '.delete', function() {
        var id = $(this).attr("id");
        var res = parse_string_by_delim(id, "_");
        var idx = parseInt(res[1]);

        var prev = parseInt(get_value_from_innerHTML('notice_counter'));
        while ((add_press + prev) > notice_list.length) {
            notice_list.push(1);
        }
        notice_list[idx - 1] = 0;
        $('#row_' + idx).hide();
        fix_row_num();

    });

    function parse_string_by_delim(str, delim) {
        var result = str.split(delim);
        return result;
    }

    $(document).on('click', '#update', function() {
        var prev = parseInt(get_value_from_innerHTML('notice_counter'));
        while ((add_press + prev) > notice_list.length) {
            notice_list.push(1);
        }

        var str = '';
        for (i = 0; i < notice_list.length; i++) {
            if (notice_list[i] == 1) {
                var val = i + 1;
                var value = get_value_from_innerHTML('row_value_' + val);
                if (str == "") str = value;
                else str = str + "^" + value;
            }
        }
        make_update_in_database(str);
    });

    function make_update_in_database(str) {

        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "update"; //bring data
        var variable = "notice";
        var value = str;

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                alert(data);
            }
        });
    }

    function make_on_off() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "get"; //bring data
        var variable = "account";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                if (data != "Admin") {
                    $('.need-to-hide').hide();
                    $('.delete').hide();
                }
            }
        });

    }

});