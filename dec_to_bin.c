#include <stdio.h>
#include <stdlib.h>
void reverse_array(int len, char *s, int j)
{
	char temp;
	if(j < (len - 1 - j)){
		temp = s[j];
		s[j] = s[len - 1 - j];
		s[len - 1 - j] = temp;
		j++;
		reverse_array(len, s, j);
	} else {
		return;
	}	
}

void print_binary(int num, int i, char *s)
{
	int rem = 0;

	if (num <= 0) {
		reverse_array(i, s, 0);
		printf("%s\n", s);
		return;
	}

	rem = num % 2;
	s[i++] = rem + '0';
	num = num / 2;
	print_binary(num, i, s);
}
int main(void)
{
	int n;
	printf("Enter the num which you want to show in binary : ");
	scanf("%d", &n);
	char *s = (char *)malloc(sizeof(char)* 32);
	print_binary(n, 0, s);
	free(s);
	return 0;
}

