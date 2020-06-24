#include "stdio.h"

unsigned long long m;
unsigned long long a;
unsigned long long c;
unsigned long long x;

// Calculate a*x mod m
unsigned long long mult(unsigned long long a, unsigned long long  x, unsigned long long m)
{
unsigned long long b,n,r;

r = 0;
n = 1;
b = 1;
while (n <= 64)
{
if ((a & b) != 0)
r = (r + x) % m;
x = (x + x) % m;
b *= 2;
n++;
}

return r;
}

unsigned long long genRand()
{
x = (mult(a,x,m) + c) % m;
return x;
}

int main()
{
int i, n;
unsigned long long low, high;

printf("Enter the coefficient m\n");
scanf("%Ld", &m);

printf("Enter the coefficient a\n");
scanf("%Ld", &a);

printf("Enter the coefficient c\n");
scanf("%Ld", &c);

printf("Enter the seed value x[1]\n");
scanf("%Ld", &x);

printf("Enter how many pseudo-random numbers to draw\n");
scanf("%d", &n);

printf("Enter the lowest value of the range of generated numbers\n");
scanf("%Ld", &low);

printf("Enter the highest value for the range of generated numbers\n");
scanf("%Ld", &high);

for (i=0; i<n; i++)
{
printf("%Ld\n", low + (genRand() % (high - low + 1)));
}

return 0;
}
