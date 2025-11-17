#include <stdio.h>
#define SWAP(a, b)  { \
    typeof(a) temp = a; \
    a = b;              \
    b = temp;           \
}
// not understood the algorithm 
int fermat_algo(int n) {
	int i = 2, f, g;
	while (i <= n) {
		if (n % i == 0) {
			f = n / i;
			g = i;
			if (i < f) {
				int temp = g;
				g = f;
				f = temp;
			}
			break;
		}
		i++;
	}
	int x = (f + g) / 2;
	int y = (g - f) / 2;
	x = 2 * x + 1;
	y = 2 * y + 1;
	f = (x - y) / 2;

	return f;
}
int main(void) {
	int n = 0;
	scanf("%d", &n);
	printf("factore = %d\n", fermat_algo(n));
	return 0;
}
