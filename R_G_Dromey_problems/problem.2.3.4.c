
#include <stdio.h>

int main(void)
{
	int n = 4, inp, i= 0;
	float sum = 0;
	while (i < 4) {
	scanf("%d", &inp); 
	sum = sum +(1 /(float)(inp));
	i++;
	}

	printf("Harmonic mean :- %.2f\n", (float)n / sum);
	return 0;
	}
