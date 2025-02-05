#include <stdio.h>
int linearSearch(int target, int *arr, int len, int i){
	if(arr[i] == target)
		return i;
	if(i >= len - 1)
		return -1;
	return linearSearch(target, arr, len, i + 1);
}
int main(){
	int arr[]  = {}, x;
	int target = 0;
	if((x = linearSearch(target, arr, 8, 0)) > -1)
		printf("The target %d is found at index %d\n", target, x);

	else 
		printf("Not found in Array");
	return 0;
}
