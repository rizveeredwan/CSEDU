<?php
	session_start();
	$_SESSION["page_name"] = "research_group_account.php";
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

    <!--Research Group Meta data section-->
    <div id="research_group_metadata_server"></div>

    <!--The Reseach Group Information Section
    <div class="form" id="part-1">
        <div></div>
        <div>
            <form class="form-container">
                <h1>Research Group Information</h1>
                <!--Research Group Name
                <div class="form-group">
                    <label for="name">Research Group Name</label>
                    <input type="text" class="form-control" id="name" value="Green Network" readonly>
                </div>
                <!--Account Type
                <div class="form-group">
                    <label for="account_type">Account</label>
                    <select class="form-control" id="account">
                            <option>Manager</option>
                    </select>
                </div>

                <!--Password
                <div class="form-group">
                    <label for="password">Password</label>
                    <input type="password" class="form-control" id="password" value="">
                </div>

                <!--Confirm Password
                <div class="form-group">
                    <label for="confirm password">Confirm Password</label>
                    <input type="password" class="form-control" id="confirm_password" placeholder="Confirm Password">
                </div>

                <!--Email
                <div class="form-group">
                    <label for="email">Email</label>
                    <input type="email" class="form-control" id="email" placeholder="someone@gmail.com">
                </div>

                <!--Phone Number
                <div class="form-group">
                    <label for="phone">Phone</label>
                    <input type="text" class="form-control" id="phone1" placeholder="0173*******">
                    <input type="text" class="form-control" id="phone2" placeholder="0173*******">
                </div>

                <!--Website Link
                <div class="form-group">
                    <label for="link">Website Link</label>
                    <input type="text" class="form-control" id="link" placeholder="www.shoshikkha.com">
                </div>

                <!--Google Drive Link
                <div class="form-group">
                    <label for="link">Google Drive Link</label>
                    <input type="text" class="form-control" id="link" placeholder="www.googledrive.com">
                </div>

                <!--Dropbox Link
                <div class="form-group">
                    <label for="link">Dropbox Link</label>
                    <input type="text" class="form-control" id="link" placeholder="www.dropbox.com">
                </div>

                <!--Github Link
                <div class="form-group">
                    <label for="link">Github Link</label>
                    <input type="text" class="form-control" id="link" placeholder="www.dropbox.com">
                </div>

                <!--Facebook Link
                <div class="form-group">
                    <label for="link">Facebook Profile</label>
                    <input type="text" class="form-control" id="link" placeholder="www.dropbox.com">
                </div>

                <!--Update button
                <button type="submit" class="btn btn-default" id="update">Update</button>
                <button type="submit" class="btn btn-default" id="delete">Delete</button>
                <!--Alert Message
                <div>
                    </br>
                    </br>
                </div>
                <div class="alert alert-warning">
                    <strong>Warning!</strong> Very Careful while deleting.Delete operation will clear everything related to this research group.
                </div>
            </form>
        </div>
        <div> </div>
    </div>
-->

    <!--Supervisor add section -->
    <div id="supervisor_add_section"></div>

    <!--Table Design
    <div class="table-design">
        <!-- heading decoration
        <div class="table-section-heading-decoration">
            <h2>Supervisors Informations</h2>
        </div>
        <div class="simple-form">
            <!--Supervisor Suggestion
            <div class="form-group">
                <label for="supervisor_suggestion">Faculty Members</label>
                <select class="form-control">
                    <option>Hasnain Heickel (hhjami@gmail.com)</option>
                    <option>Md. Haidar Ali (haidar_ali@gmail.com)</option>
                </select>
            </div>
        </div>
        <!--Add Button
        <div class="button-center">
            <div></div>
            <div>
                <button type="submit" class="btn btn-default btn-success btn-block" id="add">Add</button>
            </div>
            <div></div>
        </div>
        <!-- Supervisor Informations
        <div class="simple-form">
            <table class="table table-bordered table-responsive" style="background:white;">
                <thead></thead>
                <tbody>
                    <tr>
                        <td>Name</td>
                        <td>Hasnain Heickel</td>
                    </tr>
                    <tr>
                        <td>Designation</td>
                        <td>Assistant Professor</td>
                    </tr>
                    <tr>
                        <td>Email</td>
                        <td>hhjami@gmail.com</td>
                    </tr>
                    <tr>
                        <td>Phone</td>
                        <td>01758545903</td>
                    </tr>
                    <tr>
                        <td>Portfolio</td>
                        <td><a href="#">Profile</a></td>
                    </tr>
                    <tr>
                        <td>Status</td>
                        <td>Present</td>
                    </tr>
                </tbody>
            </table>
            <div class="form-group">
                <button class="btn btn-default btn-danger" type="submit" id="">Remove</button>
            </div>
        </div>
    </div>
-->

    <div id="create_thesis_section_server"></div>

    <!--Thesis create section
    <div class="table-design">
        <!-- heading decoration
        <div class="table-section-heading-decoration">
            <h2>Creating Thesis/Project</h2>
        </div>
        <div class="simple-form">
            <form>
                <!--Thesis/Project Name
                <div class="form-group">
                    <label for="thesis_name">Thesis/Project Name</label>
                    <input type="text" class="form-control" id="thesis_name" placeholder="Designing an efficient..">
                </div>
                <!--Supervisor Name
                <div class="form-group">
                    <label for="supervisor_name">Supervisor Name</label>
                    <select id="supervisor_name" class="form-control">
                        <option>Mamun Or Rashid</option>
                        <option>Mofijul Islam Akash</option>
                    </select>
                </div>
                <!--Year of this thesis
                <div class="form-group">
                    <label for="year">Year</label>
                    <input type="text" class="form-control" id="year" value="2018">
                </div>
                <!--View
                <div class="form-group">
                    <label for="general_view">General View</label>
                    <select id="view" class="form-control">
                        <option>Yes</option>
                        <option>No</option>
                    </select>
                </div>

                <!--Student Number
                <div class="form-group">
                    <label for="num_student">Add Student</label>
                </div>

                <div class="space-creator-from-top" id="student_list">
                    <table class="table table-bordered table-responsive" style="background:white;" id="student_info">
                        <thead>
                            <tr>
                                <td>Name</td>
                                <td>Roll</td>
                                <td>Email</td>
                                <td>Program</td>
                            </tr>
                        </thead>
                        <tbody>
                            <!-- 
                            <tr>
                                <td><input type="text" id="" class="form-control" placeholder="name"></td>
                                <td><input type="text" id="" class="form-control" placeholder="roll"></td>
                                <td><input type="text" id="" class="form-control" placeholder="session"></td>
                                <td><input type="text" id="" class="form-control" placeholder="email"></td>
                                <td><input type="text" id="" class="form-control" placeholder="password"></td>
                            </tr>
                        -->
    <!--
                        </tbody>
                    </table>

                    <!--Add new row, Thesis group create button
                    <div class="form-group">
                        <button type="button" class="btn btn-default btn-success" id="student_list_create">Add Student</button>
                        <button type="button" class="btn btn-default btn-danger" id="student_list_delete">Delete Student</button>
                        <button type="button" class="btn btn-default btn-warning" id="create_thesis">Create Thesis/Project</button>
                    </div>
                </div>


            </form>
        </div>
    </div>

-->

    <!--File Upload Section-->
    <div class="table-design">
        <!-- heading decoration -->
        <div class="table-section-heading-decoration">
            <h2>File Upload Section</h2>
        </div>
        <!--File Upload -->
        <!--Here Simple Form decorates the div make a mergin from left-->
        <div class="simple-form">
            <!--File Showing/Provoking option-->
            <div class="form-group table-update-button">
                <label for="file_viewing">File Showing Option</label>
                <select class="form-control" id="view">
                        <option>Yes</option>
                        <option>No</option>
                </select>
            </div>
            <!--File Type option-->
            <div class="form-group table-update-button">
                <label for="file_type">File Type</label>
                <select class="form-control">
                        <option>Research Group General File</option>
                </select>
            </div>
            <!--File Upload Part -->
            <div class="form-group table-update-button">
                <form enctype="multipart/form-data">
                    <input type="file" name="file" id="file_input">
                </form>
            </div>
            <div class="form-group table-update-button">
                <button type="button" class="btn btn-default btn-success" id="file_submit">upload file</button>
            </div>
        </div>

        <!--Submitted Files Showing Part-->
        <div class="simple-form">
            <div id="files_from_server"></div>
            <!-- Existing File
            <div class="table-section-heading-decoration">
                <h2>Files</h2>
            </div>
            <div>
                <table class="table table-bordered table-responsive" style="background:white;">
                    <thead></thead>
                    <tbody>
                        <td>Uva</td>
                        <td><a href="/home/rizvee/Books/WEB/uva" target="_blank">View</a></td>
                        <td><a href="/home/rizvee/Books/WEB/uva" download="uva">Download</a></td>
                        <td><button type="button" class="btn btn-default btn-danger" id="">Remove</button></td>
                    </tbody>
                </table>
            </div>
        -->
        </div>

    </div>


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


    <!--Modal Section -->
    <div class="modal fade" id="my_modal" role="dialog">
        <div class="modal-dialog">
            <!--Modal Content -->
            <div class="modal-content">
                <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal">&times;</button>
                <h4 class="modal-title">Mail to be sent</h4>
            </div>
            <div class="modal-body" id="modal_description">
                
                <!--<p>Some text in the modal.</p>-->
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-default" id="send_mail" data-dismiss="modal">send mail</button>
            </div>
      </div>
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

    <!-- <script src="create_research_group.js"></script> -->
    <script src="sql_injection.js"></script>
    <script src="create_thesis.js"></script>
    <script src="header_futer.js"></script>
    <script src="research_group_account.js"></script>
    <script src="file_upload.js"></script>

</body>

</html>
