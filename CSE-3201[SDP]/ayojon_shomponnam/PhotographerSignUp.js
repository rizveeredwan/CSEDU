var photographerSubmit = document.getElementById("photographerSubmit");

photographerSubmit.onclick = function() {
    var photographerName = document.getElementById("photographerFullName").value;
    var photographerAddress = document.getElementById("photographerAddress").value;
    var photographerDateBirth = document.getElementById("photographerDateBirth").value;
    var photographerContact = document.getElementById("photographerContact").value;
    var photographerEmail = document.getElementById("photographerEmail").value;
    var photographerNID = document.getElementById("photographerNID").value;
    var photographerPassword = document.getElementById("photographerPassword").value;
    var photographerConfirmPassword = document.getElementById("photographerConfirmPassword").value;
    var photographerPortfolio = document.getElementById("photographerPortfolio").value;
    var photographerImg = document.getElementById("photographerImg").value;

    //Requesting
    var hr = new XMLHttpRequest();
    //path
    var url = "PhotographerSignUp.php";
    //data
    var data = "photographerName=" + photographerName + "&photographerAddress=" + photographerAddress + "&photographerDateBirth=" +
        photographerDateBirth + "&photographerContact=" +
        photographerContact + "&photographerEmail=" + photographerEmail + "&photographerNID=" + photographerNID + "&photographerPassword=" + photographerPassword +
        "&photographerConfirmPassword=" + photographerConfirmPassword + "&photographerPortfolio=" + photographerPortfolio + "&photographerImg=" + photographerImg;
    //message is requested to post  
    hr.open("POST", url, true);
    //type
    hr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    //when data transmission is going
    hr.onreadystatechange = function() {
        if (hr.readyState == 4 && hr.status == 200) {
            var return_data = hr.responseText;
            document.write(return_data);
        }
    }
    hr.send(data);
    return false;

};