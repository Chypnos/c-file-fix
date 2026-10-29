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

static int append_char(char *buffer, size_t buffer_size, size_t *length, char c) {
    if (*length + 1 >= buffer_size) {
        return 0;
    }

    buffer[*length] = c;
    (*length)++;
    buffer[*length] = '\0';
    return 1;
}

int fix_file(char file[], char mode[], char *data, size_t data_size) {
    char fixed_str[STR_SIZE];
    FILE *fptr = NULL;
    int c;
    int prev;
    char separator = ',';
    int count = 0;
    size_t fixed_length = 0;
    size_t data_length = 0;

    if (!data || data_size == 0) {
        return FIX_FILE_BUFFER_TOO_SMALL;
    }

    while (data_length < data_size && data[data_length] != '\0') {
        data_length++;
    }

    if (data_length == data_size) {
        return FIX_FILE_BUFFER_TOO_SMALL;
    }

    memset(fixed_str, '\0', STR_SIZE);

    fptr = fopen(file, mode);
    if (!fptr) {
        return FIX_FILE_READ_ERROR;
    }

    printf("File open ok!\n");
    c = fgetc(fptr);
    while (c != EOF) {
        if (char_digit_numeric((char)c)){
            if (!append_char(fixed_str, STR_SIZE, &fixed_length, (char)c)) {
                fclose(fptr);
                return FIX_FILE_BUFFER_TOO_SMALL;
            }
        }

        prev = c;
        c = fgetc(fptr);
        if (!char_digit_numeric((char)prev) && c != EOF && char_digit_numeric((char)c)) {
            if (count > 0) {
                if ((count % 3) == 0) {
                    if (!append_char(fixed_str, STR_SIZE, &fixed_length, '\n')) {
                        fclose(fptr);
                        return FIX_FILE_BUFFER_TOO_SMALL;
                    }
                } else {
                    if (!append_char(fixed_str, STR_SIZE, &fixed_length, separator)) {
                        fclose(fptr);
                        return FIX_FILE_BUFFER_TOO_SMALL;
                    }
                }
            }
            count++;
        }
    }

    if (ferror(fptr)) {
        fclose(fptr);
        return FIX_FILE_READ_ERROR;
    }

    fclose(fptr);

    if (fixed_length > data_size - data_length - 1) {
        return FIX_FILE_BUFFER_TOO_SMALL;
    }

    memcpy(data + data_length, fixed_str, fixed_length + 1);
    return FIX_FILE_OK;
}
