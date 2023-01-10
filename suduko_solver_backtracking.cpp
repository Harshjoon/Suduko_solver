#include <stdio.h>
#include <iostream>
using namespace std;
#define UNASSIGNED 0
#define N 9

bool findUnassigned(int grid[N][N], int& row, int &col);
bool numValid(int grid[N][N], int row, int col, int num);
bool solveSuduko(int grid[N][N]);
bool inCol(int grid[N][N], int col, int num);
bool inRow(int grid[N][N], int row, int num);
bool inBox(int grid[N][N], int start_col, int start_row, int num);
void print(int grid[N][N]);

int main(){
    int grid[N][N] = {{5,3,0,0,7,0,0,0,0},
                      {6,0,0,1,9,5,0,0,0},
                      {0,9,8,0,0,0,0,6,0},
                      {8,0,0,0,6,0,0,0,3},
                      {4,0,0,8,0,3,0,0,1},
                      {7,0,0,0,2,0,0,0,6},
                      {0,6,0,0,0,0,2,8,0},
                      {0,0,0,4,1,9,0,0,5},
                      {0,0,0,0,8,0,0,7,9}};
    
    if(solveSuduko(grid)) print(grid);
    else cout << "no solution" << endl;
    return 0;
}
// solve suduko by backtracking
bool solveSuduko(int grid[N][N]){
    int row, col;
    if( !findUnassigned(grid, row, col) ) return true;
    for(int num=1;num<=9;num++){
        if(numValid(grid, row, col, num)){
            grid[row][col] = num;
            if(solveSuduko(grid)) return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

bool findUnassigned(int grid[N][N], int & row, int & col){
    for(row=0; row<N; row++){
        for(col=0; col<N; col++){
            if(grid[row][col]==UNASSIGNED) return true;
        }
    }
    return false;
}

bool inCol(int grid[N][N], int col, int num){
    for(int row=0; row < N; row++){
        if( grid[row][col] == num ) return true;
    }
    return false;
}

bool inRow(int grid[N][N], int row, int num){
    for(int col=0; col < N; col++){
        if( grid[row][col]==num ) return true;
    }
    return false;
}

bool inBox(int grid[N][N], int start_row, int start_col, int num){
    for(int row=0; row<3; row++){
        for( int col=0; col<3; col++ ){
            if( grid[start_row + row][start_col + col] == num ) return true;
        }
    }
    return false;
}

bool numValid(int grid[N][N], int row, int col, int num){
    return grid[row][col] == UNASSIGNED 
        && !inCol(grid, col, num)
        && !inRow(grid, row, num)
        && !inBox(grid, row - row%3, col - col%3, num);
}

void print(int grid[N][N]){
    for(int row=0; row<N; row++){
        for(int col=0;col<N; col++){
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}