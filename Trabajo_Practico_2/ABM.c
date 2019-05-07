#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Validaciones.h"
#include "Get.h"
#define MAX_CARACTER 51
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
                retorno = 0;
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
            strncpy(arrayEmpleado[lugarVacio].apellido,lastName,51);
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
int ordenarMayorAMenorApellidoYSector(Empleado* arrayEmpleado, int limite)
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
                else if(strcmp(arrayEmpleado[i].apellido,arrayEmpleado[j].apellido)==0)
                {
                    if(arrayEmpleado[i].sector < arrayEmpleado[j].sector)
                    {
                        aux = arrayEmpleado[i];
                        arrayEmpleado[i] = arrayEmpleado[j];
                        arrayEmpleado[j] = aux;
                    }
                }
                retorno = 0;
            }
        }
    }
    return retorno;
}

int ordenarMenorAMayorApellidoYSector(Empleado* arrayEmpleado, int limite)
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
                else if(strcmp(arrayEmpleado[i].apellido,arrayEmpleado[j].apellido)==0)
                {
                    if(arrayEmpleado[i].sector < arrayEmpleado[j].sector)
                    {
                        aux = arrayEmpleado[i];
                        arrayEmpleado[i] = arrayEmpleado[j];
                        arrayEmpleado[j] = aux;
                    }
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
    if((arrayEmpleado != NULL && limite > 0) && (order == 1 || order == 0))
    {
        if(order == 1)
        {
            ordenarMayorAMenorApellidoYSector(arrayEmpleado,limite);
        }
        else
        {
            ordenarMenorAMayorApellidoYSector(arrayEmpleado, limite);
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

int ABM_sumaYPromedioSalarios(Empleado* arrayEmpleado, int limite, int* promedio)
{
    int i;
    int retorno = -1;
    float salarioTotal=0;
    int cantEmpleados=0;

    if(arrayEmpleado != NULL && limite > 0)
    {
        for(i=0; i<=limite; i++)
        {
            if(arrayEmpleado[i].isEmpty == 0)
            {
                salarioTotal += arrayEmpleado[i].salario;
                cantEmpleados++;
            }
        }
        *promedio = salarioTotal / cantEmpleados;
        retorno = 0;
    }
    return retorno;
}

int ABM_ModificarEmpleado(Empleado* arrayEmpleado, int limite, int id)
{
    int vacio = -1;
    int retorno = -1;
    vacio=ABM_buscarPorId(arrayEmpleado, limite,id);
    if(vacio != -1)
    {
        if(!GET_Name("\nIngrese Nombre del Empleado: ","\nNombre Invalido",2,MAX_CARACTER,2,nombre)&&
                !GET_Name("\nIngrese Apellido del Empleado: ","\nApellido Invalido",2,MAX_CARACTER,2,apellido)&&
                !GET_Int("\nIngrese el sector: ","\nSector Invalido", 1,6,2,&sector))
        {
            strncpy(arrayEmpleado[vacio].nombre,nombre,51);
            strncpy(arrayEmpleado[vacio].apellido,lastName,51);
            arrayEmpleado[vacio].salario = salario;
            arrayEmpleado[vacio].sector = sector;
            arrayEmpleado[lugarVacio].id = id;
            arrayEmpleado[lugarVacio].isEmpty = 0;
            printf("El Empleado se ha modificado correctamente! ");
            id++;
        }
    }
    else
    {
        printf("Id no encontrado");
    }

}

void ABM_menu(int* opcion)
{
    printf("\n------MENU ABM------");
    printf("\n1-Alta Empleado\n2-Modificar Empleado\n3-Baja Empleado\n4-Informar\n5-Salir\n");
    GET_Int("Ingrese la opcion elegida: ","Opcion Invalida! ",1,5,2,opcion);
}

void ABM_operaciones(Empleado* arrayEmpleados,int limite)
{
    char nombre[MAX_CARACTER];
    char apellido[MAX_CARACTER];
    float salario;
    int opcionElegida;
    int sector;
    int id=0;
    do
    {
        ABM_menu(&opcionElegida);
        switch(opcionElegida)
        {
        case 1:
            if(!GET_Name("\nIngrese Nombre del Empleado: ","\nNombre Invalido",2,MAX_CARACTER,2,nombre)&&
                    !GET_Name("\nIngrese Apellido del Empleado: ","\nApellido Invalido",2,MAX_CARACTER,2,apellido)&&
                    !GET_Int("\nIngrese el sector: ","\nSector Invalido", 1,6,2,&sector)&&
                    ABM_addEmployee(arrayEmpleados,limite,nombre,apellido,125000,sector,id))
            {
                printf("El Empleado se ha cargado correctamente! ");
                id++;
            }
            else
            {
                printf("\nNo se ha podido dar de alta al empleado.\nPor favor, revise la informacion antes de ingresarla.");
            }

            break;
        default:
            printf("Opcion incorrecta.");
        }
    }
    while(opcionElegida!=5);
}
