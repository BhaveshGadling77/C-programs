#include <stdio.h>
#include <string.h>
double atof1(char s[])
{
	double result;
	int i = 0, sign = 1, power_of_10 = 1.0;

	if (s[i] == '-') {
		sign = -1;
		i++;
	}
	while (s[i] - '0'  <= '9' - '0' && s[i] != '.' && i < strlen(s)) {
		result = 10.0 * result + (s[i] - '0');
		i++;
	}
	i = i + 1;
	while (i < strlen(s) && s[i] != '\0' && s[i] - '0' <= '9' - '0') {
		result = result * 10.0 + (s[i] - '0');
		power_of_10 *= 10.0;
		i++;
	}
	return sign * (result / power_of_10);
}
int main()
{
	char s[32];
	scanf("%s", s);
	double val = atof1(s);
	printf("double = %lf\n", val);
}

