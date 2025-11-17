#include <stdio.h>
#include <string.h>

void str_to_num(char *s) {
	int len = strlen(s), num = 0;
	for (int i = 0; i < len; i++) {
		num = num * 10 + (s[i] - '0');
	}
	printf("%d", num); 
}

int main() {
	char s[64];
	scanf("%s", s);	
	str_to_num(s);
	return 0;
}
