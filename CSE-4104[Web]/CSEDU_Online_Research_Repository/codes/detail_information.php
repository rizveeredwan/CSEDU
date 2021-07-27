<?php
	session_start();
	$_SESSION["page_name"] = "detail_information.php";
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
    <link rel="stylesheet" href="image_slider.css">
    
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


    <div class="table-design">
        <!--Image Section -->
        <div>
            <image src="home_page_image.jpg" class="img-responsive" width="100%"></image>  
        </div>
    </div>

    <div class="table-design">
        <!-- Written Section -->
        <!-- heading decoration -->
        <div class="table-section-heading-decoration" style="color:black;">
            <h2>List of Research Groups </h2>
        </div>

        <!--The border section under image-->
        <div class="bar-under-menu" style="margin-left:2%; margin-right:2%;">
            <div class="bar-under-menu-main-part"></div>
        </div>

        <!-- To Create Space -->
        <div style="height:50px;"></div>

        <!--Introduction-->
        <div style="margin-left: 5%; margin-right: 5%;">
            <p>Currently our department provides following research groups.Each research
               group has its own unique features,credentials and research vision.Each of them whole
               heartedly give focuses to their field.In the following section, you can find an idea
               about the vast dimension of their works.
            </p>
            <!-- Info starts -->
            <div>
                <div>
                    <a href="http://www.cse.du.ac.bd/research-groups/">Data Mining Research Group(DMR)</a>
                </div>
                <div>
                    <p>Research Interests: Data Mining and Knowledge Discovery, Machine Learning, Stream Data Management, Web Mining, Correlation Analysis, Database Management, Information Retrieval</p>
                </div>
            </div>

            <div>
                <div>
                    <a href="http://www.cse.du.ac.bd/research-groups/">Green Networking Research Group(GNR)</a>
                </div>
                <div>
                    <p> Research Interests: Computer Networking, Cloud Computing, Sensor and Ad Hoc Networks, Green Cellular Networks, Analysis of Computer Comm, MAC and Congestion Control </p>
                </div>
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

    <script src="header_futer.js "></script>
   
    </body>

</html>
