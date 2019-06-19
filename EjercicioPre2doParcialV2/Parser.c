#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int retorno = 0;
    FILE* pFile;
    if(fileName != NULL && listaEmpleados != NULL)
    {
        pFile = fopen(fileName,"r");
        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
               fscanf(pFile,"%[^,],%[^,],%[^\n]\n",)

            }


        }

    }

    return 1; // OK
}

