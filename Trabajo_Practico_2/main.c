#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Get.h"
#include <string.h>
#include "ABM.h"
#define LIMITE 1000
#define TRUE 1
#define FALSE 0

int main()
{
    Empleado empleados[LIMITE];
    ABM_initArray(empleados,LIMITE);
    //-----------------------------------COMIENZO DEL MOCK-------------------------------------------
    empleados[0].id = 50;
    empleados[0].isEmpty = FALSE;
    strcpy(empleados[0].nombre,"Matias");
    strcpy(empleados[0].apellido,"Moll");
    empleados[0].sector = 2;
    empleados[0].salario = 55000;

    empleados[1].id = 51;
    empleados[1].isEmpty = FALSE;
    strcpy(empleados[1].nombre,"Isabella");
    strcpy(empleados[1].apellido,"Moll");
    empleados[1].sector = 1;
    empleados[1].salario = 100000;

    empleados[2].id = 52;
    empleados[2].isEmpty = FALSE;
    strcpy(empleados[2].nombre,"Noelia");
    strcpy(empleados[2].apellido,"Neyra");
    empleados[2].sector = 1;
    empleados[2].salario = 150000;

    empleados[3].id = 50;
    empleados[3].isEmpty = FALSE;
    strcpy(empleados[3].nombre,"Santiago");
    strcpy(empleados[3].apellido,"Gaggia");
    empleados[3].sector = 4;
    empleados[3].salario = 25000;
    //-----------------------------------FIN DEL MOCK-------------------------------------------
    ABM_operaciones(empleados,LIMITE);




    return 0;
}
