/*
    @Author: Ahmad Raza
    @Email: ar124official2019@gmail.com
    @Version: 1.0.0
    @License: GNU General Public License v3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <temp_file.h>


/* Creates a new temporary file using mkstemp */
/* Sets back the temporary file name to file_name */
/* Warning - You must delete / unlink this file yourself */
temp_file_t * create_temp_file_stemp(char * filename) {
    strcpy(filename, "mylib.XXXXXX");

    // create temp file and close descriptor associated with
    int fd = mkstemp(filename);
    assert(fd != -1);
    close(fd);

    // reopen file in read write mode
    FILE *file = fopen(filename, "w+");
    assert(file != NULL);

    return file;
}