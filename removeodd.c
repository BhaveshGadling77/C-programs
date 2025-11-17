/*Write a C function, which given an array of integers, removes all odd numbers from the array, maintaining the order of remaining numbers. The function returns the new length of the array. Assume that all numbes will be >=0

int removeodd(int a[], int len);

For example:
Test 	Result

int a[] = {1, 2, 3, 4}, len, i;
len = removeodd(a, 4);
for(i = 0; i < len; i++)
  printf("%d ", a[i]); */
#include <stdio.h>
int isodd(int num) {
	int com = 1;
	if (num == com)
		return 1;
	while (num >= com) {
		if (num == com) {
			return 1;
		}
		com += 2;
	}
	return 0;
}
void insert(int *a, int i, int len) {
	while (i < len ) {
		a[i] = a[i + 1];
		i++;
	}
}
int removeodd(int *a, int len) {
	int i = 0, nlen = len;
	while (i < len) {
		if (isodd(a[i])) {
			printf("i = %d ,%d\n", i, isodd(a[i]));
			printf("this is true\n");
			insert(a, i, len);
			nlen--;
		}
		else
			i++;
	}
	return nlen;
}

int main(){
	
	int a[] = {1, 1, 3, 4, 4, 5}, len, i;
	len = removeodd(a, 6);
	for(i = 0; i < len; i++)
		printf("%d ", a[i]);
}

