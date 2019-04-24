#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Empleado.h"
#define LEN_LISTA    100

int main()
{

   /* int opcion;
    char nombres[LEN_LISTA][20];
    int posAeliminar;
    int i,posLibre;
    char buffer[20];

    for(i=0; i<LEN_LISTA;i++)
        nombres[i][0]='\0';



    while(1)
    {

        utn_getNumber(&opcion,
                      "1)ingresar\n2)listar,4)eliminar\n",
                      "NO!",
                      1,10,2);

        printf("elegiste:%d\n",opcion);
        switch(opcion)
        {
            case 1:
            {
                printf("agregar nombre\n");

                if(buscarLibre(nombres,LEN_LISTA,&posLibre)==0)
                {
                    printf("1.se encontro lugar en %d\n",posLibre);

                    //utn_getString(buffer,"Ingrese:","No!",0,20,1);
                    fgets(buffer,20,stdin);

                    printf("se ingreso:%s\n",buffer);

                    printf("2. se encontro lugar en %d\n",posLibre);
                    //nombres[posLibre] = buffer;
                    strncpy(nombres[posLibre],buffer,20);


                    for(i=0;i<10; i++)
                        printf("-%d: %s\n",i,nombres[i]);

                }

                break;
            }
            case 4:
            {
                // PIDO NOMBRE
                //utn_getString(buffer,...)
                fgets(buffer,20,stdin);buffer[strlen(buffer)-1]='\0';

                // en buffer esta el nombre
                buscarNombre(buffer,
                            nombres,
                            LEN_LISTA,
                            &posAeliminar);

                // borro
                nombres[posAeliminar][0]='\0';

                break;
            }
        }

    }*/
    int posicionRepetido = -1;
    Empleado prueba = {1,0, "Matias"};
    printf(prueba);
    /*Empleado arrayEmpleados[5];
    strcpy(arrayEmpleados[0].nombre,"Cintia");
    strcpy(arrayEmpleados[1].nombre,"Matias");
    strcpy(arrayEmpleados[2].nombre,"Roberto");
    strcpy(arrayEmpleados[3].nombre,"Carlos");
    strcpy(arrayEmpleados[4].nombre,"Juan");
    for(int i=0;i<5;i++)
    {
        printf("\n%s",arrayEmpleados[i].nombre);
    }
    EMP_buscarNombre(arrayEmpleados, 5,"Cintia",&posicionRepetido);
    printf("\n%d", posicionRepetido);*/

    return 0;
}



