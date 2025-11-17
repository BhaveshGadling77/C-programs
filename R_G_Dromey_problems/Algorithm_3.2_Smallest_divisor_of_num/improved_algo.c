#include <stdio.h>
#include <math.h>
int main() {
	int n, i = 2, final_num;
	scanf("%d", &n);
	final_num = n;
	while (i <= sqrt(n)) {
		
		if (n % i == 0) {
			final_num = i;
			break;
		}
		else {
			final_num = n;
		}
		i++;
	}
	printf("%d", final_num);
	return 0;
}
