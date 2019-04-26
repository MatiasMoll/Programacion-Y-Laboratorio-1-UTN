typedef struct
{
    int idPantalla;
    int isEmpty;
    char nombre[50];
    char direccion[256];
    float precio;
    char tipo[4];
}ePantalla;

int pant_initArray(ePantalla* arrayPantalla,int cantidad);
int pant_buscarVacio(ePantalla* arrayPantalla,int cantidad);
int pant_printArray(ePantalla* arrayPantalla,int cantidad);
int pant_alta(char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos, ePantalla* arrayPantalla, int cantidad);
