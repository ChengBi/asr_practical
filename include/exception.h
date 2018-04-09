#ifndef EXCEPTION_H
#define EXCEPTION_H

// #include <string>
#include <cstdio>

namespace asr {

	template <class Elem> class IndexExceedException : public std::exception{
	public:
		const char* trace() {
			return "captured Exception: IndexExceedException";
		};
	};
}
#endif
