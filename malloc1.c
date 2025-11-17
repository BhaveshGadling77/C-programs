#include <stdio.h>
#include <stdlib.h>

double avg_of_these(int n){
	double *p = (double *)malloc(sizeof(double) * n), sum = 0;
	for(int i = 0; i < n; i++){
	scanf("%lf", &p[i]);
	sum += p[i];
	}
	sum = sum / n;
	free(p);
	return sum;

}
int main(){
	int n = 0, x = 0;
	printf("Enter n : ");
	x = scanf("%d", &n);
	if (x < 1) {
		printf("Enter the valid number");
		return 1;
	}
	double avg = avg_of_these(n);
	printf("%.2lf\n", avg);
	return 0;
}



	
