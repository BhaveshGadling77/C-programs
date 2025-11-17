#include <stdio.h>
int findmin(int *arr, int st, int end)
{
	int min = st;
	for (int i = st + 1; i < end; i++) {
		if (arr[min] > arr[i])
			min = i;
	}
	return min;
}
void selectionsort(int *arr, int len)
{
	/* select the ith min element and move it to the ith position or swap*/
	/* find ith min and swap to index 0*/
	int min, temp;
	for (int i = 0; i < len - 1; i++) {
		min = findmin(arr, i, len);
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

}

int main()
{
	int arr[] = {4, 1, 2, 3}, len = 4;
	selectionsort(arr, len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}
