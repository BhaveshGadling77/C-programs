
#include <stdio.h>
int main(void) {
	int n = 8, sum =2, term = 2;
	while (n-1>0){
		term += 2;
	sum = sum + term;

	printf("%d\n", sum);
	n--;
	}
	printf("sum :- %d\n", sum);
	return 0;
}
