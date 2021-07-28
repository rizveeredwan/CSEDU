<?php
   session_start();
	class person {
		var $name;
		var $addressMain;
		var $addressSub;
		var $dateBirth;
		var $contact;
		var $email;
		var $password;
		var $gender;
		var $NID;
		var $TIN;
		var $religion;
		var $cast;
		var $portfolioLink;
		var $thumbnailLink;
		
		function __construct($row){
			$this->name = $row['name'];
			$this->addressMain = $row['addressMain'];
			$this->addressSub = $row['addressSub'];
			$this->contact = $row['contact'];
			$this->email = $row['email'];
			$this->password = $row['password'];
			$this->gender = $row['gender'];
			$this->NID = $row['NID'];
			$this->TIN = $row['TIN'];
			$this->religion = $row['religion'];
			$this->cast = $row['cast'];
			$this->portfolioLink = $row['portfolioLink'];
			$this->dateBirth = $row['dateBirth'];
			$this->thumbnailLink = $row['thumbnailLink'];
		} 
		
		function insert($conn){
		}
	}

	class hall extends person{
		var $hallID;
		function insert($conn){
			$hallID = mysqli_query($conn,"SELECT COUNT * FROM `hall`"); 
			$hallID = (int)$hallID;
			$hallID = $hallID + 1;
			$hallID = "H".$hallID;
			$sql = "INSERT INTO `hall`(
				`hallId`, 
				`hallName`, 
				`hallAddress1`,
				`hallAddress2`,
				`hallDateBirth`,
				`hallReligion`,
				`hallCast`,
				`hallContact`,
				`hallEmail`,
				`hallNID`,
				`hallTIN`,
				`hallGender`,
				`hallPassword`,
				`hallPortfolioLink`,
				`hallThumbImgLoc`
				)
				VALUES (
					'$hallID',
					'$this->name',
					'$this->addressMain',
					'$this->addressSub',
					'$this->dateBirth',
					'$this->religion',
					'$this->cast',
					'$this->contact',
					'$this->email',
					'$this->NID',
					'$this->TIN',
					'$this->gender',
					'$this->password',
					'$this->portfolioLink',
					'$this->thumbnailLink'
					)";
			if (mysqli_query($conn, $sql)) {
				echo "New record created successfully<br>";
			} else {
				echo "Error: " . $sql . "<br>" . mysqli_error($conn);
			}
		}
	}

	class customer extends person{
		var $customerID;
		function insert($conn){
			$customerID = mysqli_query($conn,"SELECT COUNT * FROM `customer`"); 
			$customerID = (int)$customerID;
			$customerID = $customerID + 1;
			$customerID = "C".$customerID;
			
			$sql = "INSERT INTO `customer`(
				`customerId`, 
				`customerName`, 
				`customerAddress1`,
				`customerAddress2`,
				`customerDateBirth`,
				`customerReligion`,
				`customerCast`,
				`customerContact`,
				`customerEmail`,
				`customerNID`,
				`customerTIN`,
				`customerGender`,
				`customerPassword`,
				`customerPortfolioLink`,
				`customerThumbImgLoc`
				)
				VALUES (
					'$customerID',
					'$this->name',
					'$this->addressMain',
					'$this->addressSub',
					'$this->dateBirth',
					'$this->religion',
					'$this->cast',
					'$this->contact',
					'$this->email',
					'$this->NID',
					'$this->TIN',
					'$this->gender',
					'$this->password',
					'$this->portfolioLink',
					'$this->thumbnailLink'
					)";
			if (mysqli_query($conn, $sql)) {
				echo "New record created successfully<br>";
			} else {
				echo "Error: " . $sql . "<br>" . mysqli_error($conn);
			}
		}
	}
	
	class photographer extends person{
		var $photographerID;
		function insert($conn){
			$photographerID = mysqli_query($conn,"SELECT COUNT * FROM `photographer`"); 
			$photographerID = (int)$photographerID;
			$photographerID = $photographerID + 1; 
			$photographerID = "P".$photographerID; 
			$sql = "INSERT INTO `photographer`(
				`photographerId`, 
				`photographerName`, 
				`photographerAddress1`,
				`photographerAddress2`,
				`photographerDateBirth`,
				`photographerReligion`,
				`photographerCast`,
				`photographerContact`,
				`photographerEmail`,
				`photographerNID`,
				`photographerTIN`,
				`photographerGender`,
				`photographerPassword`,
				`photographerPortfolioLink`,
				`photographerThumbImgLoc`
				)
				VALUES (
					'$photographerID',
					'$this->name',
					'$this->addressMain',
					'$this->addressSub',
					'$this->dateBirth',
					'$this->religion',
					'$this->cast',
					'$this->contact',
					'$this->email',
					'$this->NID',
					'$this->TIN',
					'$this->gender',
					'$this->password',
					'$this->portfolioLink',
					'$this->thumbnailLink'
					)";
			if (mysqli_query($conn, $sql)) {
				echo "New record created successfully<br>";
			} else {
				echo "Error: " . $sql . "<br>" . mysqli_error($conn);
			}
		}
	}
	
	class decorator extends person{
		var $decoratorID;
		function insert($conn){
			$decoratorID = mysqli_query($conn,"SELECT COUNT * FROM `decorator`"); 
			$decoratorID = (int)$decoratorID;
			$decoratorID = $decoratorID + 1; 
			$decoratorID = "D".$decoratorID; 
			$sql = "INSERT INTO `decorator`(
				`decoratorId`, 
				`decoratorName`, 
				`decoratorAddress1`,
				`decoratorAddress2`,
				`decoratorDateBirth`,
				`decoratorReligion`,
				`decoratorCast`,
				`decoratorContact`,
				`decoratorEmail`,
				`decoratorNID`,
				`decoratorTIN`,
				`decoratorGender`,
				`decoratorPassword`,
				`decoratorPortfolioLink`,
				`decoratorThumbImgLoc`
				)
				VALUES (
					'$decoratorID',
					'$this->name',
					'$this->addressMain',
					'$this->addressSub',
					'$this->dateBirth',
					'$this->religion',
					'$this->cast',
					'$this->contact',
					'$this->email',
					'$this->NID',
					'$this->TIN',
					'$this->gender',
					'$this->password',
					'$this->portfolioLink',
					'$this->thumbnailLink'
					)";
			if (mysqli_query($conn, $sql)) {
				echo "New record created successfully<br>";
			} else {
				echo "Error: " . $sql . "<br>" . mysqli_error($conn);
			}
		}
	}
	
	class catering extends person{
		var $cateringID;
		function insert($conn){
			$cateringID = mysqli_query($conn,"SELECT COUNT * FROM `catering`"); 
			$cateringID = (int)$cateringID;
			$cateringID = $cateringID + 1; 
			$cateringID = "T".$cateringID; 
			
			$sql = "INSERT INTO `catering`(
				`cateringId`, 
				`cateringName`, 
				`cateringAddress1`,
				`cateringAddress2`,
				`cateringDateBirth`,
				`cateringReligion`,
				`cateringCast`,
				`cateringContact`,
				`cateringEmail`,
				`cateringNID`,
				`cateringTIN`,
				`cateringGender`,
				`cateringPassword`,
				`cateringPortfolioLink`,
				`cateringThumbImgLoc`
				)
				VALUES (
					'$cateringID',
					'$this->name',
					'$this->addressMain',
					'$this->addressSub',
					'$this->dateBirth',
					'$this->religion',
					'$this->cast',
					'$this->contact',
					'$this->email',
					'$this->NID',
					'$this->TIN',
					'$this->gender',
					'$this->password',
					'$this->portfolioLink',
					'$this->thumbnailLink'
					)";
			if (mysqli_query($conn, $sql)) {
				echo "New record created successfully<br>";
			} else {
				echo "Error: " . $sql . "<br>" . mysqli_error($conn);
			}
		}
	}
	class marriageofficiant extends person{
		var $marriageofficiantID;
		function insert($conn){
			$marriageofficiantID = mysqli_query($conn,"SELECT COUNT * FROM `marriageofficiant`"); 
			$marriageofficiantID = (int)$marriageofficiantID;
			$marriageofficiantID = $marriageofficiantID + 1; 
			$marriageofficiantID = "M".$marriageofficiantID; 
			$sql = "INSERT INTO `marriageofficinat`(
				`marriageofficinatId`, 
				`marriageofficinatName`, 
				`marriageofficinatAddress1`,
				`marriageofficinatAddress2`,
				`marriageofficinatDateBirth`,
				`marriageofficinatReligion`,
				`marriageofficinatCast`,
				`marriageofficinatContact`,
				`marriageofficinatEmail`,
				`marriageofficinatNID`,
				`marriageofficinatTIN`,
				`marriageofficinatGender`,
				`marriageofficinatPassword`,
				`marriageofficinatPortfolioLink`,
				`marriageofficiantThumbImgLoc`
				)
				VALUES (
					'$marriageofficinatID',
					'$this->name',
					'$this->addressMain',
					'$this->addressSub',
					'$this->dateBirth',
					'$this->religion',
					'$this->cast',
					'$this->contact',
					'$this->email',
					'$this->NID',
					'$this->TIN',
					'$this->gender',
					'$this->password',
					'$this->portfolioLink',
					'$this->thumbnailLink'
					)";
			if (mysqli_query($conn, $sql)) {
				echo "New record created successfully<br>";
			} else {
				echo "Error: " . $sql . "<br>" . mysqli_error($conn);
			}
		}
	}
?>

