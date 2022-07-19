//
//  simplist.c
//  life2
//
//

#include "simplist.h"
#include "common.h"



void createList(List *list){
    list->count = 0;
}
void clearList(List *list){
    list->count = 0;
}
Boolean listEmpty(const List *list){
    return list->count <= 0;
}
Boolean listFull(const List *list){
    return list->count >= MAXLIST;
}
int listSize(const List *list){
    return list->count;
}
void addList(listEntry x, List *list){
    if(listFull(list)){
        warning("Attempt to insert at the end of a full list");
    }
    else
        list->entry[list->count++]=x;
}
void traverseList(List*list, void (*visit)(listEntry)){
    for(int i=0; i<list->count; i++){
        (*visit)(list->entry[i]);
    }
}
void copyList(List *maylist, const List *newlist){
    for(int i=0; i<newlist->count; i++){
        maylist->entry[i] = newlist->entry[i];
    }
    maylist->count = newlist->count;
}

void writeList(List * list, char * listName){
    printf("\n%s: ", listName);
    for(int i=0; i<list->count; i++){
        printf("%d %d, ", list->entry[i].row, list->entry[i].col);
    }
    printf("\n");
}
