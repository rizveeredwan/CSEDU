var userName;
var password;


var formInput = document.getElementById('formInputLogIn');

formInput.onsubmit = function() {

    userName = document.getElementById("userName").value;
    password = document.getElementById("passWord").value;
    /*document.write(userName);*/

    //request created
    var hr = new XMLHttpRequest();
    //where data will go 
    /*****************This is main**********
     * 
     * I am commenting 
     */
    //var url = "loginconfirmation.php"; ///changing
    var url = "LogInServer.php";
    //data made 
    var data = "username=" + userName + "&password=" + password;
    //sending 
    hr.open("POST", url, true);
    //type data 
    hr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

    //when data transmission is going 
    hr.onreadystatechange = function() {
            if (hr.readyState == 4 && hr.status == 200) {
                var got_data = hr.responseText;
                var v = got_data.localeCompare("successful");
                if (v == 0) {
                    alert(got_data);
                    document.location.href = "HomePageTesting.php";
                    return false;
                } else {
                    alert("wrong username or password");
                }
            }
        }
        //sending data 
    hr.send(data); //the data being sent 
    return false;
};