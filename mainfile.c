//this was made by: Paulo
//It's totally free to use 
//github: Paulo-Henrique-Silva

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> 

char board[9];
char winnerSymbol;
int play = 0, iaDifficult; 

enum difficult {easy = 1, medium, hard};

void PlayerVsPlayer(); 
void PlayerVsIA();

void createBoard();
void isValid();
void refreshBoard(char playerSymbol);

void computerPlay();
int computerAttack();
int computerDefend();
void computerRandom();

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
                PlayerVsIA();
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

    while(1) //continues the game "forever", until someone wins
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
        printf("\nPLAYER 1 WINS");
    else if(winnerSymbol == 'O')
        printf("\nPLAYER 2 WINS");
    else
        printf("\nIT'S A TIE!");
}
//this is the player vs player mode

void PlayerVsIA()
{
    const char PLAYER = 'X', COMPUTER = 'O';

    do
    {
        system("cls");
        printf("\t\t\tDIFFICULT SELECTOR\n");
        printf("\n\t\t\t[1] - Easy");
        printf("\n\t\t\t[2] - Medium");
        printf("\n\t\t\t[3] - Hard");
        printf("\n\nType: ");
        scanf("%d", &iaDifficult);

        if(iaDifficult < 1 || iaDifficult > 3)
        {
            printf("Invalid Input. Type Again!");
            getch();
        }
    } while(iaDifficult < 1 || iaDifficult > 3);
    
    system("cls");
    createBoard(); 

    while(1)
    {
        printf("\n\nPlayer Turn - Type your play(1 - 9): ");
        scanf("%d", &play);
        isValid();

        system("cls"); //clean the screen for the next move
        refreshBoard(PLAYER);

        if(isVictory(PLAYER) || isTie())
            break; 

        system("cls");
        computerPlay();
        refreshBoard(COMPUTER);

        if(isVictory(COMPUTER) || isTie())
            break; 
    }

    printf("\n\nEND GAME!");

    if(winnerSymbol == 'X')
        printf("\nPLAYER WINS");
    else if(winnerSymbol == 'O')
        printf("\nCOMPUTER WINS");
    else
        printf("\nIT'S A TIE!");
}
//PLAYER vs IA

void computerPlay()
{ 
    switch(iaDifficult)
    {
        case easy: //just play
            computerRandom();
            break;

        case medium: //tries to defend
            if(computerDefend())
                break;
            else
                computerRandom();
            break;

        case hard: //tries to attack and defend
            if(computerAttack())
                break;
            else if(computerDefend())
                break;
            else
                computerRandom();
            break;
        //the computer will check if it cans attacks
        //if it cant's, then will try to defend
        //if it does not need a defense, will just play randomly
    }  
}

int computerAttack()
{
    int i;

//the computer, in the next lines, will try to find if it can attack and finish the game 

    //rows
    for(i = 0; i <= 6; i+=3)
    {
        if(board[i] == 'O' && board[i+1] == 'O' && (board[i+2] != 'X' && board[i+2] != 'O'))
        {
            play = i + 3; //it's not i + 2, because the invertal is 0-8
            return 1; //if it returns 1, it means that it was need a defense
        }
        else if(board[i] == 'O' && (board[i+1] != 'X' && board[i+1] != 'O') && board[i+2] == 'O' )
        {
            play = i + 2;
            return 1;
        }
        else if((board[i] != 'X' && board[i] != 'O') && board[i+1] == 'O' && board[i+2] == 'O' )
        {
            play = i + 1;
            return 1;
        }
    }

    //columns
    for(i = 0; i <= 2; i++)
    {
        if(board[i] == 'O' && board[i+3] == 'O' && (board[i+6] != 'X' && board[i+6] != 'O'))
        {
            play = i + 7;
            return 1;
        }
        else if(board[i] == 'O' && (board[i+3] != 'X' && board[i+3] != 'O') && board[i+6] == 'O' )
        {
            play = i + 4;
            return 1;
        }
        else if((board[i] != 'X' && board[i] != 'O') && board[i+3] == 'O' && board[i+6] == 'O' )
        {
            play = i + 1;
            return 1;
        }
    }
    
    //main diagonal
    if(board[0] == 'O' && board[4] == 'O' && (board[8] != 'X' && board[8] != 'O'))
    {
        play = 9;
        return 1;
    }
    else if(board[0] == 'O' && (board[4] != 'X' && board[4] != 'O') && board[8] == 'O' )
    {
        play = 5;
        return 1;
    }
    else if((board[0] != 'X' && board[0] != 'O') && board[4] == 'O' && board[8] == 'O' )
    {
        play = 1;
        return 1;
    }

    //second diagonal
    if(board[2] == 'O' && board[4] == 'O' && (board[6] != 'X' && board[6] != 'O'))
    {
        play = 7;
        return 1;
    }
    else if(board[2] == 'O' && (board[4] != 'X' && board[4] != 'O') && board[6] == 'O' )
    {
        play = 5;
        return 1;
    }
    else if((board[2] != 'X' && board[2] != 'O') && board[4] == 'O' && board[6] == 'O' )
    {
        play = 3;
        return 1;
    }

    return 0; //if does not need, returns 0(no)
}

int computerDefend()
{
    int i;

//the computer, in the next lines, will defend itself against a possible defeat(if it needs)

    //rows
    for(i = 0; i <= 6; i+=3)
    {
        if(board[i] == 'X' && board[i+1] == 'X' && (board[i+2] != 'X' && board[i+2] != 'O'))
        {
            play = i + 3;
            return 1; //if it returns 1, it means that it was need a defense
        }
        else if(board[i] == 'X' && (board[i+1] != 'X' && board[i+1] != 'O') && board[i+2] == 'X' )
        {
            play = i + 2;
            return 1;
        }
        else if((board[i] != 'X' && board[i] != 'O') && board[i+1] == 'X' && board[i+2] == 'X' )
        {
            play = i + 1;
            return 1;
        }
    }

    //columns
    for(i = 0; i <= 2; i++)
    {
        if(board[i] == 'X' && board[i+3] == 'X' && (board[i+6] != 'X' && board[i+6] != 'O'))
        {
            play = i + 7;
            return 1;
        }
        else if(board[i] == 'X' && (board[i+3] != 'X' && board[i+3] != 'O') && board[i+6] == 'X' )
        {
            play = i + 4;
            return 1;
        }
        else if((board[i] != 'X' && board[i] != 'O') && board[i+3] == 'X' && board[i+6] == 'X' )
        {
            play = i + 1;
            return 1;
        }
    }
    
    //main diagonal
    if(board[0] == 'X' && board[4] == 'X' && (board[8] != 'X' && board[8] != 'O'))
    {
        play = 9;
        return 1;
    }
    else if(board[0] == 'X' && (board[4] != 'X' && board[4] != 'O') && board[8] == 'X' )
    {
        play = 5;
        return 1;
    }
    else if((board[0] != 'X' && board[0] != 'O') && board[4] == 'X' && board[8] == 'X' )
    {
        play = 1;
        return 1;
    }

    //second diagonal
    if(board[2] == 'X' && board[4] == 'X' && (board[6] != 'X' && board[6] != 'O'))
    {
        play = 7;
        return 1;
    }
    else if(board[2] == 'X' && (board[4] != 'X' && board[4] != 'O') && board[6] == 'X' )
    {
        play = 5;
        return 1;
    }
    else if((board[2] != 'X' && board[2] != 'O') && board[4] == 'X' && board[6] == 'X' )
    {
        play = 3;
        return 1;
    }

    return 0;
}

void computerRandom()
{
    srand(time(0)); //a random seed to generate a random number

    do
        play = rand() % 9 + 1; //a num between 9 and 1
    while(board[play - 1] == 'X' || board[play - 1] == 'O');
}

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

