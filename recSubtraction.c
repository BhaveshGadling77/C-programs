#include <stdio.h>
int sub(int a, int b)
{
	if(a == 0)
		return b > 0? -b : b;
	else if(b == 0)
		return a;
	else if(b < 0)
		return sub(a + 1, b + 1);
	else
		return sub(a - 1, b - 1);
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("subtraction : %d\n", sub(a, b));
}
