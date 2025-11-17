#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	/* start x = x + 1; upto 5 after that and goes like dx = fabs(dx - 6);
	 *  x = dx + x;
	 *  test whether x is prime or not
	 *
	 *  then store it in an array for further testing 
	*/
	int x = 1, dx = 4, n = 0, limit = 0;
	int p[1024];
	p[1] = 2; p[2] = 3; p[3] = 5;
	scanf("%d", &n);
	while (x < n) {
		dx = fabs(dx - 6);
		x += dx;
	}
}
