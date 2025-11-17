#include <stdio.h>
int main(void) {
	int divCnt[101] = {0};

	for (int d = 1; d <= 100; ++d)
		for (int m = d; m <= 100; m += d)  
        		divCnt[m]++;

	int best = 0;
	for (int k = 1; k <= 100; ++k)
		if (divCnt[k] > best)
		       	best = divCnt[k];
	printf("Max = %d divisors\n", best);
	for (int k = 1; k <= 100; ++k)
		if (divCnt[k] == best)
			printf("%d ", k);
	return 0;
}
