#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "file.h"
#include "crypto.h"

int main(int argc, char *argv[])
{
    if (argc != 3){
        printf("Usage: SecureVault <file> <password>\n");
        return 1;
    }

    size_t length;

    unsigned char *buffer = load_file(argv[1], &length);
    if (buffer == NULL){
        printf("Cannot open file.\n");
        return 1;
    }

    xor_transform( buffer, length, (const unsigned char *)argv[2], strlen(argv[2]));

    int result = save_file(argv[1], buffer, length);

    free(buffer);

    return result;
}