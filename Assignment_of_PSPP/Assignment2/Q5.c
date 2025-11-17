#include <stdio.h>
int main()
{
	int c1,g1,c2,g2,c3,g3,c4,g4,c5,g5;
	scanf("%d %d %d %d %d %d %d %d %d %d",&c1,&g1,&c2,&g2,&c3,&g3,&c4,&g4,&c5,&g5);
	float sgpa= (float)((c1*g1)+(c2*g2)+(c3*g3)+(c4*g4)+(c5*g5))/(c1+c2+c3+c4+c5);
	printf("%.6f",sgpa);
	return 0;
}
