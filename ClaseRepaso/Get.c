#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

int GET_String(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && resultado != NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s", msg);
            fgets(buffer,sizeof(buffer)-1, stdin);
            if(strlen(buffer)<= maximo)
            {
                strncpy(resultado, buffer,maximo);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", msgError);
                reintentos--;
            }
        }
        while(reintentos>=0);

    }
    return retorno;
}

int GET_Edad(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char* buffer[4096];
    if(msg != NULL && msgError != NULL && resultado != NULL && minimo<=maximo && reintentos>=0)
    {
        GET_String(msg, msgError, 1,3,reintentos,buffer);
        if(VAL_Edad(buffer, minimo, maximo))
        {
            printf("Edad Ingresada Correctamente");
        }else
            {
                printf("Edad Invalida");
            }

    }
    return retorno;
}
