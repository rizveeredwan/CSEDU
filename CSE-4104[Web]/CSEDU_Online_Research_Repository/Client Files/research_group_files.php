<?php
	session_start();
	$_SESSION["page_name"] = "research_group_files.php";
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

    <!--Files Section -->
    <div class="table-design">
        <!--Research Group Files will come here from server -->
        <div id="research_group_name_option_from_server"></div>
        <!--
        <!-- Heading Section
        <!-- heading decoration
        <div class="table-section-heading-decoration">
            <h2>Research Group Files</h2>
        </div>

        <!--The bar under Header Section
        <div class="bar-under-menu" style="margin-left:2%; margin-right:2%;">
            <div class="bar-under-menu-main-part"></div>
        </div>

        <!-- space creating div
        <div style="padding: 2% 0 2% 0;"></div>

        <!-- Input section
        <div style="margin-left:2%; margin-right:2%;">
            <div class="form-group">
                <select class="form-control">
                    <option>Data Mining</option>
                    <option>Cyber Security</option>
                 </select>
            </div>
            <div class="form-group">
                <button type="button" class="btn btn-default btn-danger">Search</button>
            </div>
        </div>

    -->
        <div id="research_group_files_server"></div>

        <!--Research Group Files
        <!-- space creating div
        <div style="padding: 2% 0 2% 0;"></div>

        <div style="margin-left:2%; margin-right:2%;">
            <div class="table-section-heading-decoration">
                <h2>Files</h2>
            </div>
            <!-- Table
            <div style="margin-left:5%; margin-right:5%;">
                <table class="table table-bordered table-responsive" style="background:white;">
                    <thead></thead>
                    <tbody>
                        <tr>
                            <td>uva</td>
                            <td><a href="uva" target="_blank">View</a></td>
                            <td><a href="uva" download="uva">Download</a></td>
                        </tr>
                    </tbody>
                </table>
            </div>
        </div>
    -->
    </div>


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
            <a href=" ">[Department's Website Link]</a>
            <a href=" ">[Contact]</a>
            <a href=" ">[Policy]</a>
        </div>
        <!-- Space section-->
        <div></div>
    </div>

    <script src="header_futer.js "></script>
    <script src="research_group_files_show_controller.js "></script>

</body>

</html>
