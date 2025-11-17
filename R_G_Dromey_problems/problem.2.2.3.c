#include <stdio.h>
int main(void)
{
	int count, n, no_of_passed;
	scanf("%d", &n);
	count = n;
	no_of_passed = n;
	while (scanf("%d", &n) != EOF) {
		if(n<50){
			count--;
		}
	}
	
	printf("no of passed :-%d, no of failed :- %d",count , no_of_passed - count);
       return 0;
}       
