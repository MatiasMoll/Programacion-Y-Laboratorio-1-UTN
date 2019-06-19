#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>

void em_calcularSueldo(void* p)
{
    int sueldo;
    int horasTrabajadas;
    Empleado* aux = (Empleado*)p;
    if(p != NULL)
    {
        horasTrabajadas = aux->horasTrabajadas;
        sueldo = horasTrabajadas;
        if(horasTrabajadas<=120)
        {
            sueldo *= 180;
        }else if(horasTrabajadas<=160)
            {
                sueldo *= 240;
            }else if(horasTrabajadas<=240)
                {
                    sueldo *= 350;
                }
       aux->sueldo=sueldo;
    }
}
