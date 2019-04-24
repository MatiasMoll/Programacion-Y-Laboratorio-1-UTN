#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"
#define LEN_LISTA    100

int EMP_initArray(Empleado* arrayEmpleado, int limite)
{
    int retorno = -1;
    if(arrayEmpleado != NULL && limite>0)
    {
        for(int i=0;i<=limite;i++)
        {
            arrayEmpleado[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

int EMP_lugarLibre(Empleado* arrayEmpleados, int limite, int* lugarLibre)
{
    int i;
    int retorno=-1;
    for(i=0; i<limite ; i++)
    {
        if(arrayEmpleados[i].isEmpty == 1)
        {
            *lugarLibre = i;
            retorno=0;
            break;
        }
    }
    return retorno;

}

int EMP_buscarNombre(Empleado* arrayEmpleados, int limite, char* nombre, int* posicionEncontrada)
{
    int i;
    int ret=-1;
    if(arrayEmpleados != NULL && limite > 0 && nombre != NULL && posicionEncontrada != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(strcmp(nombre,arrayEmpleados[i].nombre)==0)
            {
                *posicionEncontrada = i;
                ret=0;
                break;
            }
        }
    }

    return ret;
}

int EMP_buscarEdad(Empleado* arrayEmpleados, int limite, int edad, int* indice)
{
    int i;
    int retorno = -1;
    if(arrayEmpleados != NULL && limite >0 && edad>0 && indice != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayEmpleados[i].edad == edad)
            {
                *indice = i;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
