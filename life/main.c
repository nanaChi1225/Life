//
//  main.c
//  life
//
//  Created by nana on 2022/7/13.
//

#include <stdio.h>
#include "life.h"

int main() {
    printf("start");
    Grid map;
    Grid newmap;
    initialize(map);
    writeMap(map);
    do{
        for(int row=1; row<=MAXROW; row++){
            for(int col=1; col<=MAXCOL; col++){
                switch(nightbor(map, row, col)){
                    case 0:
                    case 1:
                        newmap[row][col]=DEAD;
                        break;
                    case 2:
                        newmap[row][col]=map[row][col];
                        break;
                    case 3:
                        newmap[row][col]=ALIVE;
                        break;
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        newmap[row][col]=DEAD;
                        break;
                }
            }
        }
        copy(map, newmap);
        writeMap(map);
    }while(userYes());
    return 0;
}
