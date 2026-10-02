#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    int roll_number;
    char name[MAX_NAME_LENGTH];
    int marks[MAX_SUBJECTS];
    float percentage;
    char grade;
} Student;

// Function to validate marks input
int validateMarks(int marks) {
    return (marks >= 0 && marks <= 100);
}

// Function to validate roll number
int validateRollNumber(int roll) {
    return (roll > 0);
}

// Function to get grade based on percentage
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

// Function to calculate percentage
float calculatePercentage(int *marks, int num_subjects) {
    int total = 0;
    for (int i = 0; i < num_subjects; i++) {
        total += marks[i];
    }
    return (total * 100.0) / (num_subjects * 100);
}

// Function to input student data with validation
void inputStudentData(Student *students, int num_students, int num_subjects) {
    printf("\n========== INPUT STUDENT DATA ==========\n");
    
    for (int i = 0; i < num_students; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        
        // Input and validate roll number
        int valid = 0;
        while (!valid) {
            printf("Enter Roll Number: ");
            if (scanf("%d", &students[i].roll_number) != 1) {
                while (getchar() != '\n');
                printf("Invalid input! Please enter a valid number.\n");
                continue;
            }
            
            if (validateRollNumber(students[i].roll_number)) {
                valid = 1;
            } else {
                printf("Invalid Roll Number! Please enter a positive number.\n");
            }
        }
        
        // Clear input buffer and input name
        while (getchar() != '\n');
        printf("Enter Name: ");
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        
        // Remove newline from name
        size_t len = strlen(students[i].name);
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0';
        }
        
        // Input marks with validation
        printf("Enter marks for %d subjects (0-100):\n", num_subjects);
        for (int j = 0; j < num_subjects; j++) {
            valid = 0;
            while (!valid) {
                printf("Subject %d: ", j + 1);
                if (scanf("%d", &students[i].marks[j]) != 1) {
                    while (getchar() != '\n');
                    printf("Invalid input! Please enter a valid number.\n");
                    continue;
                }
                
                if (validateMarks(students[i].marks[j])) {
                    valid = 1;
                } else {
                    printf("Invalid marks! Please enter marks between 0-100.\n");
                }
            }
        }
        
        // Calculate percentage and grade
        students[i].percentage = calculatePercentage(students[i].marks, num_subjects);
        students[i].grade = getGrade(students[i].percentage);
        
        printf("✓ Student %d added successfully!\n", i + 1);
    }
}

// Function to display individual student report
void displayStudentReport(Student *student, int num_subjects) {
    printf("\n+================================================+\n");
    printf("| STUDENT DETAILS                                 |\n");
    printf("+================================================+\n");
    printf("| Roll Number: %-37d |\n", student->roll_number);
    printf("| Name: %-47s |\n", student->name);
    printf("| Percentage: %-38.2f%% |\n", student->percentage);
    printf("| Grade: %-45c |\n", student->grade);
    printf("+================================================+\n");
    
    printf("\n| Subject-wise Marks:\n");
    for (int i = 0; i < num_subjects; i++) {
        printf("|   Subject %d: %d/100\n", i + 1, student->marks[i]);
    }
    printf("+================================================+\n");
}

// Function to display all students report
void displayAllStudentsReport(Student *students, int num_students, int num_subjects) {
    if (num_students == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    
    printf("\n+==================================================================+\n");
    printf("|                   STUDENT MARKS REPORT                          |\n");
    printf("+==================================================================+\n");
    printf("| %-12s | %-20s | %-15s | %-10s |\n", "Roll Number", "Name", "Percentage", "Grade");
    printf("+==================================================================+\n");
    
    for (int i = 0; i < num_students; i++) {
        printf("| %-12d | %-20s | %-14.2f%% | %-10c |\n",
               students[i].roll_number,
               students[i].name,
               students[i].percentage,
               students[i].grade);
    }
    printf("+==================================================================+\n");
}

// Function to display detailed report
void displayDetailedReport(Student *students, int num_students, int num_subjects) {
    if (num_students == 0) {
        printf("\nNo students to display!\n");
        return;
    }
    
    printf("\n========== DETAILED STUDENT REPORT ==========\n");
    
    for (int i = 0; i < num_students; i++) {
        displayStudentReport(&students[i], num_subjects);
    }
}

// Function to display class statistics
void displayStatistics(Student *students, int num_students) {
    if (num_students == 0) {
        printf("\nNo students available for statistics!\n");
        return;
    }
    
    float highest = students[0].percentage;
    float lowest = students[0].percentage;
    float average = 0;
    int passCount = 0;
    int failCount = 0;
    int aCount = 0, bCount = 0, cCount = 0, dCount = 0, eCount = 0, fCount = 0;
    
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
        
        // Count grades
        switch (students[i].grade) {
            case 'A': aCount++; break;
            case 'B': bCount++; break;
            case 'C': cCount++; break;
            case 'D': dCount++; break;
            case 'E': eCount++; break;
            case 'F': fCount++; break;
        }
    }
    
    average /= num_students;
    
    printf("\n+========== CLASS STATISTICS ==========+\n");
    printf("| Total Students: %-23d |\n", num_students);
    printf("| Highest Percentage: %-20.2f%% |\n", highest);
    printf("| Lowest Percentage: %-21.2f%% |\n", lowest);
    printf("| Average Percentage: %-20.2f%% |\n", average);
    printf("+======================================+\n");
    printf("| Pass Count: %-26d |\n", passCount);
    printf("| Fail Count: %-26d |\n", failCount);
    printf("| Pass Percentage: %-21.2f%% |\n", (passCount * 100.0) / num_students);
    printf("+======================================+\n");
    printf("| Grade Distribution:\n");
    printf("|   Grade A: %-28d |\n", aCount);
    printf("|   Grade B: %-28d |\n", bCount);
    printf("|   Grade C: %-28d |\n", cCount);
    printf("|   Grade D: %-28d |\n", dCount);
    printf("|   Grade E: %-28d |\n", eCount);
    printf("|   Grade F: %-28d |\n", fCount);
    printf("+======================================+\n");
}

// Function to search student by roll number
void searchStudent(Student *students, int num_students, int num_subjects) {
    if (num_students == 0) {
        printf("\nNo students available to search!\n");
        return;
    }
    
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
    
    printf("\n❌ Student with Roll Number %d not found!\n", roll);
}

// Function to sort students by percentage (descending)
void sortStudentsByPercentage(Student *students, int num_students) {
    if (num_students == 0) {
        printf("\nNo students to sort!\n");
        return;
    }
    
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (students[j].percentage < students[j + 1].percentage) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    printf("\n========== STUDENTS RANKED BY PERCENTAGE ==========\n");
    printf("%-8s | %-12s | %-20s | %-15s | %-10s\n", "Rank", "Roll No.", "Name", "Percentage", "Grade");
    printf("====================================================\n");
    
    for (int i = 0; i < num_students; i++) {
        printf("%-8d | %-12d | %-20s | %-14.2f%% | %-10c\n",
               i + 1,
               students[i].roll_number,
               students[i].name,
               students[i].percentage,
               students[i].grade);
    }
}

// Function to display menu
void displayMenu() {
    printf("\n+========== STUDENT MARKS REPORT SYSTEM ==========+\n");
    printf("|  1. Display All Students Report                 |\n");
    printf("|  2. Display Detailed Student Report             |\n");
    printf("|  3. Display Class Statistics                    |\n");
    printf("|  4. Search Student by Roll Number              |\n");
    printf("|  5. Display Students Ranked by Percentage       |\n");
    printf("|  6. Exit                                        |\n");
    printf("+================================================+\n");
    printf("Enter your choice (1-6): ");
}

// Main function
int main() {
    Student students[MAX_STUDENTS];
    int num_students, num_subjects;
    int choice;
    
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║  STUDENT MARKS REPORT SYSTEM (v2.0)   ║\n");
    printf("║  Max Students: 50                      ║\n");
    printf("║  Max Subjects: 5                       ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    printf("\nEnter number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &num_students);
    
    if (num_students <= 0 || num_students > MAX_STUDENTS) {
        printf("\n❌ Invalid number of students! Please enter a value between 1 and %d.\n", MAX_STUDENTS);
        return 1;
    }
    
    printf("Enter number of subjects (max %d): ", MAX_SUBJECTS);
    scanf("%d", &num_subjects);
    
    if (num_subjects <= 0 || num_subjects > MAX_SUBJECTS) {
        printf("\n❌ Invalid number of subjects! Please enter a value between 1 and %d.\n", MAX_SUBJECTS);
        return 1;
    }
    
    // Input student data
    inputStudentData(students, num_students, num_subjects);
    
    // Menu-driven system
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
                sortStudentsByPercentage(students, num_students);
                break;
            case 6:
                printf("\n╔════════════════════════════════════════╗\n");
                printf("║ Thank you for using the system!        ║\n");
                printf("║ Goodbye!                               ║\n");
                printf("╚════════════════════════════════════════╝\n\n");
                exit(0);
            default:
                printf("\n❌ Invalid choice! Please enter a number between 1-6.\n");
        }
    } while (choice != 6);
    
    return 0;
}
