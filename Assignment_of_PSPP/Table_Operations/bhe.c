#include <stdio.h>
#include <limits.h>
int main() {
int x = 0;
char ch = 'A';
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            printf(" %c ", ch);
            ch++;

        }
       
        printf("\n");
    }
}