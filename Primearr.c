#include <stdio.h>
#include <math.h>

int prime(int num)
{
    int i = num;
    while (i <= sqrt(num))
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
    int n, i = 2, i1 = 0, x = 0, primearr[256], len = 0, j = 0;
    printf("Enter num which num prime factor you want :- ");
    scanf("%d", &n);
    while (i <= n)
    {
        x = prime(i);
        if (x == 1)
        {
            if (n % i == 0)
            {
                primearr[j++] = i;
                n = n / 2;
                len++;
            }
            else if (n % i != 0)
                i++;
        }
    }
    while (i1 < len)
    {
        printf("%d \n", primearr[i1]);
    }

    return 0;
}