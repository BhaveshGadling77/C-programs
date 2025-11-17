#include <stdio.h>
#include <math.h>
int isprime(int num)
{
    int i = 2;
    while (i < sqrt(num))
    {
        if (num % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int main()
{
    int n, i = 2, x = 0;
    while (i < n)
    {
        x = isprime(i);
        if (x == 1)
        {
            printf("%d", i);
        }
        i++;
    }
    return 0;
}
