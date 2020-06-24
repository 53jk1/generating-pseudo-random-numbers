#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

typedef unsigned long long ulong;

ulong NWD ( ulong a, ulong b )
{
  ulong t;

  while( b )
  {
    t = b; b = a % b; a = t;
  }
  return a;
}

int main( )
{
  ulong m, a, c, x, d, g;

  srand ( ( unsigned )time ( NULL ) );
  cin >> x;
  m = x + 1;
  do c = rand( ) % m; while( NWD ( m, c ) != 1 );
  a = 1; x = m; d = 2; g = ( ulong )sqrt ( m );
  while( d <= g )
  {
    if( x % d == 0 )
    {
      a *= d;
      do x /= d; while( x % d == 0 );
    }
    if( d == 2 ) d++; else d += 2;
    if( x < d ) break;
  }
  a *= x;
  if( m % 4 == 0 ) a <<= 1;
  a++;
  cout << "m = " << setw ( 12 ) << m << endl
       << "a = " << setw ( 12 ) << a << endl
       << "c = " << setw ( 12 ) << c << endl
       << endl;
  return 0;
}
