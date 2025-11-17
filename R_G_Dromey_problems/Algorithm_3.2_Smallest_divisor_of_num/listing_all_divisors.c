#include <stdio.h>
#include <math.h>
void find_smallest_divisor(int n) {
	int d;
	d = 1;
	printf("All Divisors 1 ");
	while (d < n) {
		d = d + 1;
		if (n % d == 0) {
			printf("%d ", d);
		}
	}
	printf("\n");
}
int main() {
	//given that a int find the smallest divisor of the int other than 1.
	// designing algorithm for this 
	// approach 1 : bruteforce approach which say find upto sqroot(n) increment the divisor by 1 first and return 1st divisor
	// approach 2 : if n is even then return 2 else find start with d = 3 and increment by 2 upto n % d == 0 else return 1;
	int n;
	scanf("%d", &n);
	find_smallest_divisor(n);
	return 0;	
}
