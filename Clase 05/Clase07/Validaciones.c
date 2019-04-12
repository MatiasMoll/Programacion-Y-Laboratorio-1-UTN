#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TomarDatos.h"

int VAL_Edad(char* cadena, int minimo, int maximo)
{
    int retorno = 1;
    int buffer = atoi(cadena);
    if(cadena != NULL && minimo < maximo)
    {
        if(buffer > minimo && buffer < maximo)
        {
            retorno = 0;
        }
    }
    return retorno;
}

int VAL_Name(char* cadena)
{
    return 0;
}
