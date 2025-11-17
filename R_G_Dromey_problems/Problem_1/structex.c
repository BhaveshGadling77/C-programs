#include <stdio.h>
#include <string.h>

struct course {
	char name[32];
	char course_id[16];
	int credits;
	int type;
	char category[16];
};

int PCC = 0, LC = 0, HSSC = 0, OE = 0, DE = 0, LLC = 0, lab_cr = 0, tut_cr = 0;
typedef struct course course;
course courses[100];

int getindex(char *str)
{
	if (strcmp(str, "PCC") == 0)
		return 1;
	else if (strcmp(str, "LC") == 0)
		return 2;
	else if (strcmp(str, "HSSC") == 0)
		return 3;
	else if (strcmp(str, "OE") == 0)
		return 4;
	else if (strcmp(str, "DE") == 0)
		return 5;
	else if (strcmp(str, "LLC") == 0)
		return 6;
	else
		return -1;
}

void sum(int i)
{
	
}

void read_seq(course *courses)
{
	int i = 0, sum_of_all_credits = 0, index = 0, sum_of_L_credits = 0; //sum_of_t_credits = 0;

	while (i < 100 && ((scanf("%s%s%d%d%s", courses[i].name,
					courses[i].course_id,
					&courses[i].credits,
					&courses[i].type,
					courses[i].category)) == 5)) {
		sum_of_all_credits += courses[i].credits;
		if (courses[i].type == 2) {
			sum_of_L_credits += courses[i].credits;
		}
		index = getindex(courses[i].category);
		switch (index) {
			case 1:
				PCC += courses[i].credits;
				break;
			case 2:
				LC += courses[i].credits;
				break;
			case 3:
				HSSC += courses[i].credits;
				break;
			case 4:
				OE += courses[i].credits;
				break;
			case 5:
				DE += courses[i].credits;
				break;
			case 6:
				LLC += courses[i].credits;
				break;
			default:
				break;
		}
	}
	printf("%d\n%d\n", sum_of_all_credits, sum_of_L_credits);
	printf("PCC %d\n", PCC);
	printf("HSSC %d\n", HSSC);
	printf("LL %d\n", LC);
	printf("LLC %d\n", LLC);
	printf("OE %d\n", OE);
	printf("DE %d\n", DE);
}

int main()
{
	read_seq(courses);
	return 0;
}
