#ifndef CRYPTO_H
#define CRYPTO_H

#include <stddef.h>

void xor_transform(unsigned char *buffer, size_t length, const unsigned char *key, size_t key_length);

#endif