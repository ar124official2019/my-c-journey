/*
    @Author: Ahmad Raza
    @Email: ar124official2019@gmail.com
    @Version: 1.0.0
    @License: GNU General Public License v3.0
*/

#include <string.h>
#include <temp_file.h>

/* Write buff to temp_file */
size_t write_temp_file(temp_file_t *temp_file, const char *buff) {
    fseek(temp_file, 0, SEEK_END); // make sure you append
    return fwrite(buff, 1, strlen(buff), temp_file); // write and return bytes written
}