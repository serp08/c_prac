#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[100];
    int id;
    float salary;
    char dept[50];
    int exp;
    float perf;
};

void addEmployee(struct Employee *list, int *numEmployees);
void updateEmployee(struct Employee *list, int numEmployees);
void displayEmployee(struct Employee list[], int numEmployees);
void searchEmployeeByName(struct Employee list[], int numEmployees);
struct Employee sortEmployeesByPerformance(struct Employee *out, struct Employee list[], int numEmployees);

int main(){
    int numEmployees = 0;
    struct Employee *ppl = calloc(0, sizeof(struct Employee));
    addEmployee(ppl, &numEmployees);
    // updateEmployee(ppl, numEmployees);
    // addEmployee(ppl, &numEmployees);
    // struct Employee a[2];
    // sortEmployeesByPerformance((struct Employee*) a, ppl, numEmployees);
    printf("%s", ppl[0].dept);
    free(ppl);
    return 0;
}

void addEmployee(struct Employee *list, int *numEmployees){
    (*numEmployees)++;
    printf("%d", *numEmployees);
    struct Employee e;
    printf("Enter employee name: ");
    scanf("%s", &e.name);
    printf("Enter employee ID: ");
    scanf("%d", &e.id);
    printf("Enter employee salary: ");
    scanf("%f", &e.salary);
    printf("Enter employee department: ");
    scanf("%s", &e.dept);
    printf("Enter employee years of experience: ");
    scanf("%s", &e.exp);
    e.perf = 0.3*e.exp + 0.7*e.salary;
    list = (struct Employee *)realloc(list, sizeof(e) * (*numEmployees));
    list[*numEmployees - 1] = e;
}

void updateEmployee(struct Employee *list, int numEmployees){
    int id;
    printf("Enter Employee ID to update: ");
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

void displayEmployee(struct Employee list[], int numEmployees);

void searchEmployeeByName(struct Employee list[], int numEmployees);

struct Employee sortEmployeesByPerformance(struct Employee *out, struct Employee list[], int numEmployees){
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
                if(list[i].perf > highest && list[i].perf < (*(out + counter)).perf){
                    highest = list[i].perf;
                    idx = i;
                }
            }
        }
        *(out + counter) = list[idx];
        counter++;
    }
}