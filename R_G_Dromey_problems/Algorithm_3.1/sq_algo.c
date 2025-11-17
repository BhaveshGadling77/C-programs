#include <stdio.h>
#include <math.h>
int main(void) {
	int m;
	double g1, g2;
	scanf("%d", &m);
	g1 = m / 2;
	g2 = m / 2;
	while (fabs(g1 * g2 - m) > 0.0000001) {
		g2 = (g1 + (m / g1)) / 2;
		g1 = g2;
	}

	printf("%.2lf\n", g1);
	return 0;
} 
