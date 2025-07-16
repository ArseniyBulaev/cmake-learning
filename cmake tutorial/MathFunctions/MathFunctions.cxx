#include "MathFunctions.h"

// TODO 11: include cmath
#include <cmath>

// TODO 10: Wrap the mysqrt include in a precompiled ifdef based on USE_MYMATH
#ifdef USE_MYMATH
# include "mysqrt.h"
#endif

namespace mathfunctions {
double sqrt(double x)
{

  double sqrt_value;

  // TODO 9: If USE_MYMATH is defined, use detail::mysqrt.
  // Otherwise, use std::sqrt.
  #ifdef USE_MYMATH
    sqrt_value = detail::mysqrt(x);
  #else
    sqrt_value = std::sqrt(x);
  #endif 
    return sqrt_value;
}
}