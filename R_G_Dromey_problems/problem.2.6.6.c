#include <stdio.h>
int main(){
	int n, i = 1, j = 2, t = 1, f= 2;
	
	scanf("%d", &n);
	printf("%d ", f);
	while(n - 1 > 0){
		t = t * i;
		f = t * (j + 1);
		j++;
		i++;
		printf("%d ",f);
		n--;
	}
	return 0;
}
