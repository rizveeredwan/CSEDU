<?php
	session_start();
	$_SESSION["page_name"] = "other.php";
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
    <link rel="stylesheet" href="overlay_design.css">
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

    <div class="table-design" style="background:#0f0f57; color:white;">
        <!-- heading decoration -->
        <div class="table-section-heading-decoration">
            <h2>Other Facilities</h2>
        </div>

        <!--The bar under heading -->
        <div style="margin-left:2%; margin-right:2%;">
            <div class="bar-under-menu">
                <div class="bar-under-menu-main-part"></div>
            </div>
        </div>

        <!-- To Create Space -->
        <div style="height:50px;"></div>

        <!-- The thumbil image section -->
        <div style="margin-left: 2%; margin-right:2%; display:grid; grid-template-columns:32% 32% 32%">
            <!--Research Group Files-->
            <div class="thumbnail facility change_cursor" style="margin-left:1%; margin-right:1%;" id="research_group_files">
                <img class="img-thumbnail" src="files_image.png" style="width:100%;">
                <div class="caption" style="background:black; color:white; text-align:center;">
                    <p>Research Group Files</p>
                </div>
            </div>

            <!--Google Drive -->
            <div class="thumbnail facility change_cursor" style="margin-left:1%; margin-right:1%;" id="google_drive">
                <img class="img-thumbnail" src="google_drive_image.jpeg" style="width:100%;">
                <div class="caption" style="background:black; color:white; text-align:center;">
                    <p>Google Drive</p>
                </div>
            </div>

            <!--Dropbox -->
            <div class="thumbnail facility change_cursor" style="margin-left:1%; margin-right:1%;" id="dropbox">
                <img class="img-thumbnail" src="dropbox_image.png" style="width:100%;">
                <div class="caption" style="background:black; color:white; text-align:center;">
                    <p>Dropbox</p>
                </div>
            </div>
        </div>

        <!-- The thumbil image section -->
        <div style="margin-left: 2%; margin-right:2%; display:grid; grid-template-columns:32% 32% 32%">
            <!--Github-->
            <div class="thumbnail facility change_cursor" style="margin-left:1%; margin-right:1%;" id="github">
                <img class="img-thumbnail" src="github_image.png" style="width:100%;">
                <div class="caption" style="background:black; color:white; text-align:center;">
                    <p>Github</p>
                </div>
            </div>

            <!--Mail -->
            <div class="thumbnail facility change_cursor" style="margin-left:1%; margin-right:1%;" id="mail">
                <img class="img-thumbnail" src="gmail_emage.png" style="width:100%;">
                <div class="caption" style="background:black; color:white; text-align:center;">
                    <p>Mailing System</p>
                </div>
            </div>

            <!--facebook -->
            <div class="thumbnail facility change_cursor" style="margin-left:1%; margin-right:1%;" id="facebook">
                <img class="img-thumbnail" src="facebook_image.png" style="width:100%;">
                <div class="caption" style="background:black; color:white; text-align:center;">
                    <p>Facebook</p>
                </div>
            </div>

        </div>
    </div>

    <!--Mail System -->
    <!-- Mail Section -->
    <div id="mail_section_server"></div>
    <div class="table-design" id="mail_reply"></div>

    <!--
    <div class="table-design">
        <!-- heading decoration
        <div class="table-section-heading-decoration">
            <h2>Mail</h2>
        </div>

        <!--The bar under Menu decoration
        <div style="margin-left:2%; margin-right:2%;">
            <div class="bar-under-menu">
                <div class="bar-under-menu-main-part"></div>
            </div>
        </div>

        <!-- To Create Space 
        <div style="height:50px;"></div>

        <!--
        <div style="margin-left:2%; margin-right:2%;">
            <!--Supervisor
        <div class="form-group">
            <label for="supervisor">Supervisor</label>
            <select class="form-control">
                    <option>Hasnain Hecikel(hhjami@gmail.com)</option>
                    <option>Dr.Chowdhury Farhan Ahmed(chowdhury_farhan@gmail.com)</option>
                </select>
        </div>
        <!--subject
        <div class="form-group">
            <label for="subject">Subject</label>
            <input class="form-control" placeholder="subject">
        </div>
        <!--Message
        <div class="form-group">
            <label for="subject">Message</label>
            <textarea class="form-control" rows="5"></textarea>
        </div>
        <!--Message
        <div class="form-group">
            <button type="button" class="btn btn-default">Mail</button>
        </div>

    </div>
    -->

    <!--
    <div class="table-design">
        <!-- heading decoration
        <div class="table-section-heading-decoration">
            <h2> Group Mail System</h2>
        </div>
        <!--border
        <div style="margin-left:2%; margin-right:2%;">
            <div class="bar-under-menu">
                <div class="bar-under-menu-main-part"></div>
            </div>
        </div>
        <!-- To Create Space
        <div style="height:50px;"></div>
        <div style="margin-left:2%; margin-right:2%;">
            <!--Supervisor
            <div class="form-group">
                <label for="supervisor">Supervisor</label>
                <select class="form-control">
                    <option>Hasnain Hecikel(hhjami@gmail.com)</option>
                    <option>Dr.Chowdhury Farhan Ahmed(chowdhury_farhan@gmail.com)</option>
                </select>
            </div>
            <div class="form-group">
                <button type="button" class="btn btn-default btn-primary" id="add_supervisor">Add Supervisor</button>
            </div>
            <!--Students
            <div class="form-group">
                <label for="student">Student</label>
                <select class="form-control">
                    <option>Nahian Ahsraf(raidanahian@gmail.com)</option>
                    <option>Md. Shahadat Hossain Shahin(shshahin065@gmail.com)</option>
                </select>
            </div>
            <div class="form-group">
                <button type="button" class="btn btn-default btn-success" id="add_student">Add Student</button>
            </div>
        </div>



        <!--Receipent table
        <div style="margin-left:2%; margin-right:2%;">

            <!-- heading decoration
            <div class="table-section-heading-decoration">
                <h2> Receipent Name</h2>
            </div>

            <table class="table table-bordered table-responsive" style="background:white;">
                <thead>
                    <tr>
                        <td>Name</td>
                        <td>Email</td>
                        <td>Mail Status</td>
                        <td></td>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td>Hasnain Heickel</td>
                        <td>hhjami@gmail.com</td>
                        <td>Not Sent</td>
                        <td>
                            <button type="button" class="btn btn-default btn-danger">Delete</button>
                        </td>
                    </tr>
                    <tr>
                        <td>Hasnain Heickel</td>
                        <td>hhjami@gmail.com</td>
                        <td>Not Sent</td>
                        <td>
                            <button type="button" class="btn btn-default btn-danger">Delete</button>
                        </td>
                    </tr>
                </tbody>
            </table>
        </div>

        <!--subject
        <div style="margin-left:2%; margin-right:2%;">
            <div class="form-group">
                <label for="subject">Subject</label>
                <input class="form-control" placeholder="group_subject">
            </div>
            <!--Message
            <div class="form-group">
                <label for="subject">Message</label>
                <textarea class="form-control" rows="5"></textarea>
            </div>
            <!--button
            <div class="form-group">
                <button type="button" class="btn btn-default">Mail</button>
            </div>
        </div>
    </div>
-->

    <!--Overlay section -->
    <div id="overlay">
        <div id="text">Sending...</div>
    </div>

    <script>
        function on() {
            document.getElementById("overlay").style.display = "block";
        }

        function off() {
         document.getElementById("overlay").style.display = "none";
        }
    </script>



    <!--The Footer Section-->
    <div class=" footer ">
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
    <script src="other.js "></script>

</body>

</html>
