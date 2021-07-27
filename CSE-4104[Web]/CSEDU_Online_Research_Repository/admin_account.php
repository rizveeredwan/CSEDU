<?php
	session_start();
	$_SESSION["page_name"] = "admin_account.php";
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

    <!-- -->
    <div id="will_come_from_server">

    </div>
    <!--The Admin Account Part
    <div class="table-design">
        <!-- heading decoration
        <div class="table-section-heading-decoration">
            <h2>Admin Account </h2>
        </div>
        <div class="simple-form">
            <!--Account Type
            <div class="form-group">
                <label for="Account Type">Account Type</label>
                <input type="text" class="form-control" value="Admin" readonly>
            </div>
            <!--Password
            <div class="form-group">
                <label for="Password">Password</label>
                <input type="password" class="form-control" placeholder="password">
            </div>
            <!--Confirm Password
            <div class="form-group">
                <label for="Confirm Password">Confirm Password</label>
                <input type="password" class="form-control" placeholder="">
            </div>
            <!--Email
            <div class="form-group">
                <label for="Email">Email</label>
                <input type="email" class="form-control" placeholder="someone@gmail.com">
            </div>
            <!--Phone 
            <div class="form-group">
                <label for="Phone">Phone</label>
                <input type="text" class="form-control" placeholder="01758545903">
            </div>
        </div>

        <!--Supervisors Section
        <div class="table-section-heading-decoration">
            <h2>Teachers Section </h2>
        </div>

        <!--Input Field
        <div class="simple-form">
            <table class="table table-bordered table-responsive" style="background:white;">
                <thead></thead>
                <tbody>
                    <tr>
                        <td>Name</td>
                        <td><input type="text" class="input-field-design" placeholder="name"></td>
                    </tr>
                    <tr>
                        <td>Designation</td>
                        <td><input type="text" class="input-field-design" placeholder="professor/lecturer"></td>
                    </tr>
                    <tr>
                        <td>Email</td>
                        <td><input type="email" class="input-field-design" placeholder="someone@gmail.com"></td>
                    </tr>
                    <tr>
                        <td>Phone</td>
                        <td><input type="text" class="input-field-design" placeholder="017........"></td>
                    </tr>
                    <tr>
                        <td>Portfolio</td>
                        <td><input type="text" class="input-field-design" placeholder="link of profile"></td>
                    </tr>
                    <tr>
                        <td>Current Status</td>
                        <td><input type="text" class="input-field-design" placeholder="Active/On leave"></td>
                    </tr>
                </tbody>
            </table>
            <!--Add supervisor
            <div class="form-group">
                <button type="button" class="btn btn-default btn-success">Add New Teacher</button>
            </div>
        </div>

        <!--Existing Teachers
        <div class="simple-form">
            <table class="table table-bordered table-responsive" style="background:white;">
                <thead>
                    <tr>
                        <td>Name</td>
                        <td>Designation</td>
                        <td>Email</td>
                        <td>Phone</td>
                        <td>Portfolio</td>
                        <td>Status</td>
                        <td></td>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td>Hasnain Heickel</td>
                        <td>Assistant Lecturer</td>
                        <td>hhjami@gmail.com</td>
                        <td>01758545903</td>
                        <td><a href="#">www.facebook.com</a></td>
                        <td>Active</td>
                        <td><button type="button" class="btn btn-default btn-danger">Delete</button></td>
                    </tr>
                </tbody>
            </table>
        </div>

        <!--Create New Research Group-
        <div class="simple-form">
            <div class="form-group">
                <button type="button" class="btn btn-default btn-primary">Create New Research Group</button>
            </div>
        </div>

        <!--Update
        <div class="simple-form">
            <div class="form-group">
                <button type="button" class="btn btn-default btn-warning">Update</button>
            </div>
        </div>


    </div>

-->

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

    <script src="sql_injection.js"></script>
    <script src="header_futer.js"></script>
    <script src="admin_account.js"></script>

</body>

</html>
