//
//  life2.h
//  life2
//
//

#ifndef life2_h
#define life2_h

#define MAXROW 10
#define MAXCOL 10


#include <stdio.h>
#include "common.h"



typedef enum state{DEAD, ALIVE}State;
typedef State Grid[MAXROW+2][MAXCOL+2];
typedef int Gridcount[MAXROW + 2] [MAXCOL + 2];


#include "simplist.h"
Boolean userSaysYes(void);
void writeMap(Grid);
void writeNumbernbrs(Gridcount);
void findSize(int *, int *);
void readMap(List *, Grid);
void vivify(listEntry);
void killCell(listEntry);

void addNeighbors(listEntry);
void subtractNeighbors(listEntry);
void initialize (Grid, Gridcount, List *, List *, List *, List *);



#endif /* life2_h */
