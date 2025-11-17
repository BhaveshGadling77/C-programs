#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <math.h>

typedef struct subject {
	char name[128];
	int credits;
	int semester;
} subject;

typedef struct grades {
	double grades[7];
} grades;

typedef struct no_of_sub{
	double points;
	double marks;
	char grade[3];
} no_of_sub;

int capacity = 100;
int no_of_stu = 0;
char *grade[9] = {"FF", "DD", "CD", "CC", "BC", "BB", "AB", "AA"};
typedef struct student {
	long mis;
	no_of_sub *p;
} student;

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
	return p;
}

int getindex(char *choice) {
	char *choices[16] = {"grade", "gradeall", "cgpa", "sgpa", "failed", "topsem", "topsub", "topnsub","stdev", "exit" };
	for (int i = 0; i < 10; i++)
		if (strcmp(choices[i], choice) == 0)
				return i;
	return -1;
}

void gradeall(student *p, int no_of_subjects)
{
	for (int i = 0; i < no_of_stu; i++) {
		printf("%ld, ", p[i].mis);
		for (int j = 0; j < no_of_subjects; j++) {
			printf("%s, ", p[i].p[j].grade);
		}
		printf("\n");
	}
}

int find_student(student *p, long mis)
{
	int i = 0;

	while (i < no_of_stu) {
		if (mis == p[i].mis) {
			return i;
		}
		i++;
	}
	return -1;
}

void grade_mis(student *p, int no_of_subjects, long mis, subject *p1)
{
	int j = 0, indx = 0;
	char sub[64];
	scanf("%s", sub);
	indx = find_student(p, mis);
	if (indx == -1) {
		printf("Record not found\n");
		return;	
	}
	while (j < no_of_subjects) {
		if (strcmp(sub, p1[j].name) == 0) {
			printf("%s\n", p[indx].p[j].grade);
			return;
		}
		j++;
	}
	if (j == no_of_subjects) {
		printf("subject record not found\n");
		return;
	}
}

void cgpa(student *p, int no_of_sub, long *mis, subject *p1)
{
	double cgpa = 0.0;
	int i = 0, x = 0, sum_of_crs = 0, index = 0;

	if ((x = scanf("%ld", mis)) == -1) {
		printf("Enter valid MIS\n");
		return;
	}
	index = find_student(p, *mis);
	if (index == -1) {
		printf("Mis not Found\n");
		return;
	}
	while (i < no_of_sub) {
		cgpa += (p1[i].credits * p[index].p[i].points);
		sum_of_crs += p1[i].credits;
		i++;
	}
	printf("%.2lf\n", (cgpa /(float)sum_of_crs));
}

void failed (student *p, int no_of_sub, long *mis, subject *p1)
{
	int i = 0, x = 0, index = 0;
	if ((x = scanf("%ld", mis)) < 1) {
		printf("Enter Valid MIS\n");
		return;
	}
	index = find_student(p, *mis);
	if (index == -1) {
		printf("Mis not Found\n");
		return;
	}
	while (i < no_of_sub) {
		if (strcmp(p[index].p[i].grade, "FF") == 0) {
			printf("%s\n",p1[i].name);
		}
		i++;
	}	
}

void sgpa(student *p, long *mis, int no_of_sub, subject *p1)
{

	int i = 0, x = 0, sum_of_crs = 0, sem = 0, index = 0;
	double sgpa = 0;
	if ((x = scanf("%ld", mis)) == -1) {
		printf("Enter valid MIS\n");
		return;
	}
	scanf("%d", &sem);
	
	index = find_student(p, *mis);
	if (index == -1) {
		printf("Mis not Found\n");
		return;
	}
	while (i < no_of_sub) {
		if (p1[i].semester == sem) {
			sgpa += (p[index].p[i].points) * (p1[i].credits);			
			sum_of_crs += p1[i].credits;
		}
		i++;
	}
	printf("sgpa = %.2lf\n", sgpa / sum_of_crs);
}

void topsem(student *p, int no_of_sub, subject *p1)
{
	int indx_of_sub = 0, j = 0, i, max_indx = 0, sem;
	float max = 0;

	if (scanf("%d", &sem) < 1) {
		printf("please enter semester\n");
		return;
	}
	for (i = 0; i < no_of_sub; i++) {
		if (p1[i].semester == sem) {
			j = 0;
			max = 0;
			indx_of_sub = i;
			while (j < no_of_stu) {
				if (p[j].p[i].marks > max) {
					max_indx = j;
					max = p[j].p[i].marks;
				}
				j++;
			}
			printf("%ld %s\n", p[max_indx].mis, p1[indx_of_sub].name);
		}
	}
}

int find_subject(subject *p, int no_of_sub, char *subject)
{
	int i = 0;
	while (i < no_of_sub) {
		if (strcmp(p[i].name, subject) == 0) {
			return i;
		}
		i++;
	}
	return -1;
}

void topsub(student *p, int no_of_sub, subject *p1)
{
	int i = 0, indx = 0, max_indx = 0;
	char subject[32];
	scanf("%s", subject);
	indx = find_subject(p1, no_of_sub, subject);
	if (indx == -1) {
		printf("Subject not found\n");
		return;
	}
	while (i < no_of_stu) {
		if (p[i].p[indx].marks > p[max_indx].p[indx].marks) {
			max_indx = i;
		}
		i++;
	}
	printf("%ld\n", p[max_indx].mis);
}

void bubblesort(student a[], int indx, int no_of_toppers) {
	int i, j, count = 0;
	student t;

	for(j = 0; j < no_of_stu - 1; j++) {
		i = 0;
		while(i < no_of_stu - j - 1) {
			if(a[i].p[indx].marks > a[i + 1].p[indx].marks) {
				t = a[i];
				a[i] =a[i + 1];
				a[i + 1] = t;
			}
			i++;
		}
		count++;
		if(count == no_of_toppers)	
			return;
	}
}

void topnsub (student *p, subject *p1, int no_of_sub)
{
	int no_top_stu, indx, i = 0;
	char sub[64];

	if (scanf("%s %d", sub, &no_top_stu) < 2) {
		printf("There is error in input\n");
		return;
	}
	indx = find_subject(p1, no_of_sub, sub);
	if (indx == -1) {
		printf("Subject not found\n");
		return;
	}
	if (no_of_stu < no_top_stu) {
		printf("no. of Records is less than n you demanded\n");
		return;
	}
	/*sort upto n students*/
	bubblesort(p, indx, no_top_stu);
	i = no_of_stu - no_top_stu;
	/* print the students in assending order */
	while (i < no_of_stu) {
		printf("%ld, %.2lf\n", p[i].mis, p[i].p[indx].marks);
		i++;
	}
}

double find_mean(student *p, int indx)
{
	double mean;
	int i = 0;
	while (i < no_of_stu) {
		mean += p[i].p[indx].marks;
		i++;
	}
	return (mean / no_of_stu);
}

double find_deviations(student *p, int indx, double mean)
{
	int i = 0;
	double dev = 0, res = 0;
	while (i < no_of_stu) {
		res = p[i].p[indx].marks - mean;
		dev += pow(res, 2);
		i++;
	}
	return dev;
}

void stdev(student *p, subject *p1, int no_of_sub)
{
	int indx;
	double deviations, stdev, mean;
	char sub[64];
	if (scanf("%s", sub) < 1) {
		printf("There is error in input\n");
		return;
	}
	//find the sub
	indx = find_subject(p1, no_of_sub, sub);
	if (indx == -1) {
		printf("Subject not found\n");
		return;
	}
	/*find mean x = (marks1 + .....)/n  error free*/
	mean = find_mean(p, indx);
	/* find deviations summation(xi - x)2 */ 
	deviations = find_deviations(p, indx, mean);
	/* find square of de*/
	stdev = sqrt((deviations / (no_of_stu)));
	printf("stdev = %.2lf\n", stdev);
} 

void input(subject *p, grades *p1, student *p2, int no_of_sub)
{
	int index = 0, x = 0;
	long mis = 0;
	char str1[64], str2[4];
	while (1) {
		printf(">");
		x = scanf("%s", str1);
		if (x == -1) {
			return;
		}
		index = getindex(str1);
		if (index == 0) {
			if (scanf("%ld", &mis) == 0) {
				scanf("%s", str2);
				strcat(str1, str2);
				index = getindex(str1);
			}
		}

		switch (index) {
			case 0 :
				grade_mis(p2, no_of_sub, mis, p);
				break;
			case 1 :
				gradeall(p2, no_of_sub);
				break;
			case 2 :
				cgpa(p2, no_of_sub, &mis, p);
				break;
			case 3 :
				sgpa(p2,  &mis, no_of_sub, p);
				break;
			case 4 :
				failed(p2, no_of_sub, &mis, p);
				break;
			case 5 :
				topsem(p2, no_of_sub, p);
				break;
			case 6 :
				topsub(p2, no_of_sub,  p);
				break;
			case 7 :
				topnsub (p2, p, no_of_sub);
				break;
			case 8 :
				stdev(p2, p, no_of_sub);
				break;
			case 9 :
				printf("Thanks for using this programme.\n");
				return;
			default :
				printf("Error\n");
				break;
		}
		//remove the part of previous str1[]
		memset(str1, 0, strlen(str1));
	}
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
	memset(t, 0, strlen(t));
	/*copying the data using *p */
	p = copying_data(p, t);
	/* converting it to integer */
	s->credits = atoi(t);
	/* clearing the datA to avoid from overwriting in t */
	memset(t, 0, strlen(t));
	/* copying the data using *p */
	copying_data(p, t);
	/* converting and saving the into int */
	s->semester = atoi(t);
	/*again clearing the data */
	memset(t, 0, strlen(t));
	if (s->semester < 1 || s->credits < 1) {
		printf("Error in subjects.csv\n");
		exit(1);
	}
}

int readline(int fd, char *lines, int signal)
{
	int  i = 0, x = 0, req = 0, count = 0;
	char ch;
	if (signal == 1) {
		req = 2;
	} else if (signal == 2) {
		req = 6;
	} else {
		req = signal;
	}
	while ((x = read(fd, &ch, 1)) > 0 && ch != '\n') {
		lines[i] = ch;
		if (ch == ',') {
			count++;
		}
		if (count > req) {
			printf("Extra data detected in a file detected\n");
			exit(1);
		}
		i++;
	}
	lines[i] = '\0';
	if (x == 0) {
		return -1;
	}
	return i;
}

int read_sub_csv(int *fd, subject *p, int capacity1)
{
	int i = 0, x = 0;
	char lines[128];
	*fd = open("./subjects.csv", O_RDONLY);
	if (*fd == -1) {
		perror("Can't open the file\n");
		return errno;
	}
	while ((x = readline(*fd, lines, 1)) != -1) {
		/* This will read the struct after reading the lines*/
		if (x == 0)
			continue;
		readsubj_st(lines, &p[i]);
		i++;
		if (i >= capacity1) {
			capacity1 += 10;
			p = (subject *)realloc(p, capacity1 * sizeof(subject));
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

void read_grade_csv_into_st(int fd, char *lines, grades *p, int len)
{
	char *t, *pt, token[64];
	t = token;
	int i = 1;
	/*copying data until 1st ',' */
	pt = copying_data(lines, t);
	p->grades[0] = atof(t);
	/*converting to double and store it */
	while (i < 7) {
		pt = copying_data(pt, t);
		p->grades[i] = atof(t);
		if (p->grades[i] < 0 || p->grades[i] > 100) {
			printf("Error in the grades found can't be negative or greater than 100\n");
			exit(1);
		} else if (p->grades[i] <= p->grades[i - 1]) {
			printf("Error in the grades.\n");
			exit(1);
		}
		memset(t, 0, strlen(token));
		i++;
	}
}

void read_grade_csv(int *fd, grades *p, int len)
{
	int i = 0, x;
	*fd = open("./grades.csv", O_RDONLY);
	if (*fd == -1){
		perror("Can't open the file \n");
		return;
	}
	char lines[64];
	/*reading of file into struct */
	while ((x = readline(*fd, lines, 2)) != -1) {
		//check for blank line
		if (x == 0)
			continue;
		read_grade_csv_into_st(*fd, lines, &p[i], len);
		memset(lines, 0, strlen(lines));
		i++;
	}
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
	memset(t, 0, strlen(t));
	/*copying the data using *p */
	while (i < len) {
		/* copying the data and storing it into */
		pt = copying_data(pt, t);
		/* converting it to double */
		(*p).p[i].marks = atof(t);
		if ((*p).p[i].marks < 0 || (*p).p[i].marks > 100) {
			printf("Error in the marks found can't be negative or greater than 100\n");
			exit(1);
		}
		i++;
		/* clearing the datA to avoid from overwriting in t */
		memset(t, 0, strlen(t));
	}
}

void assign_grades_and_points(student *p, grades *p1, int no_of_subject)
{
	int j = 6, points = 10, check = 0;
	for (int i = 0; i < no_of_subject; i++) {
		points = 10;
		j = 6;
		check = 0;
		while (j >= 0) {
			if (p->p[i].marks > p1[i].grades[j]) {
				strcpy(p->p[i].grade, grade[j + 1]);
				p->p[i].points = points;
				check = 1;
				break;
			}
			j--;
			points--;
		}
		if (check == 0) {
			strcpy(p->p[i].grade, "FF");
			p->p[i].points = 0.0;
		}
	}
}

student *read_marks_csv(int *fd, int len, grades *p1, subject *p2)
{
	*fd = open("./marks.csv", O_RDONLY);
	if (*fd == -1){
		perror("Can't open the file \n");
		exit(1);
	}
	/*reading of file into struct */
	student *p;
	char lines[158];
	int i = 0, x;
	p = (student *)malloc(sizeof(student) * capacity);

	while ((x = readline(*fd, lines, len)) != -1) {
		/* Check for blank line*/
		if (x == 0) 
			continue;
		p[i].p = (no_of_sub *)malloc(sizeof(no_of_sub) * len);
		/*read marks of this */
		read_marks_Into_St(&p[i], len, *fd, lines);
		/* Assign grades and points */
		assign_grades_and_points(&p[i], p1, len);
		i++;
		if (i >= capacity) {
			capacity += 100;
			p = (student *)realloc(p, sizeof(student) * capacity);
			if (p == NULL) {
				perror("Failed to reallocate memory\n");
				close(*fd);
				exit(1);
			}
		}
	}
	no_of_stu = i;
	return p;
}

int main(void)
{
	int fd, len = 0, i = 0, capacity1 = 5;
	/* Read csv file into subjects arr*/
	subject *p = (subject *)malloc(sizeof(subject) * capacity1);
	len = read_sub_csv(&fd, p, capacity1);
	/* Read grades.csv into grades struct */
	grades *p1 = (grades *)malloc(sizeof(grades) * len);
	read_grade_csv(&fd, p1, len);
	/* Read marks.csv into a large struct and assign grades, points too... */
	student *p2 = read_marks_csv(&fd, len, p1, p);
	/*Taking input or commands */
	input(p, p1, p2, len);
	while (i < no_of_stu) {
		free(p2[i].p);
		i++;
	}
	free(p2);
	free(p1);
	free(p);
	return 0;
}
