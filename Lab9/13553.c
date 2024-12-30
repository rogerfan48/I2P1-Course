#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alphabet[65];
//implement split string function, return 2d char array to store result, set correct number of splitted strings
char **split(char* string, char* pattern, int* splittedStrings) {
    int prev=0, now=0;
    int ls = strlen(string);
    int lp = strlen(pattern);
    char **splitted = calloc(250, sizeof(char *));
    while (now < ls) {
        while (now < ls && strncmp(&string[now], pattern, lp)) {
            now++;
        }
        if ((now-prev)){
            splitted[*splittedStrings] = calloc(now-prev+1, sizeof(char));
            for (int i=0; i<now-prev; i++) {
                splitted[*splittedStrings][i] = string[prev+i];
            }
            *splittedStrings += 1;
        }
        prev = now = now + lp;
    }
    return splitted;
}
//free memory space
void free_(char **result, int splittedStrings) {
    while (splittedStrings--) {
        free(result[splittedStrings]);
    }
    free(result);
}
//sort each splitted string
void sort( char* string) {
    int** count = calloc(65, sizeof(int*));
    int max;
    int max_index;
    for (int i=0; i<65; i++) {
        count[i] = calloc(100, sizeof(int));
        count[i][0] = 0;
    }
    int len = strlen(string);
    char *ans = calloc(len+1, sizeof(char));
    int ans_index=0;
    for (int i=0; i<len; i++) {
        for (int j=0; j<65; j++) {
            if (string[i] == alphabet[j]) {
                count[j][++count[j][0]] = i;
                break;
            }
        }
    }
    while (1) {
        max = 0;
        for (int i=0; i<65; i++) {
            if (count[i][0]>max) {
                max = count[i][0];
                max_index = i;
            }
        }
        if (max<=1) break;
        int back_index;
        if (max_index>=0 && max_index<26) back_index = max_index + 'A';
        else if (max_index>=26 && max_index<52) back_index = max_index + 'a' - 26;
        else back_index = max_index + '0' - 52;
        for (int i=0; i<count[max_index][0]; i++) {
            ans[ans_index++] = back_index;
            string[count[max_index][i+1]] = 127;
        }
        count[max_index][0] = -1;
    }

    char tmp;
    for (int i=0; i<65; i++) {
        if (count[i][0]==1) {
            if (i>=0 && i<26) tmp = i + 'A';
            else if (i>=26 && i<52) tmp = i + 'a' - 26;
            else tmp = i + '0' - 52;
            ans[ans_index++] = tmp;
        }
    }

    strcpy(string, ans);
    printf("%s\n", string);
}


int main(){
    char pattern[10];
    char string[500];

    scanf("%s",string);
    scanf("%s",pattern);
    int splittedStrings = 0;
    char **result = split(string, pattern, &splittedStrings);
    for( int i = 0 ; i < 26 ; i++ ) alphabet[i] = (char)('A' + i);
    for( int i = 26 ; i < 52 ; i++ ) alphabet[i] = (char)('a' + i - 26 );
    for( int i = 52 ; i < 62 ; i++ ) alphabet[i] = (char)('0' + i - 52 );

    for(int i=0; i<splittedStrings; ++i){
        sort(result[i]);
        // printf("%s\n",result[i]);
    }
    free_(result, splittedStrings);
    return 0;
}