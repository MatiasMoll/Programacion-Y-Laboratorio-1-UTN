#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"



int getArrayInt (char* msg, char* msgError, int minimo, int maximo, int reintentos, int *arrayresultado, int limite);

int main()
{
    int *aResultado[10];
    getArrayInt ("Ingrese la edad: ","Edad Invalida",18,90,10, &aResultado[10],10);
    return 0;
}

int getArrayInt (char* msg, char* msgError, int minimo, int maximo, int reintentos, int *arrayResultado, int limite)
{
    int retorno=-1;
    int numeroObtenido;
    int i;

    if(msg != NULL && msgError!=NULL && arrayResultado != NULL && maximo>=minimo && reintentos>=0 && limite > 0)
    {
        for(i=0;i<limite;i++)
        {

            getInt(msg,msgError,minimo,maximo,reintentos,&numeroObtenido);
            if(numeroObtenido != 0)
            {
                arrayResultado[i] = numeroObtenido;
            }else
                {
                    printf("%s", msgError);

                }

        }
    }
    return getInt(msg,msgError,minimo,maximo,reintentos,&numeroObtenido);;
}
