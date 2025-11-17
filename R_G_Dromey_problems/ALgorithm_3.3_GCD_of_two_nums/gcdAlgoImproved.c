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
	unsigned long a, b, gcd_of_num;
	scanf("%lu%lu", &a, &b);
	gcd_of_num = gcd(a, b);
	printf("Gcd = %lu\n", gcd_of_num);
}
