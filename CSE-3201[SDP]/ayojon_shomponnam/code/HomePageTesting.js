var searchButton = document.getElementById("searchButton");
searchButton.onclick = function() {
    /*
      first need to take the values 
    */
    var search = document.getElementById("search").value;
    /* Now to see which radio button is selected*/
    var choiceRadioButton;
    if (document.getElementById("hallOp").checked) {
        choiceRadioButton = "hallOp";
    }
    if (document.getElementById("cateringOp").checked) {
        choiceRadioButton = "cateringOp";
    }
    if (document.getElementById("decoratorOp").checked) {
        choiceRadioButton = "decoratorOp";
    }
    if (document.getElementById("photographerOp").checked) {
        choiceRadioButton = "photographerOp";
    }
    if (document.getElementById("officiantOp").checked) {
        choiceRadioButton = "officiantOp";
    }
    if (document.getElementById("packageOp").checked) {
        choiceRadioButton = "packageOp";
    }

    /*Now need to send*/
    var hr = new XMLHttpRequest(); //Request
    var url = "Search.php";
    var data = "search=" + search + "&choiceRadioButton=" + choiceRadioButton;
    //message is requested to post  
    hr.open("POST", url, true);
    //message header set 
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