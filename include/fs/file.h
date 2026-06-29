#ifndef FILE_H
#define FILE_H

#include <stddef.h>

unsigned char *load_file(const char *path, size_t *size);

int save_file(const char *path,  const unsigned char *buffer,  size_t size);

#endif