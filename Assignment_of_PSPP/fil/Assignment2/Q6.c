#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0) {
        printf("can't find roots\n");
        return 1;
    }
    float discriminant = (b * b) -(4 * a * c);

    if (discriminant < 0) {
        printf("can't find roots\n");
    } else {
        float root1, root2;
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("%.6f %.6f\n", root1, root2);
       
    }
    return 0;
}
