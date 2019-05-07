#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Get.h"
#include <string.h>
#include "ABM.h"
#define LIMITE 1000

int main()
{
    Empleado empleados[4];
    int opcion;
    int retorno = -1;
    char nombre[50];
    /*int largoArray = strlen(empleados);

    strcpy(empleados[0].apellido,"Carlos");
    strcpy(empleados[1].apellido,"Alberto");
    strcpy(empleados[2].apellido,"Zanoni");
    strcpy(empleados[3].apellido,"Humberto");
    ABM_printEmployees(empleados, 3);
    ordenarMayorAMenorApellidoYSector(empleados,3);
    ABM_printEmployees(empleados, 3);
    ordenarMenorAMayorApellidoYSector(empleados,3);
    ABM_printEmployees(empleados,3);
    printf("%d",largoArray);*/
    ABM_initArray(empleados,4);
    ABM_operaciones(empleados,4);
    ABM_printEmployees(empleados,4);


    return retorno;
}
