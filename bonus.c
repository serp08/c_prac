#include <stdio.h>

struct Employee {
    char name[100];
    int id;
    float salary;
    char dept[50];
    int exp;
    float perf;
};

struct Employee addEmployee(){
    struct Employee e;
    printf("Enter employee name: ");
    scanf("%s", &e.name);
    printf("Enter employee ID: ");
    scanf("%d", &e.id);
    printf("Enter employee salary: ");
    scanf("%.2f", &e.salary);
    printf("Enter employee department: ");
    scanf("%s", &e.dept);
    printf("Enter employee years of experience: ");
    scanf("%s", &e.exp);
    e.perf = .3*e.exp + 0.7*e.salary;
    return e;
}

int main(){
    return 0;
}