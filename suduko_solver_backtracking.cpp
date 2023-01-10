#include <stdio.h>
using namespace std;
#define UNASSIGNED 0
#define N 9

bool findUnassigned(int grid[N][N], int& row, int &col);
bool numValid(int grid[N][N], int row, int col, int num);
bool solveSuduko(int grid[N][N]);
bool inCol(int grid[N][N], int col, int num);
bool inRow(int grid[N][N], int row, int num);
bool inBox(int grid[N][N], int start_col, int start_row, int num);

int main(){
    return 0;
}

bool findUnassigned(int grid[N][N], int& row, int &col){
    for(row=0; row<N; row++){
        for(col=0; col<N; col++){
            if(grid[row][col]==UNASSIGNED) return true;
        }
    }
    return false;
}

bool numValid(int grid[N][N], int row, int col, int num);
bool solveSuduko(int grid[N][N]);
bool inCol(int grid[N][N], int col, int num);
bool inRow(int grid[N][N], int row, int num);
bool inBox(int grid[N][N], int start_col, int start_row, int num);