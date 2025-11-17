#include <stdio.h>
int add(int a, int b){
	if(b == 0)
		return a;
	else if(a == 0)
		return b;
	else if(a < 0)
		add(a + 1, b - 1);
	else if(b < 0)
		add(a - 1, b + 1);
	else
		add(a - 1, b + 1);
}
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = add(a, b);
	printf("sum : %d\n", sum);
}	
