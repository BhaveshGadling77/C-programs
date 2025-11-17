#include <stdio.h>
#include <string.h>
#include <math.h>
void bin_to_dec(char *str) {
	int i = 0;
	int num = 0;
	int len = strlen(str);
	while (i < len) {
		if (str[len - 1 - i] == '0') {
		} else {
			num += pow(2, i);
		}
		i++;
	}
	printf("num = %d\n", num);
}
int main() {
	char n[64];
	scanf("%s", n);
	bin_to_dec(n);
	return 0;
}
