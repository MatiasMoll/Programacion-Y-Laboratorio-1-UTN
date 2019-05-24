#define LEN_NAME 50
#ifndef PERSONA_H
#define PERSONA_H
typedef struct
{
    int id;
    char nombre[LEN_NAME];
    char apellido[LEN_NAME];
    int estado;
}Persona;
#endif

Persona* Persona_new(void);
int Persona_delete(Persona* this);
//*************************************************************************************************************
int Persona_setId(Persona* this, int id);
int Persona_getId(Persona* this, int* valor);
int Persona_setNombre(Persona* this, char* nombre);
int Persona_getNombre(Persona* this, char* valor);
int Persona_setApellido(Persona* this, char* apellido);
int Persona_getApellido(Persona* this, char* apellido);
int Persona_setEstado(Persona* this, int estado);
int Persona_getEstado(Persona* this, int* valor);
int Persona_compararNombre(Persona* this,Persona* this1);//-1 = this>this1 ,0=Nombres Iguales, 1=this<this1
Persona* Persona_alta(char* nombre, char* apellido, int estado, int id);
//*************************************************************************************************************
int Persona_setIdStr(Persona* this, char* id);
int Persona_getIdStr(Persona* this, char *id);
int Persona_getEstadoStr(Persona* this, char *estado);
int Persona_setEstadoStr(Persona* this, char* estado);
Persona* Persona_altaStr(char* nombre, char* apellido, char* id, char* estado);
//*************************************************************************************************************
