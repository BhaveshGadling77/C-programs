#include <stdio.h>
char *strconcat(char *dest, char *src){
      int len = 0;
	while(dest[len] != '\0') 
		len++;
int i = 0;
	while(src[i] != '\0'){
		dest[len + i] = src[i];
	i++;
	}
      return dest;
}       
int main(){
	char b[16] = "Abhijit";
	char a[16] = "coep";
	char *p = strconcat(b, a);
	printf("%s\n", p);
}
