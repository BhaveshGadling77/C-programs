#include <stdio.h>
int removedupl_k(int *a, int len, int k){
	int c[32], add[32];
	for(int i = 0; i <32; i++){
		c[i] = 1;
	}
	int i = 0;
	int j = 0, count = 0, l = 1;
	while (i < len) {
		while(j < len) {
			if(a[i] == a[j++]){
				count++;
			}
		}
		j = 0;	l = 1 + i;
		if (count >= k) {	
		while (l < len) {
		 if (a[i] == a[l]) {
				c[l] = 0;
			}	l++;
		
		}	
		} l = i;
		
		count = 0;	
			i++;
	}
	int m = 0, n = 0, t = 0;
	while(m < len){
		if(c[m] == 1){
			add[n++] = a[m];
		}
		m++;
	}
	while(t < n){
		a[t] = add[t];
		t++;
	}

	return n;
}
int main(void)
{
	int a[128] = {1,2 , 1, 2,2, 4 ,3, 2, 1, 3, 3 };
	int len = 11;
	len = removedupl_k(a, len, 3);
	for(int i = 0; i < len; i++){
		
		printf("%d ", a[i]);
	}
	printf("\n");
return 0;
}
