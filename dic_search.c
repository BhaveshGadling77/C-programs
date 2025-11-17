#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> 
typedef struct dic {
	char name[32];
	int money;
} dic;
int readline (int fd, char *line) {
	int i = 0, x = 0;
	char ch;
	while ((x = read(fd, &ch, 1)) != 0 && ch != '\n' && i < 64) {
		line[i] = ch;
		i++;
	}
	line[i] = '\0';
	if (x == 0) {
		return -1;
	}
	return i;
}
void bubblesort(dic *a, int len) {
	dic temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (strcmp(a[j].name, a[j + 1].name) > 0) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main(int argc, char *argv[])
{	
	int fd, i = 0, x = 0, capacity = 20;
	dic *p;
	char line[64], *t;
	fd = open(argv[1], O_RDONLY);
	int arr[32] = {1, 6, 4, 5,2};
	p = (dic *)malloc(sizeof(dic) * 20);
	// read a line in an array
	while ((x = readline(fd, line)) != -1) {
		if (x == 0) {
			continue;
		}
		if (i >= 20) {
			capacity += 5;
			p = (dic *) realloc(p, sizeof(dic) * capacity);
		}
		//toknise on , and space
		t = strtok(line, ",");
		strcpy(p[i].name, t);
		t = strtok(NULL, ",");
		p[i].money = atoi(t);
		printf("%s, %d\n", p[i].name, p[i].money);
		i++;
	}
	printf("After sorting\n");
	x  = i;
	// sort on order of dictionary
	bubblesort(p, x);
	for (int i = 0; i < x; i++) {
		printf("%s %d\n",p[i].name, p[i].money);
	}
}
