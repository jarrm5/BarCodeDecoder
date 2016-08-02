#ifndef ZIPCODEEXCEPTION
#define ZIPCODEEXCEPTION

#include <string>

using namespace std;

class ZipCodeException
{
public:
	ZipCodeException(const string);
	string getErrorMessage();
private:
	string errorMessage;
};

#endif
