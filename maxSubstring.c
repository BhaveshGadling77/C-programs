#include <stdio.h>
char *strmaxstr(char *a, char *b) {

	int count = 0, add = -1, j = 0, max_count = 0;
		for (int i = 0; a[i] != '\0'; i++) {
			if (a[i] == b[j]) {
				count++;
				i++;
	  	     		j++;
				while ((a[i] != '\0') && (a[i] == b[j])) {
					count++;
	      	 			j++;
	       				i++;
				}
				j = 0;
		}
			if (count > max_count) {
				max_count = count;
				add = i - count;
			} 
			count= 0;

		}
if(add != -1)
	return &a[add];
else 
	return NULL;
}
int main(){
	char str[] = "ababa";
	char substr[] = "aba";
	char *p = strmaxstr(str, substr);

		if(p == NULL)
			printf("NULL");
		else
			printf("%s\n", p);
		
}
