//
//  simplist.h
//  life2
//
//

#ifndef simplist_h
#define simplist_h
#define MAXLIST 30

#include <stdio.h>
#include "common.h"

typedef struct cell {
    int row,col;
} Cell;
typedef Cell listEntry;

typedef struct list {
    int count;
    listEntry entry[MAXLIST];
} List;
void createList(List *);
void clearList(List *);
Boolean listEmpty(const List *);
Boolean listFull(const List *);
int listSize(const List *);
void addList(listEntry, List *);
void traverseList(List *, void(*)(listEntry));
void copyList(List *, const List *);
void writeList(List*, char *);

#endif /* simplist_h */
