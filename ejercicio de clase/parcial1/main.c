#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"

int main()
{
    ePantalla Prueba[3];
    pant_initArray(Prueba,3);
    Prueba[0].isEmpty = 0;
    Prueba[1].isEmpty = 0;
    Prueba[2].idPantalla = 105;
    Prueba[2].precio = 2500.25;
    pant_alta("Ingrese un nombre: ","Error",2,10,0,Prueba,3);
    pant_printArray(Prueba,3);
    pant_Baja("Id a borrar","Error",1,3,0,Prueba,3);
    pant_printArray(Prueba,3);




}
