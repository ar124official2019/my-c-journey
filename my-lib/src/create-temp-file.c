/*
    @Author: Ahmad Raza
    @Email: ar124official2019@gmail.com
    @Version: 1.0.0
    @License: GNU General Public License v3.0
*/

#include <stdio.h>
#include <temp_file.h>

/* Create a new temp file */
temp_file_t * create_temp_file() {
    return tmpfile(); // see `man 2 tmpfile`
}