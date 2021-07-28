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
    <link href="CateringAccount.css" type="text/css" rel="stylesheet">
    <link href="MarriageOfficiantAccount.css" type="text/css" rel="stylesheet">
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
  Date-of-Birth <input type="date" name="" placeholder="" value="23-08-1996" class="infoClass" id="birth">
  Gender: <input type="text" name="" placeholder="" value="gender" class="infoClass" id="gender">
  Religion:<input type="text" name="" placeholder="" value="gender" class="infoClass" id="religion">
  Cast:<input type="text" name="" placeholder="" value="gender" class="infoClass" id="cast">
  NID: <input type="text" name="" placeholder="" value="1234567890" class="infoClass" id="nid">
  TIN: <input type="text" name="" placeholder="" value="1234567000" class="infoClass" id="tin">
  portfolio Link: <input type="text" name="" placeholder="" value="" class="infoClass" id="portfolio">
  <h2>Image File Upload Section</h2>
  Thumbnail Image:(uploading will override existing file/image condition)<input type="file" enctype="multipart/form-data" id="thumbnail">
   </div>
</div>

    <div id="foodPart">
            <h1 id="foodHeader">Items</h1>
            <div id="foodDataPart">
                        <div id="foodEditPart">
                           <form id="foodEditForm">                            
                               Item Name:<input type="text" name="" placeholder="item name" id="name">
                               Price:<input type="text" name="" placeholder="Morning/Evening" id="price">
                               Availability:<input type="text" name="" placeholder="yes/no" id="foodFree">
                               Row Number:<input type="text" name="" placeholder="number to edit/delete" id="foodRow">
                          </form>
                          <form id="foodButtonForm">
                              <input type="submit" value="Add" id="foodAdd">
                              <input type="submit" value="Edit" id="foodEdit">
                              <input type="submit" value="Delete" id="foodDelete">
                          </form>                        
                        </div>
                        <div id="foodTablePart">
                            <h2>Items</h2>
                             <table>
                                 <tr>
                                    <th>Item name</th>
                                    <th>Price</th>
                                    <th>Availability</th>
                                 </tr>
                                 <tr>
                                        <td>Hazir Biriyani</th>
                                        <td>Morning</th>
                                        <td>Yes</th>
                                 </tr>
                                
                             </table>
                             
                        </div>
    
            </div>
            
        </div>
    
    
    
    
    <div id="scheduleTablePart">
        <h1>Booked Schedule</h1>
        <div id="tableEverything">
           
        </div>
        <div id="addInTable">
         <h1>Add New Schedule<h1>
             <form>
                <td><input type="date" name="" value="27-05-2018" id="bar0" weight="1px"></td>
                <td><input type="text" name="" value="morning" id="bar1"></td>
                <td><input type="text" name="" value="C02" id="bar2"></td>
            </form>
            <div>
                <input type="submit" name="" value="add" id="add"> 
            </div>
        </div>
    </div>
    <div id="submitButton">
        <input type="submit" name="" value="submit" id="submit">
    </div>
    <script src="CateringAccount.js"></script>
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