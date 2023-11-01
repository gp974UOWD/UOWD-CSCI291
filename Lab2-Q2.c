#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define numOfSubjects 8
#define numOfStudents 20

// Function prototypes
void enrol();
void searchUpdate();
void topStudents();
void calculateAggregate();

// Typedef struct with definition student_t to be easily called to declare items
typedef struct {
    char FirstName[50];
    char LastName[50];
    int StudentID;
    float SubjectMarks[numOfSubjects];
    int AggregateMarks;
    char Grade[10];
} student_t;

// Predefined students with given first names, last names, and a student ID each. 2 empty spaces in case the user wants to add any students. 
// First names and last names were randomly generated using https://www.name-generator.org.uk/quick/
student_t students[numOfStudents] = {
    {"John", "Smith", 1}, 
    {"Ricky", "Chambers", 2}, 
    {"Isaac", "Graham", 3}, 
    {"Aqsa", "Reese", 4}, 
    {"Brenda", "Peterson", 5}, 
    {"Eugene", "Franco", 6}, 
    {"Haydn", "Hines", 7},
    {"Carlo", "Henry", 8},
};




// Main function performing all requirements, calling 3 different functions 
int main(void)
{
    // Main menu is in an infinite loop so all values are permanently saved until the user fully exits the program
    while(1){
        int option;
        printf("\nSelect an option:\n1. Enrol students\n2. Look up student\n3. Display top students\n4. Exit\n");
        scanf(" %d", &option);
        char throwawayforcasedefault = getchar(); // Without this the case-default would loop infinitely

        switch (option) {
            case 1: {
                enrol();
                break;
            }

            case 2: {
                searchUpdate();
                break;
            }
            
            case 3: {
                topStudents();
                break;
            }

            case 4: {
                return 0; // Exits the program entirely
                break;
            }

            default: {
                printf("\nInvalid input. Try again.\n");
                break;
            }
        }
    }
}




// Function is void as no values have to be returned, simply the function has to be executed
void enrol()
{
    int studentIDInput;
    
    printf("\nEnter student ID: ");
    scanf(" %d", &studentIDInput);

    if (studentIDInput <= numOfStudents && studentIDInput >= 0){
        int studentIndex;

        // Assigns the value of the input to studentIndex by browsing throughout the entire array in the struct member
        for (int i = 0; i < numOfStudents; i++) {
            if (students[i].StudentID == studentIDInput) {
                studentIndex = i;
                break;
            }
        }

        
        printf("\nEnter marks for %s %s:\n", students[studentIndex].FirstName, students[studentIndex].LastName);
        for (int i = 0; i < numOfSubjects; i++) {
            char markInput[100];
            float grade;
            
            int markInputLoop = 1; // Flag value to use in a while loop

            // Whole loop checks for either a string input OR an integer input and will execute either as given by the if-else statements
            while (markInputLoop){
                printf("\nSubject %d: ", i);
                scanf(" %s", markInput);
                if (strcasecmp(markInput, "No")==0){
                    students[studentIndex].SubjectMarks[i] = -1;
                    markInputLoop = 0; // Exits the while loop after all subjects reached
                }else if (sscanf(markInput, " %f", &grade) == 1){ // Using sscanf takes the input from markInput even if it is a string, and reads the specific number value
                    students[studentIndex].SubjectMarks[i] = grade;
                    markInputLoop = 0;
                }else printf("\nInvalid input. Try again.\n");   
            }
        }

        int allMarksValid = 1; // Flag value to check if all subjects have been entered

        for (int i = 0; i < numOfSubjects; i++) { // For loop to scan for any -1 values in any of the Grades
            if (students[studentIndex].SubjectMarks[i] == -1) {
                allMarksValid = 0;
                break;
            }
        }

        // If only one subject has been input as "No", the entire aggregate mark is set as -1
        if (allMarksValid == 1){
            int aggregateMarks;
            for (int i = 0; i < numOfSubjects; i++) {
                aggregateMarks += students[studentIndex].SubjectMarks[i];
            }
            students[studentIndex].AggregateMarks = (aggregateMarks/numOfSubjects);
            int aggregate = students[studentIndex].AggregateMarks;

            if (aggregate >= 85 && aggregate <= 100) { // Copies "HD" to the Grade member of the chosen student if the aggregate mark is between 85 and 100 as per the table
                strcpy(students[studentIndex].Grade, "HD");
            } else if (aggregate >= 75) { 
                strcpy(students[studentIndex].Grade, "D");
            } else if (aggregate >= 65) {
                strcpy(students[studentIndex].Grade, "C");
            } else if (aggregate >= 50) {
                strcpy(students[studentIndex].Grade, "P");
            } else if (aggregate >= 0) { // Copies "F" if the aggreggate mark is below 50 but still above or equal 0
                strcpy(students[studentIndex].Grade, "F"); 
            }
        }else { // Sets aggreggate of the student as -1 and overall Grade as "undefined" if one of the subject marks is "No"
            students[studentIndex].AggregateMarks = -1;
            strcpy(students[studentIndex].Grade, "undefined");
        }

        printf("\nAll marks of %s %s have been entered.\n", students[studentIndex].FirstName, students[studentIndex].LastName);
        
    }else printf("\nInvalid input.\n");
    return;

    sleep(1); // 1 second delay for aesthetic purposes
}




// Function is void as no values have to be returned, simply the function has to be executed
void searchUpdate()
{
    int searchInput;
    printf("\nSearch by:\n1. Student ID\n2. Last Name\n");
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
        printf("\nunfound\n");
        return;
    }

    for (int i = 0; i < numOfStudents; i++) {
        if ((searchInput == 1 && students[i].StudentID == searchID) || 
            (searchInput == 2 && strcasecmp(students[i].LastName, searchLastName) == 0)) {
            studentIndex = i;
            break;
        } else printf("\nInvalid input. Try again.\n");
    }

    printf("\nName: %s %s ", students[studentIndex].FirstName, students[studentIndex].LastName);
    printf("\nStudent ID: %d ", students[studentIndex].StudentID);
    printf("\nSubject marks: ");
    for (int k=0; k<numOfSubjects; k++){
        printf("%d ", students[studentIndex].SubjectMarks[k]);
    }
    printf("\nAggregate marks: %d ", students[studentIndex].AggregateMarks);
    printf("\nGrade: %s \n", students[studentIndex].Grade);

    char updateResponse[5];

    printf("\nWould you like to update? y/n\n");
    scanf(" %s", updateResponse);

    int updatingLoop = 1;

    while (updatingLoop){
        if (strcasecmp(updateResponse, "y")==0){
            char firstName[50];
            char lastName[50];
            int studentID;

            printf("\nEnter first name: ");
            scanf(" %s", firstName);
            strcpy(students[studentIndex].FirstName, firstName);

            printf("\nEnter last name: ");
            scanf(" %s", lastName);
            strcpy(students[studentIndex].LastName, lastName);
            
            int idCheckLoop = 1;

            while(idCheckLoop) {
                printf("\nEnter new student ID: ");
                scanf(" %d", &studentID);
                int idExists = 0;

                for (int i = 0; i < numOfStudents; i++) {
                    if (studentID == students[i].StudentID) {
                        idExists=1;
                    }
                }

                if (idExists==1){
                    printf("\nThis ID already exists in the database. Try something else.\n");
                }else {
                    students[studentIndex].StudentID = studentID;
                    idCheckLoop=0;
                }
            }

            printf("\nEnter new marks:\n");
            for (int i = 0; i < numOfSubjects; i++) {
                char markInput[100];
                float grade;
                
                int markInputLoop = 1;

                while (markInputLoop){
                    printf("\nSubject %d: ", i);
                    scanf(" %s", markInput);
                    if (strcasecmp(markInput, "No")==0){
                        students[studentIndex].SubjectMarks[i] = -1;
                        markInputLoop = 0;
                    }else if (sscanf(markInput, " %f", &grade) == 1){
                        students[studentIndex].SubjectMarks[i] = grade;
                        markInputLoop = 0;
                    }else printf("\nInvalid input. Try again.\n");   
                }

                int allMarksValid = 1;

                for (int i = 0; i < numOfSubjects; i++) {
                    if (students[studentIndex].SubjectMarks[i] == -1) {
                        allMarksValid = 0;
                        break;
                    }
                }

                if (allMarksValid == 1){
                    int aggregateMarks;
                    for (int i = 0; i < numOfSubjects; i++) {
                        aggregateMarks += students[studentIndex].SubjectMarks[i];
                    }
                    students[studentIndex].AggregateMarks = (aggregateMarks/numOfSubjects);
                    calculateAggregate(studentIndex);
                }else {
                    students[studentIndex].AggregateMarks = -1;
                    strcpy(students[studentIndex].Grade, "undefined");
                }
            }
            printf("\nStudent has been updated.\n");
            updatingLoop=0;
        }else if (strcasecmp(updateResponse, "n")==0){
            updatingLoop=0;
        }else {
            printf("\nInvalid input. Try again.\n");
            scanf(" s", updateResponse);
        }
    }   
    sleep(1);
}




void topStudents()
{
    printf("\nStudents sorted by highest aggregate mark:\n");

    int temp;

    for (int i=0; i<numOfStudents; i++){
        for (int j=i+1; j<numOfStudents; j++){
            if (students[i].AggregateMarks < students[j].AggregateMarks){
                // Basic C bubble sort to sort by AggreggateMarks descending
                temp = students[i].AggregateMarks;
                students[i].AggregateMarks = students[j].AggregateMarks;
                students[j].AggregateMarks = temp;
            }
        }
    }

    for (int i=0; i<numOfStudents; i++){
        // Prints individual details of each student, starting with highest AggreggateMarks as given by i
        printf("\nName: %s %s ", students[i].FirstName, students[i].LastName);
        printf("\nStudent ID: %d ", students[i].StudentID);
        printf("\nSubject marks: ");
        for (int k=0; k<numOfSubjects; k++){
            printf("%d ", students[i].SubjectMarks[k]);
        }
        printf("\nAggregate marks: %d ", students[i].AggregateMarks);
        printf("\nGrade: %s \n", students[i].Grade);
    }

    sleep(1);
} 