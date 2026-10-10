#include<stdio.h>
#include<math.h>
int main()
{
    printf("\t ----- STUDENT DETAILS ----- \n\n");
    //Taking Student input
    char Name[50], UniversitySeatNumber[20];   // no spaces allowed in these, scanf stops at space
    int Semester;
    printf("Name : ");
    scanf("%s", Name);
    printf("USN : ");
    scanf("%s", UniversitySeatNumber);
    printf("Semester : ");
    scanf("%d", &Semester);
    printf("\n\n");
    
    printf("\t ----- STUDENT MARKS ----- \n\n");
    //Taking Student Marks input
    float Subject1, Subject2, Subject3, Subject4;   // marks are out of 100 each
    printf("Enter Marks in Subject 1 : ");
    scanf("%f", &Subject1);
    printf("Enter Marks in Subject 2 : ");
    scanf("%f", &Subject2);
    printf("Enter Marks in Subject 3 : ");
    scanf("%f", &Subject3);
    printf("Enter Marks in Subject 4 : ");
    scanf("%f", &Subject4);
    printf("\n\n");
    
    //Calculation
    float Total, Average, Percentage;
    Total = (Subject1 + Subject2 + Subject3 + Subject4);
    Average = Total/4;   // 4 subjects
    Percentage = (Total/400)*100;   // 400 = maximum marks
    
    //Printing Student Marks Report
    printf("==================================\n");
    printf(" ----- STUDENT MARKS REPORT ----- \n");
    printf("==================================\n");
    printf("Name       :    %s\n", Name);
    printf("USN        :    %s\n", UniversitySeatNumber);
    printf("Semester   :    %d\n", Semester);
    printf("----------------------------------\n");
    printf("Subject 1  :    %.1f\n", Subject1);
    printf("Subject 2  :    %.1f\n", Subject2);
    printf("Subject 3  :    %.1f\n", Subject3);
    printf("Subject 4  :    %.1f\n", Subject4);
    printf("----------------------------------\n");
    printf("TOTAL      :    %.2f\n", Total);
    printf("AVERAGE    :    %.2f\n", Average);
    printf("PERCENTAGE :    %.2f %%\n", Percentage);   // %% prints a single % sign
    printf("----------------------------------\n");
    printf("REPORT - \n\n");
    
    //If-Else Statements for Grades
    {
        if (Percentage >= 85)
        {
            printf("\t FINAL GRADE : A+ (Excellent)\n");
            printf("\t STATUS      : PASS\n");
            printf("\t REMARK      : Outstanding work! Keep it up!\n");
        } 
        else if (Percentage >= 75 && Percentage < 85) 
        {
            printf("\t FINAL GRADE : A (Very Good)\n");
            printf("\t STATUS      : PASS\n");
            printf("\t REMARK      : Great performance! Aim for the top!\n");
        } 
        else if (Percentage >= 55 && Percentage < 75) 
        {
            printf("\t FINAL GRADE : B (Good)\n");
            printf("\t STATUS      : PASS\n");
            printf("\t REMARK      : Solid effort! Push a bit harder next time.\n");
        } 
        else if (Percentage >= 40 && Percentage < 55) 
        {
            printf("\t FINAL GRADE : C (Satisfactory)\n");
            printf("\t STATUS      : PASS\n");
            printf("\t REMARK      : Fair. Needs more focus on core areas.\n");
        } 
        else   // anything below 40 fails
        {
            printf("\t FINAL GRADE : D (Fail)\n");
            printf("\t STATUS      : FAIL\n");
            printf("\t REMARK      : Action required. Academic support advised.\n");
        }
    }
    printf("----------------------------------\n");
    printf("==================================\n");
        
    return 0;
}
