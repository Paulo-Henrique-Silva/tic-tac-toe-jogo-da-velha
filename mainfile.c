//this was made by: Paulo
//It's totally free to use 
//github: Paulo-Henrique-Silva

//it does not have the IA mode yet

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> 

char board[9];
char winnerSymbol;
int play = 0; //this is the player move

void PlayerVsPlayer(); 
void PlayerVsIA();
void createBoard();
void isValid();
void refreshBoard(char playerSymbol);
int isVictory(char symb);
int isTie();
//fuctions prototypes

int main()
{
    int operation = 0;

    while(operation != 3)
    {
        system("cls"); //clean the screen

        printf("\t\t\tTIC-TAC-TOE GAME!\n");
        printf("\n\t\t\t[1] - Player vs Player");
        printf("\n\t\t\t[2] - Player vs IA");
        printf("\n\t\t\t[3] - Exit");
        printf("\n\nType Your Operation: ");
        scanf("%d", &operation);

        switch(operation)
        {
            case 1:
                PlayerVsPlayer();
                break;
            case 2:
                break;
            case 3:
                printf("Exiting...");
                break;
            default:
                printf("Invalid Input!");
                break;
        }

        getch(); //pause before closes it
    }

    return 0;
}

void PlayerVsPlayer()
{
    system("cls");
    const char PLAYER1 = 'X', PLAYER2 = 'O';
    
    createBoard(); 

    while(1)
    {
        printf("\n\nPlayer 1 Turn - Type your play(1 - 9): ");
        scanf("%d", &play);
        isValid();

        system("cls"); //clean the screen for the next move

        refreshBoard(PLAYER1);

        if(isVictory(PLAYER1) || isTie())
            break; 

        printf("\n\nPlayer 2 Turn - Type your play(1 - 9): ");
        scanf("%d", &play);
        isValid();

        system("cls");

        refreshBoard(PLAYER2);

        if(isVictory(PLAYER2) || isTie())
            break; 
    }

    printf("\n\nEND GAME!");

    if(winnerSymbol == 'X')
        printf("\nPALYER 1 WINS");
    else if(winnerSymbol == 'O')
        printf("\nPALYER 2 WINS");
    else
        printf("\nIT'S A TIE!");
}
//this the player vs player mode

void createBoard()
{
    for(int i = 0; i < 9; i++)
        board[i] = (i+1) + '0'; 
    //add '0' will assing the "i" value as a char
    //we're +1 because 1-9 is more "user friendly" than 0-8

    printf("\n\t\t\t %c | %c | %c ", board[0], board[1], board[2]);
    printf("\n\t\t\t---|---|---");
    printf("\n\t\t\t %c | %c | %c ", board[3], board[4], board[5]);
    printf("\n\t\t\t---|---|---");
    printf("\n\t\t\t %c | %c | %c ", board[6], board[7], board[8]);

    winnerSymbol = ' '; //sets the winner symbol, because the game has just begun
}
//it creates the game board

void isValid()
{
    while(play < 1 || play > 9 || board[play - 1] == 'X' || board[play - 1] == 'O')
    {
        printf("Invalid play! Type again: ");
        scanf("%d", &play);
    }
}
//checks if the user input is between the board interval or if it has been taken already

void refreshBoard(char playerSymbol)
{ 
    play--;
    board[play] = playerSymbol;
    //-1 because the interval is 0-8

    printf("\n\t\t\t %c | %c | %c ", board[0], board[1], board[2]);
    printf("\n\t\t\t---|---|---");
    printf("\n\t\t\t %c | %c | %c ", board[3], board[4], board[5]);
    printf("\n\t\t\t---|---|---");
    printf("\n\t\t\t %c | %c | %c ", board[6], board[7], board[8]);
}
//refreshs the board with the last player move

int isVictory(char playerSymbol)
{
    //rows
    if
    (
        (board[0] == playerSymbol && board[1] == playerSymbol && board[2] == playerSymbol) ||   
        (board[3] == playerSymbol && board[4] == playerSymbol && board[5] == playerSymbol) ||    
        (board[6] == playerSymbol && board[7] == playerSymbol && board[8] == playerSymbol)
    )
        winnerSymbol = playerSymbol;

    //columns
    if
    (
        (board[0] == playerSymbol && board[3] == playerSymbol && board[6] == playerSymbol) ||
        (board[1] == playerSymbol && board[4] == playerSymbol && board[7] == playerSymbol) ||
        (board[2] == playerSymbol && board[5] == playerSymbol && board[8] == playerSymbol)
    )
        winnerSymbol = playerSymbol;

    //diagonals
    if
    (
        (board[0] == playerSymbol && board[4] == playerSymbol && board[8] == playerSymbol) ||
        (board[2] == playerSymbol && board[4] == playerSymbol && board[6] == playerSymbol)
    )
        winnerSymbol = playerSymbol;

    if(winnerSymbol != ' ')
        return 1;
    else
        return 0; //if every case don't matches, will return false. Therefore, anyone hasn't won.
}
//checks if it's a victory

int isTie()
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i] != 'X' && board[i] != 'O') //it means that the game hasn't finish yet
            return 0;
    }

    return 1; //if it's a tie, returns TRUE 
}

