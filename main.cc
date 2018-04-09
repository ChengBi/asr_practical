#include <cstdio>
#include <iostream>
#include "array.h"
#include "ops.h"

int main() {


	asr::Scalar<float> s(10);
	asr::Scalar<float> s1(15);
	for (int i = 0; i < 15; i ++) {
		s << i*1.0;
		s1 << i*1.0 + 2;
	}
	std::string temp = s.tostring();
	printf("%s\n", temp);
	// printf("%s\n", s1.tostring());

	// printf("%d\n", s.size());
	// printf("%f\n", s.at(1));
	// printf("%f\n", s.at(20));
	// asr::Scalar<float> a1 = s + s1;
	// std::cout << a1.tostring() << std::endl;
	// printf("Add test 1, %s\n", a1.tostring());
	// printf("%s\n", (s + s).tostring());
	return 1;
}
