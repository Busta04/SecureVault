#include <stdio.h>
#include <stdlib.h>

#include "file.h"


//load the fine in the returned fuffer, allocate memory
// path i sthe path of the file
// size is the size of the file for main
unsigned char *load_file(const char *path, size_t *size)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL){
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    if (length<=0){
        fclose(file);
        return NULL;
    }

    unsigned char *buffer = malloc(length);
    if (buffer == NULL){
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, length, file);
    if (bytes_read != (size_t)length){
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);

    *size = (size_t)length;
    return buffer;
}


//create or overvrite the file path, free the memory of buffer
int save_file(const char *path, const unsigned char *buffer, size_t size){
    FILE *file = fopen(path, "wb");

    if (file == NULL){
        return -1;
    }

    size_t written = fwrite(buffer, 1, size, file);

    fclose(file);

    if (written != size){
        return -1;
    }

    return 0;
}