#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define numOfSubjects 8
#define numOfStudents 10

void enrol();
void searchUpdate();
void topStudents();

typedef struct {
    char FirstName[50];
    char LastName[50];
    int StudentID;
    float SubjectMarks[numOfSubjects];
    int AggregateMarks;
    char Grade[50];
} student_t;

student_t students[numOfStudents] = {
    {"John", "Smith", 1}, 
    {"Ricky", "Chambers", 2}, 
    {"Isaac", "Graham", 3}, 
    {"Aqsa", "Reese", 4}, 
    {"Brenda", "Peterson", 5}, 
    {"Eugene", "Franco", 6}, 
    {"Haydn", "Hines", 7},
    {"Carlo", "Henry", 8},
    {"Lorna", "Rowe", 9},
    {"Maariyah", "Harris", 10}
};

int main(void)
{
    while(1){
        int option;
        printf("\nSelect an option:\n1. Enrol students\n2. Look up student\n3. Display top students\n4. Exit\n");
        scanf("  %d", &option);

        switch (option) {
            case 1: enrol();
            break;

            case 2: searchUpdate();
            break;
            
            case 3: topStudents();
            break;

            case 4: return 0;
            break;

            default: printf("\nInvalid input. Try again.\n");
            continue;
        }

    }
}


void enrol(){
    int studentIDInput;
    
    printf("\nEnter student ID: ");
    scanf(" %d", &studentIDInput);

    int studentIndex;

    for (int i = 0; i < numOfStudents; i++) {
        if (students[i].StudentID == studentIDInput) {
            studentIndex = i;
            break;
        }
    }

    printf("\nEnter marks for %s %s:\n", students[studentIndex].FirstName, students[studentIndex].LastName);
    for (int i = 0; i < numOfSubjects; i++) {
        char markInput[100];
        float number;
        
        int markInputLoop = 1;

        do {
            printf("\nSubject %d: ", i);
            if (scanf(" %f", &number) == 1){
                students[studentIndex].SubjectMarks[i] = number;
                markInputLoop = 0;
            }else {
                scanf(" %s", markInput);
                if (strcasecmp(markInput, "No")==0){
                    students[studentIndex].SubjectMarks[i] = -1;
                    markInputLoop = 0;
                }else {printf("\nInvalid input. Try again.\n");
            }
        } while (markInputLoop);
    }



    printf("\nAll marks of %s %s have been entered.\n", students[studentIndex].FirstName, students[studentIndex].LastName);
}


void searchUpdate(){
    int searchInput;
    printf("Search by:\n1. Student ID\n2. Last Name\n");
    scanf(" %d", &searchInput);

    int searchID;
    char searchLastName[50];
    int studentIndex;

    if (searchInput == 1) {
        printf("\nEnter Student ID: ");
        scanf(" %d", &searchID);
    } else if (searchInput == 2) {
        printf("\nEnter Last Name: ");
        scanf(" %s", searchLastName);
    } else {
        printf("\nInvalid input. Try again.\n");
        return;
    }

    for (int i = 0; i < numOfStudents; i++) {
        if ((searchInput == 1 && students[i].StudentID == searchID) || (searchInput == 2 && strcasecmp(students[i].LastName, searchLastName) == 0)) {
            studentIndex = i;
            break;
        } else printf("\nInvalid input. Try again.\n");
    }



}


void topStudents(){

} 