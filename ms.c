#include <stdio.h>
void shellsort(int v[], int n)
{
int gap, i, j, temp;
for (gap = n/2; gap> 0; gap /= 2)
for (i = gap; i < n; i++)
for (j = i-gap; j >= 0 && v[j]>v[j+gap]; j-=gap) {
temp = v[ j];
v[j] = v[j+gap];
v[j+gap] = temp;
}
}
int main(){
int i = 8;
int v[] = {1, 1, 2,6,1 ,1, 3,3};
shellsort(v, i);
for(int i = 0; i < 8; i++){
printf("%d\n", v[i]);
}
}
