#include <stdio.h>
void dec_to_bin(int n) {
	int rem = 0, i = 0;
	int arr[128];
	while (n > 0) {
		rem = n % 2;
		n /= 2;
		arr[i] = rem;
		i++;
	}
	 i = i - 1;
	printf("0.");
	while (i >= 0) {
		printf("%d", arr[i]);
		i--;
	}
	printf("\n");
}
int main() {
	//take a number
	char str[64], str2[64];
	int i = 0, j = 0;
	scanf("%s", str);
	while (str[i] != '.') {
		i++;
	} 
	i++;
	while (str[i] != '\0') {
		str2[j++] = str[i++];
	}
	str2[j] = '\0';
	int n = 0;
	i = 0;
	while (str2[i] != '\0') {
		n = n* 10 + str2[i++] - '0';
	}
	dec_to_bin(n); 
}
