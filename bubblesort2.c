#include <stdio.h>
#include <stdbool.h>
void bubblesort(int *a, int len)
{
	int i = 0, j = 1, checker = 0, temp = 0;
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
int main(void)
{
	int arr[] = {1, 2, 3, 43,2 ,21}, len = 6;
	bubblesort(arr, len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

}
