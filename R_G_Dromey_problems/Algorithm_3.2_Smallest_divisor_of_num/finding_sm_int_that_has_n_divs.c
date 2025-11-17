#include <stdio.h>
int main() {
	int n, num, count = 0, i = 1;
	scanf("%d", &n);
	num = n;
	int res = 0;
	if (n < 3) {
		printf("result = %d\n", n);
		return 0;
	}
	while (count <  n) {
		count = 0;
		i = 1;
		while (i <= num) {
			if (num % i == 0) {
				count++;
			}
			i++;
		}
		if (count >= n)
			res = num;	
		num++;
	}
	printf("result = %d\n", res);
	return 0;

}
