#include <stdio.h>
#include <stdlib.h>
typedef struct point {
	int x, y, z;
} point;
void insert(int indx, int i, point *p)
{
	point temp;

	while (indx != i) {
		temp = p[indx];
		p[indx] = p[i];
		p[i] = temp;
		indx++;
	}
}
int another_input(int i, point *p, int n)
{
	int indx = 0;

	scanf("%d %d %d %d", &indx, &p[i].x, &p[i].y, &p[i].z);
	return indx;
}
void print_struct(point *p, int n)
{
	int i = 0;

	while (i < n) {
		printf("%d %d %d\n", p[i].x, p[i].y, p[i].z);
		i++;
	}
}
int read_struct(point *p, int n)
{
	int i = 0;

	while (i < n) {
		scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
			i++;
	}
	return i;
}
int main(void)
{
	int n, i = 0, x = 0, indx = 0;

	if ((x = scanf("%d\n", &n)) != 1) {
		printf("Error\n");
		return 0;
	}
	point *p = (point *)malloc(sizeof(point) * (n + 1));
	/* Read Struct */
	i = read_struct(p, n);
	//printf("i = %d", i);
	/* Print Struct*/
	printf("Output:\n");
	print_struct(p, n);
	/*take another input*/
	indx = another_input(i, p, n + 1);
	if (n == 0 && indx > n) {
		printf("Error\n");
		return 0;
	} else if ((indx == -1 || indx > n + 1) && (n == 0 || n > 0)) {
		printf("Error\n");
		print_struct(p, n);
	} else {
		/*Insert it in that array*/
		insert(indx, i, p);
		/* Again print The whole array*/
		printf("After Insertion of element :\n");
		print_struct(p, n + 1);
	}
	//printf("indx = %d\n", indx);
	return 0;
}
