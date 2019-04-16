#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int VAL_Name(char* cadena)
{
    int i;
    int retorno = TRUE;
    for(i=0;i<strlen(cadena);i++)
    {
        if((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' && cadena[i]>'Z'))
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

int VAL_Edad(char* cadena, int minimo, int maximo)
{
    int retorno = FALSE;
    int buffer;
    buffer = atoi(cadena);
    if(buffer!=0)
    {
        if(buffer>=minimo && buffer<=maximo)
        {
            retorno = TRUE;
        }

    }

    return retorno;
}
