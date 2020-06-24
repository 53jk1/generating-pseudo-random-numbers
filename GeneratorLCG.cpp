#include <iostream>

using namespace std;

int main( )
{
  unsigned long long m, a, c, x, x0;

  cin >> m >> a >> c >> x0;
  x = x0;
  do
  {
    x = ( a * x + c ) % m;
    cout << x << " ";
  } while( x != x0 );
  cout << endl;
  return 0;
}
