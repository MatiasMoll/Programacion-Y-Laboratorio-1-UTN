int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_totalBultosImportePromedio(LinkedList* arrayEntregas, int* totalBultos,float* promedio);
//int controller_promedioImporte(LinkedList* arrayEntregas, int totalBultos, float* promedio);
int controller_tiposEntregas(LinkedList* arrayEntregas, int* cantRegular, int* cantPlus, int* cantGold);
int entregaRegular(void* p);
int entregaPlus(void* p);

