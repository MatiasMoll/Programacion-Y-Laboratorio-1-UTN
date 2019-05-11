#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socio.h"
#include "libros.h"
#include "prestamos.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array prestamos Array of prestamos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int prestamos_Inicializar(Prestamos array[], int size)                                    //cambiar prestamos
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int prestamos_buscarEmpty(Prestamos array[], int size, int* posicion)                    //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamos_buscarID(Prestamos array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int prestamos_buscarIdSocio(Prestamos array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idSocio==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int prestamos_buscarIdLibro(Prestamos array[], int size, int valorBuscado, int* posicion)                    //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idLibro==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
//String


//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int prestamos_alta(Prestamos array[],Socios arraySocios[],int sizeSocio, Libros arrayLibros[],int sizeLibros, int size, int* contadorID)                          //cambiar prestamos
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(prestamos_buscarEmpty(array,size,&posicion)==-1)                          //cambiar prestamos
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            socios_listar(arraySocios, sizeSocio);
            utn_getUnsignedInt("\nIngrese Id del socio: ","\nError",1,sizeof(int),1,sizeSocio,1,&array[posicion].idSocio);
            libros_listar(arrayLibros, sizeLibros);           //mensaje + cambiar campo varInt
            utn_getUnsignedInt("\nIngrese Id del libro: ","\nError",1,sizeof(int),0,sizeLibros,1,&array[posicion].idLibro);             //mensaje + cambiar campo varFloat

            printf("\n Posicion: %d\n ID: %d\n Id de Socio: %d\nId de Libro: %d\n",
                   posicion, array[posicion].idUnico,array[posicion].idSocio,array[posicion].idLibro);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamos_baja(Prestamos array[], int sizeArray)                                      //cambiar prestamos
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(prestamos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].idLibro=0;                                                               //cambiar campo varInt
            array[posicion].idSocio=0;                                                             //cambiar campo varFloat
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int prestamos_bajaValorRepetidoInt(Prestamos array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].idSocio=0;                                                               //cambiar campo varInt
                array[i].idLibro=0;                                                             //cambiar campo varFloat
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int prestamos_modificar(Prestamos array[], int sizeArray)                                //cambiar prestamos
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(prestamos_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID prestamo: %d\n ID Del socio: %d\n ID Del libro: %d",
                       posicion, array[posicion].idUnico,array[posicion].idSocio,array[posicion].idLibro);
                utn_getChar("\nModificar: A B S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\nID del Socio: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idSocio);           //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nID Del libro: ","\nError",1,sizeof(int),0,1,1,&array[posicion].idLibro);             //mensaje + cambiar campo varFloat
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int prestamos_ordenarPorDobleCriterio(Prestamos array[],int size, int orderFirst, int orderSecond)                              //cambiar prestamos
{
    int retorno=-1;
    int i;
    Prestamos buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].idLibro,array[i+1].idLibro) < 0) && orderFirst) ||
                    ((strcmp(array[i].idLibro,array[i+1].idLibro) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].idLibro,array[i+1].idLibro) == 0)
                {
                    if( ((array[i].idSocio < array[i+1].idSocio ) && orderSecond) ||
                        ((array[i].idSocio  > array[i+1].idSocio ) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array prestamos Array de prestamos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int prestamos_listar(Prestamos array[], int size)                      //cambiar prestamos
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n Id del Socio: %d\n ID Del Libro: %d",
                       array[i].idUnico,array[i].idSocio,array[i].idLibro);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


void prestamos_mock(Prestamos arrayPrestamos[], int size,int *contadorId)                      //cambiar prestamos
{
    //*******************************************************************
    arrayPrestamos[0].idUnico=0;
    arrayPrestamos[0].isEmpty=0;
    arrayPrestamos[0].idLibro=0;
    arrayPrestamos[0].idSocio=0;
    *contadorId++;

    arrayPrestamos[1].idUnico=1;
    arrayPrestamos[1].isEmpty=0;
    arrayPrestamos[1].idLibro=0;
    arrayPrestamos[1].idSocio=0;
    *contadorId++;

    arrayPrestamos[2].idUnico=2;
    arrayPrestamos[2].isEmpty=0;
    arrayPrestamos[2].idLibro=0;
    arrayPrestamos[2].idSocio=20;
    *contadorId++;

    arrayPrestamos[3].idUnico=3;
    arrayPrestamos[3].isEmpty=0;
    arrayPrestamos[3].idLibro=0;
    arrayPrestamos[3].idSocio=10;
    *contadorId++;
}

