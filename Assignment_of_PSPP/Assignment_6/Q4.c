#include <stdio.h>
#include <stdlib.h>
char *strdupl(const char *s){

	char *p = (char *)malloc(sizeof(char) * 20);
	for(int i = 0; s[i] != '\0'; i++){
		p[i] = s[i];
	}
	return &p[0];
}
int main(){

char *str = "hello", *p;
p = strdupl(str); 
printf("%s\n", p);

free(p);
}
