#include <stdio.h>
int strcasecompare(char *a, char *b){
	
		for(int i = 0; i < 10 ; i++){
			if(a[i] > b[i])
				return 1;
			else if(a[i] < b[i])
				return -1;
		}
		return 0;
	}
int main(void)
{
	char *a = "hi", *b = "hi";
printf("%d\n", strcasecompare(a, b));
		return 0;
}
