#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100
#define FILENAME "nums.txt"

void gen_num(int n);
void read_num(int *arr, int n);
double mean(int *arr, int n);
double med(int *arr, int n);
int mode(int *arr, int n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s (num of random ints)", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    if(n > MAX_NUM || n < 1){
        printf("Please enter a number from 1 to %d", MAX_NUM);
        return 1;
    }

    int nums[MAX_NUM];
    return 0;
}

void gen_num(int *arr, int n){
    FILE *f = fopen(FILENAME, "w");
    if(f == NULL){
        printf("Error opening file");
        exit(1);
    }

    srand(time(NULL));
    for(int i = 0; i < n; i++){
        int num = rand() % 100;
        fprintf(f, "%d\n", num);
    }fclose(f);
}

void read_num(int n){
    FILE *f = fopen(FILENAME, "r");
    if(f == NULL){
        printf("Error opening file");
        exit(1);
    }
}