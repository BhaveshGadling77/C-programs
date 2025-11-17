#include <stdio.h> 
void swap(int *a, int *b) {
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}
int main()
{
	int arr[8], len = 4, max_indx = 0, min_indx = 0;
	scanf("%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3]);
	for (int i = 0; i < len; i++) {
		if (arr[max_indx] < arr[i]) {
			max_indx = i;
		}
	}
	swap(&arr[len - 1], &arr[max_indx]);
	for(int i = 0; i < len; i++) {
		if(arr[min_indx] > arr[i]) {
			min_indx = i;
		}
	}
	swap(&arr[0], &arr[min_indx]);
	printf("%d %d\n", arr[1], arr[2]);

}
