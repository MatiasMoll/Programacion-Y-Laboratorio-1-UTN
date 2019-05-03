#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "Get.h"
#include <string.h>
#include "ABM.h"
#define LIMITE 1000

int main()
{
    char* nombre[50];
    char* apellido[50];
    Empleado empleados[1000];
    GET_Name("Ingrese nombre: ", "Error",2,15,2,nombre);
    GET_Name("Ingrese apellido: ","Error",2,10,2,apellido);
    ABM_addEmployee(empleados,LIMITE, nombre, apellido, 12500,7, 1);
}
