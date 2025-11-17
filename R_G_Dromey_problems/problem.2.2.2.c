#include <stdio.h>
int main(void)
{	int c, p_nums = 0, n_nums = 0, inp;
       while ((c = scanf("%d", &inp) != -1)) {
       if(inp >0){
	p_nums++;
       }else {
       n_nums++;
       }
       }
	printf("P nums :- %d N nums :- %d", p_nums, n_nums);
}	
