#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    float precio;
    int idMarca;
    int idTipo;
    int isEmpty;
} eNotebook;

typedef struct{

int id;
char descripcion[20];

}eMarca;

typedef struct{

int id;
char descripcion[20];

}eTipo;

#endif // NOTEBOOK_H_INCLUDED

int inicializarNotebooks(eNotebook vec[], int tam);
int hardcodearNotebooks(eNotebook vec[], int tam, int cant, int* pId);

int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, int* pId);
int modificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);
int bajaNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex);

int listarMarcas(eMarca marcas[], int tam);
int listarTipos(eTipo tipos[], int tam);
int listarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

int mostrarNotebooks(eNotebook n, eMarca marcas[], eTipo tipos[], int tam);

int cargarDescripcionMarcas(eMarca marcas[], int tam, int id, char descripcion[]);
int cargarDescripcionTipos(eTipo tipos[], int tam, int id, char descripcion[]);

int buscarMarcas(eMarca marcas[], int tam, int id, int* pIndice);
int buscarTipos(eTipo tipos[], int tam, int id, int* pIndice);

int validarMarcas(eMarca marcas[], int tam, int id);
int validarTipos(eTipo tipos[], int tam, int id);

