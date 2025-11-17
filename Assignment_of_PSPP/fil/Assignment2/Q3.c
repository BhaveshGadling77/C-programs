#include <stdio.h>
int main()
{ 
float principal,rate,year, interest;
scanf("%f %f %f",&principal,&rate,&year);
 interest= (principal/100)*rate*year+ principal;
printf("%f", interest);
return 0;
}
