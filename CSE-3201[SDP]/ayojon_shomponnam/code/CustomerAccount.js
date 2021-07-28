// global Variables;


//global variables
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

//special attributes
var tin;
var portfolio;

var thumbnail;

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
    return false;
}

//function to bring other Queries
function bringOtherElements() {

    $.ajax({
        //I need to have a page to get all the customer JSON attribute 
        //Data Receiving to update in html
        url: ("CustomerAccountServerPage1.php"),
        method: "POST",
        data: { userName: userName },
        dataType: "json",
        success: function(data) {
            //getting all the json attribute of customer and will update
            //the account 
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
            document.getElementById("thumbnail").value = data[12]; //A special case */
            thumbnail = data[12];

            //special 
            document.getElementById("tin").value = data[13]; //A special case */
            tin = data[13];
            document.getElementById("portfolio").value = data[14]; //A special case */
            portfolio = data[14];

            //alert(data);
            return false;
        }

    });
    return false;
}

//function to update normal data
//on submit data
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

    //special part
    var tin1 = document.getElementById("tin").value; //A special case */
    tin = tin1;
    var portfolio1 = document.getElementById("portfolio").value; //A special case */
    portfolio = portfolio1;

    //comparing part


    //requesting to update part 
    //page : CustomerAccountServerPage2.php
    $.ajax({
        //This page will update the customer account 
        url: "CustomerAccountServerPage2.php",
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
            return false;
        }
    });
    return false;
}

//Javascript
$(document).ready(function() {

    var got;
    var makePage = false;
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