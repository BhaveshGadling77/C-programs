#include <stdio.h>
int main(void){
	int a[16] = {1, 2, 3, 4}, len = 4, i;
	reverse(a, len);
	for(int i = 0; i < len; i++)
		printf("%d ", a[i]);

	return 0;
}
void reverse(int a[], int len){
	int i = 0, temp = 0, j = len - 1;
	while(i <= j){
	temp = a[j];
	a[j] = a[i];
	a[i] = temp;
	i++;
	j--;
	}
	return;
}	
