
#include <stdio.h>

int main(void)
{
	int n = 0, sum = 0, i= 0;
	float avg = 0;
	scanf("%d", &n);
	sum = n;
	while (scanf("%d",&n) != EOF) {
	sum = sum + n;
	i++;
	}

	if(i == 0){
	printf("Invalid\n");
	return 0;
	}
	else{
	avg = ((float)sum / (float)i);
	printf("Average :- %f\n", avg / 2);
	return 0;
	}
}
