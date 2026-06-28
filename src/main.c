#include <stdio.h>
#include "utils.h"
#include "fileio.h"

int main(void)
{
    print_banner();

    printf("Copying file...\n");

    int result = copy_file("input.txt", "output.txt");

    if (result == 0) {
        printf("File copiato con successo!\n");
    } else {
        printf("Errore nella copia del file.\n");
    }

    return 0;
}