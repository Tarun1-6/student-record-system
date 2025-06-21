#include <stdio.h>
#include <stdlib.h>

void addStudent();
void viewStudent();
void updateStudent();

typedef struct
{
    int roll;
    char name[100];
    float marks;
} stu;

stu student[100];
int count = 0;

int main()
{
    int firstRun = 1;
    while (1)
    {
        if (!firstRun)
        {
            printf("\n============================\n");
        }

        firstRun = 0;

        // menu
        printf("\nSTUDENT RECORD SYSTEM\n");
        printf("-----------------------\n");
        printf("1.Add Student\n");
        printf("2.View All Students\n");
        printf("3.Update Student\n");
        printf("4.Exit\n");

        // taking input
        int c;
        printf("Enter your choice: ");
        scanf("%d", &c);
        printf("\n");

        // tasks
        switch (c)
        {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            printf("Exiting the program. Goodbye!\n");
            exit(0); // terminates the program.
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void addStudent()
{
    printf("Enter roll number: ");
    scanf("%d", &student[count].roll);

    while ((getchar()) != '\n')
        ;

    printf("Enter name: ");
    scanf("%[^\n]", student[count].name);

    printf("Enter marks: ");
    scanf("%f", &student[count].marks);
    count++;
    printf("\n");
    printf("Student added successfully!\n");
}

void viewStudent()
{
    printf("STUDENT LIST\n");
    printf("---------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("Roll number: %d\n", student[i].roll);
        printf("Name: %s\n", student[i].name);
        printf("Marks: %f\n", student[i].marks);
        printf("---------------------\n");
    }
}

void updateStudent()
{
    int key, found = 0;
    printf("Enter roll number to update: ");
    scanf("%d", &key);
    for (int i = 0; i < count; i++)
    {
        if (student[i].roll == key)
        {

            while ((getchar()) != '\n')
                ; //  FLUSH HERE

            printf("Enter new name: ");
            scanf("%[^\n]", student[i].name);

            printf("Enter new marks: ");
            scanf("%f", &student[i].marks);

            printf("\n");
            printf("Updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found\n");
}
