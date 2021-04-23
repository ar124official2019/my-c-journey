/*
    @Author: Ahmad Raza
    @Email: ar124official2019@gmail.com
    @Version: 1.0.0
    @License: GNU General Public License v3.0
*/

#include <stdio.h>

#ifndef __temp__file
#define __temp__file

typedef FILE temp_file_t;

temp_file_t *create_temp_file(void);
temp_file_t *create_temp_file_stemp(char *filename);
char *read_temp_file(temp_file_t *file, size_t *length, int close_file);
size_t write_temp_file(temp_file_t *file, const char *buffer);

#endif