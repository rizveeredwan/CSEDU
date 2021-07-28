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

    var currentSelectedId;
    //the main purpose of this function to move to book page with the selected ID
    $(document).on('click', ".button", function() {
        var selectedId = $(this).attr("id");
        currentSelectedId = selectedId;
        //first need to update session variable to go to a new page
        $.ajax({
            url: "CurrentSelectedId.php",
            method: "POST",
            data: { currentSelectedId: selectedId },
            dataType: "text",
            success: function(data) {
                document.location.href = "HallBookPage.php";
                return false;
            }
        });
        return false;
    });

});