void setInitialValues(char (*infinVerb)[30], char (*subPronoun)[5]) {
    getInfinVerb(infinVerb);    
    getSubPronoun(subPronoun);
    printf("Verb: %s\nPronoun: %s\n", *infinVerb, *subPronoun);
}

void capitalizeWord(char (*word)[]) {
    int wordLen = strlen(*word);
    for (int i = 0; i < wordLen; i++)
        (*word)[i] = toupper((*word)[i]);
}

void getInfinVerb(char (*infinVerb)[30]) {
    int infinVerbLen = 0;
    do {
        printf("Infinitive Verb: ");
        scanf("%s", *infinVerb);
        capitalizeWord(infinVerb); 
        infinVerbLen = strlen(*infinVerb);
    } while (strcmp(*infinVerb, "SEIN") != 0 && strcmp(*infinVerb, "TUN") != 0 && ((*infinVerb)[infinVerbLen - 2] != 'E' || (*infinVerb)[infinVerbLen - 1] != 'N') && ((*infinVerb)[infinVerbLen - 3] != 'E' || ((*infinVerb)[infinVerbLen - 2] != 'R' && (*infinVerb)[infinVerbLen - 2] != 'L') || (*infinVerb)[infinVerbLen - 1] != 'N'));
}

void getSubPronoun(char (*subPronoun)[5]) {
    int subPronounLen = 0;
    do {
        printf("Subject Pronoun: ");
        scanf("%s", *subPronoun);
        capitalizeWord(subPronoun);
        subPronounLen = strlen(*subPronoun);
    } while (strcmp(*subPronoun, "ICH") != 0 && strcmp(*subPronoun, "DU") != 0 && strcmp(*subPronoun, "ER") != 0 && strcmp(*subPronoun, "SIE") != 0 && strcmp(*subPronoun, "ES") != 0 && strcmp(*subPronoun, "WIR") != 0 && strcmp(*subPronoun, "IHR") != 0 && strcmp(*subPronoun, "SIEP") != 0);
}