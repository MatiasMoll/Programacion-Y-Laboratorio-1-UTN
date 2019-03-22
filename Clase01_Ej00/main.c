#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CANTIDAD_NUMEROS 5

int sumaDeDosNumeros(void);
int promediosNumeroPedidos(int);
int sumaNumerosPedidos(void);


int main()
{
    sumaNumerosPedidos();
    return 0;
}

int sumaDeDosNumeros(void)
{
    int numeroA;
    int numeroB;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d",&numeroA);
    printf("\n");

    printf("Ingrese otro numero: ");
    scanf("%d",&numeroB);
    printf("\n");

    resultado=numeroA+numeroB;

    printf("La suma de ambos es: %d",resultado);

    return 0;
}

int sumaNumerosPedidos(void)
{
    int numerosIngresados;
    int maximo;
    int minimo;
    int acumulador;
    int contador;
    float promedio;

    maximo=INT_MIN;
    minimo=INT_MAX;
    numerosIngresados=0;
    acumulador=0;
    promedio=0;
    for(contador=0;contador<CANTIDAD_NUMEROS;contador++)
    {
        printf("Ingrese un numero: ");
        scanf("\n %d",&numerosIngresados);
        acumulador+=numerosIngresados;
        if(numerosIngresados<minimo)
        {
            minimo = numerosIngresados;
        }
        if(numerosIngresados>maximo)
        {
            maximo = numerosIngresados;
        }
    }
    promedio=acumulador / contador;
    printf("El promedio es: %f \n",promedio);
    printf("El maximo es %d \n",maximo);
    printf("El minimo es %d \n",minimo);
    return 0;
}

