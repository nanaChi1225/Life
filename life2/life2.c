//
//  life2.c
//  life2
//
//

#include "life2.h"
#include "common.h"

Grid map;
Gridcount numbernbrs;
List newlive,
     newdie,
     maylive,
     maydie;
int maxrow, maxcol;

int main() {
   
    initialize (map, numbernbrs, &newlive, &newdie, &maylive, &maydie);
    writeMap(map);
    printf("Proceed with the demonstration\n");
    while (userSaysYes()) {
        traverseList(&maylive, vivify);
        writeList(&newlive, "newlive");
        traverseList(&maydie, killCell);
        writeList(&newdie, "newdie");
        writeMap(map);
        writeNumbernbrs(numbernbrs);
        clearList(&maylive);
        clearList(&maydie);
        traverseList(&newlive, addNeighbors);
        writeList(&newlive, "newlive");
        writeNumbernbrs(numbernbrs);
        traverseList(&newdie, subtractNeighbors);
        writeList(&newdie, "newdie");
        writeNumbernbrs(numbernbrs);
        clearList(&newlive);
        clearList(&newdie);
        printf("Continue?(y/n)");
    }
    
    return 0;
}

Boolean userSaysYes(void){
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
void writeMap(Grid map){
    printf("\n");
    for(int row=1; row<MAXROW; row++){
        for(int col=1; col<MAXCOL; col++){
            if (map[row][col] == ALIVE){
                printf("*");
            }
            else{
                printf("-");
            }
        }
        printf("\n");
    }
}//na
void writeNumbernbrs(Gridcount nbrs){
    printf("---numbernbrs\n");
    for(int row=1; row<MAXROW; row++){
        for(int col=1; col<MAXCOL; col++){
            printf("%d,", nbrs[row][col]);
        }
        printf("\n");
    }
}//na

void findSize(int *maxrow, int *maxcol){
    printf("Enter size: row col\n");
    scanf("%d%d", maxrow, maxcol);
}//na
void readMap(List * newlive, Grid map){
    listEntry cell;
    int i, j, r, c;
    for(r=0; r<=maxrow+1; r++){
        for(c=0; c<=maxcol+1; c++){
            map[r][c] = DEAD;//初始化
        }
    }
    printf("On each line give a pair of coordinates for a living cell.\n");
    printf("Terminate the list with the the special pair -1 -1\n");
    scanf("%d%d", &i, &j);
    while (i != -1 || j != -1){
        if(i >= 0 && i<maxrow && j >= 0 && j<maxcol){
            map[i][j] = ALIVE;
            cell.row = i;
            cell.col = j;
            addList(cell, newlive);
        }
        else{
            printf("Values are not within range\n");
        }
        scanf("%d%d", &i, &j);
    }//輸入
}//na

void vivify(listEntry cell){
    if(map[cell.row][cell.col]==DEAD && numbernbrs[cell.row][cell.col]==3){
        if(cell.row>=1 && cell.row<=maxrow && cell.col>=1 && cell.col <= maxcol){
            map[cell.row][cell.col] = ALIVE;
            addList(cell, &newlive);
            
        }
    }
}

void killCell(listEntry cell){
    if(map[cell.row][cell.col]==ALIVE && (numbernbrs[cell.row][cell.col]<2 || numbernbrs[cell.row][cell.col]>3)){
        if(cell.row>=1 && cell.row<=maxrow && cell.col>=1 && cell.col <= maxcol){
            map[cell.row][cell.col] = DEAD;
            addList(cell, &newdie);
        }
    }
}//na

void addNeighbors(listEntry cell){
    int i, j;
    Cell neighbor;
    for(i=cell.row-1; i<=cell.row+1; i++)
        for(j=cell.col-1; j<=cell.col+1; j++)
            if(i!=cell.row||j!=cell.col){
                numbernbrs[i][j]++;
           
                switch(numbernbrs[i][j]){
                    case 0:
                        error("lmpossible case in AddNeighbors.");
                        break;
                    case 3:
                        if(map[i][j]==DEAD){
                            neighbor.row = i;
                            neighbor.col = j;
                            addList(neighbor, &maylive);
                        }
                        break;
                    case 4:
                        if(map[i][j]==ALIVE){
                            neighbor.row = i;
                            neighbor.col = j;
                            addList(neighbor, &maydie);
                        }
                        break;
                }
            }
        
}
void subtractNeighbors(listEntry cell){
    int i, j;
    Cell neighbor;
    for(i=cell.row-1; i<=cell.row+1; i++){
        for(j=cell.col-1; j<=cell.col+1; j++){
            if(i!=cell.row||j!=cell.col){
                numbernbrs[i][j]--;
            }
            switch(numbernbrs[i][j]){
                case 0:
                    error("lmpossible case in AddNeighbors.");
                    break;
                case 3:
                    if(map[i][j]==DEAD){
                        neighbor.row = i;
                        neighbor.col = j;
                        addList(neighbor, &maylive);
                    }
                    break;
                case 4:
                    if(map[i][j]==ALIVE){
                        neighbor.row = i;
                        neighbor.col = j;
                        addList(neighbor, &maydie);
                    }
            }
        }
    }
}//na

void initialize (Grid map, Gridcount numbernbrs, List *newlive, List *newdie, List *maylive, List *maydie){
    int i, j;
    createList(newlive);
    createList(newdie);
    createList(maylive);
    createList(maydie);
    
    findSize(&maxrow, &maxcol);
    readMap(newlive, map);
    
    for(i=0; i<=maxrow; i++){
        for(j=0; j<=maxcol; j++){
            numbernbrs[i][j] = 0;
        }
    }
   
    traverseList(newlive, addNeighbors);
    copyList(maydie, newlive);
    clearList(newlive);
}
