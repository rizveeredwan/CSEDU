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
                        <li>The Sole purpose of our website is to provide a better,
                            easier and collaborative environment to accomplish research works/projects.
                        </li>
                        <li>Any thesis/project uploaded in the repository is the property of the 
                        department of Computer Science and Engineering, University of Dhaka(CSEDU). 
                        Each of these works is the result of immense dedication and hard work.
                        Any unintended use of these works without the consent of authority will be 
                        considered as an act of plagiarism.
                        </li>
                        <li>
                            Thesis/Project works are very crucial and senstive topic.Please be careful
                            while sharing any infomation regarding them.Any kind of 
                            unethical and unprofessional act regarding them is considered as punishable 
                            act and if found doing that, strict action will be taken by the authority.
                        </li>
                        <li>
                            Each research group is controlled by managers.So it is expected to behave
                            with professionalism in each step. Ethics and professionalism is expected to be carried
                            all the time. Personal rivalry of clash should not be used.While maintaining a research 
                            work or project, supervisors and students both must respect each others concent and 
                            do not perform any unintended behavious.
                        </li>
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
                         <i><b style="color:#ffbf00;">CSEDU Online Research Repository</b></i> is 
                         a dream work of some respectable faculty members and students of CSEDU. 
                         CSEDU provides highest echelon of technology and academics.One of the most 
                         fascinating feature of us is to provide a good environment for qualitiful research.
                         Message from our chairperson: 
                    </div>
                    <div>
                         <div style="margin-top:1%; background:white; color:black;">
                         <blockquote cite="http://www.cse.du.ac.bd/">
                                <span><i><b>"We provide not only a world class teaching atmosphere for
                                the core areas of CSE, but also high quality research environment
                                of interdisciplinary areas."</b></i></span>
                         </blockquote>
                         </div>
                    </div>
                    <div>
                        But we didn't have our own repository sytem to collectively control the whole works.
                        And from that dream this website was created. To make an online based system
                        to get all the works in one place.
                    </div>
                    <!-- Here the image of Mamun sir-->
                    <div style="margin-left:1%; margin-right:1%; margin-top:2%; display:grid; grid-template-columns:30% 50%;">
                        <div>
                            <img class="img-thumbnail" src="mamun sir.jpeg" style="width:100%;">
                            <div class="caption" style="background:black; color:white; text-align:center; padding:2% 2% 2% 2%;">
                                <p>Mamun Or Rashid</p>
                            </div>
                        </div>
                        <!--description-->
                        <div style="margin-left:10%;">
                            <div>
                               This beautiful idea came from our respectable sir, Professor Mamun Or Rashid.Developers 
                               express their gratitude to give them scope to do this prestiguous work for our own department.
                               We hope this website will make a marvellous effect in the field of research for CSEDU.And thank
                               you sir for believing in us.
                            </div>
                        </div>
                    </div>

                    <!-- Rana sir -->
                    <!-- Here the image of Mamun sir-->
                    <div style="margin-left:1%; margin-right:1%; margin-top:2%; display:grid; grid-template-columns:50% 30%;">
                        <!--description-->
                        <div style="margin-right:10%;">
                            <div>
                                The whole work was supervised under precious guidance of sir,Mahmudur Rahman Rana.
                                Thank you very much for your kind advice,guidance,time and motivation.And thank 
                                you for pointing out various issues related to making websites. Those advices really
                                helped us while building the website, securing the website,designing the UI,UX.
                            </div>
                        </div>
                        <div>
                            <img class="img-thumbnail" src="rana sir.jpg" style="width:100%;">
                            <div class="caption" style="background:black; color:white; text-align:center; padding:2% 2% 2% 2%;">
                                <p>Mahmudur Rahman Rana</p>
                            </div>
                        </div>
                    </div>

                    <!-- Rana sir -->
                    <!-- Here the image of Mamun sir-->
                    <div style="margin-left:1%; margin-right:1%; margin-top:2%; display:grid; grid-template-columns:50% 48%;">
                        <!--description-->
                        <div style="margin-right:10%;">
                            <div>
                               This website was made as a project of CSE 4114: E-Commerce and Web Engineering lab,2018. Developers
                               behind this website was Mehreen Rahman and Redwan Ahmed Rizvee.It was a very beautiful journey
                               for the developers while developing the website. Creating something new is always very attractive and fascinating
                               for us.<br>
                               We do want to thank, sir Hasnain Heickal, for motivating us to do something for dept. in 2-2 while
                               taking algorithm course to make us learn how to think. We want to thank Mofizul Islam Akash, for
                               our software design pattern course and to make us teach why software design patterns are necessary.This course
                               was really helpful for making this website.<br>
                               And we do want to thank Fahim Arefin(20th batch),Pritom Saha(20th batch), the knights of debugging.We 
                               started from zero knowledge and came here, becuase of their many advices and guidance.<br>
                               And We want to thank Abid Naziri Sami, Mahfda Jerin, Nahian Ashraf Raida,Amor Deb Nath,Mukhlesur
                               Rahman Bulbul,Tahsin Sayeed, Abdul Helal, Shahadat Hossain Shahin and many others for their 
                               valuable suggestions and help. <br>
                               Thank you Very much.
                               
                            </div>
                        </div>
                        <div>
                            <img class="img-thumbnail" src="mehreen.jpg" style="width:100%;">
                            <div class="caption" style="background:black; color:white; text-align:center; padding:2% 2% 2% 2%;">
                                <p>Mehreen and Rizvee</p>
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
            <a href="http://www.cse.du.ac.bd/">[Department's Website Link]</a>
            <a href="about_us.php">[Contact]</a>
            <a href="about_us.php">[Policy]</a>
        </div>
        <!-- Space section-->
        <div></div>
    </div>

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
