#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct lines{
	char arr[1024];
};
typedef struct lines lines;
void read_lines(lines *p, int n)
{
	int i = 0, j = 0;
	char c = getchar();
	while (i < n) {
		while (j < 1024) {
			p[i].arr[j] = getchar();
			if (p[i].arr[j] == '\n') {
				p[i].arr[j] = '\0';
				break;
				
			}
			j++;
		} j = 0;
		i++;
	}
}
int findmax_length(lines *p, int n) {
	int i = 0, max = 0, max_length = 0;
	while (i < n) {
		if(strlen(p[i].arr) > max_length) {
			max = i;
			max_length = strlen(p[i].arr);
		} i++;
	}

	return max;
}
int main(void)
{
	int n = 0, x = 0, max = 0;
	x = scanf("%d", &n);
	if (x < 1) {
		printf("Error Invalid input\n");
		return 0;
	} else {
		lines *p = malloc(sizeof(lines) * n);

		// read Inputs in that array until newline is not reach
		read_lines(p, n);
		// find max length with strlen
		max = findmax_length(p, n);
		// return that index of max length and then print it
		printf("%s\n", p[max].arr);
}
	return 0;
}
