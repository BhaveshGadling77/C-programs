#include <stdio.h>
void insert(int j, int len, int *a)
{
	int temp;
	while (j > 0 && a[j - 1] > a[j] && j < len) {
		temp = a[j - 1];
		a[j - 1] = a[j];
		a[j] = temp;
	j--;
	}
}

void insertionsort(int *a, int len)
{
	int i = 0, j; 
	while (i < len - 1) {
		j = i + 1;
		insert(j, len, a); 
		i++;
	}
}

int main()
{
	int arr[32], len;
	for (int i = 0; i < 32 && scanf("%d", &arr[i]) != -1; i++)
		len++;
	insertionsort(arr, len);
	for (int i = 0; i < len; i++) 
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
