#include <stdio.h>
#include <string.h>
int check(char *str, char ch) {
	for (int i = 0; i < 10; i++) {
		if(ch == str[i]) {
			return 1;
		}
	}	
	return 0;
}
int main() {
	int i = 0, count_dot = 0, count_digit = 0, count_sign = 0;
	char s[64];
	char str[10] = "0123456789";
	scanf("%s", s);
	int len = strlen(s);
	while (i < len) {
		if (s[i] == '.') {
			count_dot++;
		} else if ((s[i] == '-' || s[i] == '+'))  {
			count_sign++;
			if (count_digit != 0) {
				printf("it is not a number\n");
				return 1;
			}
		}
		else if (check(str, s[i])) {
			count_digit++;
		} else {
			printf("it is not a number\n");
			return 1;
		}
		i++;
		if ( count_sign > 1 || count_dot > 1) {
			printf("it is not a number\n");
			return 1;
		} 
		if (count_digit == 0 && (count_sign == 1 || count_dot == 1)) {
			printf("it is not a number\n");
			return 1;
		}
	}
	if (len != 0)
		printf("Its a number!\n");
	else 
		printf("Its not a number\n");
	return 0;
}
