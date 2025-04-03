#include <stdio.h>

void bwdArr(int *arr){
    int tmp = *arr;
    *arr = *(arr+5);
    *(arr+5) = tmp;

    tmp = *(arr+1);
    *(arr+1) = *(arr+4);
    *(arr+4) = tmp;

    tmp = *(arr+2);
    *(arr+2) = *(arr+3);
    *(arr+3) = tmp;
}

int main(){
    int arr[6];
    for(int i = 0; i < 6; i++){
        printf("Enter num: ");
        scanf("%d", &arr[i]);
    }
    bwdArr(arr);
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}