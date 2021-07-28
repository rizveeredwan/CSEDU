$(document).ready(function() {
    var i = 0;
    $("#add").click(function() {
        i++;
        $("#orderPlaceTable").append('<tr class="orderPlaceTableRow" id="row' + i + '"><td class="orderPlaceTableData" id="data"><input type="text" class="startColumn" name="" placeholder="item number" id="input0"> </td><td class="orderPlaceTableData" id="data' + i + '"><input type="text" class="tableInput" name="" placeholder="amount" id="amount' + i + '"></td><td class="orderPlaceTableData" id="data' + i + '"><input type="submit" class="tableInput deleteButton" name="" value="Delete" id="' + i + '"></td></tr>');
        return false;
    });
    $(document).on('click', '.deleteButton', function() {
        var element = $(this).attr("id");
        $('#row' + element + '').remove();
        return false;
    });
});