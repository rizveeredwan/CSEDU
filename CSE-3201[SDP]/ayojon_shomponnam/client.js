mk();

function mk() {

    var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            var myObj = JSON.parse(this.responseText);
            //document.getElementById("demo").innerHTML = myObj.name;
            document.write(myObj.name);
        }
    };
    xmlhttp.open("GET", "demo_file.php", true);
    xmlhttp.send();
}