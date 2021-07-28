//function to create entity in hall 
var hallCreateSubmit = document.getElementById("hallCreateSubmit");

hallCreateSubmit.onclick = function() {
    var hallTable = document.getElementById("hallTable");
    var lastRow = hallTable.rows.length; //last Row

    //data's been taken 
    var hallCreate = document.getElementById("hallCreate").value;
    var hallCapacity = document.getElementById("hallCapacity").value;
    var hallRow = document.getElementById("hallRow").value;

    //new Row Create 
    var newRow = hallTable.insertRow(lastRow);
    var cell1 = newRow.insertCell(0); // new column create 
    var cell2 = newRow.insertCell(1);

    cell1.innerHTML = hallCreate;
    cell2.innerHTML = hallCapacity;
    return false;
};

//function to Edit entry in hall

var hallCreateEdit = document.getElementById("hallCreateEdit");

hallCreateEdit.onclick = function() {

    var hallRow = document.getElementById("hallRow").value;
    var hallTable = document.getElementById("hallTable"); //took table 
    var lastRow = hallTable.rows.length; //took row 

    if (hallRow > 0 && hallRow < lastRow) {
        var row = hallTable.rows[hallRow].cells;
        row[0].innerHTML = document.getElementById("hallCreate").value;
        row[1].innerHTML = document.getElementById("hallCapacity").value;
    }
    return false;
};

//function to delete entry in hall 
var hallCreateDelete = document.getElementById("hallCreateDelete");

hallCreateDelete.onclick = function() {

    var hallTable = document.getElementById("hallTable"); //took table 
    var lastRow = hallTable.rows.length; //took size 

    //take data
    var hallRow = document.getElementById("hallRow").value;
    if (hallRow > 0 && hallRow < lastRow) {
        hallTable.deleteRow(hallRow);
    }
    return false;
};

//function to create entity in schedule table

var scheduleCreate = document.getElementById("scheduleCreate");

scheduleCreate.onclick = function() {

    var scheduleTable = document.getElementById("scheduleTable");
    var lastRow = scheduleTable.rows.length; //last Row

    //take data 
    var scheduleDate = document.getElementById("scheduleDate").value;
    var scheduleHall = document.getElementById("scheduleHall").value;
    var scheduleMorning = document.getElementById("scheduleMorning").value;
    var scheduleAfternoon = document.getElementById("scheduleAfternoon").value;
    var scheduleNight = document.getElementById("scheduleNight").value;
    var scheduleDDel = document.getElementById("scheduleDDel").value;

    //new Row Create 
    var newRow = scheduleTable.insertRow(lastRow);
    var cell0 = newRow.insertCell(0); // new column create Data
    var cell1 = newRow.insertCell(1); //hall name 
    var cell2 = newRow.insertCell(2); //morning 
    var cell3 = newRow.insertCell(3); //afternoon
    var cell4 = newRow.insertCell(4); //night 



    //data change 
    cell0.innerHTML = scheduleDate;
    cell1.innerHTML = scheduleHall;
    cell2.innerHTML = scheduleMorning;
    cell3.innerHTML = scheduleAfternoon;
    cell4.innerHTML = scheduleNight;
    return false;
};


//function to Edit entry in schedule
var scheduleEdit = document.getElementById("scheduleEdit");

scheduleEdit.onclick = function() {

    var scheduleTable = document.getElementById("scheduleTable");
    var lastRow = scheduleTable.rows.length; //last Row

    //take data 
    var scheduleDate = document.getElementById("scheduleDate").value;
    var scheduleHall = document.getElementById("scheduleHall").value;
    var scheduleMorning = document.getElementById("scheduleMorning").value;
    var scheduleAfternoon = document.getElementById("scheduleAfternoon").value;
    var scheduleNight = document.getElementById("scheduleNight").value;
    var scheduleDDel = document.getElementById("scheduleDDel").value;

    if (scheduleDDel > 0 && scheduleDDel < lastRow) {
        var row = scheduleTable.rows[scheduleDDel].cells;
        row[0].innerHTML = scheduleDate;
        row[1].innerHTML = scheduleHall;
        row[2].innerHTML = scheduleMorning;
        row[3].innerHTML = scheduleAfternoon;
        row[4].innerHTML = scheduleNight;
    }
    return false;
};

//function to delete row
var scheduleDelete = document.getElementById("scheduleDelete");

scheduleDelete.onclick = function() {
    var scheduleTable = document.getElementById("scheduleTable");
    var lastRow = scheduleTable.rows.length; //last Row



    //take data
    var scheduleDDel = document.getElementById("scheduleDDel").value;
    if (scheduleDDel > 0 && scheduleDDel < lastRow) {
        scheduleTable.deleteRow(scheduleDDel);
    }
    return false;
};

//function to send data to php file

var decoratorSubmit = document.getElementById("decoratorSubmit");

decoratorSubmit.onclick = function() {

}