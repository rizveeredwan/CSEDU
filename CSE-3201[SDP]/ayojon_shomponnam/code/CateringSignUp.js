//adding food items


var itemNameInput, itemPriceInput;
var addItem = document.getElementById("addItem");
var itemNameInput;
var foodProductTable = document.getElementById("foodProductTable");

//this function to add items in food item table 
addItem.onclick = function() {
    itemNameInput = document.getElementById("itemNameInput").value;
    itemPriceInput = document.getElementById("itemPriceInput").value;

    //now add item
    var lastRow = foodProductTable.rows.length; //table size 
    var newRow = foodProductTable.insertRow(lastRow); //creating row
    var cell1 = newRow.insertCell(0); //creating cell
    var cell2 = newRow.insertCell(1); //creating cell

    cell1.innerHTML = itemNameInput; //cell lines
    cell2.innerHTML = itemPriceInput; //cell lines 

    return false;


};

//for editing existing row
var editItem = document.getElementById("editItem");
editItem.onclick = function() {
    //taking the values
    var itemRow = document.getElementById("itemRow").value;
    var itemNameInputUpdate = document.getElementById("itemNameInputUpdate").value;
    var itemPriceInputUpdate = document.getElementById("itemPriceInputUpdate").value;

    //updating 
    var lastRow = foodProductTable.rows.length;
    if (itemRow < lastRow) {
        itemRow = parseInt(itemRow);
        if (itemRow != 0) {
            var tempRow = foodProductTable.rows[itemRow].cells;
            tempRow[0].innerHTML = itemNameInputUpdate;
            tempRow[1].innerHTML = itemPriceInputUpdate;
        }
    }
    return false; //to stop from page loading 
};

//this function to delete a table entry 
var deleteItem = document.getElementById("deleteItem");

deleteItem.onclick = function() {
    var special = document.getElementById("special").value;
    special = parseInt(special);
    var lastRow = foodProductTable.rows.length;
    if (special >= 0 && special < lastRow) {
        foodProductTable.deleteRow(special);
    }
    return false;
}



//function to press submit and send data to new php page 

var cateringSubmit = document.getElementById("cateringSubmit");

cateringSubmit.onclick = function() {

    //basic information 
    var cateringFullName = document.getElementById("cateringFullName");
    var cateringAddress = document.getElementById("cateringAddress");
    var cateringContact = document.getElementById("cateringContact");
    var cateringEmail = document.getElementById("cateringEmail");
    var cateringTIN = document.getElementById("cateringTIN");
    var cateringPassword = document.getElementById("cateringPassword");
    var cateringConfirmPassword = document.getElementById("cateringConfirmPassword");
    var cateringImg = document.getElementById("cateringImg");
    //table information
    //converting table to JSON object 
    var tableData = new Array(); //making array 
    for (i = 1; i < foodProductTable.rows.length; i++) {
        var tempRow = foodProductTable.rows[i].cells;
        tableData[i] = {
            "item": tempRow[0].innerHTML,
            "price": tempRow[1].innerHTML
        }
    }
    //now js array to json
    var tableDataSend = JSON.stringify(tableData);


    //now the needed data 
    data = "cateringFullName=" + cateringFullName + "&cateringAddress=" + cateringAddress + "&cateringContact=" +
        cateringContact + "&cateringEmail=" + cateringEmail + "&cateringTIN=" + cateringTIN + "&cateringPassword=" + cateringPassword +
        "&cateringConfirmPassword=" + cateringConfirmPassword + "&tableDataSend=" + tableDataSend + "&cateringImg=" + cateringImg;
    //now the connection establishment and data send
    //document.write("yes");
    var hr = new XMLHttpRequest(); //request
    url = "CateringSignUp.php";
    hr.open("POST", url, true);
    hr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    hr.onreadystatechange = function() {
        if (hr.readyState == 4 && hr.status == 200) {
            var got_data = hr.responseText;
            document.write(got_data);
        }
    }
    hr.send(data);
    document.write(tableDataSend);
    return false;

};