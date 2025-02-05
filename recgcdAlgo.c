#include <stdio.h>

long recgcd(long a, long b)
{	long rem;
	rem = a % b;
	if(rem == 0)
                return b;
	a = b;
	b = rem;
	return recgcd(a, b);
}
int main(void)
{	long a, b;
	scanf("%ld %ld", &a, &b);
	printf("gcd = %ld\n", recgcd(a, b));
}
