#include <stdio.h>
#include <stdlib.h>
#include "TomarDatos.h"

int main()
{
    char buffer[10];
    printf("Hello world!\n");
    TOMDAT_Name("Nombre: ", "Error", 2,5,2, buffer);
    return 0;
}
