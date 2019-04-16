#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Get.h"

int main()
{
    char buffer[6];
    GET_Edad("Edad: ", "\nError", 0,101,10, buffer);
    printf("Hello world!\n");
    return 0;
}





