#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#define ERROR_VAL "Direccion Invalida"

//----------------------------------------------------------------------------------------------------------------------------
int GET_String(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno =  0;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
       do{
            printf("%s", msg);
            fgets(buffer,sizeof(buffer)-1, stdin);
            if(strlen(buffer)-1<=maximo && strlen(buffer)-1>=minimo)
            {
                retorno = 1;
                strcpy(&buffer[strlen(buffer)-1],"\0");
                strncpy(resultado,buffer,maximo);
                break;
            }else
                {
                   printf("%s",msgError);
                   reintentos--;
                }

        }while(reintentos>=0);
    }
    return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------

int GET_Int(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && minimo<=maximo && reintentos>=0&&resultado!=NULL)
    {
        if(GET_String(msg,msgError,minimo,maximo,reintentos,buffer))
        {
            if(VAL_Int(buffer))
            {
                resultado = buffer;
                retorno = 1;
            }
        }else
            {
                printf(msgError);
            }
    }
    return retorno;
}
int GET_Name(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[maximo];
    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        if(GET_String(msg,msgError,minimo,maximo,reintentos,buffer))
        {
            if(VAL_Name(buffer))
            {
                strncpy(resultado,buffer,maximo);
                retorno  = 0;
            }else
                {
                    printf("%s", msgError);
                }
        }else
            {
                printf("%s", msgError);
            }
    }
    return retorno;
}

int GET_Edad(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[maximo];
    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do{
            if(GET_String(msg,msgError,1,3,reintentos,buffer))
            {
                if(VAL_Edad(buffer, minimo, maximo))
                {
                    printf("%s", buffer);
                    retorno  = 0;
                    break;
                }else
                    {
                        printf("%s", msgError);
                        reintentos--;
                    }
            }else
                {
                    printf("%s", msgError);
                    reintentos--;
                }
        }while(reintentos>=0);
    }
    return retorno;
}

int GET_Direccion(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && minimo<=maximo && reintentos >= 0)
    {
        do
        {
            if(GET_String(msg, msgError, minimo, maximo, reintentos, buffer))
            {
                if(VAL_Direccion(buffer))
                {
                    retorno = 0;
                    strncpy(resultado,buffer,maximo);
                    break;
                }else
                    {
                        printf("%s",ERROR_VAL);
                        reintentos--;
                    }
            }else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
        }while(reintentos>=0);
    }
    return retorno;
}

int GET_Cuil(char* msg, char* msgError,int reintentos, char* resultado)
{
    int retorno = 0;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && reintentos >= 0)
    {
        do
        {
            if(GET_String(msg, msgError, 10, 11, reintentos, buffer))
            {
                if(VAL_Cuil(buffer))
                {
                    retorno = 0;
                    strncpy(resultado,buffer,11);
                    break;
                }else
                    {
                        printf("%s",ERROR_VAL);
                        reintentos--;
                    }
            }else
                {
                    printf("%s",msgError);
                    reintentos--;
                }
        }while(reintentos>=0);
    }
    return retorno;

}
