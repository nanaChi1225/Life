//
//  life.h
//  life
//
//  Created by nana on 2022/7/13.
//

#ifndef life_h
#define life_h

#define MAXROW 10
#define MAXCOL 10

#include <stdio.h>
#include "common.h"

typedef enum state{DEAD, ALIVE}State;
typedef State Grid[MAXROW+2][MAXCOL+2];
void copy(Grid map, Grid newmap);
Boolean userYes(void);
void initialize(Grid map);
int nightbor(Grid map, int row, int col);
void writeMap(Grid map);


#endif /* life_h */
