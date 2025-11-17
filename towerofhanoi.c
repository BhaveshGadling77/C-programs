#include <stdio.h>
void TOH(char src, char help, char dest, int n)
{
	if(n == 1) {
		printf("move %d from %c to %c using %c\n", n, src, dest, help);
		return;
	}
	TOH(src, dest, help, n -1);
	printf("move %d from %c to %c using %c\n", n, src, dest, help);
	TOH(help, src, dest, n - 1);
}
int main(int *agr, char *agrv[]){
	int n = 0;
	scanf("%d", &n);
	TOH('A', 'B', 'C', n);
}
