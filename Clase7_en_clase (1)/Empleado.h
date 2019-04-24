#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct
{
    int idEmpleado;
    int isEmpty;
    char nombre[50];
    int edad;
}Empleado;

int EMP_initArray(Empleado* arrayEmpleado, int limite);
int EMP_lugarLibre(Empleado* arrayEmpleado, int limite, int* lugarLibre);
int EMP_alta(Empleado* arrayEmpleado, int limite, int id);
int EMP_baja(Empleado* arrayEmpleado, int limite);
int EMP_buscarNombre(Empleado* arrayEmpleado, int limite, char* nombre, int* indice);
int EMP_buscarEdad(Empleado* arrayEmpleado, int limite, int edad, int* indice);
int EMP_ordenarNombre(Empleado* arrayEmpleado, int limite);
int EMP_ordenarEdad(Empleado* arrayEmpleado, int limite);

#endif // EMPLEADO_H_INCLUDED
