#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"  //cambiar por nombre entidad
#include "autor.h"
#include "socio.h"
#include "libros.h"
#include "prestamos.h"

#define QTY_ARRAY_TIPO 10
#define QTY_ARRAY_AUTOR 10
#define QTY_ARRAY_SOCIO 10
#define QTY_ARRAY_LIBROS 10
#define QTY_ARRAY_PRESTAMOS 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int primeraOpcion;
    int contadorIdfantasma=0;                   //cambiar

    Fantasma arrayFantasma[QTY_ARRAY_TIPO];                   //cambiar
    fantasma_Inicializar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
    fantasma_mock(arrayFantasma, QTY_ARRAY_TIPO, &contadorIdfantasma) ;                     //cambiar fantasma


    int contadorIdautor=0;
    Autor arrayAutor[QTY_ARRAY_AUTOR];                   //cambiar
    autor_Inicializar(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
    autor_mock(arrayAutor, QTY_ARRAY_AUTOR, &contadorIdautor) ;                     //cambiar fantasma

    int contadorIdsocios=0;
    Socios arraySocios[QTY_ARRAY_SOCIO];                   //cambiar
    socios_Inicializar(arraySocios,QTY_ARRAY_SOCIO);                   //cambiar
    socios_mock(arraySocios, QTY_ARRAY_SOCIO, &contadorIdsocios) ;                     //cambiar fantasma

    int contadorIdlibros=0;
    Libros arrayLibros[QTY_ARRAY_LIBROS];                   //cambiar
    libros_Inicializar(arrayLibros,QTY_ARRAY_LIBROS);                   //cambiar
    libros_mock(arrayLibros, QTY_ARRAY_LIBROS, &contadorIdlibros) ;                     //cambiar fantasma

    int contadorIdprestamos=0;
    Prestamos arrayPrestamos[QTY_ARRAY_PRESTAMOS];                   //cambiar
    prestamos_Inicializar(arrayPrestamos,QTY_ARRAY_PRESTAMOS);                   //cambiar
    prestamos_mock(arrayPrestamos, QTY_ARRAY_PRESTAMOS, &contadorIdprestamos) ;                     //cambiar fantasma






    do
    {
        utn_getUnsignedInt("\n1-Menu Autor\n2-Menu Socios\n3-Menu Prestamos\n4-Menu Libros\n5-Salir\nIngrese su opcion: ","\nOpcion Invalida.",1,sizeof(int),1,5,1,&primeraOpcion);
        switch(primeraOpcion)
        {
            case 1:
                do{
                utn_getUnsignedInt("\n\n-------MENU AUTORES-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar\n6)Salir\nIngrese la opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                case 1: //Alta
                    autor_alta(arrayAutor,QTY_ARRAY_AUTOR,&contadorIdautor);                   //cambiar
                    break;

                case 2: //Modificar
                    autor_modificar(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
                    break;

                case 3: //Baja
                    autor_baja(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
                    break;

                case 4://Listar
                    autor_listar(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
                    break;

                case 5://Ordenar
                    autor_ordenarPorDobleCriterio(arrayAutor,QTY_ARRAY_AUTOR,SORT_UP,SORT_DOWN);                   //cambiar
                    break;
                case 6:
                    break;
                }
                }while(opcion!=6);
            break;

            case 2:
               do{
                    utn_getUnsignedInt("\n\n-------MENU SOCIOS-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar\n6)Salir\nIngrese su opcion: ",                   //cambiar
                                       "\nError",1,sizeof(int),1,6,1,&opcion);
                    switch(opcion)
                    {
                    case 1: //Alta
                        socios_alta(arraySocios,QTY_ARRAY_SOCIO,&contadorIdsocios);                   //cambiar
                        break;

                    case 2: //Modificar
                        socios_modificar(arraySocios,QTY_ARRAY_SOCIO);                   //cambiar
                        break;

                    case 3: //Baja
                        socios_baja(arraySocios,QTY_ARRAY_SOCIO);                   //cambiar
                        break;

                    case 4://Listar
                        socios_listar(arraySocios,QTY_ARRAY_SOCIO);                   //cambiar
                        break;

                    case 5://Ordenar
                        socios_ordenarPorDobleCriterio(arraySocios,QTY_ARRAY_SOCIO,SORT_UP,SORT_DOWN);                   //cambiar
                        break;
                    case 6:
                    break;
                    }
                }while(opcion!=6);
            break;

            case 3:
                do{
                 utn_getUnsignedInt("\n\n-------MENU PRESTAMOS-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar\n6)Salir\nIngrese su opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                case 1: //Alta
                    prestamos_alta(arrayPrestamos,arraySocios,QTY_ARRAY_SOCIO,arrayLibros,QTY_ARRAY_LIBROS,QTY_ARRAY_PRESTAMOS,&contadorIdprestamos);                   //cambiar
                    break;

                case 2: //Modificar
                    prestamos_modificar(arrayPrestamos,QTY_ARRAY_PRESTAMOS);                   //cambiar
                    break;

                case 3: //Baja
                    prestamos_baja(arrayPrestamos,QTY_ARRAY_PRESTAMOS);                   //cambiar
                    break;

                case 4://Listar
                    prestamos_listar(arrayPrestamos,QTY_ARRAY_PRESTAMOS);                   //cambiar
                    break;

                case 5://Ordenar
                    prestamos_ordenarPorDobleCriterio(arrayPrestamos,QTY_ARRAY_PRESTAMOS,SORT_UP,SORT_DOWN);                   //cambiar
                    break;
                }
                case 6:
                break;
                }while(opcion!=6);
            break;
            case 4:
                do{
                utn_getUnsignedInt("\n\n-------MENU LIBROS-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar\n6)Salir\nIngrese la opcion: ",                   //cambiar
                                   "\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                case 1: //Alta
                    libros_alta(arrayLibros,QTY_ARRAY_LIBROS,&contadorIdlibros);                   //cambiar
                    break;

                case 2: //Modificar
                    libros_modificar(arrayLibros,QTY_ARRAY_LIBROS);                   //cambiar
                    break;

                case 3: //Baja
                    libros_baja(arrayLibros,QTY_ARRAY_LIBROS);                   //cambiar
                    break;

                case 4://Listar
                    libros_listar(arrayLibros,QTY_ARRAY_LIBROS);                   //cambiar
                    break;

                case 5://Ordenar
                    libros_ordenarPorDobleCriterio(arrayLibros,QTY_ARRAY_LIBROS,SORT_UP,SORT_DOWN);                   //cambiar
                    break;
                case 6:
                    break;
                }
                }while(opcion!=6);
            break;
        }
        }while(primeraOpcion!=5);

           /* utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n\n 6) Alta autor \n7) Modificar autor \n8) Baja autor \n9) Listar autor \n10) Ordenar autor \n11) Salir\n",                   //cambiar
                               "\nError",1,sizeof(int),1,11,1,&opcion);
            switch(opcion)
            {
            case 1: //Alta
                fantasma_alta(arrayFantasma,QTY_ARRAY_TIPO,&contadorIdfantasma);                   //cambiar
                break;

            case 2: //Modificar
                fantasma_modificar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                fantasma_baja(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 4://Listar
                fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                fantasma_ordenarPorDobleCriterio(arrayFantasma,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;
            case 6: //Alta
                autor_alta(arrayAutor,QTY_ARRAY_TIPO,&contadorIdautor);                   //cambiar
                break;

            case 7: //Modificar
                autor_modificar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 8: //Baja
                autor_baja(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 9://Listar
                autor_listar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 10://Ordenar
                autor_ordenarPorDobleCriterio(arrayAutor,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 11://Salir
                break;

            default:
                printf("\nOpcion no valida");
            }
        }
        while(opcion!=6);*/
        return 0;
   }
