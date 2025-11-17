#include <stdio.h>
int main() {
	int n, no_of_digit = 0, rem, rev = 0;
	scanf("%d", &n);
	while (n > 0) {
		rem = n % 10;
		no_of_digit++;
		rev = 10 * rev + rem;
		n /= 10;
	}
	printf("%d", no_of_digit);

	return 0;
}
