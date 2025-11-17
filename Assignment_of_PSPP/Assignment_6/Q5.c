#include <stdio.h>
char *strchar(char *str, char c){
	int i = 0, count = 1;
	for(i = 0; str[i] != '\0'; i++){
		count++;
	}
	for(int j = 0; j < count; j++){
		if(c == str[j]){
			return &str[j];
		}
	}
//	char str1[] = "NULL";
	return NULL;
}
int main(){
printf("%s\n", strchar("abhijit", '\0') != NULL ? strchar("abhijit", '\0'): "NULL");
return 0;
}

