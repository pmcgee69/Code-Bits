//  see :  https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include <iostream>
#include <iomanip>
using namespace std;

#define N 6  //8
#define XX 1
#define YY 0

unsigned long moves = 0;

int solveKTUtil(int x, int y, int movei, int sol[N][N],
				int xMove[], int yMove[]);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
	return (x >= 0 && x < N && y >= 0 && y < N
			&& sol[x][y] == -1);
}

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	cout << endl << endl;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout << " " << std::setw(2) << sol[x][y] << " ";
		cout << endl;
	}
	cout << "\nMoves explored: " << moves << endl;
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
	int sol[N][N];

	/* Initialization of solution matrix */
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	/* xMove[] and yMove[] define next move of Knight.
	xMove[] is for next value of x coordinate
	yMove[] is for next value of y coordinate */
	int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	sol[XX][YY] = 0;

	/* Start from 0,0 and explore all tours using
	solveKTUtil() */
	if (solveKTUtil(XX, YY, 1, sol, xMove, yMove) == 0) {
		cout << "Solution does not exist";
		return 0;
	}
	else
		printSolution(sol);

	return 1;
}

/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
				int xMove[N], int yMove[N])
{
	int k, next_x, next_y;
	if (movei == N * N)
		return 1;

	++moves;
	if ((moves << 6) == 0)
			cout << std::setw(10) << moves << "  ";

	/* Try all next moves from
	the current coordinate x, y */
	for (k = 0; k < 8; k++) {
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol)) {
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y, movei + 1, sol,
							xMove, yMove)
                == 1)
                return 1;
            else
                
               // backtracking
                sol[next_x][next_y] = -1;
        }
	}
	return 0;
}

// Driver Code
int main()
{
	  // Function Call
	solveKT();

    getchar();
	return 0;
}
