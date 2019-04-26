#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "Validaciones.h"
#include "Get.h"
int pant_initArray(ePantalla* arrayPantalla,int cantidad)
{
    int retorno=-1;
    int i;
    if(arrayPantalla != NULL && cantidad>0)
    {
        for(i=0; i<=cantidad; i++)
        {
            arrayPantalla[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;

}

int pant_buscarVacio(ePantalla* arrayPantalla,int cantidad)
{
    int retorno=-1;
    int i;
    if(arrayPantalla!=NULL && cantidad>0)
    {
        for(i=0; i<=cantidad; i++)
        {
            if(arrayPantalla[i].isEmpty == 1)
            {
                retorno=i;
                break;
            }
        }

    }
    return retorno;

}
int pant_printArray(ePantalla* arrayPantalla,int cantidad)
{
    int retorno=-1;
    int i;
    if(arrayPantalla!=NULL && cantidad>0)
    {
        for(i=0; i<=cantidad; i++)
        {
            printf("\n%d",arrayPantalla[i].idPantalla);
            printf("\n%d",arrayPantalla[i].isEmpty);
            printf("\n%s",arrayPantalla[i].nombre);
            printf("\n%s",arrayPantalla[i].direccion);
            printf("\n%.2f",arrayPantalla[i].precio);
            printf("\n%s",arrayPantalla[i].tipo);
        }
        retorno=1;
    }
    return retorno;

}
int pant_alta(char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos, ePantalla* arrayPantalla, int cantidad)
{
    int retorno=-1;
    int posicionVacia;
    char buffer[4096];
    if(mensaje != NULL && mensajeError !=NULL && minimo <= maximo && reintentos>=0 && arrayPantalla != NULL)
    {
        if(pant_buscarVacio(arrayPantalla,cantidad)!=-1)
        {
            posicionVacia=pant_buscarVacio(arrayPantalla,cantidad);

            GET_Name(mensaje,mensajeError,minimo,maximo,reintentos,&buffer);
            strncpy(arrayPantalla[posicionVacia].nombre,buffer,maximo);

            GET_String(mensaje,mensajeError,minimo,maximo,reintentos,&buffer);
            strncpy(arrayPantalla[posicionVacia].direccion,buffer,maximo);

            GET_String(mensaje,mensajeError,minimo,maximo,reintentos,&buffer);
            strncpy(arrayPantalla[posicionVacia].tipo,buffer,maximo);

            arrayPantalla[pant_buscarVacio(arrayPantalla,cantidad)].isEmpty = 0;

            retorno=0;

        }
        else
        {
            printf("Esta lleno");
        }

    }
    else
    {
        printf("%s",mensajeError);
    }
    return retorno;
}
int pant_BuscarId(ePantalla* arrayPantalla,int cantidad,int id)
{
    int retorno=-1;
    int i;
    if(arrayPantalla!=NULL && cantidad>0 && id >= 0)
    {
        for(i=0; i<=cantidad; i++)
        {
            if(arrayPantalla[i].idPantalla==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
int pant_Baja(char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos, ePantalla* arrayPantalla, int cantidad)
{
    int retorno=-1;
    int idIngresado;
    int idEncontrado;
    char buffer[4096];
    if(mensaje != NULL && mensajeError !=NULL && minimo <= maximo && reintentos>=0 && arrayPantalla != NULL)
    {
        GET_String(mensaje,mensajeError,minimo,maximo,reintentos,&buffer);
        idIngresado=atoi(buffer);
        if(pant_BuscarId(arrayPantalla,cantidad,idIngresado)!=-1)
        {
            arrayPantalla[pant_BuscarId(arrayPantalla,cantidad,idIngresado)].isEmpty=1;
            retorno =0;
        }
    }
    return retorno;
}










