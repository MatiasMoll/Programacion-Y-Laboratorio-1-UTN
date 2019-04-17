#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Get.h"
#define TRUE 0
#define FALSE 1
#define MAX_CARACTER_NOMBRE 50
#define CANTIDAD_EMPLEADOS 4

int vaciarArray(char array[][MAX_CARACTER_NOMBRE], int maximoArray);
int lugarDisponible(char array[][MAX_CARACTER_NOMBRE], int maximoArray,int* posicionVacia);
int mostrarArray(char array[][MAX_CARACTER_NOMBRE], int maximoArray);
int nombreDuplicado(char array[][MAX_CARACTER_NOMBRE], char* nombre,int maximoArray, int* posicionNombreRepetido);
int cargarNombre(char* msg, char* msgError, int minimo, int maximo, int reintentos,char array[][MAX_CARACTER_NOMBRE]);
int borrarNombre(char* nombreABorrar, char array[][MAX_CARACTER_NOMBRE], int maximoArray);

int main()
{
   char nombres[CANTIDAD_EMPLEADOS][50];


   vaciarArray(nombres,CANTIDAD_EMPLEADOS);
   /*strncpy(nombres[0],"Gonzalo",MAX_CARACTER_NOMBRE);
   strncpy(nombres[1],"Alberto",MAX_CARACTER_NOMBRE);
   strncpy(nombres[2],"Juan",MAX_CARACTER_NOMBRE);*/
   strncpy(nombres[0],"Matias",MAX_CARACTER_NOMBRE);
   strncpy(nombres[1],"Noelia",MAX_CARACTER_NOMBRE);
   cargarNombre("Ingrese El nombre", "No se ha podido cargar el nombre", 4, 10,1,nombres);
   borrarNombre(char* nombreABorrar, char array[][MAX_CARACTER_NOMBRE], int maximoArray)






   return 0;
}

int vaciarArray(char array[][MAX_CARACTER_NOMBRE],int maximoArray)
{
    int i;
    for(i=0;i<maximoArray;i++)
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
        if(strcmp(array[i], nombre) == TRUE)
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

int cargarNombre(char* msg, char* msgError, int minimo, int maximo, int reintentos,char array[][MAX_CARACTER_NOMBRE])
{
    int retorno = -1;
    int posicionVacia = -1;
    int posicionRepetida = -1;
    char buffer[maximo];
    if(msg != NULL && msgError != NULL && array != NULL && maximo>=minimo && reintentos>=0)
    {
        lugarDisponible(array, MAX_CARACTER_NOMBRE,&posicionVacia);
        if(posicionVacia != -1)
        {
            GET_Name(msg, msgError, minimo, maximo,reintentos, &buffer);
            nombreDuplicado(array,buffer, maximo,&posicionRepetida);
            if(posicionRepetida != -1)
            {
                strcpy(array[posicionVacia],buffer);
                printf("El nombre %s se ha cargado correctamente", buffer);
                retorno = 0;
            }else
                {
                    printf("Nombre Repetido");
                }

        }else
           {
                    printf("%s", msgError);
           }

    }

    return retorno;
}

int borrarNombre(char* nombreABorrar, char array[][MAX_CARACTER_NOMBRE], int maximoArray)
{
    int retorno = -1;
    int posicionRepetida = -1;
    for(int i=0;i<maximoArray;i++)
    {
        nombreDuplicado(array,nombreABorrar,MAX_CARACTER_NOMBRE,posicionRepetida);
        if(posicionRepetida != -1)
        {
            strcpy(array[posicionRepetida], "");
        }else
            {
                printf("El Nombre no se ha encontrado");
            }
    }

}


