#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


// util functions
void setInitialValues(char (*infinVerb)[30], char (*subPronoun)[5]);
void capitalizeWord(char (*word)[]);
void getInfinVerb(char (*infinVerb)[30]);
void getSubPronoun(char (*subPronoun)[5]);
#include "gvc_utils.c"


int main(void) {
    char infinVerb[30];
    char subPronoun[5];
    setInitialValues(&infinVerb, &subPronoun);
    
}