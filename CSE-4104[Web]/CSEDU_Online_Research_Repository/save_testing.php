<?php
    session_start();
    $_SESSION["page_name"]="mehreen";
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="bootstrap-3.3.7-dist/css/bootstrap.min.css">
    <script src="Jquery/jquery-3.3.1.js"></script>
    <script src="bootstrap-3.3.7-dist/js/bootstrap.min.js"></script>
</head>

<body>
    <div id="obj">
        <button type="button" id="butt">Press</button>
    </div>
    <div id="jog"><div>
</body>

<script src="Stuk-jszip-9fb481a/dist/jszip.js"></script>
<script>
    var id=0;
    $(document).ready(function(){
        alert("asi");
        $(document).on('click','#butt',function(){
            /*
         //open link into new tab
         /*window.open('https://www.youtube.com/','_blank');*/
         //window.location='save.php?key=Rizvee';
         //window.href='save.php';
         //return false; */

         //file download feature
         var zip = new JSZip();

            // Add an top-level, arbitrary text file with contents
        zip.file("Hello.txt", "Hello World\n");

        // Generate a directory within the Zip file structure
        var img = zip.folder("images");
       

        // Add a file to the directory, in this case an image with data URI as contents
        img.file("csedu_contact.jpg", imgData, {base64: true});
        alert("ase");

        // Generate the zip file asynchronously
        zip.generateAsync({type:"blob"})
        .then(function(content) {
            // Force down of the Zip file
            saveAs(content, "archive.zip");
        });

        });
});
   
</script>

</html>


