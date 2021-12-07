//this was made by: Paulo
//It's totally free to use 
//github: Paulo-Henrique-Silva

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void createBoard();
int isValid(int input);
void refreshBoard(char playerSymbol, int play);
int isVictory();
//fuctions prototypes

char board[9];

int main()
{
    const char PLAYER1 = 'X', PLAYER2 = 'O';
    int play;

    createBoard(); 

    do
    {
        printf("\nPlayer 1 Turn - Type your play(1 - 9): ");
        scanf("%d", &play);
        play = isValid(play);
        refreshBoard(PLAYER1, play);

        printf("\nPlayer 2 Turn - Type your play(1 - 9): ");
        scanf("%d", &play);
        play = isValid(play);
        refreshBoard(PLAYER2, play);
    }
    while(/*isVictory()*/0); 

    getch(); //pause before closes it
    return 0;
}

void createBoard()
{

    for(int i = 0; i < 9; i++)
        board[i] = (i+1) + '0'; 
    //add '0' will assing the "i" value as a char
    //we're +1 because 1-9 is more "user friendly" than 0-8

    printf("\n %c | %c | %c ", board[0], board[1], board[2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", board[3], board[4], board[5]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", board[6], board[7], board[8]);
}
//it creates the game board

int isValid(int input)
{
    while(input < 1 || input > 9)
    {
        printf("\nType a Number between 1-9: ");
        scanf("%d", &input);
    }

    return input;
}
//checks if the user input is between the board interval

void refreshBoard(char playerSymbol, int play)
{
    play--; //-1 because the interval is 0-8
    board[play] = playerSymbol;

    printf("\n %c | %c | %c ", board[0], board[1], board[2]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", board[3], board[4], board[5]);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", board[6], board[7], board[8]);
}
//refreshs the board with the last player move

int isVictory()
{

}
