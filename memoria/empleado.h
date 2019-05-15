#define LEN_NAME 50
#ifndef EMPLEADO_H
#define EMPLEADO_H
typedef struct
{
    int id;
    char nombre[LEN_NAME];
    float peso;
    int estado;
}Empleado;
#endif

Empleado* Emp_new(void);
int Emp_delete(Empleado* this);

int Emp_setId(Empleado* this, int id);
int Emp_getId(Empleado* this, int* valor);
int Emp_setPeso(Empleado* this, float peso);
int Emp_getPeso(Empleado* this, float* valor);
int Emp_setNombre(Empleado* this, char* nombre);
int Emp_getNombre(Empleado* this, char* valor);
int Emp_setEstado(Empleado* this, int estado);
int Emp_getEstado(Empleado* this, int* valor);
int Emp_compararNombre(Empleado* this,Empleado* this1);//-1 = this>this1 ,0=Nombres Iguales, 1=this<this1
Empleado* Emp_alta(char* nombre, float peso, int estado, int id);




