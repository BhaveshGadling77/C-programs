#include <stdio.h>
void stprint(int n, int i){
	if(i <= 2 * n){
		printf("*");
		stprint(n, i + 1);
	} else {
		return;
	}
}
void spprint (int n, int i){
	if(i <= n){
		printf(" ");
		spprint(n, i + 1);
	} else {
		return;
	}
}
void newline(int n, int i){
	if(i < n){
		spprint(n - i, 0);
		stprint(i, 0);
		printf("\n");
		newline(n, i + 1);
	} else{
		return;
	}
}
int main(){
	int n = 0;
	scanf("%d", &n);
	newline(n, 0);
	return 0;	
}

