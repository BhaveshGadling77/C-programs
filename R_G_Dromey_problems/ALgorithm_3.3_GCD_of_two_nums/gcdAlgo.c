#include <stdio.h>
int gcd(int m, int n)
{
	int temp, rem;
	if (m > n) {
		temp = n;
		n = m;
		m = temp;
	}
	rem = n % m;
	int i = 0;
	while (rem != 0) {

		n = m;
		m = rem;
		printf("%d ", i++);
		rem = n % m;
	}
	if(m < 0)
		return -m;
	return m;
}
int main()
{
	int a, b, gcd_of_num;
	scanf("%d%d", &a, &b);
	gcd_of_num = gcd(a, b);
	printf("Gcd = %d\n", gcd_of_num);
}
