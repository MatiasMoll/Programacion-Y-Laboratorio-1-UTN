#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "Validaciones.h"
#define MIN_ID 0
#define MAX_ID 1000

Persona* Persona_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

int Persona_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Persona_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Persona_getId(Persona* this, int* valor)
{
    int retorno = -1;
    if(this != NULL && valor != NULL)
    {
        *valor = this->id;
        retorno = 0;
    }
    return retorno;
}


int Persona_setNombre(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && VAL_Name(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int Persona_getNombre(Persona* this, char* valor)
{
    int retorno = -1;
    if(this != NULL && valor != NULL)
    {
        strncpy(valor,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;

}

int Persona_setApellido(Persona* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && VAL_Name(apellido))
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int Persona_getApellido(Persona* this, char* valor)
{
    int retorno = -1;
    if(this != NULL && valor != NULL)
    {
        strncpy(valor,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;

}
int Persona_setEstado(Persona* this, int estado)
{
    int retorno = -1;
    if(this != NULL && VAL_Int(estado,0,2)) //0=Inactivo, 1=Activo, 2=Bloqueado
    {
        this->estado=estado;
        retorno = 0;
    }
    return retorno;

}
int Persona_getEstado(Persona* this, int* valor)
{
    int retorno = -1;
    if(this != NULL && valor != NULL)
    {
        *valor = this->estado;
        retorno = 0;
    }
    return retorno;
}

int Persona_compararNombre(Persona* this,Persona* this1)
{
    int retorno = -2;
    if(this != NULL && this1 != NULL)
    {
        retorno = strncmp(this->nombre,this1->nombre,sizeof(this->nombre));
    }
    return retorno;
}

Persona* Persona_alta(char* nombre, char* apellido, int estado, int id)
{
    Persona *retorno = NULL;
    Persona *persona = Persona_new();
    if(persona != NULL && !Persona_setNombre(persona,nombre) && !Persona_setApellido(persona,apellido)
        && !Persona_setEstado(persona,estado) && !Persona_setId(persona, id))
    {
        retorno = persona;
    }else
        {
            free(persona);
        }
    return retorno;
}

//***************************************************************************************************************************

int Persona_setIdStr(Persona* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && VAL_Entero(id))
    {
        retorno = Persona_setId(this,atoi(id));
    }
    return retorno;
}

int Persona_getIdStr(Persona* this, char *id)
{
    int retorno = 0;
    int buffer;
    if(this != NULL && id != NULL)
    {
      Persona_getId(this,&buffer);
      sprintf(id,"%d",buffer);
      retorno = 1;
    }
    return retorno;
}
int Persona_getEstadoStr(Persona* this, char *estado)
{
    int retorno = 0;
    int buffer;
    if(this != NULL && estado != NULL)
    {
      Persona_getEstado(this,&buffer);
      switch(buffer)
      {
        case 0:
            sprintf(estado,"false");
            break;
        case 1:
            sprintf(estado,"true");
            break;
      }
      retorno = 1;
    }
    return retorno;
}

int Persona_setEstadoStr(Persona* this, char* estado)
{
    int retorno = 0;
    if(this != NULL && estado != NULL)
    {
        if(strcmp(estado,"false")==0)
        {
            Persona_setEstado(this,0);
        }else if(strcmp(estado,"true")==0)
            {
               Persona_setEstado(this,1);
            }
        retorno = 1;
    }
    return retorno;
}

Persona* Persona_altaStr(char* nombre, char* apellido, char* id, char* estado)
{
    Persona* retorno = NULL;
    Persona* nuevaPersona = Persona_new();
    if(nuevaPersona != NULL && nombre!=NULL && apellido != NULL && estado != NULL && id != NULL)
    {
        if((!Persona_setNombre(nuevaPersona,nombre)) && (!Persona_setApellido(nuevaPersona,apellido)) &&
            (!Persona_setIdStr(nuevaPersona,id)) && (Persona_setEstadoStr(nuevaPersona,estado)))
        {
            retorno = nuevaPersona;
        }else
            {
                Persona_delete(nuevaPersona);
            }
    }else
        {
            Persona_delete(nuevaPersona);
        }
    return retorno;
}

int llenarArrayDesdeArchivo(Persona* array[], int sizeArray,char* nombreArchivo,char* parseo, int* idMaximo)
{
    int retorno = -1;
    int i=0;
    Persona* auxPersona;
    char auxNombre[50];
    char auxApellido[50];
    char auxId[50];
    char auxEstado[50];
    char basura[50];
    //int idMax = 0;
    FILE* pAux;
    pAux = fopen(nombreArchivo, "r");
    if(pAux != NULL)
    {
        while(!feof(pAux) && i<sizeArray)
        {
            fscanf(pAux,parseo,auxId,auxNombre,auxApellido,auxEstado,basura);
            auxPersona = Persona_altaStr(auxNombre,auxApellido,auxId,auxEstado);
            if(auxPersona != NULL)
            {
                array[i] = auxPersona;
                i++;
                if(*idMaximo<atoi(auxId))
                {
                    *idMaximo = atoi(auxId);
                }

            }
         }
         retorno = 0;
    }
    fclose(pAux);
    return retorno;
}
