#include <stdio.h>
#include "crypto.h"

void xor_transform(unsigned char *buffer, size_t length, const unsigned char *key,  size_t key_length){
    if (key_length == 0) return;

    for(size_t i = 0; i < length; i++){
        buffer[i] ^= key[i % key_length];
    }
}