#include <stdio.h>

void insert(int *a, int i, int len)
{
	int j = i;
	while (j < len - 1) {
		a[j] = a[j + 1];
		j++;
	}
}
int removedupl_k(int *a, int len, int k)
{
	int i = 0, count = 1, rlen = len;
	for (i = 0; i < len; i++) {
		count = 1;
		//count ith element in array
		for (int j = i + 1; j < len -1; j++) {
			if (a[i] == a[j]) {
				count++;
			}
		}
			//rlen = remove_dupl(a, i, a[i], len, &rlen);
		for (int j = i + 1; j < len - 1; j++) {
			if (a[j] == a[i]) {
				insert(a, j, len);
				rlen--;
				//printf("rlen = %d\n", rlen);
			}
		}
	}
	return rlen;
}
int main(void)
{
	int a[128] = {1, 2, 1, 3, 4, 1, 3, 2, 4, 3};
	int len = 10;
	len = removedupl_k(a, len, 3);
	len = 6;
	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
