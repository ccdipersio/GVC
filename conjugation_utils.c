/*
* Sets the inital value of conjVerb based on infinVerb.
* Uses a number of conditions to determine what kind of verb the infinVerb is
*
* char (*conjVerb)[30]: conjugated verb (pointer)
* char (*infinVerb)[30]: infinitive verb (pointer)
* char subPronoun[5]: subject pronoun
* char (*separablePrefix)[10]: separable prefix (pointer) 
* char (*inseparablePrefix)[10]: inseparable prefix (pointer)
*
* returns: Nothing, but the variables passed in as pointers are manipulated as needed.
*/
void setInitialConjVerb(char (*conjVerb)[30], char (*infinVerb)[30], char subPronoun[5], char (*separablePrefix)[10], char (*inseparablePrefix)[10]) {
    prefixSet(infinVerb, separablePrefix, inseparablePrefix);

    int infinVerbLen = strlen(*infinVerb);
    int verbEndingIndex;
    char type;

    if (strcmp(subPronoun, "DU") == 0 || strcmp(subPronoun, "ER") == 0 || strcmp(subPronoun, "SIE") == 0 || strcmp(subPronoun, "ES") == 0)
        type = stemChangeCheck(infinVerb);

    if (strcmp(*infinVerb, "SEIN") == 0)
        verbEndingIndex = 0;
    else if (strcmp(*infinVerb, "TUN") == 0)
        verbEndingIndex = 1;
    else if ((*infinVerb)[infinVerbLen - 2] == 'E' && (*infinVerb)[infinVerbLen - 1] == 'N')
        verbEndingIndex = 2;
    else
        verbEndingIndex = 3;

    for (int i = 0; i < infinVerbLen - verbEndingIndex; i++)
        (*conjVerb)[i] = (*infinVerb)[i];
    (*conjVerb)[infinVerbLen - verbEndingIndex] = '\0';

    if (type == 'e') {
        for (int i = 0; i < strlen(*conjVerb); i++) {
            if ((*conjVerb)[i] == 'E') {
                (*conjVerb)[i] = 'I';
                break;
            }
        }
    } else if (type == 'a' || type == 'i') {
        int conjVerbLen = strlen(*conjVerb);
        (*conjVerb)[conjVerbLen + 1] = '\0';
        for (int i = conjVerbLen; i > 0; i--) {
            if ((*conjVerb)[i] == 'A' || (*conjVerb)[i] == 'E') {
                if (type == 'a')
                    (*conjVerb)[i + 1] = 'E';
                else if (type == 'i') {
                    (*conjVerb)[i] = 'I';
                    (*conjVerb)[i + 1] = 'E';
                }
            } else
                (*conjVerb)[i] = (*conjVerb)[i - 1];
        }
    }
}

/*
* Sets the separable or inseparable prefixes to the correct variables and removes them from infinVerb.
*
* char (*infinVerb)[30]: infinitive verb (pointer)
* char (*separablePrefix)[10]: separable prefix (pointer)
* char (*inseparablePrefix)[10]: inseparable prefix (pointer)
*
* returns: Nothing, but the variables passed in as pointers are manipulated as needed.
*/
void prefixSet(char (*infinVerb)[30], char (*separablePrefix)[10], char (*inseparablePrefix)[10]) { 
	if((*infinVerb)[0] == 'A' && (*infinVerb)[1] == 'B') {
		(*separablePrefix)[0] = 'A'; (*separablePrefix)[1] = 'B'; (*separablePrefix)[2] = '\0';
	} else if((*infinVerb)[0] == 'A' && (*infinVerb)[1] == 'N') { 
		(*separablePrefix)[0] = 'A'; (*separablePrefix)[1] = 'N'; (*separablePrefix)[2] = '\0';
	} else if((*infinVerb)[0] == 'A' && (*infinVerb)[1] == 'U' && (*infinVerb)[2] == 'F') { 
		(*separablePrefix)[0] = 'A'; (*separablePrefix)[1] = 'U'; (*separablePrefix)[2] = 'F'; (*separablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'A' && (*infinVerb)[1] == 'U' && (*infinVerb)[2] == 'S') { 
		(*separablePrefix)[0] = 'A'; (*separablePrefix)[1] = 'U'; (*separablePrefix)[2] = 'S'; (*separablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'B' && (*infinVerb)[1] == 'E' && (*infinVerb)[2] == 'I') { 
		(*separablePrefix)[0] = 'B'; (*separablePrefix)[1] = 'E'; (*separablePrefix)[2] = 'I'; (*separablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'D' && (*infinVerb)[1] == 'U' && (*infinVerb)[2] == 'R' && (*infinVerb)[3] == 'C' && (*infinVerb)[4] == 'H') { 
		(*separablePrefix)[0] = 'D'; (*separablePrefix)[1] = 'U'; (*separablePrefix)[2] = 'R'; (*separablePrefix)[3] = 'C'; (*separablePrefix)[4] = 'H'; (*separablePrefix)[5] = '\0';
	} else if((*infinVerb)[0] == 'E' && (*infinVerb)[1] == 'I' && (*infinVerb)[2] == 'N') { 
		(*separablePrefix)[0] = 'E'; (*separablePrefix)[1] = 'I'; (*separablePrefix)[2] = 'N'; (*separablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'F' && (*infinVerb)[1] == 'O' && (*infinVerb)[2] == 'R' && (*infinVerb)[3] == 'T') { 
		(*separablePrefix)[0] = 'F'; (*separablePrefix)[1] = 'O'; (*separablePrefix)[2] = 'R'; (*separablePrefix)[3] = 'T'; (*separablePrefix)[4] = '\0';
	} else if((*infinVerb)[0] == 'M' && (*infinVerb)[1] == 'I' && (*infinVerb)[2] == 'T') { 
		(*separablePrefix)[0] = 'M'; (*separablePrefix)[1] = 'I'; (*separablePrefix)[2] = 'T'; (*separablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'N' && (*infinVerb)[1] == 'A' && (*infinVerb)[2] == 'C' && (*infinVerb)[3] == 'H') {
		(*separablePrefix)[0] = 'N'; (*separablePrefix)[1] = 'A'; (*separablePrefix)[2] = 'C'; (*separablePrefix)[3] = 'H'; (*separablePrefix)[4] = '\0';
	} else if((*infinVerb)[0] == 'V' && (*infinVerb)[1] == 'O' && (*infinVerb)[2] == 'R') { 
		(*separablePrefix)[0] = 'V'; (*separablePrefix)[1] = 'O'; (*separablePrefix)[2] = 'R'; (*separablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'W' && (*infinVerb)[1] == 'E' && (*infinVerb)[2] == 'G') { 
		(*separablePrefix)[0] = 'W'; (*separablePrefix)[1] = 'E'; (*separablePrefix)[2] = 'G'; (*separablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'Z' && (*infinVerb)[1] == 'U') { 
		(*separablePrefix)[0] = 'Z'; (*separablePrefix)[1] = 'U'; (*separablePrefix)[2] = '\0';
	} else if((*infinVerb)[0] == 'Z' && (*infinVerb)[1] == 'U' && (*infinVerb)[2] == 'R' && (*infinVerb)[3] == 'U' && (*infinVerb)[4] == 'E' && (*infinVerb)[5] == 'C' && (*infinVerb)[6] == 'K') {
		(*separablePrefix)[0] = 'Z'; (*separablePrefix)[1] = 'U'; (*separablePrefix)[2] = 'R'; (*separablePrefix)[3] = 'U'; (*separablePrefix)[4] = 'E'; (*separablePrefix)[5] = 'C'; (*separablePrefix)[6] = 'K'; (*separablePrefix)[7] = '\0';
	} else if((*infinVerb)[0] == 'Z' && (*infinVerb)[1] == 'U' && (*infinVerb)[2] == 'S' && (*infinVerb)[3] == 'A' && (*infinVerb)[4] == 'M' && (*infinVerb)[5] == 'M' && (*infinVerb)[6] == 'E' && (*infinVerb)[7] == 'N') { 
		(*separablePrefix)[0] = 'Z'; (*separablePrefix)[1] = 'U'; (*separablePrefix)[2] = 'S'; (*separablePrefix)[3] = 'A'; (*separablePrefix)[4] = 'M'; (*separablePrefix)[5] = 'M'; (*separablePrefix)[6] = 'E'; (*separablePrefix)[7] = 'N'; (*separablePrefix)[8] = '\0';
	} else {
		(*separablePrefix)[0] = '\0';
	}
	if((*infinVerb)[0] == 'B' && (*infinVerb)[1] == 'E') { 
		(*inseparablePrefix)[0] = 'B'; (*inseparablePrefix)[1] = 'E'; (*inseparablePrefix)[2] = '\0';
	} else if((*infinVerb)[0] == 'E' && (*infinVerb)[1] == 'M' && (*infinVerb)[2] == 'P') { 
		(*inseparablePrefix)[0] = 'E'; (*inseparablePrefix)[1] = 'M'; (*inseparablePrefix)[2] = 'P'; (*inseparablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'E' && (*infinVerb)[1] == 'N' && (*infinVerb)[2] == 'T') { 
		(*inseparablePrefix)[0] = 'E'; (*inseparablePrefix)[1] = 'N'; (*inseparablePrefix)[2] = 'T'; (*inseparablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'E' && (*infinVerb)[1] == 'R') { 
		(*inseparablePrefix)[0] = 'E'; (*inseparablePrefix)[1] = 'R'; (*inseparablePrefix)[2] = '\0';
	} else if((*infinVerb)[0] == 'G' && (*infinVerb)[1] == 'E') { 
		(*inseparablePrefix)[0] = 'G'; (*inseparablePrefix)[1] = 'E'; (*inseparablePrefix)[2] = '\0';
	} else if((*infinVerb)[0] == 'M' && (*infinVerb)[1] == 'I' && (*infinVerb)[2] == 'S' && (*infinVerb)[3] == 'S') { 
		(*inseparablePrefix)[0] = 'M'; (*inseparablePrefix)[1] = 'I'; (*inseparablePrefix)[2] = 'S'; (*inseparablePrefix)[3] = 'S'; (*inseparablePrefix)[4] = '\0';
	} else if((*infinVerb)[0] == 'V' && (*infinVerb)[1] == 'E' && (*infinVerb)[2] == 'R') { 
		(*inseparablePrefix)[0] = 'V'; (*inseparablePrefix)[1] = 'E'; (*inseparablePrefix)[2] = 'R'; (*inseparablePrefix)[3] = '\0';
	} else if((*infinVerb)[0] == 'V' && (*infinVerb)[1] == 'O' && (*infinVerb)[2] == 'L' && (*infinVerb)[3] == 'L') { 
		(*inseparablePrefix)[0] = 'V'; (*inseparablePrefix)[1] = 'O'; (*inseparablePrefix)[2] = 'L'; (*inseparablePrefix)[3] = 'L'; (*inseparablePrefix)[4] = '\0';
	} else if((*infinVerb)[0] == 'Z' && (*infinVerb)[1] == 'E' && (*infinVerb)[2] == 'R') { 
		(*inseparablePrefix)[0] = 'Z'; (*inseparablePrefix)[1] = 'E'; (*inseparablePrefix)[2] = 'R'; (*inseparablePrefix)[3] = '\0';
	} else { 
		(*inseparablePrefix)[0] = '\0';
	}

	if((*separablePrefix)[0] != '\0') { 
		char temp[30]; 
		int prefixLen = strlen(*separablePrefix); 
		int index = 0; 
		for(int i = prefixLen; i < strlen(*infinVerb); i++) {
			temp[index] = (*infinVerb)[i]; 
			index++; 
		}
		temp[index] = '\0'; 
		for(int i = 0; i < strlen(temp); i++) 
			(*infinVerb)[i] = temp[i]; 
		(*infinVerb)[index] = '\0'; 
	}
	if((*inseparablePrefix)[0] != '\0') { 
		char temp[30];
		int prefixLen = strlen(*inseparablePrefix); 
		int index = 0; 
		for(int i = prefixLen; i < strlen(*infinVerb); i++) { 
			temp[index] = (*infinVerb)[i]; 
			index++; 
		}
		temp[index] = '\0'; 
		for(int i = 0; i < strlen(temp); i++)
			(*infinVerb)[i] = temp[i]; 
		(*infinVerb)[index] = '\0'; 
	}

}

/*
* Checks infinVerb to determine if it has a stem change by compariing it against a list of stem chang verbs.
*
* char (*infinVerb)[30]: infinitive verb (pointer)
*
* returns: One of the following codes:
* 	E = E TO I
* 	A = A TO AE
*	I = E TO IE
* 	Z = COULDN'T LOAD LIST
* 	N = VERB NOT IN LIST
*/
char stemChangeCheck(char (*infinVerb)[30]) { 
    FILE* verb_list = fopen("stem_change_verbs.txt", "r"); 
    if(verb_list == NULL) {
        printf("ERROR! Could not load verb list!\n"); 
        return 'Z';
    }

    char r_verb[30]; 
    char letter; 

    while(letter != EOF) { 
        int index = 0; 

        while(letter != ',') { 
            letter = fgetc(verb_list);
            if(letter == EOF) 
                break; 
            r_verb[index] = letter; 
            index++; 
        }
        r_verb[index - 1] = '\0';

        if(strcmp(r_verb, *infinVerb) == 0) 
            return fgetc(verb_list); 
        else { 
            while(letter != '\n') { 
                letter = fgetc(verb_list); 
                if(letter == EOF) 
                    break; 
            }
        }
    }
    fclose(verb_list); 

    return 'N';
}

/*
* Manages which function to use based on what infinVerb is.
*
* char (*conjVerb)[30]: conjugated verb (pointer)
* char (*infinVerb)[30]: infinitive verb (pointer)
* char subPronoun[5]: subject pronoun
*
* returns: Nothing, variables are simply moved around to the appropriate function
*/
void conjugationControl(char (*conjVerb)[30], char (*infinVerb)[30], char subPronoun[5]) {
	int infinVerbLen = strlen(*infinVerb);

	if (strcmp(*infinVerb, "SEIN") == 0)
		conjugateSein(conjVerb, subPronoun);
	else if(strcmp(*infinVerb, "MUESSEN") == 0 || strcmp(*infinVerb, "KOENNEN") == 0 || strcmp(*infinVerb, "MOEGEN") == 0 || strcmp(*infinVerb, "DUERFEN") == 0 || strcmp(*infinVerb, "SOLLEN") == 0 || strcmp(*infinVerb, "WOLLEN") == 0 || strcmp(*infinVerb, "WISSEN") == 0)
		conjugateModal(conjVerb, subPronoun);
	else if((*infinVerb)[infinVerbLen - 3] == 'E' && ((*infinVerb)[infinVerbLen - 2] == 'R' || (*infinVerb)[infinVerbLen - 2] == 'L') && (*infinVerb)[infinVerbLen - 1] == 'N') { 
		char r_or_l[2]; 
		r_or_l[0] = (*infinVerb)[strlen(*infinVerb) - 2];
		r_or_l[1] = '\0'; 
		conjugateERN_ELN(conjVerb, r_or_l, subPronoun);
	} else 
		conjugateNormal(conjVerb, subPronoun);

}

/*
* Conjugates the verb SEIN.
*
* char (*conjVerb)[30]: conjugated verb (pointer)
* char subPronoun[5]: subject pronoun
*
* returns: Nothing, but conjVerb is manipulated.
*/
void conjugateSein(char (*conjVerb)[30], char subPronoun[5]) { 
    if(strcmp(subPronoun, "ICH") == 0) { 
        (*conjVerb)[0] = 'B'; (*conjVerb)[1] = 'I'; (*conjVerb)[2] = 'N'; (*conjVerb)[3] = '\0'; 
    } else if(strcmp(subPronoun, "DU") == 0) {
		(*conjVerb)[0] = 'B'; (*conjVerb)[1] = 'I'; (*conjVerb)[2] = 'S'; (*conjVerb)[3] = 'T'; (*conjVerb)[4] = '\0'; 
	} else if(strcmp(subPronoun, "ER") == 0 || strcmp(subPronoun, "SIE") == 0 || strcmp(subPronoun, "ES") == 0) { 
		(*conjVerb)[0] = 'I'; (*conjVerb)[1] = 'S'; (*conjVerb)[2] = 'T'; (*conjVerb)[3] = '\0';
	} else if(strcmp(subPronoun, "WIR") == 0 || strcmp(subPronoun, "SIEP") == 0) { 
		(*conjVerb)[0] = 'S'; (*conjVerb)[1] = 'I'; (*conjVerb)[2] = 'N'; (*conjVerb)[3] = 'D'; (*conjVerb)[4] = '\0'; 
	} else if(strcmp(subPronoun, "IHR") == 0) {
		(*conjVerb)[0] = 'S'; (*conjVerb)[1] = 'E'; (*conjVerb)[2] = 'I'; (*conjVerb)[3] = 'D'; (*conjVerb)[4] = '\0';
	}
}

/*
* Conjugates modal verbs and WISSEN.
*
* char (*conjVerb)[30]: conjugated verb (pointer)
* char subPronoun: subject pronoun
*
* returns: Nothing, but conjVerb is manipulated.
*/
void conjugateModal(char (*conjVerb)[30], char subPronoun[5]) { 
	if(strcmp(subPronoun, "ICH") == 0 || strcmp(subPronoun, "DU") == 0 || strcmp(subPronoun, "ER") == 0 || strcmp(subPronoun, "SIE") == 0 || strcmp(subPronoun, "ES") == 0) { 
		if(strcmp(*conjVerb, "MUESS") == 0) {
			(*conjVerb)[2] = 'S'; (*conjVerb)[4] = '\0'; 
			if(strcmp(subPronoun, "DU") == 0) 
				(*conjVerb)[4] = 'T'; (*conjVerb)[5] = '\0'; 
		} else if(strcmp(*conjVerb, "KOENN") == 0) { 
			(*conjVerb)[1] = 'A'; (*conjVerb)[2] = 'N'; (*conjVerb)[4] = '\0'; 
			if(strcmp(subPronoun, "DU") == 0)
				(*conjVerb)[4] = 'S'; (*conjVerb)[5] = 'T'; (*conjVerb)[6] = '\0';
		} else if(strcmp(*conjVerb, "MOEG") == 0) { 
			(*conjVerb)[1] = 'A'; (*conjVerb)[2] = 'G'; (*conjVerb)[3] = '\0'; 
			if(strcmp(subPronoun, "DU") == 0)
				(*conjVerb)[3] = 'S'; (*conjVerb)[4] = 'T'; (*conjVerb)[5] = '\0'; 
		} else if(strcmp(*conjVerb, "DUERF") == 0) { 
			(*conjVerb)[1] = 'A'; (*conjVerb)[2] = 'R'; (*conjVerb)[3] = 'F'; (*conjVerb)[4] = '\0';
			if(strcmp(subPronoun, "DU") == 0) 
				(*conjVerb)[4] = 'S'; (*conjVerb)[5] = 'T'; (*conjVerb)[6] ='\0'; 
		} else if(strcmp(*conjVerb, "SOLL") == 0) { 
			if(strcmp(subPronoun, "DU") == 0) 
				(*conjVerb)[4] = 'S'; (*conjVerb)[5] = 'T'; (*conjVerb)[6] = '\0';
		} else if(strcmp(*conjVerb, "WOLL") == 0) { 
			(*conjVerb)[1] = 'I'; 
			if(strcmp(subPronoun, "DU") == 0) 
				(*conjVerb)[4] = 'S'; (*conjVerb)[5] = 'T'; (*conjVerb)[6] = '\0'; 
		} else if(strcmp(*conjVerb, "WISS") == 0) { 
			(*conjVerb)[1] = 'E'; (*conjVerb)[2] = 'I'; (*conjVerb)[4] = 'S'; (*conjVerb)[5] = '\0';
			if(strcmp(subPronoun, "DU") == 0) 
				strcat(*conjVerb, "T"); 
		}
	} else {
		if(strcmp(subPronoun, "WIR") == 0 || strcmp(subPronoun, "SIEP") == 0)
			strcat(*conjVerb, "EN"); 
		else
			strcat(*conjVerb, "T"); 
	}
}

/*
* Conjugates ERN and ELN verbs.
*
* char (*conjVerb)[30]: conjugated verb (pointer)
* char r_or_l[2]: either and 'R' or 'L' based on whichever is in the verb
*
* returns: Nothing, but conjVerb is manipulated.
*/
void conjugateERN_ELN(char (*conjVerb)[30], char r_or_l[2], char subPronoun[5]) { 
	if(strcmp(subPronoun, "ICH") == 0) { 
		strcat(*conjVerb, r_or_l); 
		strcat(*conjVerb, "E"); 
	} else { 
		strcat(*conjVerb, "E"); 
		strcat(*conjVerb, r_or_l); 
		
		if(strcmp(subPronoun, "DU") == 0)
			strcat(*conjVerb, "ST"); 
		else if(strcmp(subPronoun, "ER") == 0 || strcmp(subPronoun, "SIE") == 0 || strcmp(subPronoun, "ES") == 0 || strcmp(subPronoun, "IHR") == 0) 
			strcat(*conjVerb, "T"); 
		else if(strcmp(subPronoun, "WIR") == 0 || strcmp(subPronoun, "SIEP") == 0) 
			strcat(*conjVerb, "N");
	}
}

/*
* Conjugates normal verbs.
*
* char (*conjVerb)[30]: conjugated verb (pointer)
* char subPronoun[5]: subject pronoun
*
* returns: Nothing, but conjVerb is manipulated.
*/
void conjugateNormal(char (*conjVerb)[30], char subPronoun[5]) { 
	if(strcmp(*conjVerb, "HAB") == 0 && (strcmp(subPronoun, "DU") == 0 || strcmp(subPronoun, "ER") == 0 || strcmp(subPronoun, "SIE") == 0 || strcmp(subPronoun, "ES") == 0)) 
		(*conjVerb)[2] = '\0'; 
	else if(strcmp(*conjVerb, "WIRD") == 0 && strcmp(subPronoun, "DU") == 0)
		(*conjVerb)[3] = '\0';

	int conjVerbLen = strlen(*conjVerb) - 1; 
	if(strcmp(subPronoun, "ICH") == 0) { 
		strcat(*conjVerb, "E"); 
	} else if(strcmp(subPronoun, "DU") == 0) { 
		if((*conjVerb)[conjVerbLen] == 'S') 
			strcat(*conjVerb, "T");
		else if((*conjVerb)[conjVerbLen] == 'T' || (*conjVerb)[conjVerbLen] == 'D')
			strcat(*conjVerb, "EST"); 
		else 
			strcat(*conjVerb, "ST"); 
	} else if(strcmp(subPronoun, "ER") == 0 || strcmp(subPronoun, "SIE") == 0 || strcmp(subPronoun, "ES") == 0 || strcmp(subPronoun, "IHR") == 0) {
        if((strcmp(subPronoun, "ER") == 0 || strcmp(subPronoun, "SIE") == 0 || strcmp(subPronoun, "ES") == 0) && strcmp(*conjVerb, "WIRD") == 0) 
            (*conjVerb)[4] = '\0'; 
		else if((*conjVerb)[conjVerbLen] == 'T' || (*conjVerb)[conjVerbLen] == 'D') 
			strcat(*conjVerb, "ET"); 
		else 
			strcat(*conjVerb, "T"); 
	} else if(strcmp(subPronoun, "WIR") == 0 || strcmp(subPronoun, "SIEP") == 0) {
		if(strcmp(*conjVerb, "TU") == 0) 
			strcat(*conjVerb, "N"); 
		else 
			strcat(*conjVerb, "EN"); 
	}
}