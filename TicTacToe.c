#include <stdio.h>
#include <ctype.h>
#define ROW_SIZE 3
#define COL_SIZE 3
void printMatrix(char arr[ROW_SIZE][COL_SIZE]);
int checkWinner(char grid[ROW_SIZE][COL_SIZE], char player);
int checkDraw(char grid[ROW_SIZE][COL_SIZE]);

//function to printMatrix by accessing the rows and cols using nested loop
void printMatrix(char arr[ROW_SIZE][COL_SIZE]){
    for(int i = 0; i <ROW_SIZE; i++){
        for(int j = 0; j< COL_SIZE; j++){
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

//function to checkwinner by comparing rows, cols and diagonals
int checkWinner(char grid[ROW_SIZE][COL_SIZE], char player){
    //check for 3 elements in a row
    for(int i = 0; i <ROW_SIZE; i++){
        if(grid[i][0] == player && grid[i][1] == player && grid[i][2] == player){
            return 1; //row has matched, returns 1 if matching row found to show win 
        }
    }

    //check for 3 elements in a column
    for(int j = 0; j<ROW_SIZE; j++){
        if(grid[0][j] == player && grid[1][j] == player && grid[2][j]==player)
        return 1;
    }

     // Check diagonals
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
        return 1; //diagonals matched fully
    }
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) {
        return 1; //diagonals matched fully
    }
    return 0;
}

//function to check draw, if there is no empty space remaining at the end, its a draw
int checkDraw(char grid[ROW_SIZE][COL_SIZE]){
    //if no cell is empty only then its a draw, otherwise its not a draw
    for(int i = 0; i<ROW_SIZE; i++){
        for(int j = 0; j < COL_SIZE; j++){
            //if a cell is empty it can never be a draw
            if(grid[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    char player1, player2; //to hold the symbol for each player
    char grid[ROW_SIZE][COL_SIZE]; //initialize grid for the game
    int rowInput, colInput; //ask user for their option 
    int turn = 0; //to keep track of which players move it is, 1st players move will be even, 2nd players move will be odd   
    char currentPlayer;
    //loop through the row
    for(int i = 0; i<ROW_SIZE; i++){
        //loop through the col
        for(int j = 0; j<COL_SIZE; j++){
            grid[i][j] = ' '; //assign every index with a blank space
        }
    }

    //assign symbols to both the players
    printf("Enter the symbol you want (O or X): ");
    scanf(" %c", &player1);
    player1 = toupper(player1);

    //keep asking for player symbol until valid symbol is entered
    do{
    if(player1 != 'O'&& player1 != 'X'){
        printf("Invalid input, please try again: ");}
    else{
        break;
    }
    }while(1);
    
    //assign for player2 based on player 1
    if(player1 == 'O'){
        player2 = 'X';
    }else{
        player2 = 'O'; 
    }

    printf("Player 1 is %c and player 2 is %c", player1, player2);

    //start the game
    while(1){
        printMatrix(grid);
        printf("\n");
        //if the turn is even, player 1 gets chance, otherwise player 2 gets chance
        if(turn % 2 == 0){
             currentPlayer = player1;
        }else{
             currentPlayer = player2;
        }



        //take row and col input from user1
        printf("Player %c, Enter the row and col number with 1 space (row col): \n", currentPlayer);
        scanf("%d %d", &rowInput, &colInput);
        printf("\n");
        
        rowInput -=1;
        colInput -=1;

        //rowinput has to be between 0 and rowsize and colinput must be between 0 and colsize
        if(rowInput<0 || rowInput >=ROW_SIZE || colInput < 0 ||colInput >= COL_SIZE){
            printf("Invalid input please try again later: ");
            continue; //go to the start of the loop
        }
        

    //check if the place the user is trying to choose is empty or not
    if(grid[rowInput][colInput] != ' '){
        printf("This cell is occupied please try again \n");
        continue;
    }

    //place the player symbol in the grid
    grid[rowInput][colInput] = currentPlayer;

    if(checkWinner(grid, currentPlayer)){
        printMatrix(grid);
        printf("player %c wins", currentPlayer);
        break;
    }

    if(checkDraw(grid)){
        printMatrix(grid);
        printf("its a draw!\n");
        break;
    }


    turn++;

}
}