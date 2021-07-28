var decoratorSubmit = document.getElementById("decoratorSubmit");

decoratorSubmit.onclick = function() {

    var decoratorFullName = document.getElementById("decoratorFullName");
    var decoratorAddress = document.getElementById("decoratorAddress");
    var decoratorContact = document.getElementById("decoratorContact");
    var decoratorEmail = document.getElementById("decoratorEmail");
    var decoratorTIN = document.getElementById("decoratorTIN");
    var decoratorPassword = document.getElementById("decoratorPassword");
    var decoratorConfirmPassword = document.getElementById("decoratorConfirmPassword");
    var decoratorPortfolio = document.getElementById("decoratorPortfolio");
    var decoratorThumb = document.getElementById("decoratorThumb");

    var data = "decoratorFullName=" + decoratorFullName + "&decoratorAddress=" + decoratorAddress +
        "&decoratorContact=" + decoratorContact + "&decoratorEmail=" + decoratorEmail +
        "&decoratorTIN=" + decoratorTIN + "&decoratorPassword=" + decoratorPassword + "&decoratorConfirmPassword=" + decoratorConfirmPassword +
        "&decoratorPortfolio=" + decoratorPortfolio + "&decoratorThumb=" + decoratorThumb;

    var hr = new XMLHttpRequest(); //request
    url = "DecoratorSignUp.php";
    hr.open("POST", url, true);
    hr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    hr.onreadystatechange = function() {
        if (hr.readyState == 4 && hr.status == 200) {
            var got_data = hr.responseText;
        }
    }
    hr.send(data);
    document.write("yes");
    return false;
};