<?php
	session_start();
	$_SESSION["page_name"] = "login.php";
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
    <div id="came_from_server_log_in_form">
        <!--
        <div class="form" id="part-1">
            <div></div>
            <div>
                <form class="form-container">
                    <h1>Log in</h1>
                    <!--Account Type
                    <div class="form-group">
                        <label for="account_type">Account</label>
                        <select class="form-control" id="account">
                            <option>Admin</option>
                            <option>Manager</option>
                            <option>Student</option>    
                            <option>Viewer</option>
                    </select>
                    </div>

                    <!--Research Group Selection
                    <div class="form-group">
                        <label for="research_group">Research Group</label>
                        <select class="form-control" id="research_group">
                        <option>Green Networking</option>
                        <option>Data Mining</option>
                        <option>Machine Learning</option>
                        <option>Cyber Security</option>
                        <option>Image Processing</option>
                    </select>
                    </div>

                    <!--Password
                    <div class="form-group">
                        <label for="password">Password</label>
                        <input type="password" class="form-control" id="password" placeholder="Password">
                    </div>

                    <!--Submit button
                    <button type="submit" class="btn btn-default" id="submit">Submit</button>
                    <!--Create New Research group
                    <button type="submit" class="btn btn-default" id="create_new">Create New Research Group</button>
                </form>
            </div>
            <div> </div>
        </div> 
    -->
    </div>

    <!--This part is for students -->
    <div class="form" id="part-2">
        <div></div>
        <div>
            <form class="form-container">
                <h1>Working Thesis/Project</h1>
                <div class="form-group">
                    <label for="Thesis/Project Code No">Thesis/Project Code No</label>
                    <input type="text" class="form-control" id="code" placeholder="TH-01">
                </div>
                <div class="form-group">
                    <label for="id">ID</label>
                    <input type="text" class="form-control" id="student_id" placeholder="@#456720">
                </div>
                <!--Submit button-->
                <button type="submit" class="btn btn-default" id="submit_two">Submit</button>
            </form>
        </div>
        <div></div>
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
            <a href="">[Department's Website Link]</a>
            <a href="">[Contact]</a>
            <a href="">[Policy]</a>
        </div>
        <!-- Space section-->
        <div></div>
    </div>

    <script src="login.js"></script>
    <script src="header_futer.js"></script>

</body>

</html>
