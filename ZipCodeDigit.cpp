#include "ZipCodeDigit.h"

ZipCodeDigit::ZipCodeDigit(){}

ZipCodeDigit::ZipCodeDigit(string code)
{
	if (validate(code))
	{
		barCode = code;
		digit = decode();
	}
	else
	{
		cout << "Unable to process " << code << endl;
	}
}
bool ZipCodeDigit::validate(const string code){

	string check = "01";
	int oneCount = 0;

	for (unsigned int i = 0; i < code.length(); i++)
	{
		int found = check.find(code[i]);
		if (found < 0)
		{
			throw ZipCodeException("There is a bad character in \"" + code + "\"");
		}
		else
		{
			if (code[i] == '1')
			{
				oneCount++;
			}
		}
	}

	if (oneCount != 2)
	{
		throw ZipCodeException("There must be exactly two 1's in \"" + code + "\"");
	}

	return true;
}
char ZipCodeDigit::decode(){

	int sum = 0, thisDigit;
	for (unsigned int i = 0; i < barCode.size(); i++)
	{
		switch (barCode[i])
		{
		case '0':
			thisDigit = 0; break;
		case '1':
			thisDigit = 1; break;
		default:
			break;
		}
		sum += (thisDigit * MULTIPLIERS[i]);
	}
	
	//Accounts for rule that if 11 is computed then the digit is '0'
	if (sum == 11)
	{
		return 48;
	}
	//The base char value for '0' is 48
	//Add the sum to 48 to get the ascii code for the digit computed
	return char(48 + sum);
}


