#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Get.h"

int main()
{
    char buffer[4096];
    GET_Direccion("Ingrese la direccion: ", "No se ha podido identificar la direccion", 5,100, 0, buffer);
    printf("%s",buffer);
    return 0;
}
