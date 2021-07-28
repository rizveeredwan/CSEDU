//this here initializes link
function initialize(v) {
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
    return false;
}

$(document).ready(function() {
    var globalVariable = false;
    var date, time;


    //common variables 
    var name;
    var address;
    var contact;
    var email;
    var capacity;
    var fee;
    var portfolio;

    var thumbnail;
    var credImg1;
    var credImg2;
    var credImg3;
    var credImg4;
    var credImg5;
    var from;
    var to;


    function buttonVisibility(v) {
        if (v == false) {
            document.getElementById("book").style.visibility = "hidden";
            document.getElementById("queue").style.visibility = "hidden";
        } else {
            //document.write("yes");
            document.getElementById("book").style.visibility = "visible";
            document.getElementById("queue").style.visibility = "visible";
        }
    }
    buttonVisibility(globalVariable);

    //this function sees if the date is available or not  
    $("#available").on('click', function() {
        date = document.getElementById("date").value;
        time = document.getElementById("time").value;
        $.ajax({
            url: ("CateringBookPageServerPage1.php"),
            method: "POST",
            data: { date: date, time: time },
            dataType: "text",
            success: function(data) {
                if (data == "yes") {
                    alert("Available");
                    globalVariable = true;
                    buttonVisibility(globalVariable);
                    document.getElementById("availability").innerHTML = "available";
                } else {
                    alert("Not Available");
                    globalVariable = false;
                    buttonVisibility(globalVariable);
                    document.getElementById("availability").innerHTML = "not available";
                }
                return false;
            }
        });
        return false;
    });

    $("#book").on('click', function() {
        date = document.getElementById("date").value;
        time = document.getElementById("time").value;
        $.ajax({
            url: ("CateringBookPageServerPage2.php"),
            method: "POST",
            data: { date: date, time: time },
            dataType: "text",
            success: function(data) {
                if (data == "Log In First as Customer") {
                    alert("Log In First as Customer");
                    document.location.href = "LogInClient.php";
                    return false;
                } else if (data == "successful") {
                    alert(data);
                }
                return false;
            }
        });
        return false;
    });
    //this function brings generalized data
    function bringOtherElements() {
        $.ajax({
            url: ("CateringBookPageServerPage3.php"),
            method: "POST",
            data: {},
            dataType: "json",
            success: function(data) {
                name = data[0];
                address = data[1];
                contact = data[2];
                email = data[3];
                portfolio = data[4];

                //setting part
                document.getElementById("name").innerHTML = name;
                document.getElementById("address").innerHTML = address;
                document.getElementById("contact").innerHTML = contact;
                document.getElementById("email").innerHTML = email;
                document.getElementById("portfolio").innerHTML = portfolio;

                //special image part
                thumbnail = data[7];

                //setting images 
                document.getElementById("thumbnail").src = thumbnail;
            }
        });
        return false;
    }
    bringOtherElements();


    //this function for appending table query table form-to
    $("#check").on('click', function() {
        from = document.getElementById("from").value;
        to = document.getElementById("to").value;
        $.ajax({
            url: "CateringBookPageServerPage4.php",
            method: "POST",
            data: { from: from, to: to },
            success: function(data) {
                $("#resultAppend").html(data);
                return false;
            }

        });
        return false;
    });



    return false;
});