#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct data {
	char name[16];
	int marks;
} data;

void bubble_sort(data *p, int len) {
	int i = 0, j = 0;
	while (i < len - 1) {
		while (j < len - 1 - i) {
			if (strcmp(p[j].name, p[j + 1].name) > 0) {
				data temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
				j++;
		}
		i++;
	}
}
int main() {
	data *p;
	int i = 0, capacity = 20, x = 0;
	p = (data *)malloc (sizeof(data) * 20);
	//read the input in struct
	while ((scanf("%s %d", p[i].name, &p[i].marks) != -1)) {
		if (i >= capacity) {
			capacity += 10;
			p = realloc(p, sizeof(data) * capacity);
		}
		i++;
	}
	//sort it 
	bubble_sort(p, i);
	//Again print it
	while (x < i) {
		printf("%s %d\n", p[x].name, p[x].marks);
		x++;
	}
}
