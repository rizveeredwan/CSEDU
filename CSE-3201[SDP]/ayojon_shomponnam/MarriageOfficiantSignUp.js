var marriageOfficiantSubmit = document.getElementById("marriageOfficiantSubmit");

var marriageOfficiantSignUpForm = document.getElementById("marriageOfficiantSignUpForm");


//function to send data to php 
marriageOfficiantSubmit.onclick = function() {

    var marriageOfficiantFullName = document.getElementById("marriageOfficiantFullName").value;
    var marriageOfficiantAddress = document.getElementById("marriageOfficiantAddress");
    var marriageOfficiantOfficeAddress = document.getElementById("marriageOfficiantOfficeAddress");
    var marriageOfficiantReligion = document.getElementById("marriageOfficiantReligion");
    var marriageOfficiantDateBirth = document.getElementById("marriageOfficiantDateBirth");
    var marriageOfficiantContact = document.getElementById("marriageOfficiantContact");
    var marriageOfficiantEmail = document.getElementById("marriageOfficiantEmail");
    var marriageOfficiantNID = document.getElementById("marriageOfficiantNID");
    var marriageOfficiantPassword = document.getElementById("marriageOfficiantPassword");
    var marriageOfficiantConfirmPassword = document.getElementById("marriageOfficiantConfirmPassword");

    //the data to be sent
    data = "marriageOfficiantFullName=" + marriageOfficiantFullName + "&marriageOfficiantAddress=" + marriageOfficiantAddress +
        "&marriageOfficiantOfficeAddress=" + marriageOfficiantOfficeAddress + "&marriageOfficiantReligion=" + marriageOfficiantReligion +
        "&marriageOfficiantDateBirth=" + marriageOfficiantDateBirth + "&marriageOfficiantContact=" + marriageOfficiantContact +
        "&marriageOfficiantEmail=" + marriageOfficiantEmail + "&marriageOfficiantNID=" + marriageOfficiantNID +
        "marriageOfficiantPassword=" + marriageOfficiantPassword + "&marriageOfficiantConfirmPassword=" + marriageOfficiantConfirmPassword;

    var hr = new XMLHttpRequest(); //request
    url = "MarriageOfficiantSignUp.php";
    hr.open("POST", url, true);
    hr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    hr.onreadystatechange = function() {
        if (hr.readyState == 4 && hr.status == 200) {
            var got_data = hr.responseText;
        }
    };
    hr.send(data);
    return false;
};