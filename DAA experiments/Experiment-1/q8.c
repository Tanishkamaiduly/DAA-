#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

int main()
{
    struct Student s[100];
    int n, i, j;
    int topper = 0;
    float classAverage = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;

        printf("Enter marks of 5 subjects:\n");

        for(j = 0; j < 5; j++)
        {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5.0;

        if(s[i].percentage >= 90)
            s[i].grade = 'A';
        else if(s[i].percentage >= 80)
            s[i].grade = 'B';
        else if(s[i].percentage >= 70)
            s[i].grade = 'C';
        else if(s[i].percentage >= 60)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';

        classAverage += s[i].percentage;

        if(s[i].percentage > s[topper].percentage)
            topper = i;
    }

    classAverage /= n;

    printf("\n----- STUDENT RESULTS -----\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %d", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    printf("\n----- CLASS TOPPER -----\n");
    printf("Name: %s\n", s[topper].name);
    printf("Percentage: %.2f\n", s[topper].percentage);

    printf("\n----- FAILED STUDENTS -----\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(s[i].marks[j] < 40)
            {
                printf("%s\n", s[i].name);
                break;
            }
        }
    }

    printf("\nClass Average = %.2f", classAverage);

    return 0;
}