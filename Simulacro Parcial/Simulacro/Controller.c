#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entregas.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
 int entregaRegular(void* p)
 {
    int retorno = 0;
    char tipo[256];
    if(p!=NULL)
    {
        entregas_getTipo((Entregas*)p,tipo);
        if(!strcmp(tipo,"REGULAR"))
            retorno = 1;
    }
    return retorno;
 }

int entregaPlus(void* p)
{
    int retorno = 0;
    char tipo[256];
    if(p!=NULL)
    {
        entregas_getTipo((Entregas*)p,tipo);
        if(!strcmp(tipo,"PLUS"))
            retorno = 1;
    }
    return retorno;
 }
int controller_tiposEntregas(LinkedList* arrayEntregas, int* cantRegular, int* cantPlus, int* cantGold)
 {
    int retorno = -1;
    int auxContador;
    if(arrayEntregas != NULL && cantRegular != NULL && cantPlus != NULL && cantGold != NULL)
    {
        auxContador = ll_len(arrayEntregas);
        ll_reduce(arrayEntregas,entregaRegular);
        *cantRegular = auxContador - ll_len(arrayEntregas);

        auxContador = ll_len(arrayEntregas);
        ll_reduce(arrayEntregas,entregaPlus);
        *cantPlus = auxContador - ll_len(arrayEntregas);

        *cantGold = ll_len(arrayEntregas);

        retorno = 0;
    }
    return retorno;
 }

 int controller_totalBultosImportePromedio(LinkedList* arrayEntregas, int* totalBultos,float* promedio)
{
    int retorno = -1;
    int aux = 0;
    int subTotal;
    int i;
    float auxImporte=0.0;
    float subTotalImporte=0.0;
    Entregas* entrega;
    if(arrayEntregas != NULL)
    {
        for(i=0;i<ll_len(arrayEntregas);i++)
        {
            entrega = ll_get(arrayEntregas,i);
            if(entrega != NULL)
            {
                entregas_getCantidad(entrega,&subTotal);
                entregas_getImporte(entrega,&subTotalImporte);
                aux += subTotal;
                auxImporte += subTotalImporte;
            }
        }
        retorno = 0;
        *totalBultos = aux;
        *promedio = auxImporte / i;
    }
    return retorno;
}

int controller_loadFromText(char* path, LinkedList* pArrayListEntregas)
{
    int retorno = -1;
    FILE* fAux;
    if(path != NULL && pArrayListEntregas != NULL)
    {
        fAux = fopen(path, "r");
        if(fAux != NULL)
        {
            if(!parser_EntregasFromText(fAux,pArrayListEntregas))
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEntregas)
{
    int retorno = -1;
    FILE* pFile = NULL;
    if(path != NULL && pArrayListEntregas != NULL)
    {
        pFile = fopen(path, "r");
        if(pFile != NULL && !parser_EntregasFromBinary(pFile,pArrayListEntregas))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEntregas)
{
    int retorno = -1;
    float promedio;
    float importePromedio;
    int cantPlus;
    int cantRegular;
    int cantGold;
    int cantidadBultos;
    int cantidadTotal;
    FILE* pFileAux;
    if(path!= NULL && pArrayListEntregas != NULL)
    {
        pFileAux = fopen(path,"w");
        if(pFileAux != NULL)
        {
            cantidadTotal = ll_len(pArrayListEntregas);
            controller_totalBultosImportePromedio(pArrayListEntregas,&cantidadBultos,&importePromedio);
            controller_tiposEntregas(pArrayListEntregas,&cantRegular,&cantPlus,&cantGold);
            promedio = (float)cantidadBultos / cantidadTotal;
            fprintf(pFileAux,"********************\nInforme de ventas\n********************\n");
            fprintf(pFileAux,"- Cantidad total de entregas: %d\n"
                            "- Cantidad de entregas por tipo: %d(GOLD) - %d (REGULAR) - %d (PLUS)\n"
                            "- Cantidad total de bultos entregados: %d\n"
                            "- Promedio de bultos por entrega: %.2f\n"
                            "- Importe promedio por entrega: %.2f  \n"
                            ,cantidadTotal,cantGold,cantRegular,cantPlus,cantidadBultos,promedio,importePromedio);
            fprintf(pFileAux,"********************"),
            retorno = 0;
            fclose(pFileAux);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEntregas)
{
    int retorno = -1;
    FILE *pFile = NULL;
    Entregas* pAux = NULL;
    int i;
    if(path!=NULL && pArrayListEntregas != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListEntregas);i++)
            {
                pAux = ll_get(pArrayListEntregas,i);
                fwrite(pAux,sizeof(Entregas),1,pFile);
                retorno = 0;
            }


        }
    }
    return retorno;
}


/*int contadorBultos(void* pEntregas)
{
    int retorno = 0;
    if(pEntregas != NULL)
    {
        entregas_getCantidad((Entregas*)pEntregas, &retorno);
    }
    return retorno;
}*/
