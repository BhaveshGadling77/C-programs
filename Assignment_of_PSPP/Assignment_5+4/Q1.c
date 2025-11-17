#include <stdio.h>
int movetozero(int *a, int len){
	int temp = 0, i = 0, min = 0, add = 0;
	min = a[0];	
	while(i < len){
		if(min > a[i]){
			min = a[i];
			add = i;
		}
		i++;
	}
	temp = a[0];
	a[0] = min;
	min = a[add];
	a[add] = temp;
	return 0;
}

