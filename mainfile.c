//this was made by: Paulo
//It's totally free to use 
//github: Paulo-Henrique-Silva

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void createBoard();
//fuctions prototypes

char board[9];

int main()
{
    char playerX = 'X', playerO = 'O';

    createBoard(); 

    getch(); //pause before closes it
    return 0;
}

void createBoard()
{
    int i; 

    for(i = 0; i < 9; i++)
        board[i] = (i+1) + '0'; 
    //add '0' will assing the value "i" as a char
    
    printf("\n %c | %c | %c ", board[0], board[1], board[2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", board[3], board[4], board[5]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", board[6], board[7], board[8]);
}
