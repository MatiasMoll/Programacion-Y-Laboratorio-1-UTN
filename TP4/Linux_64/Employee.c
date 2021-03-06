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
    Employee* retorno = NULL;
    Employee* pEmployee = employee_new();
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL && pEmployee != NULL)
    {
        if(VAL_Entero(idStr) && VAL_Entero(horasTrabajadasStr) && VAL_Entero(sueldoStr))
        {
            if(employee_setId(pEmployee,atoi(idStr))||employee_setNombre(pEmployee,nombreStr)||employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr))||
            employee_setSueldo(pEmployee,atoi(sueldoStr)))
            {
                employee_delete(pEmployee);
            }else
                {
                    retorno = pEmployee;
                }
        }
    }
    return retorno;
}
Employee* employee_newFileBinario(Employee empleado)
{
    Employee* retorno = NULL;
    Employee* pAux = employee_new();
    if(pAux != NULL)
    {
        if(employee_setId(pAux,empleado.id)||employee_setNombre(pAux,empleado.nombre)
            ||employee_setHorasTrabajadas(pAux,empleado.horasTrabajadas)||employee_setSueldo(pAux,empleado.sueldo))
        {
            employee_delete(pAux);
        }else
            {
                retorno = pAux;
            }
    }
    return retorno;
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
    if(this != NULL )//&& VAL_Int(horasTrabajadas,0,1000))
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
    if(this != NULL )//&& VAL_Int(sueldo,MIN_SUELDO,MAX_SUELDO))
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

int em_calcularSueldo(void* p)
{
    int sueldo;
    int horasTrabajadas;
    if(p != NULL)
    {

        employee_getHorasTrabajadas(p,&horasTrabajadas);
        if(horasTrabajadas<=120)
        {
            sueldo = horasTrabajadas * 180;
        }else if(horasTrabajadas<=160)
            {
                sueldo = (120 * 180) + (horasTrabajadas - 120) * 240;
            }else if(horasTrabajadas<=240)
                {
                    sueldo = (120 * 180) + (40 * 240) + (horasTrabajadas - 160) * 350;
                }else
                    {
                        sueldo = (120 * 180) + (40 * 240 ) + (80 * 350)+(horasTrabajadas - 240) * 400;
                    }

       employee_setSueldo(p,sueldo);
    }
    return 1;
}

int filtroHorasMayor240(void* p)
{
    int retorno = 0;
    int horas;
    if(p != NULL)
    {
        employee_getHorasTrabajadas((Employee*)p,&horas);
        if(horas>=240)
        {
            retorno = 1;
        }

    }
    return retorno;
}
int filtroSueldo20k(void* p)
{
    int retorno = 0;
    int sueldo;
    if(p!=NULL)
    {
        employee_getSueldo((Employee*)p,&sueldo);
        if(sueldo>=20000)
        {
            retorno = 1;
        }

    }
    return retorno;
}
