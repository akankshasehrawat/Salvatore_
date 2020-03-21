#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

#define N 4  //maze size



//*******************************TIC TAC TOE!!************************************8


char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();

void tictactoe()
{
	int player = 1,i,choice;

    char mark;
    do
    {
        board();
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=checkwin();

        player++;
    }while(i==-1);
    board();
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();

}

/*********************************************
    FUNCTION TO RETURN WINNER
**********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
    system("CLS");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}


//*******************MAZE!!**********************************************************************************


bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

/* A utility function to check if x, y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x, y outside maze) return false
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

/* This function solves the Maze problem using BacktraCKING*/
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };

    if (solveMazeUtil(maze, 0, 0, sol) == false) {
        printf("Solution doesn't exist");
        return false;
    }

    printSolution(sol);
    return true;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x, y is goal) return true
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y) == true) {
        // mark x, y as part of solution path
        sol[x][y] = 1;

        /* Move forward in x direction */
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;

        /* If none of the above movements work then BACKTRACK:
            unmark x, y as part of solution path */
        sol[x][y] = 0;
        return false;
    }

    return false;
}


void Maze()
{

   cout<<"\n Computer generated maze\n";




      int maze[N][N] = { { 1, 0, 1, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 1, 0 },
                       { 1, 1, 1, 1 } };

            cout<<"\n\n Maze :\n";
            for(int i=0; i<N; i++)
             {
                 for(int j=0; j<N; j++)
                 {
                   cout<< maze[i][j]<< "\t";
                 }
                cout<< endl;
              }
            cout<<"\n\n Path :\n";
            solveMaze(maze);


     /* case 2: cout<<"\nMake your Maze(using 1 and 0) \n";
              for(int i=0; i<N; i++)
              {
                  for(int j=0; j<N; j++)
                  {
                      cin>>maze1[i][j];
                      cout<<"\t";

                  }
                  cout<< endl;
              }

              cout<<"\n\nMaze :\n";
              for(int i=0; i<N; i++)
              {
                  for(int j=0; j<N; j++)
                  {
                      cout<<maze1[i][j]<<"\t";

                  }
                  cout<< endl;
              }
              cout<<"\n\nPath :\n";
              solveMaze(maze1);
              break;
      default : cout<<"\nInvalid Choice\n";
   }*/
}




int main()
{
    system("CLS");
    char f;
    do{
    system("CLS");
    cout << "\n\t\t SALVATORE\t\t" << endl;
    cout << "\t\tWelcome to Salvatore\t\t" << endl;
    int x;
    cout<< "\n\n\t 1. TIC TAC TOE \n";
    cout<< "\t 2. MAZE SOLVER \n";
    cout<< "\t 3. EXIT \n";
    cout<<"\nChoose one option (1,2,3) \n";
    cin>> x;

    switch(x)
    {
        case 1 : tictactoe();
                 break;
        case 2 : Maze();
                 break;
        case 3 : exit(1);
                 break;
        default : cout<<" \n\t\tINVALID CHOICE \t\n";
    }
    cout<<"\nWanna play again?(y/n)";
    cin>>f;
    }while(f=='y'|| f=='Y');

    getch();
    return 0;

}

