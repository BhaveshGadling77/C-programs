
#include <stdio.h>
int main(void) {
	int n = 8,i = -1,term = 1;
	while (n>0){

		printf("%d ", term);	
		term = -1* term;
	//	i *= -1;	
		//printf("i = %d\n", i);
		n--;

	}	return 0;
}
