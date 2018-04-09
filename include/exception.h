#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <cstdio>
#include <exception>

namespace asr {

	class IndexExceedException : public std::exception {
	public:
		const char* what();
	};

	class ArraySizeMismatchException : public std::exception {
	public:
		const char* what();
	};


}




#endif
