#include <stdio.h>
#define SAVINGS 1
#define CURRENT 2
#include <stdlib.h>
typedef struct account{
	int accid;
	char name[32]; 
	double amount;
       	int type; 
}acc;
void readchar(acc *p, int i, int check){
	int j = 0;

	if(check == 0){
	while(j < 32 &&((*(p[i]).name[j] = getchar()) != '\n'))
		j++;
	}
	else{	
		j = 0;
		while(putchar(p[i].name[j]) != '\0')
			j++;
	}
}
void reading(acc *p, int n){
	int i = 0, check = 0;

	while (i < n) {
		//reading accid
		if(check == 0){
		scanf("%d", &(*p[i]).accid);
		//reading name
		readchar(p, i, check);
		//read amount, type
		scanf("%ld %d", &(*p[i].amount), &(p[i].type));
		if(p[i].amount < 0)
			while ((scanf("%ld %d", &(p[i].amount), &(p[i].type))) != 2)
				;
	p++;	i++;} else {
			check = 1;
			p = 0;
			//printing accid
			printf("%d", p[i].accid);
			//printing name
			readchar(p, i, check);
			//printing amount, type
			printf("%lf %d", (p[i].amount), (p[i].type));
			p++;
			i++;
			}
	}
}
int main(){
	int n = 3;
	acc *p = (acc *)malloc(sizeof(acc) * n);
	reading(p, n);


	return 0;
}
