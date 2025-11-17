#include <stdio.h>
int s_max(int *a, int len){	
int fmax = a[0], smax = a[1];
	if(len == 1){
		return a[0];
	} else if(len == 2){
		return a[0]>a[1] ? a[0] : a[1];
	} else {
	int i = 2;
	fmax = a[0] >= a[1] ? a[0] : a[1];
	smax = a[0] >= a[1] ? a[1] : a[0];
	while(i < len){
		if(a[i]>= fmax){
			smax = fmax;
			fmax = a[i];
		} else if(a[i] >= smax && a[i] <= fmax){
			smax = a[i];
		} i++;
	}
}
return smax;
}
int main(){
	int arr[16], i = 0, len = 0, smax = 0;
	while(i < 16 && scanf("%d", &arr[i]) > -1)
		len++;
	smax = s_max(arr, len);
	printf("smax = %d\n",smax);
return 0;

}

