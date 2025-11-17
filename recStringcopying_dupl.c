#include <stdio.h>
#include <stdlib.h>
char *p = (char *)(malloc(sizeof(char) * 100));
int len_of_str(char *s, int len){
	if(s[len] == '\0')
		return len;
	len_of_str(s, len + 1);

}
/*char *malarr(int len){
	char *p = (char*)malloc(sizeof(char) * len);
	return p;
}*/
char *strcopy(char *s, int i) {
	int len = len_of_str(s, 0);	
	//char *p = malarr(len);
	if(i < len && s[i] == '\0'){
	p[i] = s[i];
		return p;
	}
	p[i] = s[i];
	return strcopy(s, i + 1);

}
int main(){
	char str[] = "Hello World";
//	char *p = (char *)malloc(sizeof(char) * 100);
	printf("%s\n", strcopy(str, 0));
	}

