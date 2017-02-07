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
// conjugation util functions
void setInitialConjVerb(char (*conjVerb)[30], char (*infinVerb)[30], char (*subPronoun)[5], char (*separablePrefix)[10], char (*inseparablePrefix)[10]);
void prefixSet(char (*infinVerb)[30], char (*separablePrefix)[10], char (*inseparablePrefix)[10]);
char stemChangeCheck(char (*infinVerb)[30]);
#include "conjugation_utils.c"


int main(void) {
    char infinVerb[30];
    char subPronoun[5];
    setInitialValues(&infinVerb, &subPronoun);

    char conjVerb[30];
    char separablePrefix[10];
    char inseparablePrefix[10];

    setInitialConjVerb(&conjVerb, &infinVerb, &subPronoun, &separablePrefix, &inseparablePrefix);

    printf("conjverb: %s\nseppre: %s\ninsep: %s\n", conjVerb, separablePrefix, inseparablePrefix);
    
    // up to conjugation control in present tense!!

}