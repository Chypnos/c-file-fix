#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "file_read.h"

#define INPUT_FILE  "./data/patients.dat"
#define OUT_FILE  "./data/patients.csv"
#define HEADER_CSV "First name,Last name,Age\n"
#define MAX_SIZE_BUFFER 260

char* buffer = NULL;

int main(void)
{
    FILE * wptr = NULL;
    int fix_result = FIX_FILE_OK;

    wptr = fopen(OUT_FILE, "w");

    if(wptr) {
        fprintf(wptr, HEADER_CSV);
        fclose(wptr);
    } else {
        printf("File error!\n");
        return 1;
    };

    buffer = (char *) malloc(sizeof(char) * MAX_SIZE_BUFFER);
    if(buffer){
        memset(buffer, '\0', MAX_SIZE_BUFFER);
        /*
            do save here
        */
        fix_result = fix_file(INPUT_FILE, "r", buffer, MAX_SIZE_BUFFER);

        if (fix_result == FIX_FILE_OK) {
            printf("===========\n%s\n", buffer);

            wptr = fopen(OUT_FILE, "a");
            if(wptr) {
                fprintf(wptr, "%s", buffer);
                fclose(wptr);
            } else {
                printf("File error!\n");
            };
        } else if (fix_result == FIX_FILE_BUFFER_TOO_SMALL) {
            printf("Buffer is too small for the fixed file data.\n");
        } else {
            printf("Unable to read input file.\n");
        }

        free(buffer);
        buffer = NULL;

    } else {
        printf("Not enough memory\n");
    };
    return fix_result == FIX_FILE_OK ? 0 : 1;
}
