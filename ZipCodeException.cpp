#include "ZipCodeException.h"

ZipCodeException::ZipCodeException(const string em){
	errorMessage = em;
}
string ZipCodeException::getErrorMessage(){
	return errorMessage;
}

