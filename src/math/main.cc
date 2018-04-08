// #include <iostream>
#include <ops.h>
// using namespace asr;

int main() {
  // asr::gaussian(1, 1, 1);
  // asr::test a;
  // a.print();
  float res = asr::gaussian<float>(0., 0., 1.);
  printf("%f\n", res);
  return 1;
}
