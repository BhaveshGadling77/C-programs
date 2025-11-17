#include <stdio.h>
void dec_to_bin(int n) {
	int rem = 0, i = 0;
	int arr[128];
	if (n < 8) {
		if (n == 2 || n == 3) {
			i = 2;
			for (int k = 0; k < i; k++)
				printf("0");
		
		}
		else if (n == 1){
			i = 4 - n;
			for (int k = 0; k < i; k++)
				printf("0");
		} else {
			printf("0");
		}
	}
	i = 0;
	while (n > 0) {
		rem = n % 2;
		n /= 2;
		arr[i] = rem;
		i++;
	}
	 i = i - 1;
	while (i >= 0) {
		printf("%d", arr[i]);
		i--;
	}


}
int main() {
	// take a input number
	int n;
	scanf("%d", &n);
	dec_to_bin(n);
}
