<?php
     session_start(); 
     $currentuser = $_SESSION["username"];
?>
<!doctype html>
<html>

<head>
    <meta charset="UTF-8">
    <title>AyojonSomponnam | Home </title>
    <link href="HomePageTesting.css" type="text/css" rel="stylesheet">
    <link href="Catering.css" type="text/css" rel="stylesheet"><link href="MarriageOfficiantAccount.css" type="text/css" rel="stylesheet">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
</head>

<body>
    <header>
        <nav>
            <h1 id="header">AyojonSomponnam</h1>
            <ul>
            <li class="headerOption"><a href="#" class="notCurrent" id="logInRef">Log in</a></li>
            <li class="headerOption"><a href="#" class="notCurrent" id="signUpRef">Sign up</a></li>
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
                      Name:<p1>Khana Khajana</p1><br/>
                      Address:<p1>47/5 Mia Fazilchisti,Sylhet</p1><br/>
                      Contact No:<p1>01796660214</p1><br/>
                      Email:<p1>otpid.is@gmail.com</p1>
                      <form class="more">
                          <input type="submit" name="" value="More Details" class="button" id="T1">
                      </form>
                 </div>
             </div>
        </div>
  </div>
  <script src="Catering.js" type="text/javascript"></script>
       <script> 
            var v = "<?php echo $currentuser?>";
            initialize(v);
         </script>
       </script>
    </body>
    </html>