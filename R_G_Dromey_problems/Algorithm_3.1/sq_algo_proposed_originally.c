#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	/* if n * n == m then return n 
	 * else if n * n > m then n decreased by 0.1
	 * 	if n * n > m then n decreased by 0.01
	 * else if n * n < m then n increased by 1
	 */
	int m;
	double n = 0;
	float factor = 0.1;
	scanf("%d", &m);
	n = m / 2;
	while (fabs(m - (n * n)) > 0.0000001) {
		if (n * n == m) {
			break;
		} else if (n * n > m) {
			n = n - factor;
		} else if (n * n < m) {
			n = n + 1;
		}
	}
	printf("%.2lf\n", n);
}
