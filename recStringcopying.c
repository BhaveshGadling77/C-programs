#include <stdio.h>
#include <stdlib.h>
int len_of_str(char *s, int len){
	if(s[len] == '\0')
		return len;
	len_of_str(s, len + 1);
}
void strcopy(char *s, int i, char *p) {
	int len = len_of_str(s, 0);	
	if(s[i] == '\0'){
		p[i] = s[i];
		return;
	}
	p[i] = s[i];
	strcopy(s, i + 1, p);

}
int main()
{
	char str[] = "Hello World";
	char *p = (char *)(malloc(sizeof(char) * 100));
	strcopy(str, 0, p);
	printf("%s\n",p);
	free(p);
}
