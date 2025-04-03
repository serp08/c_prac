#include <stdio.h>

int main(){
    int a, b, c = 0, result;
    printf("Enter the number: ");
    scanf("%d", &a);
    printf("Enter the range: ");
    scanf("%d %d", &b, &c);
    int i = 0;
    while(1){
        if(i == b){
            int y = 10;
            for(int j = 1; j <= c; j++){
                y *= 10;
            }
            result = a % y;
            break;
        }a /= 10;
        c--;
        i++;
    }
    printf("Result: %d", result);
    return 0;
}