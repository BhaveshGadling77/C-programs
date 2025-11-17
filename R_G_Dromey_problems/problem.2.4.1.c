#include <stdio.h>
int fact(int n){
if (n < 0) 
	return 0;

if (n == 0 || n == 1)
	return 1;

return n * fact(n-1);
}
int main(void)
{
	int n;
	double result = 0;
	scanf("%d",&n);
	result =( 1 /((double)fact(n)));
	printf("%lf", result);
	return 0;
}
