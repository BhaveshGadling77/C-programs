#include <stdio.h>
int countcalc(int i, int *a, int len){
	int count = 1, j = 0;
	while(j < len){
	if(a[i] == a[j])
		count++;
		
		j++;
	}
	return count;
}
int arrcp(int *uarr, int *a, int len){
	for(int i = 0; i < len; i++){
		a[i] = uarr[i];
	}
	return len;
}
int removedupl_k(int *a, int len, int k){
	int i = 0, j = 0, count = 0;
	int uarr[128];
	while(i < len){
		if(a[i] == a[i+1]){
			count = countcalc(i, a, len);
		if(count >= k){
			uarr[j++] = a[i];
			i = i + count;
		} else {
			for(int t = i; t < (i + count); t++){
				uarr[j++] = a[t];
			}
			i = count + i;
		}
		} else {
			uarr[j++] = a[i];
			i++;
		}
	}
	
	len = arrcp(uarr, a, j);
return len;
}
int main(void)
{
	int a[128] = {1, 2, 1, 3, 4, 1, 3, 2, 4, 3};
	int len = 10;
	len = removedupl_k(a, len, 3);
	for(int i = 0; i < len; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
return 0;
}
