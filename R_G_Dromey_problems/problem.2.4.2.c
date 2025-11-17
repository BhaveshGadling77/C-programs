#include <stdio.h>
int fact(int n){
if (n < 0) 
	return 0;

if (n == 0 || n == 1)
	return 1;

return n * fact(n-1);
}
int x_power(int x, int n) {
	if(n == 1)
		return x;
	if (n == 0)
		return 1;

	return x * x_power(x, n-1);
}
int main(void)
{
	printf("%lf", (double) x_power(2,2)/(double) fact(2));
			return 0;
			}
