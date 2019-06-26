#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entregas.h"

/** \brief Parsea los datos los datos de los entregas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int parser_EntregasFromText(FILE* pFile, LinkedList* pArrayListEntregas)
{
    int retorno = -1;
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferImporte[4096];
    Entregas* pAuxEntregas;
    if(pFile != NULL && pArrayListEntregas != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTipo,bufferCantidad,bufferImporte);
            pAuxEntregas = entregas_newParametros(bufferId,bufferTipo,bufferCantidad,bufferImporte);
            if(pAuxEntregas != NULL)
            {
                ll_add(pArrayListEntregas,pAuxEntregas);
                retorno = 0;
            }
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los entregas desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int parser_EntregasFromBinary(FILE* pFile, LinkedList* pArrayListEntregas)
{
    int retorno = -1;
    Entregas aux;
    Entregas* entrega;
    if(pFile != NULL && pArrayListEntregas != NULL)
    {
        while(!feof(pFile))
        {

            entrega = entregas_newFileBinario(aux);
            fread(&aux,sizeof(Entregas),1,pFile);
            if(entrega != NULL)
            {
                ll_add(pArrayListEntregas,entrega);
            }
            else
            {
                entregas_delete(entrega);
            }
        }
        retorno = 0;
    }
    fclose(pFile);
    return retorno;
}
