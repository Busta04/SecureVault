#include <stdio.h>
#include "fileio.h"

int copy_file(const char *src_path, const char *dst_path)
{
    FILE *src = fopen(src_path, "rb");
    if (!src) {
        perror("Errore apertura file sorgente");
        return 1;
    }

    FILE *dst = fopen(dst_path, "wb");
    if (!dst) {
        perror("Errore apertura file destinazione");
        fclose(src);
        return 1;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);

    return 0;
}