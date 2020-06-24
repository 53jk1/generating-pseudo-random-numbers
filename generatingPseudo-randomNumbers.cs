using System;
 
namespace LCG
{

class Class1
{
private static ulong m;
private static ulong a;
private static ulong c;
private static ulong x;
 
private static ulong mult(ulong a, ulong  x, ulong m)
{
ulong b,n,r;
 
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
 
public static ulong genRand()
{
x = (mult(a,x,m) + c) % m;
return x;
}
 
[STAThread]
static void Main(string[] args)
{
int i, n;
ulong low, high;
 
Console.WriteLine("Enter the factor m");
m = ulong.Parse(Console.ReadLine());
 
Console.WriteLine("Enter the factor a");
a = ulong.Parse(Console.ReadLine());
 
Console.WriteLine("Enter the factor c");
c = ulong.Parse(Console.ReadLine());
 
Console.WriteLine("Enter the seed value x[1]");
x = ulong.Parse(Console.ReadLine());
 
Console.WriteLine("Enter how many pseudo-random numbers to draw");
n = int.Parse(Console.ReadLine());
 
Console.WriteLine("Enter the lowest value of the range of generated numbers");
low = ulong.Parse(Console.ReadLine());
 
Console.WriteLine("Enter the highest value for the range of generated numbers");
high = ulong.Parse(Console.ReadLine());
 
for (i=0; i<n; i++) {
Console.WriteLine(low + (genRand() % (high - low + 1)));
}
}
}
}