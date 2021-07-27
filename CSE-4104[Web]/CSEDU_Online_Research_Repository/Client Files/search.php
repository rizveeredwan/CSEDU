<?php
	session_start();
	$_SESSION["page_name"] = "search.php";
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

    <!--Search Types -->
    <div class="table-design">
        <!-- heading decoration -->
        <div class="table-section-heading-decoration">
            <h2>Search Options</h2>
        </div>
        <div class="radio-button-design form-group">
            <!--Space-->
            <div></div>
            <div class="radio-button-design-input">
                <input type="radio" id="project_thesis_radio" name="option">Project/Thesis
            </div>
            <div class="radio-button-design-input">
                <input type="radio" id="research_group_radio" name="option">Research Group
            </div>
            <div class="radio-button-design-input">
                <input type="radio" id="supervisor_radio" name="option">Supervisors
            </div>
            <!--space -->
            <div></div>
        </div>
    </div>


    <!--From Server search query part will come -->
    <div id="search_query_part"></div>

    <!--Search Query Part
    <div class="table-design">
        <!-- heading decoration
        <div class="table-section-heading-decoration">
            <h2>Search</h2>
        </div>

        <!-- Search Box
        <!--Thesis/Project Search
        <div class="simple-form">
            <!--Research Group
            <div class="form-group">
                <label for="Research Group">Research Group</label>
                <select class="form-control">
                    <option>Bioinformatics</option>
                    <option>Data Mining</option>
                    <option>Machine Learning</option>
                    <option>Cyber Security</option>
                    <option>Green Networking</option>
                </select>
            </div>

            <!--Supervisors
            <div class="form-group">
                <label for="supervisor">Supervisors</label>
                <select class="form-control">
                    <option>Amin Ahsan Ali</option>
                    <option>Dr.Md Mustafizur Rahman</option>
                    <option>Dr. Chowdhury Farhan Ahmed</option>
                    <option>Mamun Or Rashid</option>
                </select>
            </div>


            <!--Year
            <form class="form-inline form-group">
                <!-- Year
                <div class="form-group">
                    <label for="Year"> Year</label>
                </div>
                <div class="form-group">
                    <label for="From">From</label>
                    <input type="text" class="form-control" id="" placeholder="2017">
                </div>
                <div class="form-group">
                    <label for="To">To</label>
                    <input type="text" class="form-control" id="" placeholder="2018">
                </div>
            </form>

            <!--Thesis title
            <div class="form-group">
                <label for="title">Title</label>
                <input type="text" placeholder="thesis title" class="form-control">
            </div>

            <!--Program
            <div class="form-group">
                <label for="program">Program</label>
                <select class="form-control">
                    <option>Not Specific</option>
                    <option>BSc</option>
                    <option>MSc</option>
                    <option>Phd</option>
                    <option>Extra</option>
                </select>
            </div>

            <!--Student Name
            <div class="form-group">
                <label for="Student Name">Student Name</label>
                <input type="text" placeholder="Amor Deb Nath" class="form-control">
            </div>

            <!--Search
            <div class="form-group">
                <button type="button" class="btn btn-default btn-primary">Search</button>
            </div>
        </div>

    </div>
-->

    <!-- search result -->
    <div id="search_result"></div>

    <!--Results Section Thesis/Project
    <div class="table-design">
        <!-- heading decoration
        <div class="table-section-heading-decoration">
            <h2>Search Result</h2>
        </div>
        <div class="simple-form">
            <table class="table table-responsive table-bordered" style="background:white;">
                <!--Research Group
                <tr>
                    <td>Research Group</td>
                    <td>Data Mining</td>
                </tr>
                <!--Supervisor
                <tr>
                    <td>Supervisor</td>
                    <td>Dr.Chowdhury Farhan Ahmed</td>
                </tr>
                <!--Year
                <tr>
                    <td>Year</td>
                    <td>2018</td>
                </tr>
                <!--Title
                <tr>
                    <td>Title</td>
                    <td>Designing an efficient technique for mining sequential pattern</td>
                </tr>
                <!--Student
                <tr>
                    <td>Student</td>
                    <td>Shahadat Hossain Shahin, Redwan Ahmed Rizvee</td>
                </tr>
                <!--Student
                <tr>
                    <td>Details</td>
                    <td style="color:blue;">View</td>
                </tr>
            </table>
        </div>
    </div>
-->

    <!-- Testing ->
    <!--Research Group Details
    <div class="table-design">
        <!-- heading decoratio
        <div class="table-section-heading-decoration">
            <h2>Search Result</h2>
        </div>
        <!-- Research Group Details
        <div class="simple-form">
            <!--Simple Information 
            <table class="table table-bordered table-responsive" style="background:white;">
                <thead></thead>
                <tbody>
                    <tr>
                        <td>Name</td>
                        <td>Data Mining</td>
                    </tr>
                    <tr>
                        <td>Email</td>
                        <td>data_mining@cse.du.ac.bd</td>
                    </tr>
                    <tr>
                        <td>Phone</td>
                        <td>01758545903</td>
                    </tr>
                    <tr>
                        <td>Portfolio</td>
                        <td><a href="#">View</a></td>
                    </tr>
                </tbody>
            </table>

            <!-- heading decoratio
            <div class="table-section-heading-decoration">
                <h2>Supervisors Under Research Group</h2>
            </div>

            <!--Supervisor Informations
            <div>
                <table class="table table-bordered table-responsive" style="background:white;">
                    <thead></thead>
                    <tbody>
                        <tr>
                            <td>Name</td>
                            <td>Dr.Chowdhury Farhan Ahmed</td>
                        </tr>
                        <tr>
                            <td>Designation</td>
                            <td>Professor</td>
                        </tr>
                        <tr>
                            <td>Email</td>
                            <td>farhan@cse.du.ac.bd</td>
                        </tr>
                        <tr>
                            <td>Phone</td>
                            <td>01758545903</td>
                        </tr>
                        <tr>
                            <td>Portfolio</td>
                            <td><a href="#">View</a></td>
                        </tr>
                        <tr>
                            <td>Current Status</td>
                            <td>Present</td>
                        </tr>
                    </tbody>
                </table>

                <table class="table table-bordered table-responsive" style="background:white;">
                    <thead></thead>
                    <tbody>
                        <tr>
                            <td>Name</td>
                            <td>Dr.Chowdhury Farhan Ahmed</td>
                        </tr>
                        <tr>
                            <td>Designation</td>
                            <td>Professor</td>
                        </tr>
                        <tr>
                            <td>Email</td>
                            <td>farhan@cse.du.ac.bd</td>
                        </tr>
                        <tr>
                            <td>Phone</td>
                            <td>01758545903</td>
                        </tr>
                        <tr>
                            <td>Portfolio</td>
                            <td><a href="#">View</a></td>
                        </tr>
                        <tr>
                            <td>Current Status</td>
                            <td>Present</td>
                        </tr>
                    </tbody>
                </table>
            </div>
        </div>
    </div>
    <!--
    <div class="table-design">
        <!--One Supervisor
        <div class="simple-form">
            <!-- heading decoration
            <div class="table-section-heading-decoration">
                <h2>Searched Supervisor</h2>
            </div>
            <table class="table table-bordered table-responsive" style="background:white;">
                <thead></thead>
                <tbody>
                    <tr>
                        <td>Name</td>
                        <td>Dr.Chowdhury Farhan Ahmed</td>
                    </tr>
                    <tr>
                        <td>Designation</td>
                        <td>Professor</td>
                    </tr>
                    <tr>
                        <td>Email</td>
                        <td>farhan@cse.du.ac.bd</td>
                    </tr>
                    <tr>
                        <td>Phone</td>
                        <td>01758545903</td>
                    </tr>
                    <tr>
                        <td>Portfolio</td>
                        <td><a href="#">View</a></td>
                    </tr>
                    <tr>
                        <td>Current Status</td>
                        <td>Present</td>
                    </tr>
                </tbody>
            </table>
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
            <a href="">[Department's Website Link]</a>
            <a href="">[Contact]</a>
            <a href="">[Policy]</a>
        </div>
        <!-- Space section-->
        <div></div>
    </div>

    <script src="header_futer.js"></script>
    <script src="search.js"></script>
    <script src="search_complete.js"></script>

</body>

</html>
