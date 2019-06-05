#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    //int option = 0;
    /*
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/
    Employee* pAuxEmp;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char nombreA[4096];
    int idA;
    int horasA;
    int sueldoA;
    FILE* pFile = fopen("data.csv","r");
    parser_EmployeeFromText(pFile,listaEmpleados);
    for(int i=0;i<ll_len(listaEmpleados);i++)
    {
        pAuxEmp = ll_get(listaEmpleados,i);
        if(pAuxEmp != NULL)
        {
            employee_getId(pAuxEmp,&idA);
            employee_getNombre(pAuxEmp,nombreA);
            employee_getHorasTrabajadas(pAuxEmp,&horasA);
            employee_getSueldo(pAuxEmp,&sueldoA);

            printf("Id: %d Nombre: %s Horas Trabajadas: %d Sueldo: %d\n",idA,nombreA,horasA,sueldoA);
        }
    }
    return 0;
}
