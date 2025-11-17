#include <stdio.h>
#include <math.h>
int main() {
	float n, x0 = 1, x1 = 3;
	scanf("%f", &n);
	while (fabs(x0 - x1) > 0.02) {
		x0 = x1;
		x1 = (2 - n) * x0;
	}
	printf("reciprocal = %f\n", x0);
}

