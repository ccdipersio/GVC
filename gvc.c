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
void setInitialConjVerb(char (*conjVerb)[30], char (*infinVerb)[30], char subPronoun[5], char (*separablePrefix)[10], char (*inseparablePrefix)[10]);
void prefixSet(char (*infinVerb)[30], char (*separablePrefix)[10], char (*inseparablePrefix)[10]);
char stemChangeCheck(char (*infinVerb)[30]);
void conjugationControl(char (*conjVerb)[30], char (*infinVerb)[30], char subPronoun[5]);
void conjugateSein(char (*conjVerb)[30], char subPronoun[5]);
void conjugateModal(char (*conjVerb)[30], char subPronoun[5]);
void conjugateERN_ELN(char (*conjVerb)[30], char r_or_l[2], char subPronoun[5]);
void conjugateNormal(char (*conjVerb)[30], char subPronoun[5]);
#include "conjugation_utils.c"


int main(void) {
    char infinVerb[30];
    char subPronoun[5];
    setInitialValues(&infinVerb, &subPronoun);

    char conjVerb[30];
    char separablePrefix[10];
    char inseparablePrefix[10];

    setInitialConjVerb(&conjVerb, &infinVerb, subPronoun, &separablePrefix, &inseparablePrefix);

    conjugationControl(&conjVerb, &infinVerb, subPronoun);

    printf("%s %s%s %s\n", subPronoun, inseparablePrefix, conjVerb, separablePrefix);

}