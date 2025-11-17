#include <stdio.h>
int main(void) {
	int N, x = 1;
	scanf("%d", &N);
	while ((x * x) <= N) {
		x = x + 1;
	}
	printf("x = %d\n", x);
}
