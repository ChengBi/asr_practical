#include "exception.h"

const char* asr::IndexExceedException::what() {
	return "Invalid Index !";
}

const char* asr::ArraySizeMismatchException::what() {
	return "Array size mismatch !";
}
