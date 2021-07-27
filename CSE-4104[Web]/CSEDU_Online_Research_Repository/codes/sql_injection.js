/*A javascript file to check sql injection going to occur or not */
function check_valid_character(str) {
    for (i = 0; i < str.length; i++) {
        var char = str.charAt(i);
        //alert(char);
        if (char == "'") return false;
        if (char == '"') return false;
        if (char == ';') return false;
        if (char == ',') return false;
        if (char == '^') return false;
        if (char == '`') return false;
    }
    return true;
}


function to_check_year(year) {
    for (i = 0; i < year.length; i++) {
        var n = year.charAt(i);
        if (n >= '0' && n <= '9') continue;
        return false;
    }
    return true;
}

/* 
//code fragment
 //sql_injection prevent
        sql_injection = check_valid_character(code);
        if (sql_injection == false) {
            alert("input can not contain " + " ' " + ' " ' + ' = ' + ' _ ' + ' ; ' + ' , ' + ' = ' + ' ? ' + ' ^ characters');
             document.getElementById('code').style.borderColor = "red";
            return false;
        } else {
            document.getElementById('code').style.borderColor = "";
        }

*/