#include <stdio.h>
#include <stdbool.h>
void sorting(int *a, int len, int i, int *checker)
{
	int j = 1;
	while (j < len - i) {
		if (a[j - 1] > a[j]) {
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			*checker = 1;
		}
		j++;
	}	
}
void bubblesort(int *a, int len)
{
	int i = 0, count = 0, j = 1, checker = 0, temp = 0;
	/* Move the largest element to len-1 index*/
	while (i < len) {
		j = 1;
		checker = 0;
		sorting(a, len, i, &checker);
		count++;
		/*for (int i = 0; i < len; i++)
			printf("%d,", a[i]);
			printf("\n");
		*/
		i++;
		if (!checker)
			break;
	}
	printf("count = %d\n", count);
}
int main(void)
{
	int arr[] = {1, 4, 3, 2, 5, 6}, len = 6;
	// bubblesort(arr, len);
	// for (int i = 0; i < len; i++)
	int n;
	// 	printf("%d ", arr[i]);
	scanf("%d", &n);
	printf("%d", n);

}
