#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define LSIZE 1024
typedef struct data {
	char lines[LSIZE];
	int max_word_len;
} data;

void set_len_max_word_line(int indx, data *a)
{
	int i = 0, len = strlen(a[indx].lines), count = 0;

	a[indx].max_word_len = 0;
	while (i < len) {
		if ((a[indx].lines[i] != ' ') && (a[indx].lines[i] != '\n')) {
			count++;
		} else {
			if (count > a[indx].max_word_len)
				a[indx].max_word_len = count;
			count = 0;
		}
		i++;
	}
	if (count > a[indx].max_word_len)
		a[indx].max_word_len = count;
}

int readline(int fd, data a[], int size, int indx)
{
	int  i = 0;
	char ch;

	while (i < size && read(fd, &ch, 1) && ch != '\n') {
		a[indx].lines[i] = ch;
		i++;
	}
	a[indx].lines[i] = ch;
	//printf("%s\n", a[indx].lines);
	a[indx].lines[i] = '\0';
	return i;
}

int main()
{
	int fd,  max_len_of_word = 0;
	data a[1024];
	char data[64];
	scanf("%s", data);
	fd = open(data, O_RDONLY);
	if (fd == -1) {
		printf("Can't open the file\n");
		return 1;
	}
	int i = 0;

	/* read all data into struct*/
	while (readline(fd, a, LSIZE, i))
		i++;

	int j = 0, max_indx = 0;

	/*Set The maximum length of that line */
	while (j < i) {
		set_len_max_word_line(j, a);
		j++;
	}
	j = 0;

	/*find the index in where the maximum length of word*/
	while (j < i) {
		if (a[j].max_word_len >  max_len_of_word) {
			max_len_of_word = a[j].max_word_len;
			max_indx = j;
		}
		j++;
	}
	/* Print the max word contaning string */
	printf("%s\n", a[max_indx].lines);
	close(fd);
	return 0;
}
