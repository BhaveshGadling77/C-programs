#include <stdio.h>
double power(double x, double n)
{
	if(n < 0)
		return (1 / x) * power(x, n + 1);
	if(n == 0)
		return 1;
	return x * power(x, n -1);
}
int main(){
	double x, n;
	x = scanf("%lf %lf", &x, &n);
	if(x == 0 || x == 1){
		printf("Error\n");
		return 1;
	}
	printf("x^n : %lf\n", power(x, n));
	return 0;
}
