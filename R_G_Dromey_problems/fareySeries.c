#include <stdio.h>
#include <math.h>
int main() {
	//take a input number n
	int n = 0;
	scanf("%d", &n);
	int a = 0, p,  k, b = 1, c = 1, d = n, q;
	while (a != 1 || b != 1) {
		printf("%d/%d, ", a,  b);
		k = (n + b) / d;
		p = (k * c) - a;
		q = (k * d) - b;
		a = c;
		b = d;
		c = p;
		d = q;
	}
	printf("%d/%d\n", a, b);
	return 0;
}

