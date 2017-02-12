/*
* Sets initial values for infinVerb and subPronoun.
*
* char (*infinVerb)[30]: infinitive verb (pointer)
* char (*subPronoun)[5]: subject pronoun (pointer)
*
* returns: Nothing, but infinVerb and subPronoun are assigned values.
*/
void setInitialValues(char (*infinVerb)[30], char (*subPronoun)[5]) {
    getInfinVerb(infinVerb);    
    getSubPronoun(subPronoun);
}

/*
* Capitalizes strings passed in.
*
* char (*word)[]: any given string (pointer)
*
* returns: Nothing, but the passed in string is capitalized.
*/
void capitalizeWord(char (*word)[]) {
    int wordLen = strlen(*word);
    for (int i = 0; i < wordLen; i++)
        (*word)[i] = toupper((*word)[i]);
}

/*
* Gets, validates, and sets the user-given value for infinVerb.
*
* char (*infinVerb)[30]: infintive verb (pointer)
*
* returns: Nothing, but infinVerb is assigned a value.
*/
void getInfinVerb(char (*infinVerb)[30]) {
    int infinVerbLen = 0;
    do {
        printf("Infinitive Verb: ");
        scanf("%s", *infinVerb);
        capitalizeWord(infinVerb); 
        infinVerbLen = strlen(*infinVerb);
    } while (strcmp(*infinVerb, "SEIN") != 0 && strcmp(*infinVerb, "TUN") != 0 && ((*infinVerb)[infinVerbLen - 2] != 'E' || (*infinVerb)[infinVerbLen - 1] != 'N') && ((*infinVerb)[infinVerbLen - 3] != 'E' || ((*infinVerb)[infinVerbLen - 2] != 'R' && (*infinVerb)[infinVerbLen - 2] != 'L') || (*infinVerb)[infinVerbLen - 1] != 'N'));
}

/*
* Gets validates, and sets the user-given value for subPronoun.
*
* char (*subPronoun)[5]: subject pronoun (pointer)
*
* returns: Nothing, but subPronoun is assigned a value.
*/
void getSubPronoun(char (*subPronoun)[5]) {
    int subPronounLen = 0;
    do {
        printf("Subject Pronoun: ");
        scanf("%s", *subPronoun);
        capitalizeWord(subPronoun);
        subPronounLen = strlen(*subPronoun);
    } while (strcmp(*subPronoun, "ICH") != 0 && strcmp(*subPronoun, "DU") != 0 && strcmp(*subPronoun, "ER") != 0 && strcmp(*subPronoun, "SIE") != 0 && strcmp(*subPronoun, "ES") != 0 && strcmp(*subPronoun, "WIR") != 0 && strcmp(*subPronoun, "IHR") != 0 && strcmp(*subPronoun, "SIEP") != 0);
}