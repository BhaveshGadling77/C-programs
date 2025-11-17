
#include <stdio.h>
typedef unsigned long ul;

ul gcd(ul m, ul n)
{
	ul r = 242;
	while (r != 0) {
		r = n % m;
		n = m;
		m = r;
	}
	return n;
}
int main()
{
	unsigned long a, b, div;
	scanf("%lu%lu", &a, &b);
	a = a % 2;
	if (a == 0) {
		a = a / 2;
	} else {
		div = a / 2;
		a = div * 2 + 1;
	}
	printf("Gcd = %lu\n",gcd(a, b) );
}
