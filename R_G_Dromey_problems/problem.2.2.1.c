#include <stdio.h>
int main(void)
{	int c = 0,marks = 0, no_of_passed_s = 0, count = 0;;
	double pass_rate;
	while ((c = scanf("%d", &marks)) != -1) {
		count++;
		if(marks >= 50) {
			no_of_passed_s++;
		}
	}
	pass_rate = (((double)(no_of_passed_s) /(double)(count)));
	printf("total no. of Marks :- %d\n No. of passed :- %d\n Passing Rate :- %.2lf",count, no_of_passed_s, pass_rate);
}
