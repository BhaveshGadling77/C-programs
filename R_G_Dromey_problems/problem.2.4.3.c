#include <stdio.h>	
int fact(int n){
if (n < 0) 
	return 0;

if (n == 0 || n == 1)
	return 1;

return n * fact(n-1);
}
int main(void)
{	int n = 0;
	int i = 1,x;
	scanf("%d", &x);
	while(i < 24 && n < 207618480){
		n = fact(i);
		i++;
		if(x== n){
		printf("yes\n");
		return 0;
		}
	}
	printf("no\n");
	return 1;
}
