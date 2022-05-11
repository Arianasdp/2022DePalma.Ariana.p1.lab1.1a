#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

typedef struct{

int id;
char descripcion[20];
int precio;
}eServicio;

#endif // TRABAJO_H_INCLUDED

int inicializarTrabajos(eTrabajo vec[], int tam);
int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pId);

int altaTrabajo(eTrabajo vec[], int tam, eServicio servicios[], int tamS, int* pId);
int listarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamS);
int mostrarTrabajos(eTrabajo t, eServicio servicios[], int tam);
int cargarDescripcionServicios(eServicio servicios[], int tam, int id, char descripcion[]);
int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);
int buscarServicios(eServicio servicios[], int tam, int id, int* pIndice);
int validarServicios(eServicio servicios[], int tam, int id);

void validarFecha(eFecha unaFecha);

int listarServicios(eServicio servicios[], int tam);
