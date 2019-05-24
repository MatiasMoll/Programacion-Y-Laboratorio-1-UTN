#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

int main()
{
    /*Persona *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    //float peso;
    char nombre[50];
    char apellido[50];
    //int auxInt;

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Persona_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        if(Persona_alta("Matias","Moll",1,0)!= NULL)
        {
            pArrayEmpleado[indiceActual] = Persona_alta("Matias","Moll",1,0);
            ultimoElementoArrayEmpleado++;
        }
        Persona_getNombre(pArrayEmpleado[indiceActual],nombre);
        Persona_getApellido(pArrayEmpleado[indiceActual], apellido);

        printf("\nNombre: %s\nApellido: %s\n",nombre,apellido);

    }*/

    char nombre[50];
    char apellido[50];
    int id;
    int estado;
    Persona* nuevaP = Persona_altaStr("Matias","Moll","0", "true");
    Persona_getNombre(nuevaP,nombre);
    Persona_getApellido(nuevaP,apellido);
    Persona_getId(nuevaP,&id);
    Persona_getEstado(nuevaP,&estado);
    printf("%s\n%s\n%d\n%d\n",nombre,apellido,id,estado);
    return 0;
}
