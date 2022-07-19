//
//  main.c
//  life2
//
//

#include <stdio.h>
#include <ctype.h>
#include "life2.h"

void print(listEntry);
//void introduction(void);
void help(void);
char getCommand(void);
void doCommand(char, List *);



void help(void){
    printf("\nThis program allows one command to be entered on each line.\n"
           "For example, if the command I is entered at the command line\n"
           "then the program will ask for a string of characters and\n"
           "insert them one at a time into the simple list.\n");
    printf("Valid commands are:\n"
           "\tl - Insert values into the simple list\n"
           "\tP - Print the simple list\n"
           "\tT - Traverse the simple list (same as print)\n" "\tS - The current size of the simple list\n"
           "\tD - Delete the simple list\n"
           "\tC - Clear the simple list (same as delete)\n" "\tH - This help screen\n"
           "\tQ - Quit\n"
           "Press < Enter> to continue.");
    while(getchar()!='\n');

}

char getCommand(void){
    char command;
    printf("\n\t[l]nsert entry\t[P]rint list\t[S]ize of list\n"
           "\t[D]elete list\t[C]lear list\t[H]elp\n"
           "\t[T]raverse the list\t\t[Q]uit.\n"
           "Select command and press < Enter > :");
    while (TRUE){
        while((command=getchar())=='\n')
            command = tolower(command);
        if (command=='i' || command=='p' || command =='t' || command== 's'||command=='d'||command=='c'|| command=='h' || command=='q'){
            while (getchar()!='\n') {
                return command;
            }
        }
        printf("Please enter a valid command or H for help:");
    }
}
void doCommand(char commond, List* list){
    listEntry x;
    switch(commond){
        case 'i':
            if (listFull(list))
                warning("Sorry,listisfull.");
            else {
                printf("Enter new key(s) to insert:");
                scanf("%d%d", &x.row, &x.col);
                addList(x, list);
                }
            break;
        case 'd':
        case 'c':
            clearList(list);
            printf("List is cleared.\n");
            break;
        case 'p':
        case 't':
            if (listEmpty(list))
                printf("List is empty.\n");
            else{
                printf("\nTraversing the list; it contains:\n");
                traverseList(list, print);
            }
            break;
        case 's':
            printf("Thesizeofthelistis%d\n",listSize(list));
            break;
        case 'h':
            help();
            break;
        case 'q':
            printf("Simple list demonstration finished.\n");
            exit(0);
    }
}

void print(listEntry x){
    printf("%d%d",x.row, x.col);
}
