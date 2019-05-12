#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "socio.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array socios Array of socios
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int socios_Inicializar(Socios array[], int size)                                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int socios_buscarEmpty(Socios array[], int size, int* posicion)                    //cambiar socios
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarID(Socios array[], int size, int valorBuscado, int* posicion)                    //cambiar socios
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

//String
/** \brief Busca un string en un array
* \param array socios Array de socios
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int socios_buscarNombreYApellido(Socios array[], int size, char* nombre,char* apellido, int* indice)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,nombre)==0 && strcmp(array[i].apellido,apellido)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int socios_buscarMail(Socios array[], int size, char* valorBuscado, int* indice)                    //cambiar socios
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].mail,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array socios Array de socios
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int socios_alta(Socios array[], int size, int* contadorID)                          //cambiar socios
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(socios_buscarEmpty(array,size,&posicion)==-1)                          //cambiar socios
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
            utn_getName("\nIngrese Apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);//mensaje + cambiar campo varInt
            utn_getChar("\nIngrese el sexo: ","\Error",'A','Z',1,&array[posicion].sexo);
            utn_getTelefono("\nIngrese el telefono: ","\nError",8,16,100000000,9999999999999999,1,array[posicion].telefono);
            utn_getEmail("\nIngrese el Mail: ","\nError",1,TEXT_SIZE,1,array[posicion].mail);              //mensaje + cambiar campo varFloat
            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\nApellido: %s\nSexo: %c\nTelefono: %s\n Mail: %s",
                   posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido,array[posicion].sexo,array[posicion].telefono,array[posicion].mail);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socios_baja(Socios array[], int sizeArray)                                      //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(socios_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].sexo = " " ;                                                            //cambiar campo id
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
            strcpy(array[posicion].apellido,"");
            strcpy(array[posicion].telefono,"");
            strcpy(array[posicion].mail,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array socios Array de socios
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int socios_bajaValorRepetidoInt(Socios array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
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
                strcpy(array[i].apellido,"");                                                        //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo varString
                strcpy(array[i].telefono,"");
                strcpy(array[i].mail,"");
                array[i].sexo="";                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int socios_modificar(Socios array[], int sizeArray)                                //cambiar socios
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(socios_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
              printf("\n Posicion: %d\n ID: %d\n Nombre: %s\nApellido: %s\nSexo: %c\nTelefono: %s\n Mail: %s",
                   posicion, array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido,array[posicion].sexo,array[posicion].telefono,array[posicion].mail);
                utn_getChar("\nModificar: A B C D E S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\nIngrese Nombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 'B':
                        utn_getName("\nIngrese Apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);//mensaje + cambiar campo varInt
                        break;
                    case 'C':
                        utn_getChar("\nIngrese el sexo: ","\Error",'A','Z',1,array[posicion].sexo);
                        break;
                    case 'D':
                        utn_getTelefono("\nIngrese el telefono: ","\nError",8,16,100000000,9999999999999999,1,array[posicion].telefono);
                        break;
                    case 'E':
                        utn_getEmail("\nIngrese el Mail: ","\nError",1,TEXT_SIZE,1,array[posicion].mail);
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int socios_ordenarPorDobleCriterio(Socios array[],int size, int orderFirst, int orderSecond)                              //cambiar socios
{
    int retorno=-1;
    int i;
    Socios buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].apellido< array[i+1].apellido) && orderSecond) ||
                        ((array[i].apellido > array[i+1].apellido) && !orderSecond) )
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
* \param array socios Array de socios
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int socios_listar(Socios array[], int size)                      //cambiar socios
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
                printf("\nPosicion: %d\nID: %d\nNombre: %s\nApellido: %s\nSexo: %c\nTelefono: %s\nMail: %s\n\n",
                i, array[i].idUnico,array[i].nombre,array[i].apellido,array[i].sexo,array[i].telefono,array[i].mail);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


void socios_mock(Socios arraySocios[], int size,int *contadorId)                      //cambiar socios
{
    //*******************************************************************
    arraySocios[0].idUnico=0;
    arraySocios[0].isEmpty=0;
    strcpy(arraySocios[0].nombre,"CCCCC");
    strcpy(arraySocios[0].apellido,"CCCCC");
    strcpy(arraySocios[0].telefono,"CCCCC");
    strcpy(arraySocios[0].mail,"CCCCC");
    arraySocios[0].sexo="F";
    *contadorId++;

    arraySocios[1].idUnico=1;
    arraySocios[1].isEmpty=0;
    strcpy(arraySocios[1].nombre,"AAAAA");
    strcpy(arraySocios[1].apellido,"AAAAA");
    strcpy(arraySocios[1].telefono,"AAAAA");
    strcpy(arraySocios[1].mail,"AAAAA");
    arraySocios[1].sexo="M";
    *contadorId++;

    arraySocios[2].idUnico=2;
    arraySocios[2].isEmpty=0;
    strcpy(arraySocios[2].nombre,"AAAAAAA");
    strcpy(arraySocios[2].apellido,"AAAAAA");
    strcpy(arraySocios[2].telefono,"98797987987");
    strcpy(arraySocios[2].mail,"BBBBBB");
    *contadorId++;

    arraySocios[3].idUnico=3;
    arraySocios[3].isEmpty=0;
    strcpy(arraySocios[3].nombre,"aaaaaaaa");
    strcpy(arraySocios[3].apellido,"aaaaaaa");
    strcpy(arraySocios[3].telefono,"123123321");
    strcpy(arraySocios[3].mail,"BBBBBB");
    arraySocios[3].sexo="F";
    *contadorId++;
}
