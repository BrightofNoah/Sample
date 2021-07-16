#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
void printSolution(int board[8][8])
{
	cout<<"Solution:\n";
   	for (int i = 0; i<8; i++)
    	{
        		for (int j = 0; j < 8; j++)
            		cout<<board[i][j]<<"  ";
        			cout<<endl;
    	}
}
bool isSafe(int board[8][8],int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
     for (i = row, j = col; j >= 0 && i<8; i++, j--)
    {
        if (board[i][j])
            return false;
    }
 	return true;
}
bool solveNQUtil(int board[8][8], int col)
{
    if (col >= 8)
        return true;
    for (int i = 0; i < 8; i++)
    {
        if ( isSafe(board, i, col) )
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1) == true)
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
bool solveNQ()
{
    int board[8][8] = {0};
    if (solveNQUtil(board, 0) == false)
    {
        cout<<"Solution does not exist"<<endl;
        return false;
    }
    printSolution(board);
    return true;
}
int main()
{
    solveNQ();
    return 0;
}
