#include <stdio.h>
int is_non_descending(int *a, int len){
	for(int i = 0; i < len - 1; i++){
		if(a[i] > a[i+1]){
			return 0;
		}
	}
	return 1;
	}
int main(void){
int a[8] = {1, 2, 3, 4, 5}, len = 5;
printf("%d \n", is_non_descending(a, len));
}
