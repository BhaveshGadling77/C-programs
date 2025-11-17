#include <stdio.h>
#include <stdlib.h>
void input(int *num2)
{
	if ((scanf("%d", &(*num2))) < 1) {
		printf("bad opr2\n");
		exit(0);
	}
}
void continuous_calc()
{
	int num1, num2, x = 0;
	char ch1, ch2;
	while (1) {
		x = scanf("%d", &num1);
		if (x == 0) {
			printf("bad op1\n");
			exit(0);
		} else if (x == -1) {
			exit(1);
		}
		x = scanf(" %c", &ch1);
		if (x == -1) {
			printf("bad opr1\n");
			exit(0);
		}
		switch (ch1) {
			case '+':
				input(&num2);
				printf("%d\n", num1 + num2);
				break;
			case '*':	
				input(&num2);
				printf("%d\n", num1 * num2);
				break;
			case '-':
				input(&num2);
				printf("%d\n", num1 - num2);
				break;
			case '/':
				input(&num2);
				printf("%d\n", num1 / num2);
				break;
			case '%':
				input(&num2);
				printf("%d\n", num1 % num2);
				break;
			case '|':
				input(&num2);
				printf("%d\n", num1 | num2);
				break;
			case '&':
				input(&num2);
				printf("%d\n", num1 & num2);
				break;
			case '>':
				x = scanf(" %c", &ch2);
				if (ch2 == '>') {
					input(&num2);
					printf("%d\n", num1 >> num2);
				} else {
					printf("opr1 %c != opr2 %c\n", ch1, ch2);
					exit(1);
				}
				break;
			case '<':
				x = scanf("%c", &ch2);
				if (ch2 == '<') {
					input(&num2);
					printf("%d\n", num1 >> num2);
				} else {
					printf("opr1 %c != opr2 %c\n", ch1, ch2);
					exit(1);
				}
				break;
			default :
				printf("bad opr1\n");
				exit(1);
				break;
		}
	}
}

int main()
{
	continuous_calc();
}
