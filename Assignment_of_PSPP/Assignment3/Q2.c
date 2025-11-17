#include <stdio.h>

int main() {
    int a, b, c, d, max, min, mid1, mid2;
    

    scanf("%d %d %d %d", &a, &b, &c, &d);

 max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    if (d > max)
        max = d;

    
    min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;

    if ((a != max) && (a != min)) 
        mid1 = a;
    else if ((b != max) && (b != min))
        mid1 = b;
    else if ((c != max) && (c != min))
        mid1 = c;
    else 
        mid1 = d;

    if ((a != max) && (a != min) && (a != mid1)) 
        mid2 = a;
    else if ((b != max) && (b != min) && (b != mid1))
        mid2 = b;
    else if ((c != max) && (c != min) && (c != mid1))
        mid2 = c;
    else 
        mid2 = d;
    printf("%d %d", mid1, mid2);

    return 0;
}
