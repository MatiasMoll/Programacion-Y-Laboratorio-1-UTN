#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "Validaciones.h"

Empleado* Emp_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}

int Emp_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Emp_setId(Empleado* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Emp_getId(Empleado* this, int* valor)
{
    int retorno = -1;
    if(this != NULL && valor != NULL)
    {
        *valor = this->id;
        retorno = 0;
    }
    return retorno;
}

int Emp_setPeso(Empleado* this, float peso)
{
    int retorno = -1;
    if(this != NULL &&  VAL_Float(peso,40,180))
    {
        this->peso = peso;
        retorno = 0;
    }
    return retorno;
}

int Emp_getPeso(Empleado* this, float* valor)
{
    int retorno = -1;
    if(this != NULL && valor != NULL)
    {
        *valor = this->peso;
        retorno = 0;
    }
    return retorno;
}

int Emp_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && VAL_Name(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int Emp_getNombre(Empleado* this, char* valor)
{
    int retorno = -1;
    if(this != NULL && valor != NULL)
    {
        strncpy(valor,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;

}
int Emp_setEstado(Empleado* this, int estado)
{
    int retorno = -1;
    if(this != NULL && VAL_Int(estado,0,2)) //0=Inactivo, 1=Activo, 2=Bloqueado
    {
        this->estado=estado;
        retorno = 0;
    }
    return retorno;

}
int Emp_getEstado(Empleado* this, int* valor)
{
    int retorno = -1;
    if(this != NULL && valor != NULL)
    {
        *valor = this->estado;
        retorno = 0;
    }
    return retorno;
}

int Emp_compararNombre(Empleado* this,Empleado* this1)
{
    int retorno = -2;
    if(this != NULL && this1 != NULL)
    {
        retorno = strncmp(this->nombre,this1->nombre,sizeof(this->nombre));
    }
    return retorno;
}

int Emp_alta(char* nombre, float peso, int estado, int id)
{
    Empleado *emp = Emp_new();
    if(emp != NULL && !Emp_setNombre(emp,nombre) && !Emp_setPeso(emp,peso)
        && !Emp_setEstado(emp,estado) && !Emp_setId(emp, id))
    {

    }else
        {
            free(emp);
        }
    return emp;
}






