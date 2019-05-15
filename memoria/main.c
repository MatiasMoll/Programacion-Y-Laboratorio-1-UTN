#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    float peso;
    char* nombre;
    int auxInt;

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setPeso(pArrayEmpleado[indiceActual],120.5))
        {
            Emp_getPeso(pArrayEmpleado[indiceActual],&peso);
            printf("\n El peso es %.2f",&peso);

        }

    }


    return 0;
}
