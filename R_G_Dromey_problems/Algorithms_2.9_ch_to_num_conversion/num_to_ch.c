#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *inttostring(int x){
	char arr[20];
	int len = 1, check = 0, i = 0, k = 0;
	arr[19] = '\0';
	int rem = 0;
	char *p = (char *)malloc(sizeof(char) * 20);
	if(x == 0 || x == -0){
		p[0] = '0';
		return p;
	}
	if(x < 0 && x != 0){
		check = 1;
		p[k++] = '-';
		x = -1 * x;
	}
	for(i = 18; x > 0; i--){
		rem = x % 10;
		arr[i] =(char)(rem + '0');
		x = x / 10;
		len++;
	}
	if(check != 1)
		i++;
	for(int j = k; j < len+ 1; j++){
		p[j] = arr[i + j];
	}
	return p;
}
int main() {
	int n;
	scanf("%d", &n);
	char *p = inttostring(n);
	printf("%s\n", p);
	return 0;
}
