#include <stdio.h>
int main(void)
{
	int fact = 1,term = 1, sum = 1, i = 3, n = 3;
	while(i <= n){
	
		sum += term;
		term = term * i;
		printf("%d", term);
		i++;

	}
}

