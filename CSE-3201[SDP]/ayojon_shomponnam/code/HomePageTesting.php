<!doctype html>
<html>

<head>
    <meta charset="UTF-8">
    <title>AyojonSomponnam | Home </title>
    <link href="HomePageTesting.css" type="text/css" rel="stylesheet">
</head>

<body>
    <header>
        <nav>
            <h1 id="header">AyojonSomponnam</h1>
            <ul>
                <li class="headerOption"><a href="#" class="notCurrent">Log in</a></li>
                <li class="headerOption"><a href="#" class="notCurrent">Sign up</a></li>
                <li class="headerOption"><a href="#" class="notCurrent">About Us</a></li>
                <li class="headerOption"><a href="#" class="notCurrent">Contact</a></li>
            </ul>
        </nav>
    </header>

    <div id="breakLine">
    </div>


    <div id="menuDivisionUp">
        <p1><a href="https://www.youtube.com/watch?v=Qerz5CQa2A8" class="meneOption">Home</a></p1>
        <p1><a href="#" class="meneOption">Hall</a></p1>
        <p1><a href="#" class="meneOption">Catering</a></p1>
        <p1><a href="#" class="meneOption">Decorator</a></p1>
        <p1><a href="#" class="meneOption">Photographer</a></p1>
        <p1><a href="#" class="meneOption">Marriage Officiant</a></p1>
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
    
    <form id="searchBar">
        <input type="text" placeholder="Search anything which you feel necessary for arranging your event."
        maxlength="30" id="search">
       <input type="submit" value="Search" id="searchButton">
   </form>

   <div id="searchTab">
       <form id="searchForm" class="searchOptions">
           <input type="radio" name="choice" id="hallOp">Hall
           <input type="radio" name="choice" id="cateringOp">Catering
           <input type="radio" name="choice" id="decoratorOp">Decorator
           <input type="radio" name="choice" id="photographerOp">Photographer
           <input type="radio" name="choice" id="officiantOp">Officiant
           <input type="radio" name="choice" id="packageOp">Package
       </form>
   </div>

   <footer>
       <div id="images">
          <a href="https://www.facebook.com/"><img src="facebook.png" width="70"></a>
                    <a href="https://www.instagram.com/"><img src="insta.png" width="70"></a>
    </div>
    </footer>

    <script src="HomePageTesting.js"></script>

</body>

</html>