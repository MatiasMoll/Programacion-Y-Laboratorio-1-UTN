#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado);
int isValidInt(int numero, int maximo, int minimo);
int getFloat(char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado);
int isValidFloat(float numero, float maximo, float minimo);
int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);
int isValidChar(char letra, char maximo, char minimo);

int main()
{
    char letraIngresada;
    getChar("Ingrese una letra: ", "Error \n", "a", "z", 3, &letraIngresada);
    printf("%c", letraIngresada);

    return 0;
}

int isValidInt(int numero, int maximo, int minimo)
{
    int retorno=0;
    if(numero<=maximo && numero>=minimo)
    {
        retorno = 1;
    }
    return retorno;
}

int getInt(char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos, int *resultado)
{
    int retorno = -1;
    int i;
    int buffer;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos>=0)
    {
        for(i=0;i<=reintentos;i++)
        {
          printf("%s", mensaje);
          scanf("%d",&buffer);
          if(isValidInt(buffer, maximo, minimo))
          {
              *resultado = buffer;
               retorno = 0;
               break;
          }else
            {
                printf("%s", mensajeError);
            }
         }
    }
    return retorno;
}

int isValidFloat(float numero, float maximo, float minimo)
{
    if(numero>=minimo && numero<=maximo)
    {
        return 1;
    }
    return 0;
}

int getFloat(char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado)
{
    int retorno = -1;
    float buffer;

    if(mensaje!= NULL && mensajeError != NULL && resultado != NULL && minimo<=maximo && reintentos>=0)
    {
        do{
            printf("%s", mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
                {
                        printf("%s", mensajeError);
                }
            reintentos--;
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char letra, char maximo, char minimo)
{
    if(letra>=minimo && letra<= maximo)
    {
        return 1;
    }
    return 0;
}

int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    int retorno = -1;
    char buffer;
    if(mensaje != NULL & mensajeError != NULL && resultado != NULL && reintentos>=0)
    {
        do{
            printf("%s", mensaje);
            scanf("%c", &buffer);
            if(isValidChar(buffer, maximo, minimo))
            {
              *resultado = buffer;
              retorno=0;
              break;
            }else
                {
                    printf("%s", mensajeError);
                }
            reintentos--;
        }while(reintentos>=0);
    }
    return retorno;
}
