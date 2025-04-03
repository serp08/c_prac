#include <stdio.h>

#define ROWS 3
#define COLS 3

void game(char (*grid)[ROWS]);
int win_or_full(char (*grid)[ROWS]);
void print_grid(char (*grid)[ROWS]);
int main(){
    char grid[ROWS][COLS];
    game(grid);
}

void game(char (*grid)[ROWS]){
    int turn = 0, row = 0, col = 0;
    char uno, dos;
    printf("Enter p1's character:");
    scanf("%c", &uno);
    printf("Enter p2's character:");
    scanf("%c", &dos);
    while(1){
        if(win_or_full(grid)){
            break;
        }
        
        printf("P%d's turn - ", turn + 1);
        do{
            if(row < 0 || row > 2){
                printf("Please enter a number from 1-3.");
            }
            printf("Enter the row: ");
            scanf("%d", &row); row--;
        }while(row < 0 || row > 2);
        
        do{
            if(row < 0 || row > 2){
                printf("Please enter a number from 1-3.");
            }
            printf("Enter the column: ");
            scanf("%d", &col); col--;
        }while(row < 0 || row > 2);
        
        grid[row][col] = (turn == 0)?uno:dos;

        print_grid(grid);

        switch(turn){
            case 0:
            turn = 1;
            default:
            turn = 0;
        }
    }
}

int win_or_full(char (*grid)[ROWS]){
    if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]){
        return 1;
    }return 0;
}

void print_grid(char (*grid)[ROWS]){
    for(int i = 0; i < 3; i++){
        printf("%c %c %c\n", grid[i][0], grid[i][1], grid[i][2]);
    }
}