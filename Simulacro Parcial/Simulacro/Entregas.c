#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entregas.h"
#include "Validaciones.h"

Entregas* entregas_new()
{
    return (Entregas*)malloc(sizeof(Entregas));
}
Entregas* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char* importeStr)
{
    Entregas* retorno = NULL;
    Entregas* pEntregas = entregas_new();
    if(idStr != NULL && tipoStr != NULL && cantidadStr != NULL && importeStr != NULL && pEntregas != NULL)
    {
        if(VAL_Entero(idStr) && VAL_Entero(cantidadStr) && VAL_Decimal(importeStr))
        {
            if(entregas_setId(pEntregas,atoi(idStr))||entregas_setTipo(pEntregas,tipoStr)||entregas_setCantidad(pEntregas,atoi(cantidadStr))||
            entregas_setImporte(pEntregas,atof(importeStr)))
            {
                entregas_delete(pEntregas);
            }else
                {
                    retorno = pEntregas;
                }
        }
    }
    return retorno;
}
Entregas* entregas_newFileBinario(Entregas entrega)
{
    Entregas* retorno = NULL;
    Entregas* pAux = entregas_new();
    if(pAux != NULL)
    {
        if(entregas_setId(pAux,entrega.id)||entregas_setTipo(pAux,entrega.tipo)
            ||entregas_setCantidad(pAux,entrega.cantidad)||entregas_setImporte(pAux,entrega.importe))
        {
            entregas_delete(pAux);
        }else
            {
                retorno = pAux;
            }
    }
    return retorno;
}
void entregas_delete(Entregas* this)
{
    free(this);
}
int entregas_setId(Entregas* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int entregas_getId(Entregas* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
       *id = this->id;
       retorno = 0;
    }
    return retorno;
}

int entregas_setTipo(Entregas* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL)
    {
        strcpy(this->tipo,tipo);
        retorno = 0;
    }
    return retorno;
}
int entregas_getTipo(Entregas* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo,this->tipo);
        retorno = 0;
    }
    return retorno;
}

int entregas_setCantidad(Entregas* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL )//&& VAL_Int(cantidad,0,1000))
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}
int entregas_getCantidad(Entregas* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int entregas_setImporte(Entregas* this,float importe)
{
    int retorno = -1;
    if(this != NULL )//&& VAL_Int(importe,MIN_SUELDO,MAX_SUELDO))
    {
        this->importe = importe;
        retorno = 0;
    }
    return retorno;
}
int entregas_getImporte(Entregas* this,float* importe)
{
    int retorno = -1;
    if(this != NULL && importe != NULL)
    {
        *importe = this->importe;
        retorno = 0;
    }
    return retorno;
}

