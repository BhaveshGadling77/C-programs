#include <stdio.h>
int main(void)
{	int a, b, c, temp;
	scanf("%d%d%d",&a, &b, &c);
	temp = c;
	c = b;
	b = a;
	a = temp;
	printf("%d %d %d", a,b,c);
}

		       
