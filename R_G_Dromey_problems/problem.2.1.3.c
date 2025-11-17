#include <stdio.h>
int main(void)
{	int a, b, c, d, temp;
	scanf("%d%d%d%d",&a, &b, &c, &d);
	temp = a;
	a = b;
	b = c;
	c = d;
	d = temp;
	
	printf("%d %d %d %d", a,b,c, d);
}
