#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Get.h"
#define CANTIDAD 1

typedef struct
{
    float precio ;
    char codigo[7];
} Producto;
/*
ADMINISTRCION DE NEGOCIO
char CODIGO[7]
int PRECIO[7]

*/
int getName(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getPrecio(char* msg, float* precioIngresado);
int getCodigo(char* msg, char* codigo);

int main()
{
   int edadIngresada;
   GET_Edad("Ingrese su edad (Entre 1 y 99): ", "Edad Invalida ", 1,99, 2, &edadIngresada);


    return 0;
}

int getPrecio(char* msg, float* precioIngresado)
{
    char buffer[1024];
    float bufferNum;
    int retorno = -1;
    if(msg != NULL && precioIngresado != NULL)
    {
        printf("%s", msg);
        fgets(buffer, sizeof(buffer)-1, stdin);
        bufferNum = atof(buffer);
        if(bufferNum>0)
        {
            *precioIngresado = bufferNum;
            retorno = 0;

        }

    }
    return retorno;
}

int getCodigo(char* msg, char* codigo)
{
    char buffer[1024];
    int retorno = -1;
    if(msg != NULL && codigo != NULL)
    {
        printf("%s", msg);
        fgets(buffer, sizeof(buffer)-1, stdin);
        if(strlen(buffer) == 7)
        {
            strcpy(codigo,buffer);
            printf("%s", codigo);
            retorno = 0;
        }

    }
    return retorno;
}


