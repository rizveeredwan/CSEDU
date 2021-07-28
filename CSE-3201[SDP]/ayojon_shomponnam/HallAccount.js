//global variables 
//javascript 
var receivedObject;
var userName, passWord;

//common attributes 
var name;
var username;
var officeAddress;
var secondAddress;
var contact;
var email;
var password;
var confirmPassword;
var birth;
var tin;
var nid;
var religion;
var cast;
var gender;
var portfolio;
var thumbnail;

//special attributes 
var credImg1;
var credImg2;
var credImg3;
var credImg4;
var credImg5;
var capacity;
var fee;


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
        url: ("HallAccountServerPage1.php"), //for getting normal data this page
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
            document.getElementById("tin").value = data[8];
            tin = data[8];
            document.getElementById("nid").value = data[9];
            nid = data[9];
            document.getElementById("religion").value = data[10];
            religion = data[10];
            document.getElementById("cast").value = data[11];
            cast = data[11];
            document.getElementById("gender").value = data[12];
            gender = data[12];
            document.getElementById("portfolio").value = data[13];
            portfolio = data[13];
            document.getElementById("thumbnail").value = data[14]; //A special case 
            thumbnail = data[14];

            //special attribute part
            document.getElementById("capacity").value = data[15];
            capacity = data[15];
            document.getElementById("credImg1").value = data[16];
            credImg1 = data[16];
            document.getElementById("credImg2").value = data[17];
            credImg2 = data[17];
            document.getElementById("credImg3").value = data[18];
            credImg3 = data[18];
            document.getElementById("credImg4").value = data[19];
            credImg4 = data[19];
            document.getElementById("credImg5").value = data[20];
            credImg5 = data[20];
            document.getElementById("fee").value = data[21];
            fee = data[21];
            return false;
        }

    });
}

function bringAllTable() {
    $.ajax({
        url: "HallAccountServerPage3.php",
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
    var portfolio1 = document.getElementById("portfolio").value;
    portfolio = portfolio1;

    //special attribute part
    var capacity1 = document.getElementById("capacity").value;
    capacity = capacity1;
    var credImg11 = document.getElementById("credImg1").value;
    credImg1 = credImg11;
    var credImg21 = document.getElementById("credImg2").value;
    credImg2 = credImg21;
    var credImg31 = document.getElementById("credImg3").value;
    credImg3 = credImg31;
    var credImg41 = document.getElementById("credImg4").value;
    credImg4 = credImg41;
    var credImg51 = document.getElementById("credImg5").value;
    credImg5 = credImg51;
    var fee1 = document.getElementById("fee").value;
    fee = fee1;

    //comparing part


    //requesting to update part 
    //page : CustomerAccountServerPage2.php
    $.ajax({
        //This page will update the customer account 
        url: "HallAccountServerPage2.php", //this page is for updating normal data 
        method: "POST",
        data: {
            name: name,
            username: username,
            officeAddress: officeAddress,
            secondAddress: secondAddress,
            contact: contact,
            email: email,
            password: password,
            birth: birth,
            religion: religion,
            cast: cast,
            gender: gender,
            nid: nid,
            tin: tin,
            thumbnail: thumbnail,
            portfolio: portfolio,
            capacity: capacity,
            credImg1: credImg1,
            credImg2: credImg2,
            credImg3: credImg3,
            credImg4: credImg4,
            credImg5: credImg5,
            fee: fee
        },
        dataType: "text",
        success: function(data) {
            alert(data)
                //return false;
        }
    });
    return false;
};


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
            url: "HallAccountServerPage4.php",
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
            url: "HallAccountServerPage5.php",
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

});

$(document).ready(function() {

    function fetchData() {
        $.ajax({
            url: "HallAccountServerPage3.php",
            method: "POST",
            success: function(data) {
                $("#tableEverything").html(data);
                return false;
            }
        });
    }

    fetchData();
});