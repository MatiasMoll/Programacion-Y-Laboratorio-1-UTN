#include <stdio.h>
#include <stdlib.h>
#include "Entregas.h"
#include "Validaciones.h"
#include "LinkedList.h"
#include "Controller.h"
int main()
{
    LinkedList* arrayEntregas = ll_newLinkedList();

    controller_loadFromText("data.csv",arrayEntregas);
    controller_saveAsText("Entregas.csv",arrayEntregas);

    return 0;
}
