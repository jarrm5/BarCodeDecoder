#ifndef ZIPCODEDIGIT
#define ZIPCODEDIGIT

#include "ZipCodeException.h"
#include <string>
#include <iostream>

using namespace std;

/* Class that represents a single zip code digit
   A zip code digit is a string of 5 binary numbers,
   consisting of exactly two 1's
*/

const int MULTIPLIERS[] = {7,4,2,1,0}; 

class ZipCodeDigit
{
public:
	ZipCodeDigit();
	ZipCodeDigit(string);

	string getBarCode(){return barCode;}
	char getDigit(){return digit;}
	
private:
	string barCode;
	char digit;

	bool validate(const string); //throw(ZipCodeException);
	/*Validate a zip code digit.
	  The zipcode class validator already checked for the appropriate length,
	  so that won't need to be done here.
	  Check to make sure each grouping actually consists of binary numbers
	  And if it does, make sure there are exactly two 1's in the grouping
	  Throw an exception if any condition is violated, otherwise return true
	*/
	char decode();
	/*Loop thru the binary segment and multiply each digit by the respective multiplier
	  Add these numbers up and return the decoded digit.
	*/
};

#endif

