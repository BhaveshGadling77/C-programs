#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct transaction {
    double amount;
    time_t time;
    unsigned int from_id;
    unsigned int to_id;
    char location[32];
} transaction;

int main() {
    // Open a file for reading
    FILE *file = fopen("transactions.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    int i = 0;
i = 2;
printf("%d", i);


    // Read data into the transaction struct
    transaction trans;
    while (fscanf(file, "%lf %ld %u %u %31s\n", 
                   &trans.amount, 
                   &trans.time, 
                   &trans.from_id, 
                   &trans.to_id, 
                   trans.location) == 5) {
        // Print the transaction details
        printf("Amount: %.2f\n", trans.amount);
        printf("Time: %s", ctime(&trans.time));  // Convert time_t to human-readable format
        printf("From ID: %u\n", trans.from_id);
        printf("To ID: %u\n", trans.to_id);
        printf("Location: %s\n", trans.location);
        printf("\n");
    }

    fclose(file);  // Close the file
    return 0;
}

