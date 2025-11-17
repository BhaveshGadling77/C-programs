#include <stdio.h>
#include <math.h>
double nthroot(int num, int n) {
	
	double g1, g2;
	g1 = num / 2;
	g2 = num / 2;
	while (fabs(pow(g1, n) - num) > 0.0000001) {
		g2 = (((n - 1) * g1) + (num / pow(g1, n - 1))) / n;
		g1 = g2;
	}
	printf("%.2lf\n", g2);
	return g2;
}
int main(void) {
	int num, i = 0, n_st= 1;
	while (scanf("%d", &num) != -1) {
		n_st *= num;
		printf("%d\n", n_st);
		i++;
	}
	nthroot(n_st, i);
}
