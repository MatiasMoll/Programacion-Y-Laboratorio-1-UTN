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
    //int option;
    //Employee* pAuxEmp;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleado = ll_newLinkedList();
    //char nombreA[4096];
    //int idA;
    //int horasA;
    //int sueldoA;
    /*do{

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    controller_removeEmployee(listaEmpleados);
    controller_ListEmployee(listaEmpleados);*/
    FILE* pFile = fopen("data.csv","r");
    parser_EmployeeFromText(pFile,listaEmpleados);
    controller_saveAsBinary("data.bin",listaEmpleado);
    controller_loadFromBinary("data.bin",listaEmpleado);
    controller_ListEmployee(listaEmpleado);
    printf("%d",ll_len(listaEmpleado));

    return 0;
}
