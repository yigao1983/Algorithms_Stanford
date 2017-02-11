#include <iostream>

using namespace std;

int main()
{
  unsigned long x, y;
  
  extern unsigned long karatsuba_prod(unsigned long, unsigned long);
  
  cin >> x;
  cin >> y;
  
  cout << karatsuba_prod(x, y) << endl;
  
  return 0;
}
