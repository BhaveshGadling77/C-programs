#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SAVINGS 1
#define CREDIT 2

typedef struct account {
	int accid;
	char name[32];
	double amount;
	int type;
} account;

int input(account *p)
{
	int i = 0, x, capacity = 100;
	x = scanf("%d%s%lf%d", &p[i].accid, p[i].name, &p[i].amount, &p[i].type);
	while ((x = scanf("%d%s%lf%d", &p[i].accid, p[i].name, &p[i].amount, &p[i].type)) == 4) {
		if (i > 100) {
			capacity += 100;
			p = (account * )realloc(p, sizeof(account) * i);
		}
		if (p[i].type > 2) {
			printf("Wrong account type\n");
			return -1;
		}
		i++;
	}
	return i;
}

int find_smallest(account *p, int len)
{
	int i = 1, min_indx = 0;
	while (i < len) {
		if ((strcmp(p[min_indx].name, p[i].name)) < 0) {
			min_indx = i;
		}
		i++;
	}
	return min_indx;
}
int main(void)
{
	int i = 0, indx;
	account *p = (account *)malloc(sizeof(account) * 100);
	//input 
	indx = input(p);
	if (indx == -1) {
		return 0;
	}
	//find smallest name
	indx = find_smallest(p, indx);
	//print it
	printf("minimum = %d %s %lf %d\n", p[indx].accid, p[indx].name, p[indx].amount, p[indx].type);

}
