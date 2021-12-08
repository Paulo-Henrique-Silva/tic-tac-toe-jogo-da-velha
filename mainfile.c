//this was made by: Paulo
//It's totally free to use 
//github: Paulo-Henrique-Silva

//it does have the PvsI.A mode yet

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char board[9];
char winnerSymbol;

void PlayerVsPlayer(); 
void createBoard();
int isValid(int input);
void refreshBoard(char playerSymbol, int play);
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
    int play;

    createBoard(); 

    while(1)
    {
        printf("\n\nPlayer 1 Turn - Type your play(1 - 9): ");
        scanf("%d", &play);
        play = isValid(play);

        system("cls"); //clean the screen for the next move

        refreshBoard(PLAYER1, play);

        if(isVictory(PLAYER1) || isTie())
            break; 

        printf("\n\nPlayer 2 Turn - Type your play(1 - 9): ");
        scanf("%d", &play);
        play = isValid(play);

        system("cls");

        refreshBoard(PLAYER2, play);

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

int isValid(int input)
{
    while(input < 1 || input > 9 || board[input - 1] == 'X' || board[input - 1] == 'O')
    {
        printf("Invalid input! Type again: ");
        scanf("%d", &input);
    }

    return input;
}
//checks if the user input is between the board interval or if it has been taken already

void refreshBoard(char playerSymbol, int play)
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

int isVictory(char symb)
{
    //rows
    if
    (
        (board[0] == symb && board[1] == symb && board[2] == symb) ||   
        (board[3] == symb && board[4] == symb && board[5] == symb) ||    
        (board[6] == symb && board[7] == symb && board[8] == symb)
    )
        winnerSymbol = symb;

    //columns
    if
    (
        (board[0] == symb && board[3] == symb && board[6] == symb) ||
        (board[1] == symb && board[4] == symb && board[7] == symb) ||
        (board[2] == symb && board[5] == symb && board[8] == symb)
    )
        winnerSymbol = symb;

    //diagonals
    if
    (
        (board[0] == symb && board[4] == symb && board[8] == symb) ||
        (board[2] == symb && board[4] == symb && board[6] == symb)
    )
        winnerSymbol = symb;

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

