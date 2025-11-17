#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int f_conversion(char *arg)
{
	char ch, f[30];
	int i = 0;

	while ((ch = getchar()) && (ch == '\t' || ch == '\n' || ch == ' ') && ch - '0' <= '9' - '0')
			;
	if (ch != EOF) {
		ungetc(ch, stdin);
	}
	while (i < 30 && (ch = getchar()) && ch != '\t' && ch != ' ' && ch != '\n' && ch - '0' <= '9' - '0')
		(f[i++] = ch);
	ungetc(ch, stdin);
//		f[i++] = ch;
	f[i] = '\0';
	float *p = (float *)arg;
	*p = atof(f);
	return 1;
}

int lf_conversion(char *arg)
{
	char ch, lf[310];
	int i = 0;

	while ((ch = getchar()) && (ch == '\t' || ch == '\n' || ch == ' ') && ch - '0' <= '9' - '0')
		;
	lf[i++] = ch;

	while (i < 310 && (ch = getchar()) && ch != '\t' && ch != ' ' && ch != '\n' && ch - '0' <= '9' - '0')
		lf[i++] = ch;

	lf[i] = '\0';

	double *p = (double *)arg;
	*p = atof(lf);
	return 1;
}
int str_conversion(char *arg)
{
    char ch;
    int i = 0;

    // Skip leading whitespace characters
    while ((ch = getchar()) && (ch == '\t' || ch == '\n' || ch == ' '))
        ;

    // Push the first non-whitespace character back into the input stream
    if (ch != EOF) {
        ungetc(ch, stdin);
    }

    // Read the first non-whitespace character (now it's the first character of the string)
    while ((ch = getchar()) && ch != '\n' && ch != ' ' && ch != '\t') {
        arg[i++] = ch;
    }
    arg[i] = '\0'; // Null-terminate the string

    return 1;
}
int d_conversion(char *arg)
{
	char ch, d[11];
	int i = 0, check = 0;

	while ((ch = getchar()) && (ch == '\t' || ch == '\n' || ch == ' ') && !check) {
		;
	}
	ungetc(ch, stdin);
	//d[i++] = ch;
	while (i < 11 && (ch != '\t' && ch != '\n' && ch != ' ') && ch - '0' <= '9' - '0') {
		ch = getchar();
		d[i++] = ch;
		check = 1;
	}
	d[i] = '\0';
	if (check == 1) {
		int *p = (int *)arg;
		*p = atoi(d);
		return 1;
	} else {
		return 0;	
	}
}

int myscanf(char *format, void *arg)
{
	char ch1, ch2;
	int i = 0, check = 0;

	while (format[i++] != '%')
		;
	if (format[i - 2] == ' ')
		check = 1;
	ch1 = format[i++];
	ch2 = format[i];
	char *p = (char *)arg;

	if (ch1 == 'l') {
		if (ch2 == 'f')
			return lf_conversion(p);
		else
			return 0;
	} else if (ch1 == 's') {
		return str_conversion(p);
	} else if (ch1 == 'c') {
		if (check) {
			while ((*p = getchar()) && (*p == '\t' || *p == '\n' || *p == ' '))
				;
			return 1;
		}
		*p = getchar();
		return 1;
	} else if (ch1 == 'd') {
		return d_conversion(p);
	} else if (ch1 == 'u') {
		return d_conversion(p);
	} else if (ch1 == 'f') {
		return f_conversion(p);
	} else {
		printf("Error\n");
	return 0;
	}
}

int main(void)
{
	int i = 6;
	int in;
	unsigned int ui;
	float f;
	double d;
	char arr[22];
	char ch;
	myscanf("%f", &f);
	printf("%f\n", f);
	myscanf("%s", arr);
	printf("%s\n", arr);
	myscanf("%lf", &d);
	printf("%.2lf\n", d);
	return 0;
}
