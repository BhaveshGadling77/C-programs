#include <stdio.h>
int main()
{
	int i, j, k = 0;

	scanf("%d%d%d", &i, &j, &k);
	printf("%.2lf", (float)(i + j + k) / 3);
}
