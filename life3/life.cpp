//
//  life.cpp
//  life3
//
//  Created by nana on 2022/7/19.
//

#include "life.hpp"
using namespace std;


void Life::initialize( ){
    int row, col;
    for (row = 0; row <= maxrow + 1; row++)
        for (col = 0; col <= maxcol + 1; col++)
            grid[row][col] = 0;
    cout << "List the coordinates for living cells." << endl;
    cout << "Terminate the list with the the special pair − 1 − 1" << endl;
    cin >> row >> col;
    while (row!= -1 || col!= -1){
        if (row >= 1 && row <= maxrow)
            if (col >= 1 && col <= maxcol)
                grid[row][col] = 1;
            else
                cout << "Column " << col << " is out of range." << endl;
            else
                cout << "Row " << row << " is out of range." << endl;
        cin >> row >> col;
        
    }
}
void Life::print( ){
    int row, col;
    cout << "\nThe current Life configuration is:" << endl;
    for (row = 1; row <= maxrow; row++) {
        for (col = 1; col <= maxcol; col++)
            if(grid[row][col]== 1)
                cout << "*";
            else
                cout << "-";
            cout << endl;
        
    }
    cout << endl;
}
void Life::update( ){
    int row, col;
    int new_grid[maxrow + 2][maxcol + 2];
    for (row = 1; row <= maxrow; row++)
        for (col = 1; col <= maxcol; col++)
            switch (neighbor_count(row, col)){
                case 2:
                    new_grid[row][col] = grid[row][col];
                    break;
                case 3:
                    new_grid[row][col] = 1;
                    break;
                default:
                    new_grid[row][col] = 0;
            }
    for (row = 1; row <= maxrow; row++)
        for (col = 1; col <= maxcol; col++)
            grid[row][col] = new_grid[row][col];
}
int Life::neighbor_count(int row, int col){
    int i, j, count{0};
    for(i= row-1; i<=row+1; i++){
        for(j= col-1; j<=col+1; j++){
            count = count + grid[i][j];
        }
    }
    count = count - grid[row][col];
    return count;
}
