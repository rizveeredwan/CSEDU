/*Function to bring and control thesis_detail*/
$(document).ready(function() {
    /*global variables*/
    var account = "",
        research_group = "",
        thesis_code = "",
        thesis_id = "",
        page_name = "";
    var running_thesis_code = "";
    var thesis_name = "";
    var supervisor_name = "";
    var year = "";
    var view = "";

    var student_list = [];
    var add_student_press = 0;

    //var sql_injection = '';

    /*Function to bring the thesis_code_section part*/
    var path = "server_session_variable.php";
    var method = "POST";

    var operation = "get"; //make page
    var variable = "account^research_group^thesis_code^thesis_id^page_name^running_thesis_code";
    var value = "";
    //this will bring the thesis_code_section part 
    $.ajax({
        url: path,
        method: method,
        data: { operation: operation, variable: variable, value: value },
        success: function(data) {
            take_decision(data);
        }
    });

    function take_decision(data) {
        var res = parse_string_by_delim(data, "^");
        if (res[0] == "Student" && res[4] == "student_account.php" && res[2] != "") {
            //for student account page things will be brought
            account = res[0];
            research_group = res[1];
            thesis_code = res[2];
            thesis_id = res[3];
            page_name = res[4];
            /* debug: alert("ase"); */
            make_page(thesis_code);
        } else if (res[4] == "thesis_details.php") {
            //debug: alert("ok " + res[5]);
            if (res[5] != "") {
                make_page_for_thesis_details();
            }
        }


    }

    function parse_string_by_delim(str, delim) {
        var res = str.split(delim);
        return res;
    }

    function make_page(thesis_code_to_bring) {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "make"; //make page
        var variable = "student_account.php";
        var value = "";
        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug: alert(data);
                $("#thesis_total_information").html(data);
                //hide file counter
                $('#file_counter').hide(); //File counter vanish
                $('#student_counter').hide(); //student counter vanish 
                $('.table-link').hide(); //file link hide
                $('#delete_thesis').hide();
            }
        });
    }

    function to_check_zero_in_list() {
        counter = 0;
        for (i = 0; i < student_list.length; i++) {
            if (student_list[i] == 1) counter++;
        }
        return counter;
    }

    //function to add new row in table
    $(document).on('click', '#add_student', function() {
        //creating a new student information table
        add_student_press++;
        var val = get_inner_html("student_counter");
        val = parseInt(val);
        while ((val + add_student_press) > student_list.length) {
            student_list.push(1);
        }
        var output = ' ';
        //this students div
        output += '<div id="student_' + student_list.length + '" >';

        //label 
        output += '    <div class="form-group">';
        output += '      <label for="student" id="student_label_' + student_list.length + '"> Student ' + to_check_zero_in_list() + ' </label>';
        output += '    </div>';

        //student row 
        output += '<div>';
        output += '   <table class="table table-bordered table-responsive" style="background:white;" id="st_row_"' + student_list.length + '">';
        output += '  <thead></thead> ';
        output += '  <tbody> ';

        //name 
        var value = '';
        var add = "name";
        output += '  <tr> ';
        output += '   <td>' + add + '</td> ';
        output += '   <td><input type="text" class="input-field-design make-input-readonly" name="" placeholder="' + add + '" id="st_' + add + '_' + student_list.length + '" value="' + value + '" ></td>';
        output += ' </tr> ';

        value = '';
        add = "roll";
        output += '  <tr> ';
        output += '   <td>' + add + '</td> ';
        output += '   <td><input type="text" class="input-field-design make-input-readonly" name="" placeholder="' + add + '" id="st_' + add + '_' + student_list.length + '" value="' + value + '" ></td>';
        output += ' </tr> ';

        //program part 
        output += '<tr>';
        output += '<td>Program</td>';
        output += '<td>';
        output += ' <select class="form-control" id="st_prog_' + student_list.length + '" >  ';
        output += '<option>BSc</option>';
        output += '<option>MSc</option>';
        output += '<option>Phd</option>';
        output += '<option>Extra</option>';
        output += ' </select> ';
        output += '   </td> ';
        output += '  </tr> ';

        //email
        value = '';
        add = "email";
        output += '  <tr> ';
        output += '   <td>' + add + '</td> ';
        output += '   <td><input type="text" class="input-field-design make-input-readonly" name="" placeholder="' + add + '" id="st_' + add + '_' + student_list.length + '" value="' + value + '" ></td>';
        output += ' </tr> ';

        //table end 
        output += '</tbody>';
        output += '</table>';
        output += ' </div>';

        output += '<!-- -->';
        output += '<!-- Delete Button -->';
        output += ' <div class="form-group"> ';
        output += '<button type="button" class="btn btn-default btn-danger student-delete hide-button" id="st_delete_' + student_list.length + '" >Delete</button>';
        output += '</div>';

        output += '</div>';

        //now appending in student_information
        $('#student_information').append(output);
    })

    function get_inner_html(id) {
        var value = document.getElementById(id).innerHTML;
        return value;
    }

    //now the part of delete 
    $(document).on('click', '.student-delete', function() {
        var id = $(this).attr("id");
        var res = parse_string_by_delim(id, "_");
        var st_num = parseInt(res[res.length - 1]);
        var val = get_inner_html("student_counter");
        val = parseInt(val);
        while ((val + add_student_press) > student_list.length) {
            student_list.push(1);
        }
        //now need to make zero in the list
        student_list[st_num - 1] = 0;
        //need to hide 
        var will_hide = "#" + "student_" + st_num;
        $(will_hide).hide();
        change_label();
    });

    function change_inner_html(id, str) {
        document.getElementById(id).innerHTML = str;
        return;
    }
    //now need to change the label
    function change_label() {
        var counter = 0;
        for (i = 0; i < student_list.length; i++) {
            if (student_list[i] == 1) {
                counter = counter + 1;
                var idx = i + 1;
                var id = "student_label_" + idx;
                var str = "Student " + counter;
                change_inner_html(id, str);
            }
        }
    }

    //function to read student information datas 
    $(document).on('click', '#update', function() {
        var output = to_read_student_information();
        if (output == "") return false;
        //now need to send
        var path = "server_update_thesis_info.php";
        var method = "POST";
        $.ajax({
            url: path,
            method: method,
            data: { data: output },
            success: function(data) {
                /*debug: alert("asche");*/
                alert(data);
            }
        });

    });

    function get_value_from_input_tage(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    function to_read_student_information() {
        var str = '';
        var val = get_inner_html("student_counter");
        val = parseInt(val);
        while ((val + add_student_press) > student_list.length) {
            student_list.push(1);
        }
        thesis_name = get_value_from_input_tage('thesis_name');
        //sql_injection prevent -thesis_name
        sql_injection = check_valid_character(thesis_name);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            document.getElementById('thesis_name').style.borderColor = "red";
            return "";
        } else {
            document.getElementById('thesis_name').style.borderColor = "";
        }

        supervisor_name = get_value_from_input_tage('supervisor_name');
        research_group = get_value_from_input_tage('research_group');
        year = get_value_from_input_tage('year');
        //sql_injection prevent - year
        sql_injection = check_valid_character(year);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            document.getElementById('year').style.borderColor = "red";
            return "";
        } else {
            document.getElementById('year').style.borderColor = "";
        }


        view = get_value_from_input_tage("view");
        str = thesis_name + "^" + supervisor_name + "^" + research_group + "^" + year + "^" + view;
        alert("str " + str);
        for (i = 0; i < student_list.length; i++) {
            if (student_list[i] == 1) {
                //student data
                str = str + "^";
                //name
                var idx = i + 1;

                var id = "st_name_" + idx;
                var value = get_value_from_input_tage(id);
                str = str + value + "^";
                //sql_injection prevent - st_name_idx
                //sql_injection = check_valid_character(value);
                //alert(sql_injection);
                /*if (sql_injection == false) {
                    alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
                    document.getElementById(id).style.borderColor = "red";
                    return "";
                } else {
                    document.getElementById(id).style.borderColor = "";
                }*/


                id = "st_roll_" + idx;
                value = get_value_from_input_tage(id);
                str = str + value + "^";

                //sql_injection prevent - st_name_idx
                /*sql_injection = check_valid_character(value);
                if (sql_injection == false) {
                    alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
                    document.getElementById(id).style.borderColor = "red";
                    return "";
                } else {
                    document.getElementById(id).style.borderColor = "";
                }*/

                id = "st_prog_" + idx;
                value = get_value_from_input_tage(id);
                str = str + value + "^";


                id = "st_email_" + idx;
                value = get_value_from_input_tage(id);
                str = str + value;
                //sql_injection prevent - st_name_idx
                /*sql_injection = check_valid_character(value);
                if (sql_injection == false) {
                    alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
                    document.getElementById(id).style.borderColor = "red";
                    return "";
                } else {
                    document.getElementById(id).style.borderColor = "";
                }*/

                alert("str = " + str);
            }
        }
        return str;
    }

    //button action based on thesis_code_submit press
    $(document).on('click', '#thesis_code_submit', function() {
        var value = get_value_from_input_tage('thesis_code'); //This will be running thesis code
        running_thesis_code = value;

        if (running_thesis_code == "") return;

        //Sql injection part
        //sql_injection prevent -thesis_code_submit
        sql_injection = check_valid_character(value);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
            document.getElementById('thesis_code').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('thesis_code').style.borderColor = "";
        }



        //now need to save the running thesis code
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "set"; //make page
        var variable = "running_thesis_code";
        var value = running_thesis_code;

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                if (data == "successful") {
                    //session variable as running_thesis_code is saved 
                    //now need to make page 
                    operation = "make";
                    variable = "upload.php";
                    value = "";
                    $.ajax({
                        url: path,
                        method: method,
                        data: { operation: operation, variable: variable, value: value },
                        success: function(data) {
                            $("#thesis_total_information").html(data);
                            to_hide_common_thing();
                            authority_based_decision();
                        }
                    });
                }
            }
        });

    });


    function to_hide_common_thing() {
        //hide file counter
        $('#file_counter').hide(); //File counter vanish
        $('#student_counter').hide(); //student counter vanish 
        $('.table-link').hide(); //file link hide
    }

    //deciding who is logged in 
    function authority_based_decision() {
        //we need account^research_group^thesis_code^page_name
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "get"; //make page
        var variable = "account^research_group^thesis_code^page_name";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                var res = parse_string_by_delim(data, '^');
                if (res[3] != "") {
                    //exists a page name
                    if (res[0] == "Admin") {
                        //everything is fine
                    } else if (res[0] == "Manager") {
                        var res_group = get_value_from_input_tage('research_group');
                        if (res_group == res[1]) {
                            //everything is fine 
                        } else {
                            //things need to off 
                            //different manager 
                            need_to_off();
                            using_view_provoking_option();

                        }
                    } else if (res[0] == "Student") {
                        if (running_thesis_code == res[2]) {
                            //student's own account everything is fine
                            $('#delete_thesis').hide(); //to powerful
                        } else {
                            //not own account 
                            need_to_off();
                            using_view_provoking_option();
                        }
                    } else {
                        //normal see
                        need_to_off();
                        using_view_provoking_option();
                    }
                } else {
                    //normal see
                    need_to_off();
                    using_view_provoking_option();
                }
            }
        });
    }

    //things need to off
    function need_to_off() {
        $('.make-input-readonly').attr('readOnly', true); //input tags off 
        $('.hide-button').hide(); //buttons to hide 
        $('.hide-div').hide();
    }

    function using_view_provoking_option() {
        //see if files can ve visible or not
        view = get_value_from_input_tage('view');
        if (view == "No") {
            //File section will not be visible
            $('#file_table').hide();
        }
    }

    function make_page_for_thesis_details() {
        //now need to save the running thesis code
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "make";
        var variable = "thesis_details.php";
        var value = "";

        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                $("#thesis_total_information").html(data);
                to_hide_common_thing();
                authority_based_decision();
            }

        });



    }

    //function to delete thesis
    $(document).on('click', '#delete_thesis', function() {
        var answer = confirm('Are you sure ?');
        if (answer) {
            var path = "server_session_variable.php";
            var method = "POST";

            var operation = "delete"; //thesis will be deleted
            var variable = "thesis";
            var value = "";

            $.ajax({
                url: path,
                method: method,
                data: { operation: operation, variable: variable, value: value },
                success: function(data) {
                    alert(data);
                    location.href = "home.php";
                }
            });

        } else {
            return;
        }
        return false;
    });

});