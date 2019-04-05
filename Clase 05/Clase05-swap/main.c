#include <stdio.h>
#include <stdlib.h>
#define LIMITE 5

int swap(int *punteroUno, int *punteroDos);

int main()

{
    int* v[LIMITE]={80,0,015,500,110};
    int flag;
    int i;


    do{
        flag=0;
        for(i=0;i<LIMITE-1;i++)
        {
            if(v[i]>v[i+1])
            {
                swap(&v[i], &v[i+1]);
                flag = 1;
            }
        }
    }while(flag);

    for(i=0;i<LIMITE;i++)
    {
        printf("%d  ",v[i]);
    }
    return 0;
}

int swap(int *punteroUno, int *punteroDos)
{
    int aux;
    aux = *punteroUno;
    *punteroUno = *punteroDos;
    *punteroDos = aux;

    return 0;
}
