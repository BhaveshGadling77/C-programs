#include <stdio.h>
#include <math.h>
int main() {
	int m;
	int n;
	printf("Enter a Number : ");
	scanf("%d", &m);
	printf("Enter which root you want : ");
	scanf("%d", &n);
	// design algo
	/* using Newtons Raphson Formula */
	double g1, g2;
	g1 = m / 2;
	g2 = m / 2;
	while (fabs(pow(g1, n) - m) > 0.0000001) {
		g2 = (((n - 1) * g1) + (m / pow(g1, n - 1))) / n;
		g1 = g2;
	}
	printf("%.2lf\n", g2);

}
