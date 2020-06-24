public class LCG {
 
private static long m;
private static long a;
private static long c;
private static long x;
 
//Calculate a*x mod m
private static long mult(long a, long  x, long m) {
long b,n,r;
 
r = 0;
n = 1;
b = 1;
while (n <= 64) {
if ((a & b) != 0)
r = (r + x) % m;
x = (x + x) % m;
b *= 2;
n++;
}
 
return r;
}
 
public static long genRand(){
x = (mult(a,x,m) + c) % m;
return x;
}

public static void main(String[] args) {
int i, n;
long low, high;
 
System.out.println("Enter the m factor");
m = Console.readLong("");
 
System.out.println("Enter the factor a");
a = Console.readLong("");
 
System.out.println("Enter coefficient c");
c = Console.readLong("");
 
System.out.println("Enter the seed value x[1]");
x = Console.readLong("");
 
System.out.println("Enter how many pseudo-random numbers to draw");
n = Console.readInt("");
 
System.out.println("Enter the lowest value of the range of generated numbers");
low = Console.readLong("");
 
System.out.println("Enter the highest value for the range of generated numbers");
high = Console.readLong("");
 
for (i=0; i<n; i++) {
System.out.println(low + (genRand() % (high - low + 1)));
}
 
}
 
}