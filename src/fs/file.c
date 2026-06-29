#include <stdio.h>
#include <stdlib.h>

#include "file.h"


//load the fine in the returned fuffer, allocate memory
unsigned char *load_file(const char *path, size_t *size)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL){
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

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
int save_file(const char *path,  const unsigned char *buffer,  size_t size){
    FILE *file = fopen(path, "w");
    if (file == NULL){
        return NULL;
    }

    fprintf(file,buffer);

    fclose(file);
    free(buffer);
}