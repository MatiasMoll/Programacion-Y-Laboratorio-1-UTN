#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 256
/*
    strncpy(nombre, nombre2,sizeof(nombre));
    printf("\n%s", nombre);
    fgets(nombre, sizeof(nombre), stdin);
    printf("\n%s", nombre);
*/

int isStrOnlyChar(char buffer[]);

int main()
{
    char buffer[MAXSIZE];
    char name[MAXSIZE];
    printf("Ingrese su nombre: ");
    fgets(buffer, sizeof(buffer), stdin);
    if(isStrOnlyChar(buffer))
    {
        strncpy(name, buffer, sizeof(name));
        printf("\nSu nombre es: %s", name);
    }else
    {
        printf("\nSu nombre no es valido.");
    }

}

int isStrOnlyChar(char buffer[])
{
    int retorno = 1;
    int lengthBuffer = strlen(buffer);
    int i;
    for(i=0;i<lengthBuffer-1;i++)
    {
        if(buffer[i] < 'A' || buffer[i] > 'z')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
