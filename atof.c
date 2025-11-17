#include <stdio.h>

int fibu(int n) {
    if (n <= 1 || n == 2) {
        return 1;
    }
    return fibu(n - 1) + fibu(n - 2);
}
int main() {
    // Write C code here
  printf("fact = %d\n", fibu(6));
    return 0;
}
