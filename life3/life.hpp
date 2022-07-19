//
//  life.hpp
//  life3
//
//  Created by nana on 2022/7/19.
//

#ifndef life_hpp
#define life_hpp
#include <stdio.h>
#include <iostream>

using namespace std;

const int maxrow = 10, maxcol = 10;

class Life{
public:
    void initialize( );
    void print( );
    void update( );
public:
    int grid [maxrow + 2][maxcol + 2];
    int neighbor_count(int row, int col);
};

#endif /* life_hpp */
