#include <iostream>
#include <math.h>
namespace asr {

  template < typename T > float gaussian(const T& x, const T& m, const T& v) {
    return 1./(sqrt(2*M_PI)*v)*exp(-0.5*(x*1.-m)*(x*1.-m)/(v*v));
  };

  template <class T> class scalar {

  private:
    T* value;
  public:
    scalar(const int n);
    ~scalar();

  };




}
