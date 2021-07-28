<?php
   session_start();
?>

<!doctype html>
<html>

<head>
    <meta charset="UTF-8">
    <title>AyojonSomponnam | Home </title>
    <link href="HomePageTesting.css" type="text/css" rel="stylesheet">
    <link href="LogIn.css" type="text/css" rel="stylesheet">

</head>

<body>

    <header>
        <nav>
            <h1 id="header">AyojonSomponnam</h1>
            <ul>
            <li class="headerOption"><a href="LogIn.php" class="notCurrent" id="logInRef">Log in</a></li>
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

    <div id="breakLine">
    </div>
     
    <div class="title">
        <h1>Log In</h1>
    </div>
    <div class="container">
            <div class="left">
                
            </div>
            <div class="right">
                <div class="formBox">
                     <form id="formInputLogIn" onsubmit="foo()">
                         <p>user name</p>
                         <input type="text" name="" placeholder="user name" id="userName">
                         <p>password</p>
                         <input type="password" name="" placeholder="...." id="passWord">
                         <input type="submit" name="" value="Log in">                         
                         <a href="#">Forgot Password</a>
                    </form>
    </div>
    </div>
    </div>
    <script src="LogIn.js"></script>
</body>
</html>
