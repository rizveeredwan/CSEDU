<?php
  session_start();
  $currentSelectedId = $_SESSION["currentSelectedId"];
  $currentuser = $_SESSION["username"];
?>

<!doctype html>
<html>

<head>
    <meta charset="UTF-8">
    <title>AyojonSomponnam | Home </title>
    <link href="HomePageTesting.css" type="text/css" rel="stylesheet">
    <link href="Hall.css" type="text/css" rel="stylesheet">
    <link href="HallBookPage.css" type="text/css" rel="stylesheet">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
</head>

<body>
    <header>
        <nav>
            <h1 id="header">AyojonSomponnam</h1>
            <ul>
                <li class="headerOption"><a href="LogInClient.php" class="notCurrent" id="logInRef">Log in</a></li>
                <li class="headerOption"><a href="SignUp.php" class="notCurrent" id="signUpRef">Sign up</a></li>
                <li class="headerOption"><a href="#" class="notCurrent">About Us</a></li>
                <li class="headerOption"><a href="#" class="notCurrent">Contact</a></li>
            </ul>
        </nav>
    </header>

    <div id="breakLine">
    </div>


    <div id="menuDivisionUp">
        <p1><a href="HomePageTesting.php" class="meneOption">Home</a></p1>
        <p1><a href="Hall.php" class="meneOption">Hall</a></p1>
        <p1><a href="Catering.php" class="meneOption">Catering</a></p1>
        <p1><a href="Decorator.php" class="meneOption">Decorator</a></p1>
        <p1><a href="Photographer.php" class="meneOption">Photographer</a></p1>
        <p1><a href="MarriageOfficiant.php" class="meneOption">Marriage Officiant</a></p1>
    </div>

    <div id="menuDivision">
        <nav id="menuNev">
            <ul>
                <li><a href="#" class="meneOption">Home</a></li>
                <li><a href="#" class="meneOption">Hall</a></li>
                <li><a href="#" class="meneOption">Catering</a></li>
                <li><a href="#" class="meneOption">Decorator</a></li>
                <li><a href="#" class="meneOption">Photographer</a></li>
                <li id="officiant"><a href="#">Marriage Officiant<a/></li>    
            </ul>
        </nav>
    </div>

    <div id="hall">
        <div id="mainHeader">
            <h1 id="hallHeader">Halls</h1>
        </div>

        <div id="photoGallery">
        <img class="mySlides" src="hall_0.jpg" width="700px" height="500px" id="credImg1">
        <img class="mySlides" src="hall_1.jpg" width="700px" height="500px" id="credImg2" >
        <img class="mySlides" src="hall_2.jpg" width="700px" height="500px" id="credImg3">
        <img class="mySlides" src="hall_0.jpg" width="700px" height="500px" id="credImg4">
        <img class="mySlides" src="hall_1.jpg" width="700px" height="500px" id="credImg5">

        </div>

        <div class="pageItems">
             <div class="info">
                 <div class="image">
                      <img src="hall_0.jpg" width="100%" height="100%" id="thumbnail">
                 </div>
                 <div class="lekha">
                     <h2>Informations</h2>
                      Name:<p1 id="name">Rawa Community Center</p1><br/>
                      Address:<p1 id="address">47/5 Mia Fazilchisti,Sylhet</p1><br/>
                      Contact No:<p1 id="contact">01796660214</p1><br/>
                      Email:<p1 id="email"> otpid.is@gmail.com</p1><br/>
                      Capacity:<p1 id="capacity">500</p1></br>
                      Booking Fee:<p1 id="fee">25000 BDT.</p1></br>
                      portfolio link:<p1 id="portfolio"><a href="http://www.facebook.com">khana khajana fan page</a></p1></br>
                      
    </div>
    </div>
    </div>
    </div>

    <div id="hallItem">
        <h1>Hall Information</h1>
        <div id="tableDiv">
            <table id="hallItemTable" align="center">
                <tr>
                    <th>Number</th>
                    <th>Hall Name</th>
                    <th>Capacity</th>
                </tr>

                <tr>
                    <td>1</td>
                    <td>Grand Sultan</td>
                    <td>500</td>
                </tr>
                <tr>
                    <td>2</td>
                    <td>Darbar Hall</td>
                    <td>700</td>
                </tr>
            </table>
        </div>
    </div>

    <br/>
    <br/>
   
    <div id="bookPart">
        <div>
            <h1>Book</h1>
            <form id="formPart">
                Date: <input type="date" name="" placeholder="dd-mm-y" id="date"><br/> 
                Time:<input type="text" name="" placeholder="morning/evening" id="time"><br/> 
                Availability:<p1 id="availability">Press Availability to check Availability</p1><br/>
            </form>
            <form id="buttonPart">
                <input type="submit" value="Check Availability" id="available">
                <input type="submit" value="Book" id="book">
                <input type="submit" value="In queue" id="queue">
            </form>
        </div>
    </div>
    <br/>

    <div>
       
    </div>

    <div id="bookedDate">
         <div>
             <h1>Show Booked Schedules</h1>
             <div id="bookedScheduleDiv">
             <form id="bookedSchedule">
                 From: <input type="date" placeholder="date" value="" name="" id="from">  
                 To: <input type="date" placeholder="date" value="" names="" id="to">
                 <input type="submit" value="check" name="" id="check">
             </form>
             </div>
         <div>
         <div id="resultAppend">
        <!---
           <div id="result">
               <table id="bookedTable" align="center">
                    <tr>
                       <th>Date</th>
                       <th>Time</th>
                    </tr>
                    <tr>
                       <td>12-02-1996</td>
                       <td>Morning</td>
                    </tr>
               </table>
           </div>
            -->
         </div>
    </div>

    <div id="breakLine">
    </div>

    <script type="text/javascript" src="HallImageSlider.js"></script>
    <script type="text/javascript" src="HallBookPage.js"></script>
    <script>
       var v ="<?php echo $currentuser;?>";
       initialize(v);
    </script>
</body>

</html>