#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_DEPT 50

struct Employee {
    char name[MAX_NAME];
    int id;
    float salary;
    char dept[MAX_DEPT];
    int exp;
    float perf;
};

void addEmployee(struct Employee **list, int *numEmployees);
void updateEmployee(struct Employee *list, int numEmployees);
void displayEmployee(struct Employee list[], int numEmployees);
void searchEmployeeByName(struct Employee list[], int numEmployees);
void sortEmployeesByPerformance(struct Employee **out, struct Employee list[], int numEmployees);

int main(){
    int numEmployees = 0, choice = 0;;
    struct Employee *ppl = calloc(0, sizeof(struct Employee));
    while(choice != 5){
        printf("Employee Performance Management System\n1. Add Employee\n2. Update Employee\n3. Display All Employees\n4. Search Employee by Name\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addEmployee(&ppl, &numEmployees);
                break;
            case 2:
                updateEmployee(ppl, numEmployees);
                break;
            case 3:
                displayEmployee(ppl, numEmployees);
                break;
            case 4:
                searchEmployeeByName(ppl, numEmployees);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid input, please enter a number from 1-5.");
        }printf("\n");
    }
    free(ppl);
    return 0;
} 

void addEmployee(struct Employee **list, int *numEmployees){
    (*numEmployees)++;
    struct Employee e;
    while(getchar() != '\n');
    printf("\n\nEnter employee name: ");
    if(fgets(e.name, sizeof(e.name), stdin) == NULL){
        printf("Error reading input.");
    }e.name[strcspn(e.name, "\n")] = '\0';
    printf("Enter employee ID: ");
    scanf("%d", &e.id);
    printf("Enter employee salary: ");
    scanf("%f", &e.salary);
    printf("Enter employee department: ");
    scanf("%s", &e.dept);
    printf("Enter employee years of experience: ");
    scanf("%d", &e.exp);
    e.perf = 0.3*e.exp + 0.7*e.salary;
    *list = (struct Employee *)realloc(*list, sizeof(e) * (*numEmployees));
    if(*list == NULL){
        printf("Allocation failed.");
        exit(1);
    }(*list)[*numEmployees - 1] = e;
}

void updateEmployee(struct Employee *list, int numEmployees){
    int id;
    printf("\n\nEnter Employee ID to update: ");
    scanf("%d", &id);
    for(int i = 0; i < numEmployees; i++){
        if((*(list + i)).id == id){
            printf("Enter new salary: ");
            scanf("%f", &(*(list + i)).salary);
            printf("Enter new department: ");
            scanf("%s", &(*(list + i)).dept);
            break;
        }
        if(i == numEmployees - 1){
            printf("Employee not found.");
        }
    }
}

void displayEmployee(struct Employee list[], int numEmployees){
    struct Employee *sorted = (struct Employee*) malloc (numEmployees*sizeof(struct Employee));
    sortEmployeesByPerformance(&sorted, list, numEmployees);
    printf("\n\nEmployee Records (sorted by Performance Score):\n");
    for(int i = 0; i < numEmployees; i++){
        struct Employee e = sorted[i];
        printf("Name: %s\n", e.name);
        printf("Employee ID: %d\n", e.id);
        printf("Salary: %.2f\n", e.salary);
        printf("Department: %s\n", e.dept);
        printf("Years of experience: %d\n", e.exp);
        printf("Performance score: %.2f\n\n", e.perf);
    }
}

void searchEmployeeByName(struct Employee list[], int numEmployees){
    char search[MAX_NAME];
    int found = 0;
    printf("\n\nEnter name to search: ");
    while(getchar() != '\n');
    if(fgets(search, sizeof(search), stdin) == NULL){
        printf("Error reading input.");
    }search[strcspn(search, "\n")] = '\0';
    struct Employee *sorted = (struct Employee*) malloc (numEmployees*sizeof(struct Employee));
    sortEmployeesByPerformance(&sorted, list, numEmployees);
    printf("\nSearch results:\n\n");
    for(int i = 0; i < numEmployees; i++){
        struct Employee e = sorted[i];
        if(strstr(e.name, search) != NULL){
            printf("Name: %s\n", e.name);
            printf("Employee ID: %d\n", e.id);
            printf("Salary: %.2f\n", e.salary);
            printf("Department: %s\n", e.dept);
            printf("Years of experience: %d\n", e.exp);
            printf("Performance score: %.2f\n\n", e.perf);
            found = 1;
        }
        if(i == (numEmployees - 1) && found == 0){
            printf("Employee not found");
        }
    }
}

void sortEmployeesByPerformance(struct Employee **out, struct Employee list[], int numEmployees){
    int counter = 0;
    while(counter <= numEmployees){
        int highest = list[0].perf, idx = 0;
        for(int i = 0; i < numEmployees; i++){
            if(counter == 0){
                if(list[i].perf > highest){
                    highest = list[i].perf;
                    idx = i;
                }
            }
            else{
                if(list[i].perf > highest && list[i].perf < (*out)[counter - 1].perf){
                    highest = list[i].perf;
                    idx = i;
                }
            }
        }
        (*out)[counter] = list[idx];
        counter++;
    }
}