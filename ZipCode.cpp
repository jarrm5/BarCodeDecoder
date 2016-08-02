#include "ZipCode.h"

ZipCode::ZipCode(){}

ZipCode::ZipCode(const string code)
{
	if (validate(code))
	{
		//The full zip code passed all tests, now check each
		//grouping of 5 binary numbers seperately.
		//If a group of 5 binary numbers passes, validation, then make a binarydigit object
		//cout << "The full code "<< code << " appears to be valid.\nNow checking the digit codes." << endl;

		//We can't assign the barcode yet, need to divide the middle 25 into 5 groups of 5
		//Attempt to create the 5 groupings here

		//The index of the first barcode digit starts at 1
		int index = 1;

		//Do this process 5 times
		for (int i = 0; i < 5; i++)
		{
			ZipCodeDigit zcd;

			try{
				zcd = ZipCodeDigit(code.substr(index,5));
			}
			catch (ZipCodeException zce){
				//cout << zce.getErrorMessage() << endl;

				//Enhance the original error message with the original code that caused the issue
				zce = ZipCodeException(zce.getErrorMessage() + ". full code: " + code);
				//Pass the error to main() for processing
				throw zce;
			}
			//Add the barcode to the list of digits
			digitList[i] = zcd;
			//Increment for the next group
			index += 5;
		}
		//Succesfully obtained 5 legal digits; assign the full barcode now
		barCode = code;

		//Now we can assign the decoded digits to the zip code data item
		for (int i = 0; i < 5; i++)
		{
			zipCode += digitList[i].getDigit();
		}
	}	
	else
	{
		cout << "Unable to process " << code << endl;
	}
}
bool ZipCode::validate(const string code){

	//Check the length
	if (code.size() != 27)
	{
		//Main catches and writes error to text file.
		throw ZipCodeException("The bar code was not 27 characters in " + code + ".");
	}

	//Check the first and last chars
	if (code[0] != '1')
	{
		throw ZipCodeException("The first digit was not \'1\' in " + code + ".");
	}
	if (code[code.size() - 1] != '1')
	{
		throw ZipCodeException("The last digit was not \'1\' in " + code + ".");
	}

	//Passed all validation tests
	return true;
}


