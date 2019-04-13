#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int getString(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getName(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getPrecio(char* msg, float* precioIngresado);
int getCodigo(char* msg, char* codigo);

int main()
{
    Producto productos[CANTIDAD];
    int i;
    int j;

    for(i=0; i<CANTIDAD; i++)
    {
        while(getPrecio("\nIngrese precio: ", &productos[i].precio))
        {
            printf("\nError, reintente...");
        }
        while(getCodigo("\nIngrese codigo: ", productos[i].codigo))
        {
            printf("\nError, reintente...");
        }
    }

    for(i=0; i<CANTIDAD; i++)
    {
        printf("\nEl precio del producto es %.2f", productos[i].precio);
        printf("\nEl codigo del producto es %s \n", productos[i].codigo);
    }

    for(i=0; i<CANTIDAD; i++)
    {
        for(j=0; j<CANTIDAD; j++)
        {
            if(productos[i].precio<productos[j].precio)
            {
                Producto aux = productos[i];
                productos[i] = productos[j];
                productos[j] = aux;
            }
        }
    }
    for(i=0; i<CANTIDAD; i++)
    {
        printf("\nEl precio del producto es %.2f", productos[i].precio);
        printf("\nEl codigo del producto es %s \n", productos[i].codigo);
    }


    return 0;
}

int getString(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
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
                printf("Logrado");
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


