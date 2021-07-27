<?php
	session_start();
	$_SESSION["page_name"] = "create_research_group.php";
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

    <!--The Log in Section -->
    <div class="form" id="part-1">
        <div></div>
        <div>
            <form class="form-container">
                <h1>Research Group Information</h1>
                <!--Research Group Name-->
                <div class="form-group">
                    <label for="name">Research Group Name</label>
                    <input type="text" class="form-control" id="name" placeholder="Green Network">
                </div>
                <!--Account Type-->
                <div class="form-group">
                    <label for="account_type">Account</label>
                    <select class="form-control" id="account">
                            <option>Manager</option>
                    </select>
                </div>

                <!--Password -->
                <div class="form-group">
                    <label for="password">Password</label>
                    <input type="password" class="form-control" id="password" placeholder="Password">
                </div>

                <!--Confirm Password -->
                <div class="form-group">
                    <label for="confirm password">Confirm Password</label>
                    <input type="password" class="form-control" id="confirm_password" placeholder="Confirm Password">
                </div>

                <!--Email -->
                <div class="form-group">
                    <label for="email">Email</label>
                    <input type="email" class="form-control" id="email" placeholder="someone@gmail.com">
                </div>

                <!--Phone Number-->
                <div class="form-group">
                    <label for="phone">Phone</label>
                    <input type="text" class="form-control" id="phone1" placeholder="0173*******">
                    <input type="text" class="form-control" id="phone2" placeholder="0173*******">
                </div>

                <!--Website Link-->
                <div class="form-group">
                    <label for="link">Website Link</label>
                    <input type="text" class="form-control" id="link" placeholder="www.shoshikkha.com">
                </div>

                <!--Create button-->
                <button type="submit" class="btn btn-default" id="create">Create</button>
            </form>
        </div>
        <div> </div>
    </div>

    <!--The Footer Section-->
    <div class="footer">
        <!-- Space section-->
        <div></div>
        <!--Copyright Section-->
        <div class="copyright-section">
            <h6>&#169 CSEDU Research Repository</h6>
        </div>
        <!-- Empty  Section-->
        <div></div>
        <!--Contact Section-->
        <div class="contact-section">
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

    <script src="create_research_group.js"></script>
    <script src="header_futer.js"></script>

</body>

</html>
