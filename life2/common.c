//
//  common.c
//  life2
//
//

#include "common.h"
void error(char *s){
    fprintf(stderr, "Error:%s\n", s);
    exit(1);
}
void warning(char * message){
    fprintf(stderr, "Error:%s\n",message);
    exit(1);
}
