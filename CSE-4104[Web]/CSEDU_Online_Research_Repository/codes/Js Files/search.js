/*search for javascript */
$(document).ready(function() {

    function bring_page() {
        var path = "server_session_variable.php";
        var method = "POST";

        var operation = "make"; //make page
        var variable = "search.php";
        var value = "";

        //debug: alert("do oo");
        $.ajax({
            url: path,
            method: method,
            data: { operation: operation, variable: variable, value: value },
            success: function(data) {
                //debug: alert(data);
                //appending data
                $('#search_query_part').html(data);
                make_on_off();
            }

        });

    }
    bring_page();

    //purpose of this function is to
    function make_on_off() {
        if (document.getElementById('project_thesis_radio').checked) {
            $('#search_query_part').show();

            $('#research_group').show();
            $('#research_group_label').show();

            $('#supervisor').show();
            $('#supervisor_label').show();

            $('#year_from').show();
            $('#year_from_label').show();

            $('#year_to').show();
            $('#year_to_label').show();

            $('#thesis_title').show();
            $('#thesis_title_label').show();

            $('#program').show();
            $('#program_label').show();

            $('#student').show();
            $('#student_label').show();

            $('#year_label').show();
            $('#search').show();

        } else if (document.getElementById('research_group_radio').checked) {

            $('#search_query_part').show();

            $('#research_group').show();
            $('#research_group_label').show();

            $('#supervisor').hide();
            $('#supervisor_label').hide();

            $('#year_from').hide();
            $('#year_from_label').hide();

            $('#year_to').hide();
            $('#year_to_label').hide();

            $('#thesis_title').hide();
            $('#thesis_title_label').hide();

            $('#program').hide();
            $('#program_label').hide();

            $('#student').hide();
            $('#student_label').hide();

            $('#year_label').hide();
            $('#search').show();

        } else if (document.getElementById('supervisor_radio').checked) {
            $('#search_query_part').show();

            $('#supervisor').show();
            $('#supervisor_label').show();

            $('#research_group').hide();
            $('#research_group_label').hide();

            $('#year_to').hide();
            $('#year_to_label').hide();

            $('#year_from').hide();
            $('#year_from_label').hide();

            $('#thesis_title').hide();
            $('#thesis_title_label').hide();

            $('#program').hide();
            $('#program_label').hide();

            $('#student').hide();
            $('#student_label').hide();

            $('#year_label').hide();
            $('#search').show();

        } else {
            $('#research_group').hide();
            $('#research_group_label').hide();

            $('#supervisor').hide();
            $('#supervisor_label').hide();

            $('#year_from').hide();
            $('#year_from_label').hide();

            $('#year_to').hide();
            $('#year_to_label').hide();

            $('#thesis_title').hide();
            $('#thesis_title_label').hide();

            $('#program').hide();
            $('#program_label').hide();
            $('#student').hide();
            $('#student_label').hide();

            $('#year_label').hide();
            $('#search').hide();
            $('#search_query_part').hide();
        }
    }

    $(document).on('click', '.radio-button-design-input', function() {
        make_on_off();
    });



});
