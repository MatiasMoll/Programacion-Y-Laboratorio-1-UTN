#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

int TOMDAT_String(char* msg, char* msgError, int minimo,int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && resultado != NULL && minimo <= maximo && reintentos >=0)
    {
        printf("%s", msg);
        fgets(bufferStr, sizeof(bufferStr), stdin);

    }
    return retorno;
}

int TOMDAT_Name(char* msg, char* msgError, int minimo,int maximo, int reintentos, char* resultado)
{
    char bufferStr[4096];
    TOMDAT_String(msg, msgError, minimo, maximo, reintentos, bufferStr);
    if(!VAL_Name(bufferStr))
    {
        printf("%s", msg);
    }else
        {
            printf("%s", msgError);
        }
    return 0;
}
