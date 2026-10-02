#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5

typedef struct {
    int roll_number;
    char name[50];
    int marks[MAX_SUBJECTS];
    float percentage;
    char grade;
} Student;

char getGrade(float percentage) {
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 80)
        return 'B';
    else if (percentage >= 70)
        return 'C';
    else if (percentage >= 60)
        return 'D';
    else if (percentage >= 50)
        return 'E';
    else
        return 'F';
}

float calculatePercentage(int *marks, int num_subjects) {
    int total = 0;
    for (int i = 0; i < num_subjects; i++) {
        total += marks[i];
    }
    return (total * 100.0) / (num_subjects * 100);
}

void inputStudentData(Student *students, int num_students, int num_subjects) {
    printf("\n========== INPUT STUDENT DATA ==========\n");
    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll_number);
        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter marks for %d subjects (0-100):\n", num_subjects);
        for (int j = 0; j < num_subjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }

        students[i].percentage = calculatePercentage(students[i].marks, num_subjects);
        students[i].grade = getGrade(students[i].percentage);
    }
}

void displayStudentReport(Student *student, int num_subjects) {
    printf("\n%-15s %-20s %-12s\n", "Roll Number", "Name", "Percentage");
    printf("%-15d %-20s %-12.2f%%\n", student->roll_number, student->name, student->percentage);

    printf("\nSubject-wise Marks:\n");
    for (int i = 0; i < num_subjects; i++) {
        printf("Subject %d: %d/100\n", i + 1, student->marks[i]);
    }

    printf("Grade: %c\n", student->grade);
}

void displayAllStudentsReport(Student *students, int num_students, int num_subjects) {
    printf("\n========== STUDENT MARKS REPORT ==========\n");
    printf("%-15s %-20s %-15s %-10s\n", "Roll Number", "Name", "Percentage", "Grade");
    printf("========================================\n");

    for (int i = 0; i < num_students; i++) {
        printf("%-15d %-20s %-15.2f%% %-10c\n",
               students[i].roll_number,
               students[i].name,
               students[i].percentage,
               students[i].grade);
    }
}

void displayDetailedReport(Student *students, int num_students, int num_subjects) {
    printf("\n========== DETAILED STUDENT REPORT ==========\n");

    for (int i = 0; i < num_students; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        displayStudentReport(&students[i], num_subjects);
    }
}

void displayStatistics(Student *students, int num_students) {
    float highest = students[0].percentage;
    float lowest = students[0].percentage;
    float average = 0;
    int passCount = 0;
    int failCount = 0;

    for (int i = 0; i < num_students; i++) {
        average += students[i].percentage;

        if (students[i].percentage > highest)
            highest = students[i].percentage;

        if (students[i].percentage < lowest)
            lowest = students[i].percentage;

        if (students[i].percentage >= 50)
            passCount++;
        else
            failCount++;
    }

    average /= num_students;

    printf("\n========== CLASS STATISTICS ==========\n");
    printf("Highest Percentage: %.2f%%\n", highest);
    printf("Lowest Percentage: %.2f%%\n", lowest);
    printf("Average Percentage: %.2f%%\n", average);
    printf("Total Students Passed: %d\n", passCount);
    printf("Total Students Failed: %d\n", failCount);
    printf("Pass Percentage: %.2f%%\n", (passCount * 100.0) / num_students);
}

void searchStudent(Student *students, int num_students, int num_subjects) {
    int roll;
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll) {
            printf("\n========== STUDENT FOUND ==========\n");
            displayStudentReport(&students[i], num_subjects);
            return;
        }
    }

    printf("\nStudent not found!\n");
}

void displayMenu() {
    printf("\n========== STUDENT MARKS REPORT SYSTEM ==========\n");
    printf("1. Display All Students Report\n");
    printf("2. Display Detailed Student Report\n");
    printf("3. Display Class Statistics\n");
    printf("4. Search Student by Roll Number\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students, num_subjects;
    int choice;

    printf("========== STUDENT MARKS REPORT SYSTEM ==========\n");
    printf("Enter number of students: ");
    scanf("%d", &num_students);

    if (num_students <= 0 || num_students > MAX_STUDENTS) {
        printf("Invalid number of students!\n");
        return 1;
    }

    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    scanf("%d", &num_subjects);

    if (num_subjects <= 0 || num_subjects > MAX_SUBJECTS) {
        printf("Invalid number of subjects!\n");
        return 1;
    }

    inputStudentData(students, num_students, num_subjects);

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAllStudentsReport(students, num_students, num_subjects);
                break;
            case 2:
                displayDetailedReport(students, num_students, num_subjects);
                break;
            case 3:
                displayStatistics(students, num_students);
                break;
            case 4:
                searchStudent(students, num_students, num_subjects);
                break;
            case 5:
                printf("\nThank you for using Student Marks Report System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
