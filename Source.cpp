/*US POSTAL ZIP CODE DECODER (7-31-16)
	A bar code on an envelope is represented as a series of bars and half bars.
	The bar code can be represented in binary with '1' representing a full bar and
	'0' representing a half of a bar. A bar code is made up of exactly 27 binary chars
	such that the first and last bars are always 1, and the rest of the binary chars 
	are divided into 5 groups of 5, each group representing an encoded zip code digit.
	Each grouping must have exactly two 1s

	Decoding Rules
	Zip code digit = (1st binary digit*7) + (2nd binary digit*4) + ("" * 2)+("" * 1)+("" * 0)
	* If the sum is 11, then the zip code digit is 0

	Write a class that processes a bar code and decodes it into a zip code.
	Using a file of randomized bar codes, decode them if possible and
	output the zip codes to a text file. Log any errors in another text file.
*/
#include "ZipCode.h"
#include "ZipCodeException.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){

	ifstream fin("barcodes.txt");
	ofstream fout("zipcodes.txt");
	ofstream ferrors("errors.txt");

	while (!fin.eof())
	{
		string code;
		ZipCode zc;
		
		fin >> code;
		
		try{
			zc = ZipCode(code);

			//cout << "the decoded zip code for " << zc.getBarCode() << " is " << zc.getZipCode() << endl;
			cout << "Succesfully processed " << zc.getBarCode() << " into " << zc.getZipCode() << endl;
			fout << zc.getZipCode() << endl;
		}
		catch(ZipCodeException zce){
			//cout << zce.getErrorMessage() << endl;
			cout << "Error with code " << code << ". Check the error log for more info." << endl;
			ferrors << zce.getErrorMessage() << endl;
		}
	}

	fin.close();
	fout.close();
	ferrors.close();
	
	return 0;
}
