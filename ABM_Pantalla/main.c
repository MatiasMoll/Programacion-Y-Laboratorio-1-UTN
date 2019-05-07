#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_strings.h"
#include "Pantalla.h"
#include "Publicidad.h"
#define REINTENTOS 3
#define LEN_LISTA 5
int informePrecioMayorAMenor (Pantalla* array, int limite);
void imprimirPantalla(Pantalla pantalla);
void filtrarValor(Pantalla* array, int limite);

int main()
{
    Pantalla visores[LEN_LISTA];
    Publicidad Marketing[LEN_LISTA];
    int flag=1;
    int posLibre;
    int opcion=0;

    pan_initPantalla(visores,LEN_LISTA);
    pub_initPublicidad(Marketing,LEN_LISTA);

    strcpy(visores[0].nombre,"Matias");
    strcpy(visores[0].direccion, "calle 105 1163");
    visores[0].precio = 2.5;
    visores[0].tipo = 1;
    visores[0].isEmpty = 0;
    visores[0].idPantalla = 1000;

    strcpy(visores[1].nombre, "Cintia");
    strcpy(visores[1].direccion, "Estacion Villa Dominico");
    visores[1].precio = 1.5;
    visores[1].tipo = 2;
    visores[1].isEmpty = 0;
    visores[1].idPantalla = 1001;

    strcpy(visores[2].nombre, "ACintia");
    strcpy(visores[2].direccion, "Estacion Villa Dominico");
    visores[2].precio = 1.5;
    visores[2].tipo = 2;
    visores[2].isEmpty = 0;
    visores[2].idPantalla = 1002;

    strcpy(Marketing[0].cuit, "20401444263");
    strcpy(Marketing[0].archivo, "asdas.avi");
    Marketing[0].dias = 5;
    Marketing[0].isEmpty = 0;
    Marketing[0].idPublicidad = 000;
    Marketing[0].idPantalla = 1000;

    strcpy(Marketing[1].cuit,"27451684324");
    strcpy(Marketing[1].archivo, "asdas.jpg");
    Marketing[1].dias = 1;
    Marketing[1].isEmpty = 0;
    Marketing[1].idPublicidad = 001;
    Marketing[1].idPantalla = 1001;

    strcpy(Marketing[2].cuit,"56465251");
    strcpy(Marketing[2].archivo, "javajava.jpg");
    Marketing[2].dias = 10;
    Marketing[2].isEmpty = 0;
    Marketing[2].idPublicidad = 002;
    Marketing[2].idPantalla = 1001;

    while(opcion!=8)
    {
        getIntInRange(&opcion,"\n1)Alta de pantalla\n2)Modificar datos de pantalla\n3)Baja de pantalla\n"
                      "4)Contratar Publicidad\n5)Mostrar Pantallas\n6)Informes\n7)Filtrar\n8)salir\n    INGRESE OPCION: ","ERROR\n",1,8,3);
        switch(opcion)
        {
            case 1:
            {
                posLibre=pan_findFree(visores,LEN_LISTA);
                if(posLibre>=0)
                {
                    printf("\n----Se encontro lugar----\n");
                    if(!pan_addPan(visores,LEN_LISTA,posLibre,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio de ALTA exitosamente!----\n");
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA!----\n");
                    }
                }
                else
                {
                    printf("\n----No se encontro lugar libre!----\n");
                }
                break;
            }
            case 2:
            {
                if(flag)
                {
                    if(pan_alter(visores,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----Se modifico exitosamente----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 3:
            {
                if(flag)
                {
                    if(pan_removePantalla(visores,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La BAJA se realizo con exito!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 4:
            {
                if(flag)
                {
                    pan_printPantalla(visores,LEN_LISTA);
                    if(!pub_addPub(Marketing,visores,LEN_LISTA,"\nDATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La CONTRATACION se realizo con exito!----\n");
                    }
                    else
                    {
                        printf("\n----No pudo CONTRATARSE la pantalla!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay PANTALLAS en la NOMINA!----\n");
                }
                break;
            }
            case 5:
            {
                if(flag)
                {
                    pan_printPantalla(visores,LEN_LISTA);
                }
                break;
            }
            case 6:
                informePrecioMayorAMenor(visores,LEN_LISTA);
                pan_printPantalla(visores,LEN_LISTA);
                break;
             case 7:
                 marketingCorto(visores,Marketing,LEN_LISTA);
                break;

        }
    }
    return 0;
}

int informePrecioMayorAMenor (Pantalla* array, int limite)
{
    int i;
    int j;
    int retorno = -1;
    Pantalla auxPantalla;
    for(i=0;i<limite;i++)
    {
       for(j=0;j<=limite;j++)
       {
            if(array[i].precio>array[j].precio)
            {
                auxPantalla = array[i];
                array[i] = array [j];
                array[j] = auxPantalla;
                retorno = 0;
            }else if(array[i].precio == array[j].precio)
                  {
                        if(strncmp(array[i].nombre,array[j].nombre,50)<0)
                        {
                            auxPantalla = array[i];
                            array[i] = array [j];
                            array[j] = auxPantalla;
                            retorno=0;
                        }

                  }

       }
    }
    return retorno;
}

void imprimirPantalla(Pantalla pantalla)
{

    printf("\nID: %d\nNombre: %s\nDireccion: %s\nPrecio: %.2f\nTipo: %d\n-------",
    pantalla.idPantalla,pantalla.nombre,pantalla.direccion,pantalla.precio,pantalla.tipo);
}

void filtrarValor(Pantalla* array, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        if(array[i].precio<=10 && array[i].isEmpty==0)
        {
            imprimirPantalla(array[i]);
        }
    }
}

void marketingCorto(Pantalla* arrayP, Publicidad* arrayPub, int limite)
{
    int i;
    int auxIdPantalla;
    int j;
    float precioTotal;
    for(i=0;i<=limite;i++)
    {
        if(arrayPub[i].dias<=10 && arrayPub[i].isEmpty==0)
        {
            auxIdPantalla = arrayPub[i].idPantalla;
            j=pan_findPanById(arrayP, limite,auxIdPantalla);
            precioTotal = arrayPub[i].dias * arrayP[j].precio;
            printf("\nNombre: %s \nPrecio x Dias: %.2f \nDias: %d \nPrecio Total: %.2f \n\n",
            arrayP[j].nombre,arrayP[j].precio,arrayPub[i].dias,precioTotal);

        }

    }


}
