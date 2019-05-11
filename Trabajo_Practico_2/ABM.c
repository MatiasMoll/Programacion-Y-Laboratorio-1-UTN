#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Validaciones.h"
#include "Get.h"
#define SIN_EMPLEADOS "Base de datos Vacia."
#define REINTENTOS 3
#define MIN_SALARIO 10000
#define MAX_SALARIO 1500000
#define MIN_CARACTER 2
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
            strncpy(arrayEmpleado[lugarVacio].nombre,nombre,MAX_CARACTER);
            strncpy(arrayEmpleado[lugarVacio].apellido,lastName,MAX_CARACTER);
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
            arrayEmpleado[posId].isEmpty = TRUE;
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
            if(!arrayEmpleado[i].isEmpty)
            {
                printEmploye(arrayEmpleado[i]);
            }

        }
        retorno = 0;
    }
    return retorno;
}
int ABM_cantidadEncimaPromedio(Empleado* arrayEmpleados, int limite, float promedio,int* cantEncimaPromedio)
{
    int i;
    int retorno = -1;
    int aux=0;
    if(arrayEmpleados != NULL && limite >0 && promedio > 0)
    {
        for(i=0; i<=limite; i++)
        {
            if(arrayEmpleados[i].isEmpty == FALSE && arrayEmpleados[i].salario>promedio)
            {
                aux++;
            }
        }
        *cantEncimaPromedio=aux;
        retorno = 0;
    }
    return retorno;
}
int ABM_sumaYPromedioSalarios(Empleado* arrayEmpleado, int limite, float* promedio)
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
    int idEncontrado = -1;
    int retorno = -1;
    int opcionMod;
    if(arrayEmpleado != NULL && limite > 0 && id >=0)
    {
        idEncontrado=ABM_buscarPorId(arrayEmpleado,limite,id);
        if(idEncontrado != -1)
        {
            do{
                GET_Int("\n1-Modificar Nombre\n2-Modificar Apellido\n3-Modificar Sector\n4-Modificar Salario\n5-Salir\n",
                    "Opcion Invalida",1,5,REINTENTOS ,&opcionMod);
                switch(opcionMod)
                {
                    case 1:
                        if(!GET_Name("\nIngrese el nuevo nombre: ","\nNombre Invalido",MIN_CARACTER,MAX_CARACTER,REINTENTOS
                        ,arrayEmpleado[idEncontrado].nombre))
                        {
                            printf("Nombre modificado exitosamente");
                        }
                        break;
                  case 2:
                        if(!GET_Name("\nIngrese el nuevo apellido: ","\nApelldio Invalido",MIN_CARACTER,MAX_CARACTER,REINTENTOS
                        ,arrayEmpleado[idEncontrado].apellido))
                        {
                            printf("Apellido modificado exitosamente");
                        }
                        break;
                  case 3:
                        if(!GET_Int("\nIngrese el nuevo sector: ","\nSector Invalido",1,4,REINTENTOS
                        ,arrayEmpleado[idEncontrado].sector))
                        {
                            printf("Sector modificado exitosamente");
                        }
                        break;
                   case 4:
                        if(!GET_Float("\nIngrese el nuevo sector: ","\nSector Invalido",MIN_SALARIO,MAX_SALARIO,REINTENTOS
                        ,arrayEmpleado[idEncontrado].sector))
                        {
                            printf("Salario modificado exitosamente");
                        }
                        break;
                }
            }while(opcionMod!=5);
        }
        else
        {
            printf("Id no encontrado");
        }
    }
    return retorno;
}
void ABM_menu(int* opcion)
{
    printf("\n------MENU ABM------");
    printf("\n1-Alta Empleado\n2-Modificar Empleado\n3-Baja Empleado\n4-Informar\n5-Mostrar nomina\n6-Salir\n");
    GET_Int("Ingrese la opcion elegida: ","Opcion Invalida! ",1,7,2,opcion);
}

void ABM_operaciones(Empleado* arrayEmpleados,int limite)
{
    char nombre[MAX_CARACTER];
    char apellido[MAX_CARACTER];
    int flag =  1;
    float salario;
    float promedio;
    int sueldosAltos;
    int opcionElegida;
    int sector;
    int id=0;
    int idABorrar=0;
    do
    {
        ABM_menu(&opcionElegida);
        switch(opcionElegida)
        {
        case 1:
            if(!GET_Name("\nIngrese Nombre del Empleado: ","\nNombre Invalido",2,MAX_CARACTER,2,nombre)&&
                    !GET_Name("\nIngrese Apellido del Empleado: ","\nApellido Invalido",2,MAX_CARACTER,2,apellido)&&
                    !GET_Int("\nIngrese el sector: ","\nSector Invalido", 1,6,2,&sector)&&
                    !GET_Float("\nIngrese el salario: ","\nSalario Invalido.",1000,150000,3,&salario)&&
                    ABM_addEmployee(arrayEmpleados,limite,nombre,apellido,salario,sector,id))
            {
                printf("El Empleado se ha cargado correctamente! ");
                flag = 1;
                id++;
            }
            else
            {
                printf("\nNo se ha podido dar de alta al empleado.\nPor favor, revise la informacion antes de ingresarla.");
            }
            break;
        case 2:
            if(flag)
            {
                ABM_printEmployees(arrayEmpleados,limite);
                if(!(GET_Int("Ingrese ID a Modificar: ","\nID invalido\n",0,1000,2,&idABorrar))&&
                        ABM_ModificarEmpleado(arrayEmpleados,limite,idABorrar))
                {
                    printf("Empleado modificado exitosamente! ");
                }
                else
                {
                    printf("No se ha encontrado el ID.");
                }

            }
            else
            {
                printf("%s",SIN_EMPLEADOS);
            }
            break;
        case 3:
            if(flag)
            {
                ABM_printEmployees(arrayEmpleados,limite);
                if(!GET_Int("Ingrese ID a borrar: ","ID invalido ",0,1000,2,&idABorrar)&&
                        !ABM_removeEmployee(arrayEmpleados,limite,idABorrar))
                {
                    printf("Id borrado Exitosamente");
                }
                else
                {
                    printf("Id no encontrado");
                }
            }
            else
            {
                printf("%s",SIN_EMPLEADOS);
            }
            break;
        case 4:
            if(flag)
            {
                GET_Int("\n1-Ordenar de mayor a menor.\n2-Ordenar de menor a mayor\n3-Promediar salario de empleados.\n",
                        "Opcion Invalida",1,3,3,&opcionElegida);
                switch(opcionElegida)
                {
                case 1:
                    ABM_sortEmployee(arrayEmpleados,limite,1);
                    ABM_printEmployees(arrayEmpleados,limite);
                    break;
               case 2:
                    ABM_sortEmployee(arrayEmpleados,limite,0);
                    ABM_printEmployees(arrayEmpleados,limite);
                    break;
                case 3:
                    ABM_sumaYPromedioSalarios(arrayEmpleados,limite,&promedio);
                    ABM_cantidadEncimaPromedio(arrayEmpleados,limite,promedio,&sueldosAltos);
                    printf("El promedio del salario es: %.2f\nLa cantidad de empleados por encima de este promedio es: %d"
                           ,promedio,sueldosAltos);
                    break;
                }
                break;
            }
            else
            {
                printf("%s",SIN_EMPLEADOS);
            }
            break;
        case 5:
            if(flag)
            {
                ABM_printEmployees(arrayEmpleados, limite);
            }
            else
            {
                printf("%s",SIN_EMPLEADOS);
            }
            break;
        case 6:
            break;
        default:
            printf("Opcion incorrecta.");

        }
    }
    while(opcionElegida!=6);
}
