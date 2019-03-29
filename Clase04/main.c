#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

int main()
{
    char letraIngresado;
    getChar("ingrese: ", "error \n", 97, 122, 1, &letraIngresado);
    printf("%c", letraIngresado);

    return 0;
}


