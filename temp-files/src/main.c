/*
    @Author: Ahmad Raza
    @Email: ar124official2019@gmail.com
    @Version: 1.0.0
    @License: GNU General Public License v3.0
*/

/*
    A program that:
        * reads the file
        * stores it temporarily
        * flashes contents back to screen
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <assert.h>
#include <temp_file.h>

#define BUFF_SIZE 1024
char *program_name = NULL;

void print_usage(FILE *stream, int exit_status)
{
    fprintf(stream, "usage: %s options\n", program_name);
    fprintf(stream,
            "\nOptions:\n"
            "  -h, --help: Display this usage information\n"
            "  -i, --input: Iput file\n");

    exit(exit_status);
}

int main(int argc, char **argv) {
    char *input_file = NULL; // the file to flash back to screen
    program_name = argv[0]; // this program's binary name
    char temp_filename[32]; // temporary file's name
    temp_file_t *temp_file = NULL; // pointer to temporary file
    FILE *fp = NULL; // pointer to input file
    char buff[BUFF_SIZE]; // the buffer size
    size_t read_bytes = 0; // The number of bytes read from input file
    size_t total_file_size = 0; // Total number of bytes read from input file
    char *output = NULL; // Contents of the input file


    const char *short_options = "hi:";
    struct option long_options[] = {
        { "help", 0, NULL, 'h' }, // prints help
        { "input", 1, NULL, 'i' },// specifies which file to read
    };

    /* read command line options */
    int next_option = -1;
    do {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);
        switch (next_option) {
            case 'h':
                print_usage(stdout, 0);

            case 'i':
                input_file = optarg;
                break;

            case '?':
                print_usage(stderr, 1);
                break;

            case -1:
                break;

            default:
                abort();
        }
    } while (next_option != -1);

    // no input file was given
    if (input_file == NULL) {
        print_usage(stderr, 1);
    }

    // create temporary file
    temp_file = create_temp_file_stemp(temp_filename);

    // open input file
    fp = fopen(input_file, "r");

    // copy input file to temporary file
    while ((read_bytes = fread(buff, 1, BUFF_SIZE, fp)) > 0) {
        write_temp_file(temp_file, buff);
        total_file_size += read_bytes;
    }

    // read back temporary file
    output = read_temp_file(temp_file, &total_file_size, 0);

    // print contents
    printf("%s\n", output);

    fclose(temp_file); // close file
    unlink(temp_filename); // delete file
}