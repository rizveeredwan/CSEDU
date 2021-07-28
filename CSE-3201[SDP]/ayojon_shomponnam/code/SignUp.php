<?php
  session_start(); 
?>
<!doctype html>
<html>

<head>
    <meta charset="UTF-8">
    <title>AyojonSomponnam | Home </title>
    <link href="HomePageTesting.css" type="text/css" rel="stylesheet">
    <link href="SignUp.css" type="text/css" rel="stylesheet">
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

    <div id="signUpForm">
          <h1 id="signUpHeader">Sign up</h1>
          <div id="signForm">
              <form>
                  <input type="text" name="" class ="formBox" placeholder="username/service provider name" id="name">
                  <input type="text" name="" class ="formBox" placeholder="Service providers address" id="addressMain">
                  <input type="text" name="" class ="formBox" placeholder="residential address(mandatory for customer and officiants" id="addressSub">
                  <input type="text" name="" class ="formBox" placeholder="contact No" id="contact">
                  <input type="email" name="" class ="formBox" placeholder="email" id="email">
                  <input type="password" name="" class ="formBox"  placeholder="password" id="password">
                  <input type="password" name="" class ="formBox" placeholder="confirm password" id="confirmPassword">
                  <h2>Choose Account type</h2>
                  <input type="radio" name="option"  value="Customer" id="customer">Customer
                  <input type="radio" name="option"  value="Hall" id="hall">Hall
                  <input type="radio" name="option"  value="Catering" id="catering">Catering
                  <input type="radio" name="option"  value="Decorator" id="decorator">Decorator
                  <input type="radio" name="option"  value="Photographer" id="photographer">Photographer
                  <input type="radio" name="option"  value="Marriage Officiant" id="officiant">Marriage Officiant
                  <input type="date" name="" class ="formBox" placeholder="Date-of-Birth(mandatory for customer and officiants)" id="birth">
                  <h2>Choose Gender:Mandatory for Customer type Account</h2>
                  <input type="radio" name="gender" value="Male" id="male">Male
                  <input type="radio" name="gender" value="Female" id="female">Female
                  <input type="radio" name="gender" value="Marriage Officiant" id="others">others
                  <br/>
                  <input type="text" name="" class ="formBox" placeholder="NID No(mandatory for customer and officiants)" id="nid">
                  <input type="text" name="" class ="formBox" placeholder="TIN No(mandatory for service providers)" id="tin">
                  <input type="text" name="" class ="formBox" placeholder="religion(mandatory for customers and offciants)" id="religion">
                  <input type="text" name="" class ="formBox" class ="formBox" placeholder="cast(mandatory for customers and offciants)" id="cast">
                  <input type="text" name="" class ="formBox" placeholder="portfolio link" id="portfolioLink">
                  <br/>
                  <form id="uploadForm" enctype="multipart/form-data">
                        <br/>
                      <h2>Upload Thumbnail Image File</h2>
                      <input type="file" name="" id="thumbnail" > 
                  </form>
                  <br/> 
                  <input type="submit" name="" value="Create" id="create">
                </form>
          </div>
    </div>
    
   <script  type="text/javascript" src="SignUp.js"></script> 
   
</body>
</html>