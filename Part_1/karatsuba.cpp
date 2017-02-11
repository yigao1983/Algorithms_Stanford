#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

unsigned long num_digit(unsigned long x)
{
  unsigned long ndigit = 0;
  
  while (x > 0) {
    x /= 10;
    ndigit += 1;
  } 
  
  return ndigit;
}

unsigned long karatsuba_prod(unsigned long x, unsigned long y)
{
  unsigned long ndigit = max(num_digit(x), num_digit(y));
  
  if (ndigit <= 1) {
    return x * y;
  }
  
  unsigned a = x, b, c = y, d, tmp_x, tmp_y;
  
  for (unsigned int i = 0; i < ndigit/2; ++i) {
    a /= 10;
    c /= 10;
  }
  
  tmp_x = a;
  tmp_y = c;
  
  for (unsigned int i = 0; i < ndigit/2; ++i) {
    tmp_x *= 10;
    tmp_y *= 10;
  }
  
  b = x - tmp_x;
  d = y - tmp_y;
  
  unsigned ac = karatsuba_prod(a, c);
  unsigned bd = karatsuba_prod(b, d);
  unsigned ad_bc = karatsuba_prod(a+b, c+d) - ac - bd;
  
  for (unsigned long i = 0; i < ndigit/2 * 2; ++i) {
    ac *= 10;
    if (i < ndigit/2) {
      ad_bc *= 10;
    }
  }
  
  return ac + ad_bc + bd;
}
