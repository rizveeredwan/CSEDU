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
    <link href="PhotographerAccount.css" type="text/css" rel="stylesheet">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>    
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>   
</head>

<body>
    <header>
        <nav>
            <h1 id="header">AyojonSomponnam</h1>
            <ul>
                <li class="headerOption"><a href="#" class="notCurrent" id="logInRef">Log In</a></li>
                <li class="headerOption"><a href="#" class="notCurrent" id="signUpRef">Sign In</a></li>
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
    
    <div id="account">
        <h1>Account Information</h1>
        <div id="information">
            Name: <input type="text" name="" placeholder="" value="Azwad Anjum Islam Dipto" class="infoClass" id="name">
            User Name: <input type="text" name="" placeholder="" value="P0" class="infoClass" id="username">
  Office Address: <input type="text" name="" placeholder="" value="47/5 Mia FazilChisti" class="infoClass" id="officeAddress">
  Residential Address/Second Address: <input type="text" name="" placeholder="" value="47/5 Mia FazilChisti" class="infoClass" id="secondAddress">
  Contact No:<input type="text" name="" placeholder="" value="01796660214" class="infoClass" id="contact">
  Email: <input type="email" name="" placeholder="" value="otpid.is@gmail.com" class="infoClass" id="email">
  Password: <input type="password" name="" placeholder="" value="dipto" class="infoClass" id="password">
  Confirm Password: <input type="password" name="" placeholder="" value="dipto" class="infoClass" id="confirmPassword">
  Date-of-Birth: <input type="date" name="" placeholder="" value="23-08-1996" class="infoClass" id="birth">
  Religion:<input type="text" name="" placeholder="" value="Islam" class="infoClass" id="religion">
  Cast:<input type="text" name="" placeholder="" value="Sunni" class="infoClass" id="cast">
  Gender: <input type="text" name="" placeholder="" value="gender" class="infoClass" id="gender">
  NID: <input type="text" name="" placeholder="" value="1234567890" class="infoClass" id="nid">
  TIN: <input type="text" name="" placeholder="" value="1234567890" class="infoClass" id="tin">
  Portfolio link:<input type="text" name="" placeholder="" value="1234567890" class="infoClass" id="portfolio"> 

  <h2>Image File Upload Section</h2>
  Thumbnail Image:(uploading will override existing file/image condition)<input type="file" enctype="multipart/form-data" id="thumbnail">
   </div>
    </div>
    
    
    <div id="submitButton">
        <input type="button" name="" value="submit" id="submit">
    </div>

    <script type="text/javascript" src="CustomerAccount.js"></script>     
    <script>
        var v = "<?php echo $currentuser?>";
        window.onload = function(event){
            event.preventDefault();
            initialize(v);
            return false;
        };
    </script>
</body>
</html>