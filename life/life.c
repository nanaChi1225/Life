//
//  life.c
//  life
//
//  Created by nana on 2022/7/13.
//

#include "life.h"

void copy(Grid map, Grid newmap){
    for(int row=0; row<MAXROW; row++){
        for(int col=0; col<MAXCOL; col++){
            map[row][col] = newmap[row][col];
        }
    }
}
Boolean userYes(){
    int c;
    do{
        printf("countinue?(y/n)\n");
        while((c = getchar())== '\n');
    }while(c!='y' && c!='Y' && c!='n' && c!='N');
    if(c == 'y' || c == 'Y')
        return TRUE;
    else
        return FALSE;
}
void initialize(Grid map){
    int row, col;
    for(row=0; row<MAXROW; row++){
        for(col=0; col<MAXCOL; col++){
            map[row][col] = DEAD;
        }
    }
    scanf("%d%d", &row, &col);
    while (row != -1 || col != -1){
        if(row >= 0 && row<MAXROW && col >= 0 && col<MAXCOL){
            map[row][col] = ALIVE;
        }
        else{
            printf("Values are not within range\n");
        }
        scanf("%d%d", &row, &col);
    }
}
int nightbor(Grid map, int row, int col){
    int i, j, count=0;
    for(i=row-1; i<=row+1; i++){
        for(j=col-1; j<=col+1; j++){
            if(map[i][j]==ALIVE){
                count++;
            }
        }
    }
    if(map[row][col]==ALIVE)
        count--;
    return count;
}
void writeMap(Grid map){
    printf("\n");
    for(int row=0; row<MAXROW; row++){
        for(int col=0; col<MAXCOL; col++){
            if (map[row][col] == ALIVE){
                printf("*");
            }
            else{
                printf("-");
            }
        }
        printf("\n");
    }
}
