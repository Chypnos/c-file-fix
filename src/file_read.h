#ifndef _FILE_READ_H_INCLUDED
#define _FILE_READ_H_INCLUDED

#include <stddef.h>

#define FIX_FILE_OK 0
#define FIX_FILE_BUFFER_TOO_SMALL 1
#define FIX_FILE_READ_ERROR 2

int fix_file(char file[], char mode[], char *data, size_t data_size);
int char_digit_numeric(char c);

#endif