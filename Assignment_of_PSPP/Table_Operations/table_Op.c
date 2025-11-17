#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
typedef struct subject {
	char name[256];
	int credits;
	int semester;
} subject;

typedef struct no_of_sub{
	char name[64];
	double marks;
	char grade[3];
} no_of_sub;

/* global variable */

typedef struct student {
	long mis;
	no_of_sub *p;
} student;
void memset1(char *str, int i, int len)
{
	for (int  i = 0; i < len; i++) {
		if (str[i] == '\0')
			break;
		else
			str[i] = 0;
	}
}
void str_coversion(char *t, char *str)
{
	int i = 0;
	//printf("%s\n", t);
	str[i] = t[i];
	i++;
	while (str[i] != ',' && str[i] != '\0') {
		str[i] = t[i];
		i++;
	}
	t[i] = '\0';
	str[i] = '\0';
//	printf("This part is ok\n");
	//printf("%s\n", str);
}

char *copying_data(char *str, char *t)
{
	char *p;
	p = str;
	int i = 0;
	while (*p != '\n' && *p != ',' && *p) {
		t[i] = *p;
		p++;
		i++;
	}
	t[i] = '\0';
	p++;
//	printf("t = %s, len = %ld\n", t, strlen(t));
	//printf("what about this part\n");
	return p;
}
void readsubj_st(char *line, subject *s)
{
	char *t, *p, token[64];
	t = token;
	/* copying and convert data into Appropriate type store into Struct*/
	p = copying_data(line, t);
	/* Copy tokanise data into name*/
	strcpy(s->name, t);
	/* clear previous data to avoid from overwriting in t*/
	memset1(t, 0, strlen(t));
	/*copying the data using *p */
	p = copying_data(p, t);
	/* converting it to integer */
	s->credits = atoi(t);
	/* clearing the datA to avoid from overwriting in t */
	memset1(t, 0, strlen(t));
	/* copying the data using *p */
	copying_data(p, t);
	/* converting and saving the into int */
	s->semester = atoi(t);
	/*again clearing the data */
	memset1(t, 0, strlen(t));
	//printf("name = %s, cr = %d, Sem = %d\n", s->name, s->credits, s->semester);
}
int getindex(char *choice) {
	char *choices[] = {"grade", "gradeall", "cgpa",
	       	"sgpa", "failed", "topsem", "topsub", "topnsub", 
		"stdev", "exit" };
	for (int i = 0; i < 10; i++)
		if (strcmp(choices[i], choice) == 0)
				return i;
	return -1;
}

int readline(int fd, char *lines)
{
	int  i = 0;
	char ch;

	while (read(fd, &ch, 1) > 0 && ch != '\n') {
		lines[i] = ch;
		i++;
	}
	lines[i] = '\0';
	if (i == 0 && ch != '\n')
		return 0;
	//readsubj_st(lines, subjects);
	//printf("%s\n",lines);
	//printf("%s\n", a[indx].lines);
	return i;
}

int read_sub_csv(int *fd)
{
	int i = 0, capacity = 5;
	char lines[128];
	subject *p;
	*fd = open("./subjects.csv", O_RDONLY);
	p = (subject *)malloc(capacity * sizeof(subject));
	while (readline(*fd, lines)) {
		/* This will read the struct after reading the lines*/
		readsubj_st(lines, &p[i]);
		printf("%s %d %d\n", p[i].name, p[i].credits, p[i].semester);
		i++;
		if (i >= capacity) {
			capacity *= 2;
			p = (subject *)realloc(p, capacity * sizeof(subject));
			if (p == NULL) {
				perror("Failed to reallocate memory\n");
				close(*fd);
				exit(1);
			}
		}
	}
	close(*fd);
	return i;
}
void input()
{
	int index = 0;
	long mis = 0;
	char str1[64], str2[4];
	while (1) {	
		printf(">");
		scanf("%s", str1);
		index = getindex(str1);
		if (index == 0) {
			if (scanf("%ld", &mis) == 0) {
				scanf("%s", str2);
				strcat(str1, str2);
				index = getindex(str1);
			}
			printf("%s %s\n", str1, str2);
		}
		switch (index) {
			case 0 :
				printf("its grade\n");
				break;
			case 1 :
				printf("its grade all\n");
				break;
			case 2 :
				printf("its cgpa\n");
				break;
			case 3 :
				printf("its sgpa\n");
				break;
			case 4 :
				printf("Its failed\n");
				break;
			case 5 :
				printf("Its topsem\n");
				break;
			case 6 :
				printf("Its topsub\n");
				break;
			case 7 :
				printf("Its topnsub\n");
				break;
			case 8 :
				printf("Its Stdev\n");
				break;
			case 9 :
				printf("Its Exit\n");
				exit(0);
				break;
			default :
				printf("Error\n");
				break;
		}
		//remove the part of previous str1[]
		memset1(str1, 0, strlen(str1));
	}
}
void read_grade_csv(int *fd)
{
	*fd = open("./grades.csv", O_RDONLY);
	/*reading of file into struct */

	close(*fd);
}
void read_marks_Into_St(student *p, int len, int fd, char *line)
{
	char *t, *pt, token[64];
	int i = 0;
	t = token;
	/* copying and convert data into Appropriate type store into Struct copying_data(line, t);*/
	pt = copying_data(line, t);
	/* Copy tokanise data into name*/
	p->mis = atol(t);
	/* clear previous data to avoid from overwriting in t*/
	memset1(t, 0, strlen(t));
	printf("%ld,", p->mis);
	/*copying the data using *p */
	while (i < len) {
		/* copying the data and storing it into */
		pt = copying_data(pt, t);
		/* converting it to double */
		(*p).p[i].marks = atof(t);
		if ((*p).p[i].marks < 0 || (*p).p[i].marks > 100) {
			printf("Error in this marks can't be negative or greater than 100\n");
			exit(1);
		}
		printf("%.2lf,",(*p).p[i].marks);
		i++;
		/* clearing the datA to avoid from overwriting in t */
		memset1(t, 0, strlen(t));

	}
	printf("\n");
}
void read_data_into_stud_St(student *p, int len, int fd)
{
	int i = 0, capacity = 500;
	char lines[128];
	 while (readline(fd, lines)) {

		read_marks_Into_St(&p[i], len, fd, lines);
		i++;
		if (i >= capacity) {
			capacity *= 2;
			printf("this is true\n");
			p = (student *)realloc(p, sizeof(student) * capacity);
			if (p == NULL) {
				perror("Failed to reallocate memory\n");
				close(fd);
				exit(1);
			}
		}
		/* This will read the struct after reading the lines*/
		//read_marks_Into_St(&p[i], len, fd, lines);
		//i++;
	}
	close(fd);
	
}

void read_marks_csv(int *fd, int len)
{
	*fd = open("./marks.csv", O_RDONLY);

	/*reading of file into struct */
	student *p;
	p = (student *)malloc(sizeof(student) * 100);
	int i = 0;
	while (i < 100) {
		p[i].p = (no_of_sub *)malloc(sizeof(no_of_sub) * len);
		i++;
	}
	/* read all data into Student arr */
	read_data_into_stud_St(p, len, *fd);
	close(*fd);
}

int main()
{
	int fd, len = 0;
	/* Read csv file into subjects arr*/
	len = read_sub_csv(&fd);
	/* Read grades.csv into grades struct */
	//read_grade_csv(&fd);
	/* Read marks.csv into a large struct */
	read_marks_csv(&fd, len);
	input();
	return 0;
}
