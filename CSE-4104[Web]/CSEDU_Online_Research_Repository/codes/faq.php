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
    <link rel="stylesheet" href="media_wise_font_change.css">
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
                Answer. CSEDU Research Repository is a platform to keep all the thesis/project works of 
                various programs(MSc.,BSc. etc) of CSEDU online. The goal of this website is to provide an easier medium for the researchers
                to know about previous works of their superiors, to provide a collaborative environment for the 
                research groups.This website solely works for the advancement of research field of CSEDU.
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="question" style="background: #e6e6e6; border-radius: 25px;; padding:1% 1% 1% 1%;" id="question_2">
                <a href="#">Q2. How can I create Research Group ?</a>
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="answer" style="background:#ffbf00; border-radius: 25px; padding:1% 1% 1% 1%;" id="answer_2">
                Answer. For security and trust purpose this facility is only provided to the admin of
                this website.So, if you want to create a research group, you must request the admin to create it,
                with necessary information.Admin will cross check the information and then create a manager
                account for you.After that you will be the controller of your research group and works 
                of your research group as role of "Manager".
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="question" style="background: #e6e6e6; border-radius: 25px;; padding:1% 1% 1% 1%;" id="question_3">
                <a href="#">Q3. Who are the managers?</a>
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="answer" style="background:#ffbf00; border-radius: 25px; padding:1% 1% 1% 1%;" id="answer_3">
                Answer. "Manager" concept stands as research group controller. The second most 
                powerful role of this website is manager.All the research group supervisors can 
                work as manager for a research group.
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="question" style="background: #e6e6e6; border-radius: 25px;; padding:1% 1% 1% 1%;" id="question_4">
                <a href="#">Q4. How a student account is created?</a>
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="answer" style="background:#ffbf00; border-radius: 25px; padding:1% 1% 1% 1%;" id="answer_4">
                Answer. Each student account is connected with some thesis or project. This account is created 
                by a manager of that respective research group under which this thesis/project belongs.
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="question" style="background:#e6e6e6; border-radius: 25px;; padding:1% 1% 1% 1%;" id="question_5">
                <a href="#">Q5. How "collaboration of research works" goes under this website?</a>
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
            <div class="answer" style="background:#ffbf00; border-radius: 25px; padding:1% 1% 1% 1%;" id="answer_5">
                Answer. Each thesis/project can be shared with others through links.Besides there is a 
                view option connected with each work. If that is "Yes", the work is open for general view
                but if that is "No" then it is not open for public view. This facilty can be controlled by manager
                and students related with that thesis/project account.
            </div>
            <!-- To Create Space -->
            <div style="height:5px;"></div>
        </div>
    </div>

    <!--Constructive Message -->
    <div class="table-design">
        <div style="margin-left:2%; margin-top:2%;">
            <h2>Leave Constructive Message</h2>
        </div>
        <!--Message Section -->
        <div style="margin-left:2%; margin-top:2%; margin-right:2%;">
            <!-- Message Section -->
            <div class="form-group" style="width:70%;">
                <textarea class="form-control" rows="5" id="message"  placeholder="message, please give constructive message."></textarea>
                <div id="message_condition"></div>
            </div>
            <!-- Button -->
            <div class="form-group">
                <button type="button" id="give" class="btn btn-default">Give</button>
            </div>
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

            //to provide comment
            $(document).on('click','#give',function(){
                alert('ok');
                var message = document.getElementById('message').value;
                if(message == "") {
                    document.getElementById('message').style.borderColor="red";
                    var str = '<div>Message Can not be empty</div>';
                    $('#message_condition').html(str);
                    return false;
                }
                else {
                    document.getElementById('message').style.borderColor="";
                    var str='<div>posting..</div>';
                    $('#message_condition').html(str);
                }
                alert(message);
                var email = "CseduResearchRepository@gmail.com";
                var subject = "Comment given in website.";
                
                var path = "PHPMailer/server_mail.php";
                var method = "POST";

                $.ajax({
                url: path,
                method: method,
                data: { email: email, subject: subject, message: message },
                success: function(data) {
                    res = parse_string_by_delim(data, '\n');
                    alert(res[res.length - 1]);
                    var str='<div>Message been posted</div>';
                    $('#message_condition').html(str);
                }
             });

             return false;
                
            });

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
            <a href="http://www.cse.du.ac.bd/">[Department's Website Link]</a>
            <a href="about_us.php">[Contact]</a>
            <a href="about_us.php">[Policy]</a>
        </div>
        <!-- Space section-->
        <div></div>
    </div>

    <!-- The Ending Section -->
    <div style="width:100%; background:black; color:white">
        <div class="table-section-heading-decoration">
            <h6>To get better view of this website<br>Please switch to mozilla firefox browser.<br> </h6>
        </div>
        <div style="margin-left:50%;">
        <image class="img-responsive" src="mozilla.png" alt="Chania" height="20" width="20"></image>
        </div>

    </div>
    <!--The Black Border -->
    <div style="width:100%; background:black; color:black; height:50px">
    </div>


    <script src="header_futer.js "></script>


</body>

</html>
