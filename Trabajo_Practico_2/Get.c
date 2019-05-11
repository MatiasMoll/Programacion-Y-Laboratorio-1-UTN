#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#define ERROR_VAL "Direccion Invalida"

//----------------------------------------------------------------------------------------------------------------------------
int GET_String(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno =  0;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && minimo<=maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s", msg);
            __fpurge(stdin);
            fgets(buffer,sizeof(buffer),stdin);
            //strcpy(buffer[strlen(buffer)-1],'\0');
            if(strlen(buffer)-1<=maximo && strlen(buffer)-1>=minimo)
            {

                strncpy(resultado,buffer,maximo-1);
                retorno = 1;
                break;
            }
            else
            {
                printf("%s",msgError);
                reintentos--;
            }

        }
        while(reintentos>=0);
    }
    return retorno;
}
//----------------------------------------------------------------------------------------------------------------------------

int GET_Int(char* msg, char* msgError, int minimo, int maximo, int reintentos, int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && minimo<=maximo && reintentos>=0&&resultado!=NULL)
    {
        do
        {
            if(GET_String(msg,msgError,1,12,reintentos,buffer) && VAL_Int(buffer,minimo,maximo))
            {

                *resultado = atoi(buffer);
                retorno = 0;
                break;

            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos--);
    }
    return retorno;
}
int GET_Float(char* msg, char* msgError, float minimo, float maximo, int reintentos, float* resultado)
{
    int retorno = -1;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && minimo<=maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(GET_String(msg,msgError,1,32,reintentos,buffer)&& atof(buffer)!=0)
            {
                if(VAL_Float(buffer, minimo, maximo))
                {
                    *resultado = atof(buffer);
                    retorno = 0;
                    break;
                }
                else
                {
                    printf("Numero no Valido. ");
                }
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos--);
    }
    return retorno;
}
int GET_Name(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[maximo];
    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(GET_String(msg,msgError,minimo,maximo,reintentos,buffer))
            {
                if(VAL_Name(buffer))
                {
                    strncpy(resultado,buffer,maximo);
                    retorno  = 0;
                    break;
                }
                else
                {
                    printf("%s", msgError);
                }
            }
        }
        while(reintentos--);
    }
    return retorno;
}

int GET_Edad(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[maximo];
    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(GET_String(msg,msgError,1,3,reintentos,buffer))
            {
                if(VAL_Edad(buffer, minimo, maximo))
                {
                    printf("%s", buffer);
                    retorno  = 0;
                    break;
                }
                else
                {
                    printf("%s", msgError);
                    reintentos--;
                }
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
                }
                else
                {
                    printf("%s",ERROR_VAL);
                    reintentos--;
                }
            }
            else
            {
                printf("%s",msgError);
                reintentos--;
            }
        }
        while(reintentos>=0);
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
                }
                else
                {
                    printf("%s",ERROR_VAL);
                    reintentos--;
                }
            }
            else
            {
                printf("%s",msgError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;

}
