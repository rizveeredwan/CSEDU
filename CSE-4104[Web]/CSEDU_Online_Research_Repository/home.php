<?php
	session_start();
	$_SESSION["page_name"] = "home.php";
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

    <!--The Home Page Description Section -->
    <div class="table-design" style="background:#0A2252;">

        <div>
            <div style="display:grid; grid-template-columns:50% 50%;">
                    <!-- Image Section -->
                <div style="background:black;">
                    <div style="border:5px solid white; margin-top:5%; margin-bottom:5%; margin-left:5%; margin-right:5%;">
                        <image src="logo.png" id="move_image" class="img-responsive" height="100%" width="100%"></image>
                    </div>
                </div>
                <!--Description Section-->
                <div style="color:white;">
                    <div class="table-section-heading-decoration" style="color:white;">
                        <h2>CSEDU Online Repository</h2>
                    </div>
                    <div class="bar-under-menu" style="margin-left:2%; margin-right:2%;">
                        <div class="bar-under-menu-main-part"></div>
                    </div>
                    <div style="margin-left:2%; margin-right:2%;">
                        <p>CSEDU Online Repository is platform to uphold collaborative thesis/project works of 
                            <a href="http://www.cse.du.ac.bd/" style"text-decoration:none; color:white;">Department of Computer Science and Enginnering, University of Dhaka(CSEDU).</a>
                            Main goal of this website is to provide an easier and comfortable environment for research. Its a medium
                            to keep all the works in one place for everyone.
                        </p>
                        <p>
                            CSEDU has a glorious history in the field of research.Various dimensions 
                            of research interests already prevails here.
                        </p>
                        <p>
                            <a href="detail_information.php" style="color:#ffbf00;">Read More</a>
                        </p>
                    </div>

                </div>
            </div>
        </div>
        <!--The border section under image-->
        <div class="bar-under-menu">
            <div class="bar-under-menu-main-part"></div>
        </div>

        <div class="begin-description" style="background: #0A2252;">
            <!-- <div class="description" style="margin-left:1%; margin-right:1%; width:98%; background:#e6e6e6; border: 2px solid #ffbf00;"> -->
            <!-- heading decoration -->
            <div class="table-section-heading-decoration" style="color:white;">
                <h2>Department of Computer Science and Enginnering</h2>
            </div>
            <!-- description-->
            <div class="main-description" style="margin-left: 1%; margin-right:1%; color:white; font-size:18px;">
                <div style="padding: 1% 1% 1% 1%;">
                   <div style="display:grid; grid-template-columns: 60% 40%;">
                        <div>
                            <!--Image Section -->
                            <div style="border:5px solid white; margin-top:1%; margin-bottom:1%; margin-left:1%; margin-right:1%;">
                                <image src="inside_picture.jpg" id="move_image" class="img-responsive" height="100%" width="100%"></image>
                            </div>
                        </div>
                        <div>
                            <!--Writing Section -->
                            <div style="margin-left: 2%; margin-right:1%; margin-top:1%; margin-bottom:1%;">
                                <p>
                                    The Department of Computer Science and Engineering is one of the pioneering educational institutions in and outside of the university. The long list of achievements ranging from organization of premium research conferences and programming contests to personal accomplishment attained by the students and faculty members of the department is a strong proof of efficacy and dedication of the department towards achieving higher standard of education and organizational management.
                                    <br>
                                    <a href="http://www.cse.du.ac.bd/about/">Read More</a>
                                </p>
                            </div>
                        </div>
                   </div>
                </div>
                <!--The border section under description-->
                <div class="bar-under-menu">
                    <div class="bar-under-menu-main-part"></div>
                </div>
            </div>

            <!-- To Create Space -->
            <div style="height:50px;"></div>

            <!--Recent Thesis and Projects -->
            <div style="display:grid; grid-template-columns: 50% 50%;">
                <!-- Recent Thesis -->
                <div style="border-right: 2px solid #ffbf00; ">
                    <!-- creating main recent thesis section-->
                    <div style="margin-left:2% ; margin-right:2%;">
                        <!-- heading decoration -->
                        <div class="table-section-heading-decoration" style="color:white; background: black;">
                            <h2>Recent Created Thesis/Project</h2>
                        </div>
                        <!-- space creating div -->
                        <div style="padding: 2% 0 2% 0;"></div>
                        <!-- description part -->
                        <div style="color:black; background:white; padding: 2% 0 2% 0;">
                            <div style="margin-left:1%; margin-right:1%;">
                                Some of the recent Created Thesis/Projects can be found in the right side.Please Go to the link to get details.
                            </div>
                        </div>
                    </div>
                </div>
                <div id="recent_thesis_project_server"></div>
                <!--Table links
                <div style="margin-left:2% ; margin-right:2%;">
                    <table class="table table-responsive" style="color:black; background:white;">
                        <thead></thead>
                        <tbody>
                            <!-- 
                            <tr>
                                <td>1.</td>
                                <td><a href="">Detecting Fake News,Mofijul Islam Akash,Amor Deb Nath,Redoan Rahman,2018</a></td>
                            </tr>
                            <tr>
                                <td>2.</td>
                                <td><a href="#">Detecting Fake News,Mofijul Islam Akash,Amor Deb Nath,Redoan Rahman,2018</a></td>
                            </tr>
                        </tbody>
                    </table>
                </div> -->
            </div>
            <!-- To Create Space -->
            <div style="height:50px;"></div>

            <!--The border section under thesis/project-->
            <div class="bar-under-menu" style="margin-left:1%; margin-right:1%;">
                <div class="bar-under-menu-main-part"></div>
            </div>

            <!--Notice-->
            <!-- To Create Space -->
            <div style="height:50px;"></div>
            <!--Notice -->
            <div style="display:grid; grid-template-columns: 50% 50%;">
                <!-- Notice Header Section  -->
                <div style="border-right: 2px solid #ffbf00;">
                    <!-- Notice Header -->
                    <div style="margin-left:2% ; margin-right:2%;">
                        <!-- heading decoration -->
                        <div class="table-section-heading-decoration" style="color:white; background: black;">
                            <h2>Notice</h2>
                        </div>
                        <!-- space creating div -->
                        <div style="padding: 2% 0 2% 0;"></div>
                        <!-- Notice Input -->
                        <div class="need-to-hide">
                            <!-- Notice Input field -->
                            <table class="table  table-responsive" style="background:black; color:white;">
                                <thead></thead>
                                <tbody>
                                    <tr>
                                        <td>New Notice</td>
                                        <td><input type="text" class="form-control" id="new_notice"></td>
                                    </tr>
                                </tbody>
                            </table>
                            <!-- Add button -->
                            <div class="form-group">
                                <button type="button" class="btn btn-default btn-success" id="add_notice">Add Notice</button>
                                <button type="button" class="btn btn-default btn-warning" id="update">Update</button>
                            </div>
                        </div>
                    </div>
                </div>
                <div id="notice_server"></div>
                <!--Table links
                <div style="margin-left:2% ; margin-right:2%;">
                    <table class="table table-responsive" style="color:black; background:white;">
                        <thead></thead>
                        <tbody>
                            <tr>
                                <td><a href="">Detecting Fake News,Mofijul Islam Akash,Amor Deb Nath,Redoan Rahman,2018</a></td>
                                <td><button type="button" class="btn btn-default btn-danger">Delete</button></td>
                            </tr>
                            <tr>
                                <td><a href="#">Detecting Fake News,Mofijul Islam Akash,Amor Deb Nath,Redoan Rahman,2018</a></td>
                                <td><button type="button" class="btn btn-default btn-danger">Delete</button></td>
                            </tr>
                            <tr>
                                <td><button type="button" class="btn btn-default btn-warning">update</button></td>
                            </tr>

                        </tbody>
                    </table>
                </div> -->
            </div>

            <!-- space creating div -->
            <div style="padding: 2% 0 2% 0;"></div>

            <!--The border section under notice -->
            <div class="bar-under-menu" style="margin-left:1%; margin-right:1%;">
                <div class="bar-under-menu-main-part"></div>
            </div>

            <!-- space creating div -->
            <div style="padding: 2% 0 2% 0;"></div>

            <!-- Last Three Section -->
            <div style="display:grid; margin-left:2%; margin-right:2%; grid-template-columns: 32% 32% 32%;">

                <!--Research Group File Section -->
                <div style="border-right: 2px solid #ffbf00;">
                    <!--Research Group Files-->
                    <div class="hovering home_page_last_section change_cursor" id="research_group_files.php">
                        <!-- Main -->
                        <div style="padding: 5% 5% 5% 5%;">
                            <!-- heading decoration -->
                            <div class="table-section-heading-decoration">
                                <h2>Research Group</br> Files</h2>
                            </div>
                            <!--Border-->
                            <div class="bar-under-menu">
                                <div class="bar-under-menu-main-part"></div>
                            </div>
                        </div>
                    </div>
                </div>
                <!--Resource Section -->
                <div style="border-right: 2px solid #ffbf00;">
                    <!--Resource-->
                    <div class="hovering home_page_last_section change_cursor" id="other.php">
                        <!-- Main -->
                        <div style="padding: 5% 5% 5% 5%;">
                            <!-- heading decoration -->
                            <div class="table-section-heading-decoration">
                                <h2>Other</br> Resources</h2>
                            </div>
                            <!--Border-->
                            <div class="bar-under-menu">
                                <div class="bar-under-menu-main-part"></div>
                            </div>
                        </div>
                    </div>
                </div>
                <!--About Section -->
                <div>
                    <!--About-->
                    <div class="hovering home_page_last_section change_cursor" id="about_us.php">
                        <!-- Main -->
                        <div style="padding: 5% 5% 5% 5%;">
                            <!-- heading decoration -->
                            <div class="table-section-heading-decoration">
                                <h2>About</br>Website</h2>
                            </div>
                            <!--Border-->
                            <div class="bar-under-menu">
                                <div class="bar-under-menu-main-part"></div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            </br>
        </div>

        </div>

    </div>


    <!--The Footer Section-->
    <div class="footer">
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

    <script src="home.js "></script>
    <script src="header_futer.js "></script>
    <script src="recent_thesis_project.js "></script>
    <script src="notice.js "></script>
    <script src="home_page_last_section.js "></script>

   


</body>

</html>
