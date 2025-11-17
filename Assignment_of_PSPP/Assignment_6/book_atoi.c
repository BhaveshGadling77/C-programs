#include <stdio.h>
int atoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
	n = 10 * n + (s[i] - '0');
	return n;
}
int main() {
	int result = 0;
	char arr[8];
	scanf("%s", arr);
	result = atoi(arr);
	printf("int = %d\n", result);
}
