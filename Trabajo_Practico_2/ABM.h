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
int ABM_buscarPorId(Empleado* arrayEmpleado, int limite, int id);
#endif // ABM_H_INCLUDED
