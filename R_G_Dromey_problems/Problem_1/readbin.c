#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
typedef struct transaction{
	double amount;
	time_t time;
	unsigned int from_id;
	unsigned int to_id;
	char location[32];
} transaction;

void strcpy_custom(char *str, char *time, int st, int end)
{
	int i = 0;

	while (st < end)
		str[i++] = time[st++];
	str[i] = '\0';
}

void print_date(char *str, char *time)
{
	char ch;
	int i = 8, num_indx = 0;

	while (i < strlen(time) - 14) {
		ch = time[i++];
		if (ch - '0' <= '9' - '0')
			str[num_indx++] = ch;
	}
}
/*
void print_formated_time(char *time)
{
	char str[10];

	print_date(str, time);
	int i = atoi(str), min = 0;

	//print DD
	if (i < 10)
		printf("0%d", i);
	else
		printf("%d", i);
	//print MM
	strcpy_custom(str, time, 4, 7);
	if (strcmp(str, "Jan") == 0)
		printf(":01:");
	else if (strcmp(str, "Feb") == 0)
		printf(":02:");
	else if (strcmp(str, "Mar") == 0)
		printf(":03:");
	else if (strcmp(str, "Apr") == 0)
		printf(":04:");
	else if (strcmp(str, "May") == 0)
		printf(":05:");
	else if (strcmp(str, "Jun") == 0)
		printf(":06:");
	else if (strcmp(str, "Jul") == 0)
		printf(":07:");
	else if (strcmp(str, "Aug") == 0)
		printf(":08:");
	else if (strcmp(str, "Sep") == 0)
		printf(":09:");
	else if (strcmp(str, "Oct") == 0)
		printf(":10:");
	else if (strcmp(str, "Nov") == 0)
		printf(":11:");
	else
		printf(":12:");
	//print YYYY
	strcpy_custom(str, time, 20, 24);
	printf("%s ", str);
	strcpy_custom(str, time, 11, 13);
	int p = atoi(str);
	//printf("time = %s\n", time);
	strcpy_custom(str, time, 14, 16);
	min = atoi(str);
//	min = min + 30;
	/*if (min > 60) {
		min = min - 60;
		p = p + 1;
	} 
	if (p < 10)
		printf("0%d:", p);
	else
		printf("%d:", p);
	//printf("p = %d\n", p);
	if (min < 10) {
		printf("0%d:", min);
	} else {
		printf("%d:", min);
	}
	//strcpy_custom(str, time)
	if (p < 10)
		printf("0%d", p);
	else
		printf("%d", p);
	strcpy_custom(str, time, 13, 19);
	strcpy_custom(str, time, 17, 19);
	printf("%s", str);
}
*/
void print_formated_time(time_t *tr_time)
{
	char buffer[32];
	struct tm *gmt = gmtime(tr_time);
	strftime(buffer, sizeof(buffer), "%d:%m:%Y %H:%M:%S", gmt);
	printf("%s", buffer);
}

void print_min_record(int min, transaction p[])
{
	print_formated_time(&p[min].time);
	printf(" %s\n", p[min].location);
}

int find_min_amount_record(transaction p[], int n)
{
	int i = 0;
	int min_amount_indx = 0;

	while (i < n) {
		if (p[i].amount < p[min_amount_indx].amount)
			min_amount_indx = i;
		i++;
	}
	return min_amount_indx;
}

transaction *read_records(int fd, char argv[], int n)
{
	int i = 0;
	transaction *p = (transaction *)malloc(sizeof(transaction) * n);

	while (i < n) {
		read(fd, &p[i], sizeof(transaction));
		i++;	
	}
	return p;
}

int main(int argc, char *argv[])
{
	int fd, min;
	int n = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 1) {
		printf("can't open the file\n");
		return 0;
	}
	//read the n which is no. of records
	read(fd, &n, sizeof(int));
	//read records
	transaction *p = read_records(fd, argv[1], n);
	//find record on minimum AMount
	min = find_min_amount_record(p, n);
	//printf("%.2lf\n", p[min].amount);
	//print time that in DD:MM:YYYY HH:MM:SS this  form
	print_min_record(min, p);
	//printf("amount = %lf\n time = %lf\n", n, tr.amount );
	return 0;
}
