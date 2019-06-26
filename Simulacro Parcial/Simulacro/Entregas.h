#ifndef entregas_H_INCLUDED
#define entregas_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float importe;
}Entregas;

Entregas* entregas_new();
Entregas* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char* importeStr);
Entregas* entregas_newFileBinario(Entregas empleado);

void entregas_delete(Entregas* this);

int entregas_setId(Entregas* this,int id);
int entregas_getId(Entregas* this,int* id);


int entregas_setTipo(Entregas* this,char* tipo);
int entregas_getTipo(Entregas* this,char* tipo);

int entregas_setCantidad(Entregas* this,int cantidad);
int entregas_getCantidad(Entregas* this,int* cantidad);

int entregas_setImporte(Entregas* this,float importe);
int entregas_getImporte(Entregas* this,float* importe);


#endif // entregas_H_INCLUDED
