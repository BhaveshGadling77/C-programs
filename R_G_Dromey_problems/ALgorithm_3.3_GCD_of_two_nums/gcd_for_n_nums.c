#include <stdio.h>
typedef unsigned long ul;

//sorting of array
#include <stdbool.h>
void bubblesort(ul *a, int len)
{
	ul i = 0, j = 1, checker = 0, temp = 0;
	/* Move the largest element to len-1 index*/
	while (i < len) {
		j = 1;
		checker = 0;
		while (j < len - i) {
			if (a[j - 1] > a[j]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				checker = 1;
			}
			j++;
		}
		i++;
		if (!checker)
			break;
	}
}

ul gcd(ul m, ul n)
{
	return n;
}

int main()
{
	unsigned long a, b, gcd_of_num, arr[64];
	scanf("%lu%lu", &a, &b);
	int i = 0;
	for (i = 0; i < 64 && scanf("%lu", &arr[i]) > 0; i++)
		printf("i = %d, ", i);
	bubblesort(arr, i);
	for (int j = 0; j < i; j++) {
		printf("%d ", arr[j]);
	}
	printf("\n");
}
