#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
    float varFloat;
    char varChar;
    char varLongString[TEXT_SIZE];

}Socios;


#endif // SOCIO_H_INCLUDED

int socios_Inicializar(Socios array[], int size);                                    //cambiar socios
int socios_buscarEmpty(Socios array[], int size, int* posicion);                    //cambiar socios
int socios_buscarID(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socios
int socios_buscarInt(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socios
int socios_buscarString(Socios array[], int size, char* valorBuscado, int* indice);                    //cambiar socios
int socios_alta(Socios array[], int size, int* contadorID);                          //cambiar socios
int socios_baja(Socios array[], int sizeArray);                                      //cambiar socios
int socios_bajaValorRepetidoInt(Socios array[], int sizeArray, int valorBuscado);
int socios_modificar(Socios array[], int sizeArray);                                //cambiar socios
int socios_ordenarPorDobleCriterio(Socios array[],int size, int orderFirst, int orderSecond);                                  //cambiar socios
int socios_listar(Socios array[], int size);                      //cambiar socios
void socios_mock(Socios arraySocios[], int size,int *contadorId);                      //cambiar socios

