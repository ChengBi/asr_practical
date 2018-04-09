#ifndef OPS_H
#define OPS_H
#include <cstdio>
#include <cmath>
namespace asr {

  template < typename T > float gaussian(const T& x, const T& m, const T& v) {
    return 1./(sqrt(2*M_PI)*v)*exp(-0.5*(x*1.-m)*(x*1.-m)/(v*v));
  };


}
#endif
