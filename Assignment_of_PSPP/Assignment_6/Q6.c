#include <stdio.h>
long stringtoint(char *str){
	long num = 0, digit = 0;
	int len = 0, check = 0, j = 0;
	for(int i = 0; str[i] != '.' && str[i] != '\0'; i++){
		len++;
	}
	if(str[0] == '-'){
	       check = 1;
	       j = 1;
	}	       
	for(int i = j; i < len; i++){
		if(str[i] - '0' <= '9' - '0'){
		digit = (long)(str[i] - '0');
		num = 10 * num + digit;
		} else {
			break;
		}
	}
		if(check){
			return -1 * num;
		}else {
			return num;
		}
}
int main(){
char s[100];
scanf("%s", s);
printf("%ld\n", stringtoint(s));
}
