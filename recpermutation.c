#include <stdio.h>
int main(){
	int count = 0;
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++)
		for(int k = 1; k <= 5; k++)
		for(int m = 1; m <= 5; m++)
			for(int n = 1; n<= 5; n++){
				count ++; 
		printf("%d %d %d %d %d count = %d\n", i, j, k, m, n, count);
	}
	}
}
