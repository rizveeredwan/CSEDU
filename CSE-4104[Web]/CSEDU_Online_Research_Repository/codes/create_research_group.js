/*This js file is used to control the create_research_group.html*/
$(document).ready(function() {

    function return_id_value(id) {
        var value = document.getElementById(id).value;
        return value;
    }

    function check_two_string_equality(a, b) {
        if (a == b) return true;
        else return false;
    }

    function checking_nullity(a) {
        if (a == "") return false;
        return true;
    }

    function check_validity_of_data(name, account, password, confirm_password, email, phone1, phone2, link) {
        var ok = check_two_string_equality(password, confirm_password);
        if (!ok) {
            alert("Passwords didn't matched");
            return false; /*password confirm passowrd not matched*/
        }
        ok = checking_nullity(name);
        if (!ok) {
            alert("Research Group Name need to be provided");
            return false;
        }
        return true;
    }

    $(document).on('click', '#create', function() {
        var name = return_id_value('name');
        var account = return_id_value('account');
        var password = return_id_value('password');
        var confirm_password = return_id_value('confirm_password');
        var email = return_id_value('email');
        var phone1 = return_id_value('phone1');
        var phone2 = return_id_value('phone2');
        var link = return_id_value('link');

        var phone = phone1 + "^" + phone2;

        //debug: alert(name + " " + account + " " + password + " " + confirm_password + " " + email + " " + phone1 + " " + phone2 + " " + link);
        var ok = check_validity_of_data(name, account, password, confirm_password, email, phone1, phone2, link);
        if (!ok) return false;


        /*Data is valid need to send*/
        var path = "server_create_research_group.php";
        var method = "POST";
        $.ajax({
            url: path,
            method: method,
            data: { name: name, account: account, password: password, email: email, phone: phone, link: link },
            success: function(data) {
                if (data == "successful") {
                    alert("Account Created Successfully. Try to log in");
                    home_page_after_creation();
                } else {
                    alert(data);
                }
            }
        });

        return false;
    });

    function home_page_after_creation() {
        window.location = "home.php";
    }

});