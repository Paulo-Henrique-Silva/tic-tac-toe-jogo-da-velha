//this was made by: Paulo
//It's totally free to use 
//github: Paulo-Henrique-Silva

/*
In this version the Game Works, but: 
    - it's not going to stop if it's a tie 
    - it does not tell who has won

# Add this later
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void createBoard();
int isValid(int input);
void refreshBoard(char playerSymbol, int play);
int isVictory(char symb);
//fuctions prototypes

char board[9];

int main()
{
    const char PLAYER1 = 'X', PLAYER2 = 'O';
    int play;

    createBoard(); 

    while(1)
    {
        printf("\n\nPlayer 1 Turn - Type your play(1 - 9): ");
        scanf("%d", &play);
        play = isValid(play);
        refreshBoard(PLAYER1, play);

        if(isVictory(PLAYER1))
            break; 

        printf("\n\nPlayer 2 Turn - Type your play(1 - 9): ");
        scanf("%d", &play);
        play = isValid(play);
        refreshBoard(PLAYER2, play);

        if(isVictory(PLAYER2))
            break; 
    }

    printf("\n\nEND GAME!");
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
    while(input < 1 || input > 9 || board[input - 1] == 'X' || board[input - 1] == 'O')
    {
        printf("\nInvalid input! Type again: ");
        scanf("%d", &input);
    }

    return input;
}
//checks if the user input is between the board interval or if it has been taken already

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

int isVictory(char symb)
{
    //rows
    if(board[0] == symb && board[1] == symb && board[2] == symb)
        return 1;
    if(board[3] == symb && board[4] == symb && board[5] == symb)
        return 1;
    if(board[6] == symb && board[7] == symb && board[8] == symb)
        return 1;

    //columns
    if(board[0] == symb && board[3] == symb && board[6] == symb)
        return 1;
    if(board[1] == symb && board[4] == symb && board[7] == symb)
        return 1;
    if(board[2] == symb && board[5] == symb && board[8] == symb)
        return 1;

    //diagonals
    if(board[0] == symb && board[4] == symb && board[8] == symb)
        return 1;
    if(board[2] == symb && board[4] == symb && board[6] == symb)
        return 1;

    return 0; //if every case don't matches, will return false. Therefore, anyone hasn't won.
}
//checks if it's a victory
