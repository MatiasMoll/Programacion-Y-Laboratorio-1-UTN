#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_ARRAY 10


int getString(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char *resultado);

int main()
{
    char buffer[257];
    char nombre[TAM_ARRAY];
    int flag=0;
    int tamArray;
    int i;

    printf("Ingrese su nombre: ");
    fgets(buffer,sizeof(buffer), stdin);
    tamArray = strlen(buffer);

    if(tamArray > TAM_ARRAY)
    {
        printf("El nombre es demasiado largo");
    }else
        {
            for(i=0; i<tamArray-1;i++)
            {
                buffer[i] = tolower(buffer[i]);
                if(!(buffer[i] >= 'a' && buffer[i] <= 'z'))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                printf("Usted ha ingresado un numero");
            }else
                {
                    strncpy(nombre, buffer,sizeof(nombre));
                    printf("%s",nombre);
                }

        }


    return 0;
}

int getString(char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos, char *resultado)
{
    int retorno = -1;
    char buffer[150];
    if(mensaje != NULL && mensajeError !=  NULL && maximo > minimo && reintentos >=0)
    {
        printf("%s", mensaje);
        fgets(buffer, sizeof(buffer), stdin);
        do{
            if(strlen(buffer)>maximo)
            {
                printf("%s", mensajeError);
                reintentos--;
            }else
                {
                    strncpy(resultado,buffer,maximo);
                    retorno = 0;
                    break;
                }
        }while(reintentos>0);
    }
    return retorno;
}

int getNombre (char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;


}
