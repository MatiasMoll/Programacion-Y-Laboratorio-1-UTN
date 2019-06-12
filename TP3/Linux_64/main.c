#include <stdio.h>
#include <stdlib.h>
#include "Get.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#define REINTENTOS 2
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
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flag=0;
    char salir;

    do{

        GET_Edad("\n1)Cargar datos desde el .csv\n2)Cargar datos desde el .bin\n3)Alta de Empleado\n4)Modificar datos del empleado\n"
                "5)Baja de empleado\n6)Listar empleado\n7)Ordenar empleados\n8)Guardar datos en archivos de texto\n9)Guardar datos en modo binario\n"
                "10)Salir\nIngrese la opcion deseada: ","\nOpcion Incorrecta\n",0,11,REINTENTOS,&option);
        system("clear");
        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    flag = 1;
                    printf("Datos cargados correctamente\nPresione una tecla para continuar..\n");
                    getchar();
                    system("clear");
                }else
                    {
                        printf("Error");
                    }
                break;
            case 2:
                if(!controller_loadFromBinary("dataBkp.csv",listaEmpleados))
                {
                    flag = 1;
                    printf("Datos cargados correctamente\nPresione una tecla para continuar\n..");
                    getchar();
                    system("clear");
                }else
                    {
                        printf("Error");
                    }

                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    flag = 1;
                    printf("Empleado cargado exitosamente!\n");
                }else
                    {
                        printf("Error en la carga\n");
                    }
                break;
            case 4:
                system("clear");
                if(flag)
                {
                    controller_editEmployee(listaEmpleados);
                }else
                    {
                        printf("La base de datos esta vacia\n");
                    }
                break;
            case 5:
                system("clear");
                if(flag)
                {
                    controller_removeEmployee(listaEmpleados);
                }else
                    {
                        printf("La base de datos esta vacia\n");
                    }
                break;
            case 6:
                if(flag)
                {
                    controller_ListEmployee(listaEmpleados);
                }else
                    {
                        printf("La base de datos esta vacia\n");
                    }
                break;
            case 7:
                if(flag)
                {
                    controller_sortEmployee(listaEmpleados);
                }else
                    {
                        printf("La base de datos esta vacia\n");
                    }
                break;
            case 8:
                if(flag)
                {
                    if(!controller_saveAsText("data2.csv",listaEmpleados))
                    {
                        printf("Cambio guardados exitosamente");
                        flag = 2;
                    }else
                        {
                            printf("Error al guardar");
                        }
                }else
                    {
                        printf("Base de datos vacia");
                    }
                break;
            case 9:
                if(flag)
                {
                    if(!controller_saveAsBinary("dataBkp.csv",listaEmpleados))
                    {
                        printf("Cambio guardados exitosamente");
                        flag = 2;
                    }else
                        {
                            printf("Error al guardar");
                        }
                }else
                    {
                        printf("Base de datos vacia");
                    }
               break;
            case 10:
                if(flag == 1)
                {
                    GET_Name("\nHay cambios sin guardar, desea salir igualmente?(S/N)\n","Opcion invalida",1,2,REINTENTOS,&salir);
                    salir = tolower(salir);
                    switch(salir)
                    {
                        case 's':
                            exit(0);
                            break;
                        case 'n':
                            continue;
                    }
                }
                break;
        }
    }while(option != 10);
    return 0;
}
