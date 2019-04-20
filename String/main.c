#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Get.h"
#define TRUE 0
#define FALSE 1
#define MAX_CARACTER_NOMBRE 50
#define CANTIDAD_EMPLEADOS 6

int vaciarArray(char array[][MAX_CARACTER_NOMBRE], int maximoArray);
int lugarDisponible(char array[][MAX_CARACTER_NOMBRE], int maximoArray,int* posicionVacia);
int mostrarArray(char array[][MAX_CARACTER_NOMBRE], int maximoArray);
int nombreDuplicado(char array[][MAX_CARACTER_NOMBRE], char* nombre,int maximoArray, int* posicionNombreRepetido);
int cargarNombre(char* msg, char* msgError, int minimo, int maximo, int reintentos,char array[][MAX_CARACTER_NOMBRE]);
int borrarNombre (char* msg, char* msgError, int minimo, int maximo, int reintentos, char array[][MAX_CARACTER_NOMBRE]);

int main()
{
    char nombres[CANTIDAD_EMPLEADOS][50];
    //int posicionRepetida;
    vaciarArray(nombres,CANTIDAD_EMPLEADOS);
    mostrarArray(nombres,CANTIDAD_EMPLEADOS);
    strncpy(nombres[0],"Gonzalo",MAX_CARACTER_NOMBRE);
    strncpy(nombres[1],"Alberto",MAX_CARACTER_NOMBRE);
    strncpy(nombres[2],"Juan",MAX_CARACTER_NOMBRE);
    strncpy(nombres[3],"Matias",MAX_CARACTER_NOMBRE);
    strncpy(nombres[4],"Noelia",MAX_CARACTER_NOMBRE);
    //nombreDuplicado(nombres,"Juan",CANTIDAD_EMPLEADOS,&posicionRepetida);
    //printf("%d", posicionRepetida);

    borrarNombre("Ingrese el nombre para borrar: ", "Error\n", 2,10,2,nombres);
    mostrarArray(nombres, CANTIDAD_EMPLEADOS);

   return 0;
}

int vaciarArray(char array[][MAX_CARACTER_NOMBRE],int maximoArray)
{
    int i;
    for(i=0;i <= maximoArray;i++)
    {
        strcpy(array[i],"");
    }
    return 0;
}

int lugarDisponible(char array[][MAX_CARACTER_NOMBRE], int maximoArray, int* posicionVacia)
{
    int retorno = FALSE;
    for(int i=0; i<maximoArray;i++)
    {
        if(strcmp(array[i],"") == TRUE)
        {
            *posicionVacia = i;
            retorno = TRUE;
            break;
        }
    }
    return retorno;
}


int nombreDuplicado(char array[][MAX_CARACTER_NOMBRE], char* nombre,int maximoArray, int* posicionNombreRepetido)
{
    int retorno = FALSE;
    for(int i=0; i<maximoArray;i++)
    {
        if(strncmp(array[i], nombre,MAX_CARACTER_NOMBRE) == TRUE)
        {
            *posicionNombreRepetido = i;
            retorno = TRUE;
            break;
        }
    }
    return  retorno;
}

int mostrarArray(char array[][MAX_CARACTER_NOMBRE], int maximoArray)
{
    int retorno = -1;
    int i;

   for(i=0;i<=maximoArray;i++)
   {
        printf("\n%s", array[i]);
        retorno = 0;
   }
   return retorno;
}
//-------------------------------------------------------------------------------------------------------------------------------------

 int cargarNombre(char* msg, char* msgError, int minimo, int maximo, int reintentos,char array[][MAX_CARACTER_NOMBRE])
 {
     int retorno = -1;
     int posicionRepetida = -1;
     int posicionVacia = -1;
     char buffer[4096];
     if(msg != NULL && msgError != NULL && minimo<=maximo && reintentos>=0)
     {
        lugarDisponible(array, CANTIDAD_EMPLEADOS, &posicionVacia);
        if(posicionVacia != -1)
        {
          GET_Name(msg,msgError,minimo,maximo,reintentos,buffer);
          nombreDuplicado(array,buffer,CANTIDAD_EMPLEADOS,&posicionRepetida);
          if(posicionRepetida == -1)
          {
             strncpy(array[posicionVacia],buffer,maximo);
             retorno = 0;
          }else
            {
                printf("Nombre Repetido.");
            }
        }else
            {
                printf("Error.No hay lugar.");
            }
     }
     return retorno;
 }

int borrarNombre (char* msg, char* msgError, int minimo, int maximo, int reintentos, char array[][MAX_CARACTER_NOMBRE])
{
    int retorno  = -1;
    int posicionRepetida = -1;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && minimo<= maximo && reintentos>=0)
    {
        GET_Name(msg,msgError,minimo,maximo,reintentos,buffer);
        nombreDuplicado(array,buffer,CANTIDAD_EMPLEADOS,&posicionRepetida);
        if(posicionRepetida != -1)
        {
            strcpy(array,"");
            printf("El nombre %s se ha eliminado correctamente.", buffer);
            retorno = 0;
        }else
            {
                printf("El nombre no existe ");
            }
    }

    return retorno;
}

