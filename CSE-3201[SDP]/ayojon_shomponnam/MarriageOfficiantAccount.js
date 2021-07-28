//global variables 
//javascript 
var receivedObject;
var userName, passWord;

var name;
var username;
var officeAddress;
var secondAddress;
var contact;
var email;
var password;
var confirmPassword;
var birth;
var religion;
var cast;
var gender;
var nid;
var tin;
var portfolio;

var thumbnail;


//For table part
var date;
var time;
var customerId;

function initialize(un) {
    userName = un;
    if (v[0] == 'C') { //customer
        document.getElementById("logInRef").href = "CustomerAccount.php";
        document.getElementById("logInRef").innerHTML = "My Account";
        document.getElementById("signUpRef").href = "LogOut.php";
        document.getElementById("signUpRef").innerHTML = "Log Out";
    } else if (v[0] == 'M') { //marriageOfficiant
        document.getElementById("logInRef").href = "MarriageOfficiantAccount.php";
        document.getElementById("logInRef").innerHTML = "My Account";
        document.getElementById("signUpRef").href = "LogOut.php";
        document.getElementById("signUpRef").innerHTML = "Log Out";
    } else if (v[0] == 'P') { //photographer
        document.getElementById("logInRef").href = "PhotographerAccount.php";
        document.getElementById("logInRef").innerHTML = "My Account";
        document.getElementById("signUpRef").href = "LogOut.php";
        document.getElementById("signUpRef").innerHTML = "Log Out";
    } else if (v[0] == 'D') { //decorator
        document.getElementById("logInRef").href = "DecoratorAccount.php";
        document.getElementById("logInRef").innerHTML = "My Account";
        document.getElementById("signUpRef").href = "LogOut.php";
        document.getElementById("signUpRef").innerHTML = "Log Out";
    } else if (v[0] == 'T') { //catering
        document.getElementById("logInRef").href = "CateringAccount.php";
        document.getElementById("logInRef").innerHTML = "My Account";
        document.getElementById("signUpRef").href = "LogOut.php";
        document.getElementById("signUpRef").innerHTML = "Log Out";
    } else if (v[0] == 'H') { //hall
        document.getElementById("logInRef").href = "HallAccount.php";
        document.getElementById("logInRef").innerHTML = "My Account";
        document.getElementById("signUpRef").href = "LogOut.php";
        document.getElementById("signUpRef").innerHTML = "Log Out";
    } else {
        document.getElementById("logInRef").href = "LogInClient.php";
        document.getElementById("logInRef").innerHTML = "Log In";
        document.getElementById("signUpRef").href = "SignUp.php";
        document.getElementById("signUpRef").innerHTML = "Sign Up";
    }
    bringOtherElements();
    bringAllTable();
    return false;
}


//function to bring other Queries
function bringOtherElements() {

    $.ajax({
        //I need to have a page to get all the customer JSON attribute 
        //Data Receiving to update in html
        url: ("MarriageOfficiantAccountServerPage1.php"), //for getting normal data this page
        method: "POST",
        data: { userName: userName },
        dataType: "json",
        success: function(data) {
            //getting all the json attribute of customer and will update
            //work will data 
            document.getElementById("name").value = data[0];
            name = data[0];
            document.getElementById("username").value = data[1];
            username = data[1];
            document.getElementById("officeAddress").value = data[2];
            officeAddress = data[2];
            document.getElementById("secondAddress").value = data[3];
            secondAddress = data[3];
            document.getElementById("contact").value = data[4];
            contact = data[4];
            document.getElementById("email").value = data[5];
            email = data[5];
            document.getElementById("password").value = data[6];
            password = data[6];
            document.getElementById("birth").value = data[7];
            birth = data[7];
            document.getElementById("religion").value = data[8];
            religion = data[8];
            document.getElementById("cast").value = data[9];
            cast = data[9];
            document.getElementById("gender").value = data[10];
            gender = data[10];
            document.getElementById("nid").value = data[11];
            nid = data[11];
            document.getElementById("thumbnail").value = data[12]; //A special case 
            thumbnail = data[12];
            document.getElementById("tin").value = data[13];
            nid = data[13];
            document.getElementById("portfolio").value = data[14];
            portfolio = data[14];
            return false;
        }

    });
}




//The part of form submit
var submit = document.getElementById("submit");

submit.onclick = function(event) {
    event.preventDefault();
    //getting all the values from 
    var name1 = document.getElementById("name").value;
    name = name1;
    var username1 = document.getElementById("username").value;
    username = username1;
    var officeAddress1 = document.getElementById("officeAddress").value;
    officeAddress = officeAddress1;
    var secondAddress1 = document.getElementById("secondAddress").value;
    secondAddress = secondAddress1;
    var contact1 = document.getElementById("contact").value;
    contact = contact1;
    var email1 = document.getElementById("email").value;
    email = email1;
    var password1 = document.getElementById("password").value;
    password = password1;
    var confirmPassword1 = document.getElementById("confirmPassword").value;
    confirmPassword = confirmPassword1;
    var birth1 = document.getElementById("birth").value;
    birth = birth1;
    var religion1 = document.getElementById("religion").value;
    religion = religion1;
    var cast1 = document.getElementById("cast").value;
    cast = cast1;
    var gender1 = document.getElementById("gender").value;
    gender = gender1;
    var nid1 = document.getElementById("nid").value;
    nid = nid1;
    var thumbnail1 = document.getElementById("thumbnail").value;
    thumbnail = thumbnail1;
    var tin1 = document.getElementById("tin").value;
    tin = tin1;
    var potfolio1 = document.getElementById("portfolio").value;
    portfolio = portfolio1;
    //comparing part


    //requesting to update part 
    //page : CustomerAccountServerPage2.php
    $.ajax({
        //This page will update the customer account 
        url: "MarriageOfficiantAccountServerPage2.php", //this page is for updating normal data 
        method: "POST",
        data: {
            name: name,
            username: username,
            officeAddress: officeAddress,
            secondAddress: secondAddress,
            contact: contact,
            email: email,
            password: password,
            confirmPassword: confirmPassword,
            birth: birth,
            religion: religion,
            cast: cast,
            gender: gender,
            nid: nid,
            thumbnail: thumbnail,
            tin: tin,
            portfolio: portfolio
        },
        dataType: "text",
        success: function(data) {
            alert(data)
                //return false;
        }
    });
    return false;
};

//This function brings all the table from database
function bringAllTable() {

    $.ajax({
        url: "MarriageOfficiantAccountServerPage3.php",
        method: "GET",
        data: {},
        dataType: "html",
        success: function(data) {
            var v = document.getElementById("tableEverything");
            v.appendChild(data);
            return false;
        }

    });
    return false;
}

$(document).ready(function() {
    var i = 100;
    $("#add").click(function() {
        i++;
        $("#scheduleTable").append(' <tr id="row' + i + '"><td><input type="date" name="" value="" placeholder="dd-mm-y" id="r' + i + '"></td><td><input type="text" name="" value="" placeholder="morning/evening" id="c' + i + '"></td><td><input type="text"  name="" value="C02" id="b' + i + '"></td><td><input  class="delButton" type="submit" name="" value="delete" id="' + i + '"></td></tr>');
        //taking from add bar part 
        //after updating in real line
        var v = 'r' + i + '';
        document.getElementById(v).value = document.getElementById("bar0").value;
        date = document.getElementById("bar0").value;
        v = 'c' + i + '';
        document.getElementById(v).value = document.getElementById("bar1").value;
        time = document.getElementById("bar1").value;
        v = 'b' + i + '';
        document.getElementById(v).value = document.getElementById("bar2").value;
        customerId = document.getElementById("bar2").value;
        //this request ajax, add table in database 
        $.ajax({
            url: "MarriageOfficiantAccountServerPage4.php",
            method: "POST",
            data: { date: date, time: time, customerId: customerId },
            dataType: "text",
            success: function(data) {
                alert(data);
                return false;
            }

        });
        return false;
    });
    $(document).on("click", ".delButton", function() {
        var x = $(this).attr("id");
        var v = 'r' + x + '';
        date = document.getElementById(v).value;
        v = 'c' + x + '';
        time = document.getElementById(v).value;
        v = 'b' + x + '';
        customerId = document.getElementById(v).value;
        $('#row' + x + '').remove();
        $.ajax({
            url: "MarriageOfficiantAccountServerPage5.php",
            method: "POST",
            data: { date: date, time: time, customerId: customerId },
            dataType: "text",
            success: function(data) {
                alert(data);
                return false;
            }
        });

        return false;
    });

    //this function adds new book table in database


    //This function works on load and take who is current user
    /*window.onload = function() {
        $.ajax({
            url: "LoggedInServer.php",
            method: "POST",
            data: { query: 5 },
            dataType: "json",
            success: function(data) {
                userName = data[0];
                passWord = data[1];
                //document.write(userName + " " + passWord);
                bringOtherElements(); //A function call to bring other elements 
                return false;
            }

        });
    };*/

});

$(document).ready(function() {

    function fetchData() {
        $.ajax({
            url: "MarriageOfficiantAccountServerPage3.php",
            method: "POST",
            success: function(data) {
                $("#tableEverything").html(data);
                return false;
            }
        });
    }

    fetchData();
});