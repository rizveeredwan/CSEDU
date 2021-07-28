//global variables
var name;
var addressMain;
var addressSub;
var contact;
var email;
var password;
var confirmPassword;
var accountType;
var genderType;
var nid;
var tin;
var religion;
var cast;
var portfolioLink;
var birth;


//special variable for ajax request function 
var formData = new FormData();
var url1 = "SignUpServerPage1.php"; //page to normally send data 
var url2 = "SignUpServerPage2.php"; //page to get the file data 

//variables for sending files 
var thumbnail;

//procedure starts 
var create;
//function to check if submit is pressed or not
create = document.getElementById("create");
create.onclick = function() {
    readValue(); //function to get variable value 
    appendValue(); //function to append value in formData 
    //ajaxRequest(); //function te send 
    var xml = new XMLHttpRequest();
    xml.open("POST", url1, true);
    xml.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xml.onreadystatechange = function() {
        if (xml.readyState == 4 && xml.status == 200) {
            var got_data = xml.responseText;
            //document.write(got_data);
            //now to send file  
            //document.write(got_data);
            var n = got_data.localeCompare("successful"); //successful 
            if (n == 0) {
                alert("temp normal data update");
                //document.write(got_data);
                //the data part is saved already in temporary table 
                //now need to update thumnail image in temporary table 
                var xml2 = new XMLHttpRequest();
                xml2.open("POST", url2, true);
                xml2.send(formData);
                xml2.onreadystatechange = function() {
                    if (xml2.readyState == 4 && xml2.status == 200) {
                        var new_data2 = xml2.responseText;
                        alert(new_data2);
                        //now I need to create account in main database 
                        var xmlInt = new XMLHttpRequest();
                        var urlInt = "something.php";
                        xmlInt.open("POST", urlInt, true);
                        var data = "";
                        xmlInt.send(data);
                        xmlInt.onreadystatechange = function() {
                            if (xmlInt.readyState == 4 && xmlInt.status == 200) {
                                var new_data = xmlInt.responseText;
                                alert(new_data);
                                document.location.href = "HomePageTesting.php";
                                return false;
                            }
                        };

                    }
                }

            }
        }
    };
    xml.send(data);
    return false;
};

//function to get the value of the elements
function readValue() {
    name = document.getElementById("name").value;
    addressMain = document.getElementById("addressMain").value;
    addressSub = document.getElementById("addressSub").value;
    contact = document.getElementById("contact").value;
    email = document.getElementById("email").value;
    password = document.getElementById("password").value;
    confirmPassword = document.getElementById("confirmPassword").value;
    nid = document.getElementById("nid").value;
    tin = document.getElementById("tin").value;
    religion = document.getElementById("religion").value;
    cast = document.getElementById("cast").value;
    portfolioLink = document.getElementById("portfolioLink").value;
    birth = document.getElementById("birth").value;

    accountType = checkRadioButtonAccount();
    genderType = checkRadioButtonGender();
}

//function to check the radio buttons

function checkRadioButtonGender() {

    if (document.getElementById("male").cheked) {
        return "male";
    } else if (document.getElementById("female").cheked) {
        return "female";
    } else if (document.getElementById("others").cheked) {
        return "others";
    }
}

function checkRadioButtonAccount() {
    if (document.getElementById("customer").cheked) {
        return "customer";
    } else if (document.getElementById("hall").cheked) {
        return "hall";
    } else if (document.getElementById("catering").cheked) {
        return "catering";
    } else if (document.getElementById("decorator").cheked) {
        return "decorator";
    } else if (document.getElementById("photographer").cheked) {
        return "photographer";
    } else if (document.getElementById("officiant").cheked) {
        return "officiant";
    }
}

//function to append values to formData to send
function appendValue() {
    data = "";
    data = "name=" + name;
    data = data + "&addressMain=" + addressMain;
    data = data + "&addressSub=" + addressSub;
    data = data + "&contact=" + contact;
    data = data + "&email=" + email;
    data = data + "&password=" + password;
    data = data + "&confirmPassword=" + confirmPassword;
    data = data + "&accountType=" + accountType;
    data = data + "&genderType=" + genderType;
    data = data + "&nid=" + nid;
    data = data + "&tin=" + tin;
    data = data + "&religion=" + religion;
    data = data + "&cast=" + cast;
    data = data + "&portfolioLink=" + portfolioLink;
    data = data + "&birth=" + birth;

    toProcessImage();
}

//function to send ajax request
function ajaxRequest() {


    return false;
}

//function for processing images 
function toProcessImage() {
    thumbnail = document.getElementById("thumbnail").files[0];
    formData.append("thumbnail", thumbnail);
}