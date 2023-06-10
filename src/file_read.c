#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "file_read.h"

#define STR_SIZE 250

int char_digit_numeric(char c) {
    int res = 0;
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
        res = 1;
    }
    return res;
}

void fix_file(char file[], char mode[], char * data) {
    char fixed_str[STR_SIZE];
    FILE *fptr = NULL;
    char c;
    char separator = ',';
    int count = 0;
    memset(fixed_str, '\0', STR_SIZE);

    fptr = fopen(file, mode);
    if(fptr) {
        printf("File open ok!\n");
        c = fgetc(fptr);
        char prev;
        char end = '\n';
        while(c != EOF) {
            if (char_digit_numeric(c)){
                strncat(fixed_str, &c, 1);
            }
            prev = c;
            c = fgetc(fptr);
            if (!char_digit_numeric(prev) && char_digit_numeric(c)) {
                if (count > 0){
                    if ((count % 3) == 0) {
                        strncat(fixed_str, &end, 1);
                    } else {
                        strncat(fixed_str, &separator, 1);
                    }
                }
                count++;
            }
        }
        strcat(data, fixed_str);
        fclose(fptr);
    } else {
        printf("Something went wrong!\n");
    }
}

