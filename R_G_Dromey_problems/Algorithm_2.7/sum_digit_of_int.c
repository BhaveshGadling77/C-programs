#include <stdio.h>
int main() {
	int n, sum = 0, rem, rev = 0;
	scanf("%d", &n);
	while (n > 0) {
		rem = n % 10;
		sum += rem;
		rev = 10 * rev + rem;
		n /= 10;
	}
	printf("%d\n", sum);

	return 0;
}
