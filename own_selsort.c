#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int binsearch(int *a, int len, int target)
{
	int i = 0, mid, st = 0, end = len - 1;
	while (st <= end) {
		mid = (st + end) / 2;
		if (a[mid] == target) {
			return mid;
		} else if (a[mid] > target) {
			end = mid - 1;
		} else {
			st = mid + 1;
		}
	}
	return -1;
}
int find_max(int *a, int len)
{
	int max_indx = 0;
	for (int i = 0; i < len; i++) {
		if (a[max_indx] < a[i]) {
			max_indx = i;
		}
	}
	return max_indx;
}

void selsort(int *arr, int len)
{
	int i = 0, max_ind = 0;
	//Select ith max and swap with the swap with len -1 - i
	while (i < len) {
		// Find the max 
		max_ind = find_max(arr, len - i);
		swap(&arr[max_ind], &arr[len - 1 - i]);
		i++;
	}
}

void bubblesort(int *a, int len)
{
	int i =  0, j = 0;
	while (i < len) {
		j = 0;
		while (j < len - i - 1) {
			if (a[j + 1] <  a[j]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void inssort(int *a, int len)
{
	int i = 0, j = 0;
	while (i < len - 1) {
		j = i + 1;
		while (j > 0 && a[j - 1] < a[j] && j < len) {
			swap(&a[j - 1], &a[j]);
			j--;
		}
		i++;
	}
}

int main(void)
{
	int target = 665, len = 9;
	int arr[9] = {1, 3, 2, 3, 9, 3, 2, 1, 5};
//	selsort(arr, len);
//	bubblesort(arr, 7);
	inssort(arr, len);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	int indx = binsearch(arr, len, target);
	if (indx == -1) {
		printf("Target not Found\n");
		return 1;
	}
	printf("target %d\n", arr[indx]);
}
