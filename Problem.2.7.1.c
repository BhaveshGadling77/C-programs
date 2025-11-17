#include <stdio.h>
#include <math.h>
#include <string.h>

double sqroot(double m, double error)
{
    // Assertions: m > 0
    if (m <= 0)
    {
        printf("Error: m must be greater than 0.\n");
        return -1;
    }

    double g1, g2;
    g1 = m / 2; // Initial estimate
    g2 = m / 2; // Initial estimate
    char hell[] = "Hello";
   int i =  strlen(hell);
   printf("%d\n", i);
   do
   {
       g1 = g2;
       g2 = (g1 + m / g1) / 2; // Update estimate
    } while (fabs(g1 - g2) >= error); // Repeat until error is within tolerance

    return g2; // Return the square root estimate
}

int main()
{
    double number, tolerance, result;

    printf("Enter the number to find the square root of: ");
    scanf("%lf", &number);
    printf("Enter the tolerance (error margin): ");
    scanf("%lf", &tolerance);

    result = sqroot(number, tolerance);
    if (result != -1)
    {
        printf("The square root of %.2f is approximately %.5f\n", number, result);
    }

    return 0;
}