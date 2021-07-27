/*This file controls the thesis_code_section part*/
$(document).ready(function() {

    /*global variables*/
    var account = "",
        research_group = "",
        thesis_code = "",
        thesis_id = "",
        page_name = "";

    /*Function to bring the thesis_code_section part*/
    var path = "server_session_variable.php";
    var method = "POST";

    var operation = "get"; //make page
    var variable = "account^research_group^thesis_code^thesis_id^page_name";
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
            account = res[0];
            research_group = res[1];
            thesis_code = res[2];
            thesis_id = res[3];
            page_name = res[4];
            //one student logged in 
            //make thesis_code readonly
            set_value_in_input_id("thesis_code", res[2]);
            make_input_tag_readonly("thesis_code");
            //hide submit button 
            hide_element_by_id("thesis_code_submit");
        } else if (res[4] == "upload.php") {
            //everything is just okay and fine 
        } else if (res[4] == "thesis_details.php") {
            var operation = "get"; //make page
            var variable = "running_thesis_code";
            var value = "";

            $.ajax({
                url: path,
                method: method,
                data: { operation: operation, variable: variable, value: value },
                success: function(data) {
                    //debug: alert(data);
                    //make thesis_code readonly
                    set_value_in_input_id("thesis_code", data); //running_thesis_code
                    make_input_tag_readonly("thesis_code");
                    //hide submit button 
                    hide_element_by_id("thesis_code_submit");
                    take_decision_authority_based(res, data);
                }
            });
        } else {
            //not authorized 
            set_value_in_input_id("thesis_code", "");
            make_input_tag_readonly("thesis_code");
            hide_element_by_id("thesis_code_submit");
        }
    }

    function parse_string_by_delim(str, delim) {
        var res = str.split(delim);
        return res;
    }

    function make_input_tag_readonly(id) {
        document.getElementById(id).readOnly = true;
    }

    function hide_element_by_id(id) {
        $('#' + id).hide();
    }

    function set_value_in_input_id(id, value) {
        document.getElementById(id).value = value;
    }

    //only for thesis_details.php
    function take_decision_authority_based(res, thesis_code_running) {
        //res contains information of account^research_group^thesis_code^thesis_id^page_name
        if (res[0] == "Admin") {
            //nothing to hide 
        } else if (res[0] == "Manager") {
            //nothing to hide 
        } else if (res[0] == "Student") {
            //now students thesis code should match
            if (thesis_code_running == res[2]) {
                //nothing to hide
            } else {
                $('#thesis_code_div').hide();
            }
        } else {
            //must be hidden
            $('#thesis_code_div').hide();
        }
    }

});