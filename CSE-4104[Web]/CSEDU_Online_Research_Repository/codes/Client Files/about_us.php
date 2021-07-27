<?php
	session_start();
	$_SESSION["page_name"] = "about_us.php";
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

    <!--Main Description Part -->
    <div class="table-design">
        <!-- heading decoration -->
        <div class="table-section-heading-decoration" style="color:black;">
            <h2>About Website</h2>
        </div>
        <!--border-->
        <div style="margin-left:2%; margin-right:2%;">
            <!--The border section under header -->
            <div class="bar-under-menu">
                <div class="bar-under-menu-main-part"></div>
            </div>
            <!-- To Create Space -->
            <div style="height:50px;"></div>
        </div>
        <!--contact-->
        <div>
            <!-- heading decoration -->
            <div class="table-section-heading-decoration" style="color:black;">
                <h2>Contact</h2>
            </div>
            <!-- Contact Description  -->
            <div style="display:grid; margin-left:2%; margin-right:2%; grid-template-columns:48% 48%; background:#0f0f57; color:white;">
                <!--Image Section-->
                <div>
                    <img src="csedu_contact.jpg" class="img-responsive" width: "100%">
                </div>
                <!--Description section-->
                <div>
                    <!--Heading -->
                    <div class="table-section-heading-decoration" style="color:white;">
                        <h4>Department of Computer Science and Engineering</h4>
                        <h5>Science Complex,University of Dhaka,Dhaka-1000</h5>
                        <!--The border section under header -->
                        <div style="margin-left:10%; margin-right:10%;">
                            <div class="bar-under-menu">
                                <div class="bar-under-menu-main-part"></div>
                            </div>
                        </div>
                    </div>
                    <table class="table table-responsive" style="border:none; margin-left:10%; width:80%;">
                        <thead></thead>
                        <tbody>
                            <tr>
                                <td style="border:none !important;">Tel:</td>
                                <td style="border:none !important;"> +880 2 9670734</td>
                            </tr>
                            <tr>
                                <td>PABX:</td>
                                <td> +880 2 9661920-70, Ext. 7421</td>
                            </tr>
                            <tr>
                                <td>Email 1:</td>
                                <td>office@cse.du.ac.bd</td>
                            </tr>
                            <tr>
                                <td>Department Website Link</td>
                                <td>
                                    <a style="color:Yellow;" href="http://www.cse.du.ac.bd/about/">Go</a>
                                </td>
                            </tr>
                            <tr>
                                <td>Facebook Page</td>
                                <td>
                                    <a style="color:Yellow;" href="https://www.facebook.com/Dept.CSE.DU/">Go</a>
                                </td>
                            </tr>

                        </tbody>
                    </table>
                </div>
            </div>

            <div style="margin-left:2%; margin-right:2%;">
                <!--Border -->
                <div class="bar-under-menu">
                    <div class="bar-under-menu-main-part"></div>
                </div>
            </div>

            <!-- To Create Space -->
            <div style="height:50px;"></div>
        </div>

        <!--Policy -->
        <div style="margin-left:1%; margin-right:1%; color:white;">
            <!-- heading decoration -->
            <div class="table-section-heading-decoration" style="color:black;">
                <h2>Policy</h2>
            </div>
            <div style="margin-left:2%; margin-right:2%; background:#0f0f57; color:white;">
                <div style="padding: 2% 2% 2% 2%;">
                    <ul style="list-style-type:square;">
                        <li>The Sole purpose of our website is to aaaaaaaaaaaaaaaaa.</li>
                        <li>The Sole purpose of our website is to aaaaaaaaaaaaaaaaa.</li>
                        <li>The Sole purpose of our website is to aaaaaaaaaaaaaaaaa.</li>
                        <li>The Sole purpose of our website is to aaaaaaaaaaaaaaaaa.</li>
                        <li>The Sole purpose of our website is to aaaaaaaaaaaaaaaaa.</li>
                        <li>The Sole purpose of our website is to aaaaaaaaaaaaaaaaa.</li>
                        <li>The Sole purpose of our website is to aaaaaaaaaaaaaaaaa.</li>
                    </ul>
                </div>
            </div>
            <!--Border -->
            <div class="bar-under-menu" style="margin-left:2%; margin-right:2%;">
                <div class="bar-under-menu-main-part"></div>
            </div>
        </div>

        <!-- To Create Space -->
        <div style="height:50px;"></div>

        <div style="margin-left:1%; margin-right:1%;">
            <!-- heading decoration -->
            <div class="table-section-heading-decoration" style="color:black;">
                <h2>Story Behind this website</h2>
            </div>
            <div style="color:white; background:#0f0f57;">
                <!--Basic Description -->
                <div style="padding:2% 2% 2% 2%;">
                    <div>
                        Programming problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level
                        of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming problems
                        are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level
                        of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming
                    </div>
                    <!-- Here the image of Mamun sir-->
                    <div style="margin-left:1%; margin-right:1%; margin-top:2%; display:grid; grid-template-columns:30% 50%;">
                        <div>
                            <img class="img-thumbnail" src="rana sir.jpg" style="width:100%;">
                            <div class="caption" style="background:black; color:white; text-align:center; padding:2% 2% 2% 2%;">
                                <p>Mamun Or Rashid</p>
                            </div>
                        </div>
                        <!--description-->
                        <div style="margin-left:10%;">
                            <div>
                                Programming problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level
                                of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming
                                problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages
                                sier to solve in high-level languages – Languages closer to the level of the problem domain, e.g.,
                            </div>
                        </div>
                    </div>

                    <!-- Rana sir -->
                    <!-- Here the image of Mamun sir-->
                    <div style="margin-left:1%; margin-right:1%; margin-top:2%; display:grid; grid-template-columns:50% 30%;">
                        <!--description-->
                        <div style="margin-right:10%;">
                            <div>
                                Programming problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level
                                of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming
                                problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages
                                sier to solve in high-level languages – Languages closer to the level of the problem domain, e.g.,
                            </div>
                        </div>
                        <div>
                            <img class="img-thumbnail" src="rana sir.jpg" style="width:100%;">
                            <div class="caption" style="background:black; color:white; text-align:center; padding:2% 2% 2% 2%;">
                                <p>Mamun Or Rashid</p>
                            </div>
                        </div>
                    </div>

                    <!-- Rana sir -->
                    <!-- Here the image of Mamun sir-->
                    <div style="margin-left:1%; margin-right:1%; margin-top:2%; display:grid; grid-template-columns:50% 48%;">
                        <!--description-->
                        <div style="margin-right:10%;">
                            <div>
                                Programming problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level
                                of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming
                                problems are easier to solve in high-level languages – Languages closer to the level of the problem domain, e.g., • SmallTalk: OO programming Programming problems are easier to solve in high-level languages – Languages
                                sier to solve in high-level languages – Languages closer to the level of the problem domain, e.g.,
                            </div>
                        </div>
                        <div>
                            <img class="img-thumbnail" src="mehreen.jpg" style="width:100%;">
                            <div class="caption" style="background:black; color:white; text-align:center; padding:2% 2% 2% 2%;">
                                <p>Mamun Or Rashid</p>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <!--Border -->
        <div class="bar-under-menu" style="margin-left:1%; margin-right:1%;">
            <div class="bar-under-menu-main-part"></div>
        </div>

        <!-- To Create Space -->
        <div style="height:50px; color:#e6e6e6;"></div>
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

</body>

</html>
