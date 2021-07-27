/*Javascript file to upload in server and return the link*/
$(document).ready(function() {

    var tot_file = 0;
    var file_list = [];

    /*global function*/
    $('.table-link').hide();


    function get_value_from_input_tage(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    function get_inner_html(id) {
        var value = document.getElementById(id).innerHTML;
        return value;
    }

    $(document).on('click', '#file_submit', function() {
        //need to upload file 
        //first file type
        var file = document.getElementById('file_input').files[0];

        var sql_injection = check_valid_character(file.name);
        if (sql_injection == false) {
            alert("File Name contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            return false;
        }

        if (file) {
            /*debug: alert("sending"); */
            //first take file view option
            var path = "server_session_variable.php";
            var method = "POST";

            var operation = "set"; //make page
            var variable = "view";
            /*alert("yes");*/
            var value = get_value_from_input_tage('view');
            /*alert("value = " + value);*/

            $.ajax({
                url: path,
                method: method,
                data: { operation: operation, variable: variable, value: value },
                success: function(data) {
                    var form_data = new FormData();
                    form_data.append("file", file);
                    var ajax = new XMLHttpRequest();
                    var path = "server_file_upload.php";
                    ajax.open("POST", path);
                    ajax.send(form_data);
                    ajax.onreadystatechange = function() {
                        if (ajax.readyState == 4 && ajax.status == 200) {
                            var return_data = ajax.responseText;
                            //debug: alert(return_data);
                            if (data == "unsuccessful") {
                                alert("Problem during uploading file.\n");
                            } else {
                                //File uploaded successfully 
                                var val = get_inner_html('file_counter');
                                /*debug: alert(val);
                                alert(return_data); */
                                add_into_table(return_data);
                            }
                        }
                    };
                }
            });
        }
    });


    //function to add into database and into table
    function add_into_table(link) {

        var val = get_inner_html('file_counter');
        tot_file++;
        val = parseInt(val);
        while ((val + tot_file) > file_list.length) {
            file_list.push(1);
        }
        var res = split_from_delim(link, '`');
        //making creating a row 
        var output = ' ';
        output += '<tr id="file_row_' + file_list.length + '">';
        output += '<td>' + res[res.length - 1] + '</td>';
        output += '<td><a href="' + link + '" target="_blank" id="file_ref_' + file_list.length + '" >View</a></td>';
        output += '<td><a href="' + link + '" download="' + res[res.length - 1] + '">Download</a></td>';
        output += '<td class="table-link" id="file_link_' + file_list.length + '">' + link + '</td>';
        output += '<td><button type="button" class="btn btn-default btn-danger file-delete-button" id="file_delete_' + file_list.length + '">Delete</button></td>';
        output += '</tr>'

        /*debug alert("ase"); */
        //adding into table 
        $('#file_table > tbody:last-child').append(output);
        /*alert("done");
        alert(output);*/
        hide_special_column();
        update_into_database();
    }

    function split_from_delim(str, delim) {
        var res = str.split(delim);
        return res;
    }

    function get_href(id) {
        var val = document.getElementById(id).href;
        return val;
    }

    //pupose of this function is to add into databse
    function update_into_database() {


        //need to save view first
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "set"; //make page
        var variable = "view";
        var value = get_value_from_input_tage('view');

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //read from table and send
                var str = read_from_table();
                //now need to save into table
                path = "server_save_link_into_database.php";
                method = "POST";
                var link = str;
                //debug:alert(str);
                $.ajax({
                    url: path,
                    method: method,
                    data: { link: link },
                    success: function(data) {
                        //debug: alert("data " + data);
                        if (data == "successful") {
                            alert("data saved succesfully\n");
                        } else {
                            alert("error while saving link into database");
                        }
                    }
                });
            }

        });

    }

    function read_from_table() {
        var str = "";
        /*debug: alert("came");*/
        for (i = 0; i < file_list.length; i++) {
            var idx = i + 1;
            var id = "file_link_" + idx;
            var val = get_inner_html(id);
            /* debug: alert("val = " + val); */
            if (file_list[i] == 1) {
                str = str + val + "^";
            }
        }
        /*debug: alert("bair hoi"); */
        return str;
    }

    function hide_special_column() {
        $('.table-link').hide();
    }

    //function to delete files
    $(document).on('click', '.file-delete-button', function() {
        var id = $(this).attr("id");
        var res = split_from_delim(id, "_");
        var file_num = parseInt(res[res.length - 1]);
        var val = get_inner_html('file_counter');
        val = parseInt(val);
        /*alert("asi " + val);
        alert("asi " + tot_file);*/
        while ((val + tot_file) > file_list.length) {
            file_list.push(1);
            /*debug: alert("size = " + file_list.length); */
        }
        file_list[file_num - 1] = 0;
        var row_id = "#" + "file_row_" + file_num;
        /*alert(row_id);*/
        $(row_id).hide();
        update_into_database();
    });


});