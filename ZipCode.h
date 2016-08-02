#ifndef ZIPCODE
#define ZIPCODE

#include "ZipCodeDigit.h"
#include "ZipCodeException.h"
#include <string>
#include <iostream>

using namespace std;

class ZipCode
{
public:
	ZipCode();//Default constructor
	ZipCode(string); //Constructor that accepts bar code
	string getBarCode() {return barCode;}
	string getZipCode() {return zipCode;}
	
private:
	string barCode; //binary representation of a zip code
	string zipCode; //actual zip code
	ZipCodeDigit digitList[5]; //array of binary digits; 1 slot for each binary digit

	bool validate(const string); //throw (ZipCodeException);
	/* Check for a valid bar code
	   Return true if the bar code is exactly 27 characters, contains only binary digits,
	   first and last chars are '1', each group of 5 has two 1's
	   each group of 5 must have exactly two 1's
	   Return false if any condition is violated */
	void decode(const string);
};

#endif