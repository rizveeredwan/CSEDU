<?php
	session_start();
	$_SESSION["page_name"] = "faq.php";
?>
<!DOCTYPE html>
<html lang="en">

<!-- Initial description -->

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="bootstrap-3.3.7-dist/css/bootstrap.min.css">
    <script src="Jquery/jquery-3.3.1.js"></script>
    <script src="bootstrap-3.3.7-dist/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="header_futer.css">
    <link rel="stylesheet" href="form_design.css">
    <link rel="stylesheet" href="table_decoration.css">
    <link rel="stylesheet" href="button_design.css">
    <link rel="stylesheet" href="input_field_design.css">
    <link rel="stylesheet" href="font.css">
    <link rel="stylesheet" href="hovering.css">
</head>

<body>
    <!--The top bar-->
    <div class="top-header">
        <div></div>
        <div class="log-button">
            <button type="submit" class="btn btn-default" id="log_button">Login</button>
            <button type="submit" class="btn btn-default" id="account_button">Account</button>
        </div>
    </div>

    <!-- Name and Logo -->
    <div class="name-logo">
        <div class="logo-1">
            <image class="img-responsive" src="DU.jpg" alt="Chania" height="100" width="100"></image>
        </div>
        <div class="name">
            <h3>Department Of Computer Science and Engineering</h3>
            <h4>University of Dhaka</h4>
            <h4>Online Research Repository</h4>
        </div>
        <div class="logo-2">
            <image class="img-responsive" src="CSEDU.png" alt="Chania" height="100" width="100"></image>
        </div>
    </div>
    <!--The Down header/Menu Bar decoration-->
    <div class="menu-option-design">
        <div></div>
        <div class="menu-per-option-decoration" id="home_option">Home</div>
        <div class="menu-per-option-decoration" id="upload_option">Upload</div>
        <div class="menu-per-option-decoration" id="search_option">Search</div>
        <div class="menu-per-option-decoration" id="faq_option">FAQ</div>
        <div class="menu-per-option-decoration" id="other_option">Others</div>
        <div></div>
    </div>

    <!--The bar under Menu decoration-->
    <div class="bar-under-menu">
        <div class="bar-under-menu-main-part"></div>
    </div>

    <!--FAQ description page -->
    <div class="table-design" style="background:#0f0f57;">
        <!-- heading decoration -->
        <div class="table-section-heading-decoration" style="color:white;">
            <h2>Frequently Asked Questions</h2>
        </div>

        <!--border-->
        <div style="margin-left:2%; margin-right:2%;">
            <!--The border section under image-->
            <div class="bar-under-menu">
                <div class="bar-under-menu-main-part"></div>
            </div>
            <!-- To Create Space -->
            <div style="height:50px;"></div>
        </div>

        <!-- Question and answer -->
        <div style="margin-left:2%; margin-right:2%; color:black;">
            <div class="question" style="background:#e6e6e6; border-radius: 25px;; padding:1% 1% 1% 1%;" id="question_1">
                <a href="#" style="text-decoration:none;">Q1. Why CSEDU Research Repository was created?</a>
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="answer" style="background:#ffbf00; border-radius: 25px; padding:1% 1% 1% 1%;" id="answer_1">
                Answer. AAAAAAAAAAAAAAAAA
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="question" style="background: #e6e6e6; border-radius: 25px;; padding:1% 1% 1% 1%;" id="question_2">
                <a href="#">Q1. Why CSEDU Research Repository was created?</a>
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="answer" style="background:#ffbf00; border-radius: 25px; padding:1% 1% 1% 1%;" id="answer_2">
                Answer. AAAAAAAAAAAAAAAAA
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="question" style="background: #e6e6e6; border-radius: 25px;; padding:1% 1% 1% 1%;" id="question_3">
                <a href="#">Q1. Why CSEDU Research Repository was created?</a>
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="answer" style="background:#ffbf00; border-radius: 25px; padding:1% 1% 1% 1%;" id="answer_3">
                Answer. AAAAAAAAAAAAAAAAA
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="question" style="background: #e6e6e6; border-radius: 25px;; padding:1% 1% 1% 1%;" id="question_4">
                <a href="#">Q1. Why CSEDU Research Repository was created?</a>
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="answer" style="background:#ffbf00; border-radius: 25px; padding:1% 1% 1% 1%;" id="answer_4">
                Answer. AAAAAAAAAAAAAAAAA
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="question" style="background:#e6e6e6; border-radius: 25px;; padding:1% 1% 1% 1%;" id="question_5">
                <a href="#">Q1. Why CSEDU Research Repository was created?</a>
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="answer" style="background:#ffbf00; border-radius: 25px; padding:1% 1% 1% 1%;" id="answer_5">
                Answer. AAAAAAAAAAAAAAAAA
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
        </div>
    </div>

    <script>
        $(document).ready(function() {
            //when new question and answer is asked question number must be asked 
            var question = 5;
            var question_list = [];
            for (i = 0; i < question; i++) {
                question_list.push(0);
                var value = i + 1;
                $('#answer_' + value).hide();
            }

            $(document).on('click', '.question', function(event) {
                event.preventDefault();
                var id = $(this).attr("id");
                var res = parse_string_by_delim(id, "_"); //question_1 
                question_list[res[1] - 1] = (question_list[res[1] - 1] + 1) % 2;
                if (question_list[res[1] - 1] == 0) {
                    $('#answer_' + res[1]).hide();
                } else if (question_list[res[1] - 1] == 1) {
                    $('#answer_' + res[1]).show();
                }
            });

            function parse_string_by_delim(str, delim) {
                var res = str.split(delim);
                return res;
            }


        });
    </script>



    <!--The Footer Section-->
    <div class="footer ">
        <!-- Space section-->
        <div></div>
        <!--Copyright Section-->
        <div class="copyright-section ">
            <h6>&#169 CSEDU Research Repository</h6>
        </div>
        <!-- Empty  Section-->
        <div></div>
        <!--Contact Section-->
        <div class="contact-section ">
            <a href=" ">[Department's Website Link]</a>
            <a href=" ">[Contact]</a>
            <a href=" ">[Policy]</a>
        </div>
        <!-- Space section-->
        <div></div>
    </div>


    <script src="header_futer.js "></script>


</body>

</html>
