#include <cstdio>
#include <iostream>
#include "array.h"
#include "ops.h"

int main() {


	asr::Scalar<float> s(10);
	asr::Scalar<float> s1(10);
	// asr::Scalar<float> s2(10);

	for (int i = 0; i < 15; i ++) {
		s << i*1.0;
		s1 << i*1.0 + 2;
	}

	std::cout << s.tostring() << std::endl;
	std::cout << s1.tostring() << std::endl;

	// asr::Scalar<float> temp(10);// = s1 + s1;
	// // s + s;
	// s2 = s + s1;
	s1 = s;
	// std::cout << s.tostring() << std::endl;
	std::cout << s1.tostring() << std::endl;
	// std::cout << (s + s1).tostring() << std::endl;
	// std::cout << s2.tostring() << std::endl;

	// s1.at(5) = s.at(5) + s.at(5);
	// std::cout << s1.at(5) << std::endl;
	// std::cout << temp.tostring() << std::endl;




	return 1;
}
