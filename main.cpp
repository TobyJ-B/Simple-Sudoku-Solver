#include <iostream>
#define N 9

void display(int arr[N][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}




bool checkRow(int grid[N][N],int row ,int num)
{
    for (int i = 0; i < N; i++)
    {
        if(grid[row][i] == num){
            return false;
        }
    }
    return true;
}




bool checkCol(int grid[N][N], int col, int num)
{
    for(int i =0; i< N; i++)
    {
        if (grid[i][col] == num){
            return false;
        }
    }
    return true;
}





bool checkSquare(int grid[N][N], int row, int col, int num)
{
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + startRow][j + startCol] == num){
                return false;
            }
        }
    }
    return true;
}





bool isSafe(int grid[N][N], int row, int col, int num) {
    return checkRow(grid, row, num) && checkCol(grid, col, num) && checkSquare(grid, row, col, num);
}






bool solveSudoku(int grid[N][N], int row, int col)
{
    if (row == N)
    {
        return true;
    }

    if (col == N){
        return solveSudoku(grid, row + 1, 0);
    }

    if (grid[row][col] > 0)
    {
        return solveSudoku(grid, row, col + 1);
    }

    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(grid,row,col,num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid,row,col + 1)){
                return true;
            }
            
            grid[row][col] = 0;
        }
    }
    return false;
}


int main()
{
    int grid [N] [N]{
        {4,0,0,8,0,0,0,0,0},
        {0,0,3,0,5,0,8,0,9},
        {1,0,0,9,3,7,0,2,5},
        {3,0,0,0,6,0,2,0,4},
        {0,0,6,0,2,9,0,0,1},
        {0,9,0,3,0,1,5,0,6},
        {0,1,0,4,0,0,7,0,8},
        {6,0,0,1,8,5,0,4,0},
        {0,8,0,2,7,6,1,5,3},
    };

    display(grid);
    std::cout << "----------------------------\n";

    if (solveSudoku(grid, 0, 0))
    {
        display(grid);
    }
    else
    {
        std::cout << "No solution exists.\n";
    }

    return 0;
}