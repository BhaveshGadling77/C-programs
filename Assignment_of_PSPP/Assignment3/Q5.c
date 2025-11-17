#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    if (num > 0 && num <= 31)
        printf("%d 1", num);
    else if (num > 31 && num <= 59)
        printf("%d 2", num - 31);
    else if (num > 59 && num <= 90)
        printf("%d 3", num - 59);
    else if (num > 90 && num <= 120)
        printf("%d 4", num - 90);
    else if (num > 120 && num <= 151)
        printf("%d 5", num - 120);
    else if (num > 151 && num <= 181)
        printf("%d 6", num - 151);
    else if (num > 181 && num <= 212)
        printf("%d 7", num - 181);
    else if (num > 212 && num <= 243)
        printf("%d 8", num - 212);
    else if (num > 243 && num <= 273)
        printf("%d 9", num - 243);
    else if (num > 273 && num <= 304)
        printf("%d 10", num - 273);
    else if (num > 304 && num <= 334)
        printf("%d 11", num - 304);
    else if (num > 334 && num <= 365)
        printf("%d 12", num - 334);
    else
        printf("invalid");

    return 0;
}
