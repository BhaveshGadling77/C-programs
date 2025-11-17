#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int mat1[8][8], mat2[8][8];
int readline(char *lines, int fd)
{
	int i = 0, x = 1;
	char ch;
	while (i < 32 && (x = read(fd, &ch, 1)) && ch != '\n') {
		lines[i] = ch;
		i++;
	}
	if (x == 0) {
		return -1;
	}
	return i;
}

void read_remaining(int fd, char *line, int row, int col)
{
	int i = 0;
	while ((readline(line, fd)) != -1) {
		
	}
}
int main()
{
	int fd1, fd2, row1, row2, col1, col2;
	char filename1[32], filename2[32], line[32], *t;
	scanf("%s %s", filename1, filename2);
	//read first to integer
	//then read data
	
	fd1 = open(filename1, O_RDONLY);
	fd2 = open(filename2, O_RDONLY);
	if (fd1 == -1 || fd2 == -1) {
		printf("Can't Open the file\n");
		exit(1);
	}
	readline(line, fd1);
	t = strtok(line, "\t");
	row1 = atoi(t);
	t = strtok(NULL, "\t");
	col1 = atoi(t);	
	readline(line, fd2);
	t = strtok(line, "\t");
	row2 = atoi(t);
	t = strtok(NULL, "\t");
	col2 = atoi(t);
	if (col1 != col2 || row1 != row2) {
		printf("bad data\n");
		return 1;
	}
	read_remaining(fd1, line, row1, col1);
}
