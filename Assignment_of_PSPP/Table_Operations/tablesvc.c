#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_STUDENTS 1024
#define MAX_SUBJECTS 10
#define BUFFER_SIZE 1024

typedef struct {
    char name[128];
    long long id;
    int admissionYear;
    char subjects[MAX_SUBJECTS][30];
    int semester[MAX_SUBJECTS];
    float marks[MAX_SUBJECTS];
    int credits[MAX_SUBJECTS];
    int grades[MAX_SUBJECTS];
    float cgpa;
} StudentRecord;

int loadStudentData(const char *filename, StudentRecord students[], int maxRecords);
void displayStudentRecords(StudentRecord students[], int count);
void showStudentMarks(StudentRecord students[], int count, const char *studentName, const char *subject);
float computeSubjectAverage(StudentRecord students[], int count, const char *subject);
float computeCGPA(StudentRecord student);
void printMenu();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    StudentRecord students[MAX_STUDENTS];
    int totalStudents = loadStudentData(argv[1], students, MAX_STUDENTS);

    if (totalStudents < 0) {
        printf("Error: Unable to load data from file.\n");
        return 1;
    }

    printMenu();
    char command[BUFFER_SIZE];

    while (1) {
        printf("\nEnter a command: ");
        read(STDIN_FILENO, command, BUFFER_SIZE);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "print") == 0) {
            displayStudentRecords(students, totalStudents);
        } else if (strncmp(command, "marks", 5) == 0) {
            char studentName[128], subject[50];
            sscanf(command, "marks %s %s", studentName, subject);
            showStudentMarks(students, totalStudents, studentName, subject);
        } else if (strncmp(command, "avg", 3) == 0) {
            char subject[50];
            sscanf(command, "avg %s", subject);
            computeSubjectAverage(students, totalStudents, subject);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}

int loadStudentData(const char *filename, StudentRecord students[], int maxRecords) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("File open failed");
        return -1;
    }

    char buffer[BUFFER_SIZE * MAX_STUDENTS];
    int bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead <= 0) {
        close(fd);
        return -1;
    }
    buffer[bytesRead] = '\0';

    close(fd);

    char *line = strtok(buffer, "\n");
    line = strtok(NULL, "\n");
    int count = 0;

    while (line && count < maxRecords) {
        char *token = strtok(line, ",");
        students[count].id = atoll(token);

        token = strtok(NULL, ",");
        strcpy(students[count].name, token);

        token = strtok(NULL, ",");
        students[count].admissionYear = atoi(token);

        for (int i = 0; i < MAX_SUBJECTS; i++) {
            token = strtok(NULL, ",");
            if (!token) break;
            strcpy(students[count].subjects[i], token);

            token = strtok(NULL, ",");
            students[count].credits[i] = atoi(token);

            token = strtok(NULL, ",");
            students[count].marks[i] = atof(token);

            token = strtok(NULL, ",");
            students[count].grades[i] = atoi(token);

            token = strtok(NULL, ",");
            students[count].semester[i] = atoi(token);
        }
        students[count].cgpa = computeCGPA(students[count]);
        count++;
        line = strtok(NULL, "\n");
    }

    return count;
}

void displayStudentRecords(StudentRecord students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%lld, %s, %d, CGPA: %.2f\n",
               students[i].id,
               students[i].name,
               students[i].admissionYear,
               students[i].cgpa);
    }
}

void showStudentMarks(StudentRecord students[], int count, const char *studentName, const char *subject) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, studentName) == 0) {
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                if (strcmp(students[i].subjects[j], subject) == 0) {
                    printf("%s scored %.2f in %s\n", studentName, students[i].marks[j], subject);
                    return;
                }
            }
        }
    }
    printf("Student or subject not found.\n");
}

float computeSubjectAverage(StudentRecord students[], int count, const char *subject) {
    float totalMarks = 0.0;
    int numStudents = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            if (strcmp(students[i].subjects[j], subject) == 0) {
                totalMarks += students[i].marks[j];
                numStudents++;
                break;
            }
        }
    }

    if (numStudents == 0) {
        printf("No students found for subject: %s\n", subject);
        return 0.0;
    }

    float avg = totalMarks / numStudents;
    printf("Average marks in %s: %.2f\n", subject, avg);
    return avg;
}

float computeCGPA(StudentRecord student) {
    float totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < MAX_SUBJECTS; i++) {
        totalGradePoints += student.grades[i] * student.credits[i];
        totalCredits += student.credits[i];
    }

    return (totalCredits == 0) ? 0.0 : (totalGradePoints / totalCredits);
}

void printMenu() {
    printf("\nCommands:\n");
    printf("print - Show all student records\n");
    printf("marks <name> <subject> - Show student marks\n");
    printf("avg <subject> - Show average marks for subject\n");
    printf("exit - Quit the program\n");
}
