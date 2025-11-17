#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find_required_len(int len) {
	int i = 1;
	while (len % 3 != 0) {
		len += i;
	}
	return len;
}
char *reqstr(char *str, int from, int upTo) {
	int i = from;
	int indx = 0;
	static char req[4];
	while (i < upTo) {
		req[indx] = str[i];
		i++;
		indx++;
	}
	req[3] = '\0';
	return req;
}
void interprete_bin (char *binNum, int len) {
	char *str[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
	//take any  three bits compare it
	int set = len / 3, i = 0;
	int arr[set];
	int k = 0;
	char *string;
	while (i < set) {
		string = reqstr(binNum, k, k + 3);
		i++;
		k += 3;
		for (int j = 0; j < 8; j++) {
			if (strcmp(str[j], string) == 0) {
				arr[i] = j;
				printf("%d", arr[i]);
			}
		}
	}
	printf("\n");
	
}
char  *convert_to_valid(char *num, int len) {
	int i = 0;
	char newarr[120];
	int len2 = find_required_len(len);
	newarr[len2] = '\0';
	for (i = 0; i < len; i++) {
		newarr[len2 - 1 - i] = num[len - i - 1];
	}

	for (int j = 0; newarr[j] != '1' ; j++) { 
		newarr[j] = '0';
	}
	interprete_bin(newarr, len2);
	return num;
}
void binary_to_octal(char *num) {
	//binary number in this 
	long len = strlen(num);
	if (len % 3 != 0) {
		//convert into a valid string
		num = convert_to_valid(num, len);
	} else {
		interprete_bin(num, len);
	}
}

int main() {
	char num[120];
	scanf("%s", num);
	binary_to_octal(num);
}
