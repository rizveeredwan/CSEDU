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
    <link href="Catering.css" type="text/css" rel="stylesheet">
    <link href="CateringBookPage.css" type="text/css" rel="stylesheet">
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

    <div id="catering">
        <div id="mainHeader">
            <h1 id="cateringHeader">Caterers</h1>
        </div>

        <div class="pageItems">
             <div class="info">
                 <div class="image">
                      <img src="catering2.jpeg" width="100%" height="100%">
                 </div>
                 <div class="lekha">
                     <h2>Informations</h2>
                      Name:<p1 id="name">Khana Khajana</p1><br/>
                      Address:<p1 id="address">47/5 Mia Fazilchisti,Sylhet</p1><br/>
                      Contact No:<p1 id="contact">01796660214</p1><br/>
                      Email:<p1 id="email">otpid.is@gmail.com</p1><br/>
                    portfolio link:<p1 id="portfolio"><a href="http://www.facebook.com">khana khajana fan page</a></p1>
    </div>
    </div>
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
         </div>
    </div>
    <script type="text/javascript" src="CateringBookPage.js"></script>
    <script>
       var v ="<?php echo $currentuser;?>";
       initialize(v);
    </script>
</body>
</html>