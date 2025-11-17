#include <stdio.h>
int main()
{ 
float price, discount,final_price;
scanf("%f %f",&price,&discount);
float discount_in_rs= price*discount/100;
final_price = price -discount_in_rs;
printf("%.2f",final_price);
return 0;
}
