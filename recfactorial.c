#include <stdio.h>
int fact(int n){
	if(n == 1 || n == 0)
		return n;	
	return n * fact(n - 1);
}
int main(){
	int x = 0;
	printf("Enter the num that factorial you want : ");
	scanf("%d", &x);
	printf("fact of %d! = %d\n", x, fact(x));
	
	return 0;
}
