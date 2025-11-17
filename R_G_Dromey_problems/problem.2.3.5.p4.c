
#include <stdio.h>
int main(void) {
	int n = 8,i = 1;
       float term = 1.00, sum = 1.00;
	while (n-1>0){
		term = 1/(float)(i+1);
		sum = sum + term;
		i++;
		n--;
	}
		printf("sum :- %f\n", sum);
		return 0;
}
