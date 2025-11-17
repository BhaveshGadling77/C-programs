#include <stdio.h>
void printrow(int n)
{
	if(n == 1)
		return;
	else{
		printf("*");
		printrow(n - 1);
	}
}
void printnewline(int n){
	if(n == 0)
		return;
	else {
		printrow(n);
		printf("\n");
		printnewline(n - 1);
	}
} // 2nd type of code
void triangle_pattern(int row, int col)
{
	if (row == 0) {
		printf("\n"); 
		return;
	}else if(col == row ) {
		printf("\n");
		triangle_pattern(row - 1, 0);
	} else {
		printf("*");
		triangle_pattern(row, col + 1);
	}
	
}	
int main(){
	int n = 0;
	scanf("%d", &n);
	//printnewline(n);
	triangle_pattern(n, 0);
	return 0;	
}

