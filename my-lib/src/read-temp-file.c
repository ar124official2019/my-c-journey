/*
    @Author: Ahmad Raza
    @Email: ar124official2019@gmail.com
    @Version: 1.0.0
    @License: GNU General Public License v3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <temp_file.h>

/* read len bytes from temp_file and optinally close file if close_file is given */
char *read_temp_file(temp_file_t * temp_file, size_t* len, int close_file) {
    char *buf = (char *)malloc(*len); // allocate buffer for reading

    fseek(temp_file, 0, SEEK_SET); // make sure you start from start of file
    *len = fread(buf, 1, *len, temp_file); // store back bytes read to len

    if (close_file) { // close file if asked
        fclose(temp_file);
    }

    buf[*len + 1] = '\0'; // make sure you terminate the string buffer
    return buf;
}