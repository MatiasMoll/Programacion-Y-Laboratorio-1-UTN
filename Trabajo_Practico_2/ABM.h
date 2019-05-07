#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

typedef struct
{
    int id;
    int isEmpty;
    char nombre[51];
    char apellido[51];
    int sector;
    float salario;
}Empleado;

int ABM_initArray(Empleado* arrayEmpleados, int limite);
int ABM_addEmployee(Empleado* arrayEmpleados,int limite, char* nombre, char* lastName, float salario,int sector, int id);
int ABM_lugarVacio(Empleado* arrayEmpleado, int limite, int* vacio);
int ABM_buscarPorId(Empleado* arrayEmpleado, int limite, int id);
int ABM_removeEmployee(Empleado* arrayEmpleado, int limite, int id);
int ABM_sortEmployee(Empleado* arrayEmpleado, int limite, int order);
void printEmploye(Empleado empleado);
int ABM_printEmployees(Empleado* arrayEmpleado, int limite);
int ordenarMayorAMenor(Empleado* arrayEmpleado, int limite);
int ordenarMenorAMayor(Empleado* arrayEmpleado, int limite);
#endif // ABM_H_INCLUDED
