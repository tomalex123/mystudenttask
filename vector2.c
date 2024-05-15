#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int id;
    int age;
    float marks[3];
} Student;

// Function to add a new student
Student* addStudent(int n) {
    // Dynamically allocate memory for the Student objects
    Student* newStudent = (Student*)malloc(n * sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    return newStudent;
}

// Input student's details
void scan(Student* S, int n) {
    for (int i = 0; i < n; ++i) {
        printf("Enter student %d's name: ", i + 1);
        scanf("%s", S[i].name);
        printf("Enter student %d's ID: ", i + 1);
        scanf("%d", &S[i].id);
        printf("Enter student %d's age: ", i + 1);
        scanf("%d", &S[i].age);
        printf("Enter student %d's grades (3 grades separated by spaces): ", i + 1);
        for (int j = 0; j < 3; ++j) {
            scanf("%f", &S[i].marks[j]);
        }
        printf("\n");
    }
}

// Output student's details
void print(Student* P, int n) {
    for (int i = 0; i < n; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", P[i].name);
        printf("ID: %d\n", P[i].id);
        printf("Age: %d\n", P[i].age);
        printf("Grades: ");
        for (int j = 0; j < 3; ++j) {
            printf("%.2f ", P[i].marks[j]);
        }
        printf("\n");
    }
}

float calculateAverage(Student* P, int n){
    float totalAverage = 0;
    for (int i = 0; i < n; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", P[i].name);
        printf("ID: %d\n", P[i].id);
        printf("Age: %d\n", P[i].age);
        printf("Grades: ");
        printf("\n");
        float sum = 0;
        for (int j = 0; j < 3; ++j) {
            sum += P[i].marks[j];
        }
        float average = sum / 3;
        printf("Student %d's average mark: %.2f\n", i + 1, average);
        printf("\n");
        totalAverage += average;
    }
    return totalAverage / n;
}

void findHighestScoringStudent(Student* P, int n) {
    float maxAverage = 0;
    char* maxName = NULL;

    for (int i = 0; i < n; ++i) {
        float sum = 0;
        for (int j = 0; j < 3; ++j) {
            sum += P[i].marks[j];
        }
        float average = sum / 3;
        if (average > maxAverage) {
            maxAverage = average;
            maxName = P[i].name;
        }
    }

    // Print the name of the student with the highest average mark
    printf("Student with the highest average mark is: %s\n", maxName);
}

void sorting(Student* P, int n) {
    char op = 0;
    printf("Please enter an arithmetic operation or @ to quit the program! \n");
    printf("Select sorting criteria:\n");
    printf("1. calculateAverage\n");
    printf("2. findHighestScoringStudent\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf(" %c", &op);
    
    while (op != '@') {
        switch (op) {
            case '1':
                printf("Average marks for all students: %.2f\n", calculateAverage(P, n));
                break;
            case '2':
                findHighestScoringStudent(P, n);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("\n");
        printf("Please enter an arithmetic operation or @ to quit the program! \n");
        scanf(" %c", &op);
    }
    
    printf("Thank you!\n");
}


void delete_arr(Student* D){
	free(D);
	D = NULL;
    }

int main() {
    
    int n = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    Student* newStudent = addStudent(n);
    scan(newStudent, n);
    print(newStudent, n);
    printf("\n");
    sorting(newStudent,n);

    // Don't forget to free the memory allocated for the students
    delete_arr(newStudent);

    return 0;
}

