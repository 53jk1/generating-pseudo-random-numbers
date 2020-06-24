#include <iostream>

using namespace std;

int main( )
{
  unsigned int m, a, c, x, i, count;
  bool * T;

  while( true )
  {
     cout << "m = "; cin >> m;  // We read the module

     if( !m ) break;           // If zero, then we end

     cout << "a = "; cin >> a;  // We read the multiplier
     cout << "c = "; cin >> c;  // We read the increment

     T = new bool [ m ];        // We create a dynamic table

     for( i = 0; i < m; i++ )  // We fill it with zeros
        T [ i ] = false;

     x = 0;                     // We determine the generator seed

     for( i = 0; i < m; i++ )  // We generate m pseudo-random numbers
     {
        x = ( a * x + c ) % m;  // We determine the next pseudo-random number and place it in its place in the table
        T [ x ] = true;
     }

     count = 0;

     for( i = 0; i < m; i++ )
        if( T [ i ] ) count++;         // We count the numbers generated

     cout << count << endl;       // We display the number of generated numbers

     if( count == m ) cout << "OK\n\n"; // We evaluate the generator
     else           cout << "---\n\n";

     delete [ ] T;                 // We are removing the dynamic array
  }

  return 0;
}
