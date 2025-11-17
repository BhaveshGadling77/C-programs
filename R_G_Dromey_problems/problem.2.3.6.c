
#include <stdio.h>
int main(void) {
	int n = 8,i = 1, d = 1, sum =  1, term = 1;
	while (n > 0){
		term = term + d;
		d = term;
		sum = sum + term;
		i++;
		n--;
	}
		printf("sum :- %d\n", sum);
		return 0;
}
