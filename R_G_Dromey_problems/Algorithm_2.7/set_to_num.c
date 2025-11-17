#include <stdio.h>
int main() {
	int num = 0, i = 0;
	while (scanf("%d", &i) > 0) {
		num = num *10 + i;
	}
	printf("%d\n", num);
	return 0;
}
