#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

typedef struct transaction {
	double amount;
	time_t time;
	unsigned int from_id;
	unsigned int to_id;
	char location[32];
} transaction;

void print_formatted_time_gmt(time_t transaction_time) {
	struct tm *gmt_time = gmtime(&transaction_time);
	char buffer[32];

	strftime(buffer, sizeof(buffer), "%d:%m:%Y %H:%M:%S", gmt_time);
	printf("%s", buffer);
}

void print_min_record(int min, transaction p[]) {
	
	print_formatted_time_gmt(p[min].time);
	printf("\n");
}

int find_min_amount_record(transaction p[], int n) {
	int min_amount_index = 0;
	for (int i = 1; i < n; i++) {
		if (p[i].amount < p[min_amount_index].amount) {
	            min_amount_index = i;
		}
	}
	return min_amount_index;
}

transaction *read_records(int fd, int n) {
	transaction *p = (transaction *)malloc(sizeof(transaction) * n);
	if (p == NULL) {
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++) {
		if (read(fd, &p[i], sizeof(transaction)) != sizeof(transaction)) {
			perror("Failed to read record");
			free(p);
			exit(1);
	}
	}
    return p;
}

int main() {
	int fd, min, n;
	char filename[64];
	scanf("%s", filename);

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		perror("Error opening file\n");
		return 1;
    	}
	// Read the number of records
	if (read(fd, &n, sizeof(int)) != sizeof(int)) {
		perror("Failed to read number of records\n");
		close(fd);
		return 0;
	}

	// Read records
	transaction *p = read_records(fd, n);

	// Find record with minimum amount
	min = find_min_amount_record(p, n);

	// Print the location and formatted time of the transaction with the minimum amount
	print_min_record(min, p);

	// Clean up
	free(p);
	close(fd);
	return 0;
}
