#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
typedef struct matrix {
	int nrows, ncols;
	int **data;
}matrix;
#define SIZE 128
int fdreadline(int fd, char *s, int size){
	int x;
	char *p = s;
	while(((s - p) < size - 1) && ((x = read(fd, s, 1))==1) && (*s != '\n')) 
		s++;
	*s = '\0';
	if(x == 0)
		return -1;
	return (s - p);
}
int readmat(matrix *a, char *fname) {
	char line[SIZE], *token; 
	int fd, i, j;
	int nrows, ncols;
	fd = open(fname, O_RDONLY);
    if (fd == -1) {
        printf("Can't open the file\n");
        exit(1);
    }
	fdreadline(fd, line, SIZE);
	token = strtok(line, "\t");
	if(!token) {
		printf("bad data\n");
		return -1;
	}
	nrows = atoi(token);
	if(nrows <= 0) {
		printf("bad data\n");
		return -1;
	}
	token = strtok(NULL, "\t");
	if(!token) {
		printf("bad data\n");
		return -1;
	}
	ncols= atoi(token);
	if(ncols <= 0) {
		printf("bad data\n");
		return -1;
	}

	a->nrows = nrows;
	a->ncols = ncols;
	a->data = (int **)malloc(nrows * sizeof(int *));
	for(i = 0; i < ncols; i++)
		a->data[i] = (int *)malloc(ncols * sizeof(int));

	i = 0;	
	while(fdreadline(fd, line, SIZE) != -1) {
		token = strtok(line, "\t");
		if(!token) {
			printf("bad data\n");
			return 0;
		}
		a->data[i][0] = atoi(token);
		for(j = 1; j < ncols; j++) {
			token = strtok(NULL, "\t");
			if(!token) {
				printf("bad data\n");
				return 0;
			}
			a->data[i][j] = atoi(token);	
		}
		i++;
	}
	if(i != nrows) {
		printf("bad data\n");
		return 0;
	}
	close(fd);
	return 1;
}
int addmat(matrix *a, matrix *b, matrix *c) {
	int i, j;
	if(a->nrows != b->nrows || a->ncols != b->ncols) {
		printf("not compatible\n");
		return 0;
	}
	c->nrows = a->nrows;
	c->ncols = a->ncols;
	c->data = (int **)malloc(c->nrows * sizeof(int *));
	for(i = 0; i < c->ncols; i++)
		c->data[i] = (int *)malloc(c->ncols * sizeof(int));
	for(i = 0; i < a->nrows; i++)
		for(j = 0; j < a->ncols; j++)
			c->data[i][j] = a->data[i][j] + b->data[i][j];	
	return 1;
}
void printmat(matrix *a) {
	int i,j;
	for(i = 0; i < a->nrows; i++) {
		for(j = 0; j < a->ncols -1; j++)
			printf("%d\t", a->data[i][j]);
		printf("%d\n", a->data[i][j]);
	}
}
void freemat(matrix *a) {
	int j;
	for(j = 0; j < a->ncols; j++)
		free(a->data[j]);
	free(a->data);
}
int main() {
	char fname[32];
	int res;
	matrix a, b, c;

	scanf("%s", fname);
	res = readmat(&a, fname);
	if(res == 0) {
		freemat(&a);
		exit(1);
	} else if(res == -1) {
		exit(1);
	}
	scanf("%s", fname);
	res = readmat(&b, fname);
	if(res == 0) {
		freemat(&b);
		exit(1);
	} else if(res == -1) {
		exit(1);
	}
	
	res = addmat(&a, &b, &c);
	if(res) {
		printmat(&c);
		freemat(&c);
	}
	freemat(&a);
	freemat(&b);
	return 0;	
}