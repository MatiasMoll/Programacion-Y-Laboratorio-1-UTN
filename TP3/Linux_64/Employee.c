#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Get.h"
#include "Validaciones.h"
#define MIN_SUELDO 0
#define MAX_SUELDO 2000000

Employee* employee_new()
{
    return (Employee*)malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* pEmployee = employee_new();
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL && pEmployee != NULL)
    {
        if(VAL_Entero(idStr) && VAL_Entero(horasTrabajadasStr) && VAL_Entero(sueldoStr))
        {
            if(employee_setId(pEmployee,atoi(idStr))&&employee_setNombre(pEmployee,nombreStr)&&employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr))&&
            employee_setSueldo(pEmployee,atoi(sueldoStr)))
            {
                pEmployee = NULL;
            }
        }
    }
    return pEmployee;
}
void employee_delete(Employee* this)
{
    free(this);
}
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
       *id = this->id;
       retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && VAL_Int(horasTrabajadas,0,1000))
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && VAL_Int(sueldo,MIN_SUELDO,MAX_SUELDO))
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
