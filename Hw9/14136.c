#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char* string, char* pattern, int* splittedStrings) {
    int breakpoint=0, prevBreakpoint=0;
    int len_string = strlen(string);
    int len_pattern = strlen(pattern);

    char **split = calloc(250, sizeof(char *));
    while (breakpoint<len_string) {
        while (breakpoint<len_string && strncmp(&string[breakpoint], pattern, len_pattern)) {
            breakpoint++;
        }
        if (breakpoint-prevBreakpoint) {                                                        // when pattern link together, don't store blank string
            split[*splittedStrings] = calloc(breakpoint-prevBreakpoint+1, sizeof(char));        // (+1) for '\0'
            for (int i=0; i<breakpoint-prevBreakpoint; i++) {
                split[*splittedStrings][i] = string[prevBreakpoint+i];
            }
            *splittedStrings += 1;
        }
        breakpoint = prevBreakpoint = breakpoint + len_pattern;
    }
    return split;
}
void free_(char **result, int splitsplittedStrings_num) {
    while (splitsplittedStrings_num--) {
        free(result[splitsplittedStrings_num]);
    }
    free(result);
}

int main(){
    char pattern[10];
    char string[500];
    scanf("%s",string);
    scanf("%s",pattern);
    int splittedStrings = 0;
    char **result = split(string, pattern, &splittedStrings);
    for(int i=0; i<splittedStrings; ++i){
        printf("%s\n",result[i]);
    }
    free_(result, splittedStrings);
    return 0;
}
