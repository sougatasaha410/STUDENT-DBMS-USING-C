#include <stdio.h>

#include <string.h>

// Structure to store student data
struct student {
    char name[50];
    int roll;
    int marks[5];
    char grade;
} s[100];

// Function to calculate grade based on marks
void calculateGrade(int marks[], char *grade) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += marks[i];
    }

    int average = total / 5;

    if (average >= 90) {
        *grade = 'A';
    } else if (average >= 80) {
        *grade = 'B';
    } else if (average >= 70) {
        *grade = 'C';
    } else if (average >= 60) {
        *grade = 'D';
    } else {
        *grade = 'F';
    }
}

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Reading input data for each student
    for (i = 0; i < n; i++) {
       printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]s", s[i].name);

        printf("Enter roll number of student %d: ", i + 1);
        scanf("%d", &s[i].roll);

        printf("Enter marks of student %d in 5 subjects: ", i + 1);
        for (int j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
        }

        // Calculating grade based on marks
        calculateGrade(s[i].marks, &s[i].grade);
    }

    // Saving data to notepad file
    FILE *fp = fopen("student_data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Writing data to notepad file
    fprintf(fp, "Name\t\t\tRoll\tMarks\t\t\t\Grade\n");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s\t%d\t%d %d %d %d %d\t%c\n", s[i].name, s[i].roll, s[i].marks[0], s[i].marks[1], s[i].marks[2], s[i].marks[3], s[i].marks[4], s[i].grade);
    }

    printf("Data saved to notepad file.\n");

    // Closing notepad file
    if (fclose(fp) != 0) {
        printf("Error closing file.\n");
        return 1;
    } 
    return 0;
}

