#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n integers using malloc
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the array
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the array
    printf("You entered: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Resize the array using realloc
    printf("Enter the new size of the array: ");
    scanf("%d", &n);
    arr = (int *)realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Initialize new elements if the array grew
    for (i = 0; i < n; i++) {
        if (arr[i] == 0) {
            printf("Enter value for index %d: ", i);
            scanf("%d", &arr[i]);
        }
    }

    // Print the resized array
    printf("The resized array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
