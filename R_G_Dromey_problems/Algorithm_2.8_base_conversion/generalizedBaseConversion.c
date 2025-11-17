#include <stdio.h>
void print_valid_for_base16(int num) {
	char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	num -= 10;
	printf("%c", arr[num]);
}
int main() {
	int q, n, r, temp = 0, base, arr[64], j = 0, i = 0;
	printf("Enter base :- ");
	scanf("%d%d", &base, &n);
	q = n;
	while (q > 0) {
		r = q % base;
		q = q / base;
		arr[i++] = r;
	}
	j = i - 1;
	i = 0;
	while (i <= j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
	i = i * 2 - 1;
	j = 0;
	while (j < i) {
		if (base >  10 && arr[j] >= 10)
			print_valid_for_base16(arr[j]);
		else
			printf("%d", arr[j]);
		j++;	
	}
	printf("\n");
}
