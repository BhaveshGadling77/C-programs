#include <stdio.h>
int main(void) {
	int n = 8,sum = 0, i = 1, term = 1;
	while (n>0){
		sum = sum + i* term;
		term += 2;
		i = -1 * i;
//		printf("%d ", term);
	
		n--;
	}
		printf("sum = %d\n", sum);

		return 0;
}
