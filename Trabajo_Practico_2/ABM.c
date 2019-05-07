#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Validaciones.h"
#include "Get.h"
#define TRUE 1
#define FALSE 0

int ABM_initArray(Empleado* arrayEmpleados, int limite)
{
    int i;
    int retorno = -1;
    if(arrayEmpleados != NULL && limite > 0)
    {
        for(i=0; i<=limite; i++)
        {
            arrayEmpleados[i].isEmpty = TRUE;
        }
        retorno = 0;
    }
    return retorno;
}

int ABM_lugarVacio(Empleado* arrayEmpleado, int limite, int* vacio)
{
    int i;
    int retorno = -1;
    if(arrayEmpleado != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            if(arrayEmpleado[i].isEmpty == TRUE)
            {
                *vacio = i;
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int ABM_addEmployee(Empleado* arrayEmpleado,int limite, char* nombre, char* lastName, float salario,int sector, int id)
{
    int retorno = -1;
    int lugarVacio = -1;
    if(arrayEmpleado != NULL && limite > 0 && nombre != NULL && lastName != NULL && salario>0 && sector != -1)
    {
        ABM_lugarVacio(arrayEmpleado, limite, &lugarVacio);
        if(lugarVacio != -1)
        {
            strncpy(arrayEmpleado[lugarVacio].nombre,nombre,51);
            strncpy(arrayEmpleado[lugarVacio].apellido,nombre,51);
            arrayEmpleado[lugarVacio].salario = salario;
            arrayEmpleado[lugarVacio].sector = sector;
            arrayEmpleado[lugarVacio].id = id;
            arrayEmpleado[lugarVacio].isEmpty = 0;
            retorno =1;
        }
        else
        {
            printf("Array lleno");
        }
    }
    return retorno;
}

int ABM_buscarPorId(Empleado* arrayEmpleado, int limite, int id)
{
    int retorno = -1;
    int i;
    if(arrayEmpleado != NULL && limite>0 && id >=0)
    {
        for(i=0; i<=limite; i++)
        {
            if(arrayEmpleado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ABM_removeEmployee(Empleado* arrayEmpleado, int limite, int id)
{
    int retorno = -1;
    int posId = -1;
    if(arrayEmpleado != NULL && limite>0 && id>=0)
    {
        posId = ABM_buscarPorId(arrayEmpleado, limite, id);
        if(posId != -1)
        {
            arrayEmpleado[posId].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}

int ordenarMayorAMenor(Empleado* arrayEmpleado, int limite)
{
    int i;
    int j;
    Empleado aux;
    int retorno = -1;
    if(arrayEmpleado != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            for(j=i+1; j<=limite; j++)
            {
                if(strcmp(arrayEmpleado[i].apellido,arrayEmpleado[j].apellido)<0)
                {
                    aux = arrayEmpleado[i];
                    arrayEmpleado[i] = arrayEmpleado[j];
                    arrayEmpleado[j] = aux;
                }
                retorno = 0;
            }
        }
    }
    return retorno;
}

int ordenarMenorAMayor(Empleado* arrayEmpleado, int limite)
{
    int i;
    int j;
    Empleado aux;
    int retorno = -1;
    if(arrayEmpleado != NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            for(j=i+1; j<=limite; j++)
            {
                if(strcmp(arrayEmpleado[i].apellido,arrayEmpleado[j].apellido)>0)
                {
                    aux = arrayEmpleado[i];
                    arrayEmpleado[i] = arrayEmpleado[j];
                    arrayEmpleado[j] = aux;
                }
                retorno = 0;
            }
        }
    }
    return retorno;
}

int ABM_sortEmployee(Empleado* arrayEmpleado, int limite, int order)
{
    int retorno = -1;
    int i;
    if((arrayEmpleado != NULL && limite > 0) && (order == 1 || order == 0))
    {
        if(order == 1)
        {
            for(i=0; i<limite; i++)
            {
                //if(strcmp(arrayEmpleado[i].apellido,arrayEmpleado[i+1].apellido)==-1)
            }
        }
    }
    return retorno;
}
void printEmploye(Empleado empleado)
{
    printf("\nNombre: %s\nApellido: %s\nId: %d\nSector: %d\nSalario: %.2f\n",
           empleado.nombre,empleado.apellido,empleado.id,empleado.sector,empleado.salario);
}
int ABM_printEmployees(Empleado* arrayEmpleado, int limite)
{
    int retorno = -1;
    int i;
    if(arrayEmpleado != NULL && limite > 0)
    {
        for(i=0; i<=limite; i++)
        {
            printEmploye(arrayEmpleado[i]);
        }
        retorno = 0;
    }
    return retorno;
}
