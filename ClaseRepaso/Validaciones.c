#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int VAL_Edad(char* cadena, int minimo, int maximo)
{
    int retorno = 0;
    int buffer;
    if(atoi(cadena)!= 0)
    {
        buffer = atoi(cadena);
        printf("%d", buffer);
        if(buffer<=maximo && buffer>=minimo)
        {
            retorno = 1;
        }
    }
    return retorno;
}


