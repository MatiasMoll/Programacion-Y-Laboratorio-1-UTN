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
    int retorno = -1;
    strcpy(empleados[0].apellido,"Carlos");
    strcpy(empleados[1].apellido,"Alberto");
    strcpy(empleados[2].apellido,"Zanoni");
    strcpy(empleados[3].apellido,"Humberto");
    ABM_initArray(empleados,4);
    ABM_operaciones(empleados,4);
    ABM_printEmployees(empleados,4);


    return retorno;
}
