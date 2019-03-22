#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS_PEDIDOS 6

int promediosNumerosPedidos();
int calcularPromedio(int acumulador, int cantidad, float *promedio);
int calcularMaximo(int numeroAAnalizar, int *maximo);
int calcularMinimo(int numeroAAnalizar, int *minimo);

int main()
{
    promediosNumerosPedidos();
    return 0;
}

int promediosNumerosPedidos()
{
    int numerosPedidos=0;
    int acumulador=0;
    int contador;
    int maximo;
    int minimo;
    float promedio;

    for(contador=0;contador<CANTIDAD_NUMEROS_PEDIDOS;contador++)
    {

        printf("Ingrese un numero: ");
        scanf("%d",&numerosPedidos);
        if(contador==0)
        {
            minimo=numerosPedidos;
            maximo=numerosPedidos;
        }
        calcularMaximo(numerosPedidos, &maximo);
        calcularMinimo(numerosPedidos, &minimo);
        acumulador+=numerosPedidos;

    }
    if(!calcularPromedio(acumulador, CANTIDAD_NUMEROS_PEDIDOS, &promedio))
    {
       printf("El promedio de los numeros es: %.2f \n",promedio);
    }
    printf("El maximo es:  %d\n",maximo);
    printf("El minimo es: %d",minimo);
    return 0;
}

int calcularPromedio(int acumulador, int cantidad, float *promedio)
{
    int retorno = -1;
    if(cantidad>0 && promedio != NULL)
    {
        *promedio=(float)acumulador / cantidad;
        retorno = 0;
    }

    return retorno;
}

int calcularMaximo(int numeroAAnalizar, int *maximo)
{
    int retorno = -2;

    if(maximo != NULL)
    {
        if(numeroAAnalizar > *maximo)
        {
            *maximo = numeroAAnalizar;
            retorno = 0;
        }
    }

    return retorno;
}
int calcularMinimo(int numeroAAnalizar, int *minimo)
{
    int retorno = -2;

    if(minimo != NULL)
    {

        if(numeroAAnalizar < *minimo)
        {
            *minimo = numeroAAnalizar;
            retorno = 0;
        }

    }
    return retorno;
}

