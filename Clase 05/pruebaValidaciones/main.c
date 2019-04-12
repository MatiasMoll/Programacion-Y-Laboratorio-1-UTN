#include <stdio.h>
#include <stdlib.h>

int VAL_isNumber(char *str, int min, int max);
int GET_getNumber(char *msg, char *msgError, int min, int max, int reintentos, int *res);

int main()
{
    printf("Hello world!\n");
    return 0;
}

int VAL_isNumber(char *str, int min, int max)
{
    return 0;
}

int GET_getNumber(char *msg, char *msgError, int min, int max, int reintentos, int *res)
{
    int retorno = -1;
    char buffer;
    getString(msg, msgError, 1, 5, reintentos, &buffer);
    VAL_isNumber(buffer,min,max);
    if(VAL_isNumber(buffer,min,max))
    {
        res = atoi(buffer);
    }else
        {
            printf("El numero ingresado es mayor al pedido");
        }
    return 0;
}
