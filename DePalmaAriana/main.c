#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"
#include "trabajo.h"

#define TAM 3
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4

int menu();
void confirmarSalida(char* p);

int main()
{
    char salir = 'n';
    int proximoId = 100;
    int proximoIdT = 800;
    eNotebook lista[TAM];
    eTrabajo listaT[TAM];
    eMarca marcas[TAM_M] ={
        {500, "Compaq"},
        {501, "Asus"},
        {502, "Acer"},
        {503, "HP"}
        };
    eTipo tipos[TAM_T] ={
        {300, "Gamer"},
        {301, "Disenio"},
        {302, "Ultrabook"},
        {303, "Normalita"}
        };
    eServicio servicios[TAM_S] = {
    {200, "Bateria", 2250},
    {201, "Display", 1030},
    {202, "Mantenimiento", 4400},
    {203, "Fuente", 5600}
    };

    inicializarNotebooks(lista, TAM);
    hardcodearNotebooks(lista, TAM, 2, &proximoId);

    inicializarTrabajos(listaT, TAM);
    hardcodearTrabajos(listaT, TAM, 2, &proximoIdT);

    do{
            switch(menu())
        {
            case 1:
                 if(altaNotebook(lista, TAM, marcas, TAM_M, tipos, TAM_T, &proximoId))
                 {
                    printf("Notebook agregada con exito\n");
                 }
                 else
                 {
                     printf("Problema al hacer el alta de Notebook\n");
                 }
                break;
            case 2:
                if(modificarNotebook(lista, TAM, marcas, TAM_M, tipos, TAM_T) == 0)
                 {
                    printf("Problema al hacer la modificacion de X\n");
                 }
                break;
            case 3:
                if(bajaNotebooks(lista, TAM, marcas, TAM_M, tipos, TAM_T) == 0)
                {
                    printf("Problema al hacer la baja de la notebook\n");
                }
                break;
            case 4:
                listarNotebooks(lista, TAM, marcas, TAM_M, tipos, TAM_T);
                break;
            case 5:
                listarMarcas(marcas, TAM_M);
                break;
            case 6:
                listarTipos(tipos, TAM_T);
                break;
            case 7:
                listarServicios(servicios, TAM_S);
                break;
            case 8:
                altaTrabajo(listaT, TAM, servicios, TAM_S, &proximoIdT);
                break;
            case 9:
                listarTrabajos(listaT, TAM, servicios, TAM_S);
                break;
            case 10:
                confirmarSalida(&salir);
                break;
            default:
            printf("Opcion invalida\n\n");
            fflush(stdin);
        }
        system("pause");
    }
    while(salir != 's');
    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("     *** ABM Notebooks ***\n");
    printf("1- Alta Notebook\n");
    printf("2- Modificar Notebook\n");
    printf("3- Baja Notebook\n");
    printf("4- Listar Notebooks\n");
    printf("5- Listar Marcas\n");
    printf("6- Listar Tipos\n");
    printf("7- Listar servicios\n");
    printf("8- Alta trabajo\n");
    printf("9- Listar trabajos\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;

}

void confirmarSalida(char* p)
{
    char confirma;

    printf("Confirma salida? s/n: ");
    fflush(stdin);
    scanf("%c", &confirma);

    *p = confirma;
}

