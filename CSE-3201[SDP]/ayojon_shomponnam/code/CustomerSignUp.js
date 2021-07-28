var kisu;
var customerSignUpForm = document.getElementById('customerSignUpForm');

customerSignUpForm.onsubmit = function() {
    var customerName = document.getElementById("customerFullName").value;
    var customerAddress = document.getElementById("customerAddress").value;
    var customerDateBirth = document.getElementById("customerDateBirth").value;
    var customerReligion = document.getElementById("customerReligion").value;
    var customerCast = document.getElementById("customerCast").value;
    var customerContact = document.getElementById("customerContact").value;
    var customerEmail = document.getElementById("customerEmail").value;
    var customerNID = document.getElementById("customerNID").value;
    var customerPassword = document.getElementById("customerPassword").value;
    var customerConfirmPassword = document.getElementById("customerConfirmPassword").value;

    //Requesting
    var hr = new XMLHttpRequest();
    //path
    var url = "CustomerSignUp.php";
    //data
    var data = "customerName" + customerName + "&customerAddress" + customerAddress + "&customerDateBirth" + customerDateBirth +
        customerDateBirth + "&customerReligion" + customerReligion + "&customerCast" + customerCast + "&customerContact" +
        customerContact + "&customerEmail" + customerEmail + "&customerNID" + customerNID + "&customerPassword" + customerPassword +
        "&customerConfirmPassword" + customerConfirmPassword;
    //message is requested to post  
    hr.open("POST", url, true);
    //type
    hr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    //when data transmission is going
    hr.onreadystatechange = function() {
        if (hr.readyState == 4 && hr.status == 200) {
            var return_data = hr.responseText;
        }
    };
    hr.send(data);
    /*document.write(data);*/

};