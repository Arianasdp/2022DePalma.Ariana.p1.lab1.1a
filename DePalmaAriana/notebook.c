#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"

int inicializarNotebooks(eNotebook vec[], int tam)
{
    int todoOk = 0;
    if(vec && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearNotebooks(eNotebook vec[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    eNotebook impostores[] =
    {
        {000, "modelo4", 100000, 501, 300, 0},
        {000, "modelo1", 120000, 500, 301, 0},
        {000, "modelo3", 80000, 500, 300, 0}
    };

    if(vec && tam > 0 && pId && cant > 0 && cant <= tam)
    {

        for(int i = 0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }
    return todoOk;

}

int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, int* pId)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eNotebook nuevaNotebook;

    if(vec && tam > 0 && pId)
    {
        if(buscarNotebookLibre(vec, tam, &indice))
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                printf("Ingrese el nombre del modelo de la notebook: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevaNotebook.modelo, auxCad);

                printf("Ingrese precio: ");
                scanf("%f", &nuevaNotebook.precio);

                listarMarcas(marcas, tam);

                printf("Ingrese Id Marca: ");
                scanf("%d", &nuevaNotebook.idMarca);

                while(!validarMarcas(marcas, tam, nuevaNotebook.idMarca))
                {
                    printf("Marca invalida. Ingrese Id Marca: ");
                    scanf("%d", &nuevaNotebook.idMarca);
                }

                 listarTipos(tipos, tam);

                printf("Ingrese Id Tipo: ");
                scanf("%d", &nuevaNotebook.idTipo);

                while(!validarTipos(tipos, tam, nuevaNotebook.idTipo))
                {
                    printf("Tipo invalido. Ingrese Id Tipo: ");
                    scanf("%d", &nuevaNotebook.idTipo);
                }

                nuevaNotebook.isEmpty = 0;
                nuevaNotebook.id = *pId;
                *pId = *pId + 1;
                vec[indice] = nuevaNotebook;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec && tam > 0 && pIndex)
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(vec[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarMarcas(eMarca marcas[], int tam){
int todoOk = 0;

    if(marcas && tam > 0){
        system("cls");
        printf("   *** Lista de Marcas  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %3d    %10s\n", marcas[i].id, marcas[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int listarTipos(eTipo tipos[], int tam){
int todoOk = 0;

    if(tipos && tam > 0){
        system("cls");
        printf("   *** Lista de Tipos  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %3d    %10s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int buscarMarcas(eMarca marcas[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(marcas && tam > 0 && pIndice){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(marcas[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTipos(eTipo tipos[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(tipos && tam > 0 && pIndice){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(tipos[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarMarcas(eMarca marcas[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarMarcas(marcas, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int validarTipos(eTipo tipos[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarTipos(tipos, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int listarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int flag = 0;
    if(vec && tam > 0)
    {
        system("cls");
        printf("          *** Listado de Notebooks ***\n\n");
        printf(" Id     Modelo      Precio        Marca       Tipo\n");
        printf("--------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarNotebooks(vec[i], marcas, tipos, tam);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay notebooks en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarNotebooks(eNotebook n, eMarca marcas[], eTipo tipos[], int tam)
{
    int todoOk = 0;
    char descMarca[20];
    char descTipo[20];

    if(marcas && tipos && tam > 0){

    cargarDescripcionMarcas(marcas, tam, n.idMarca, descMarca);
    cargarDescripcionTipos(tipos, tam, n.idTipo, descTipo);

    printf("  %3d   %8s     %9.2f     %5s    %4s\n",
           n.id,
           n.modelo,
           n.precio,
           descMarca,
           descTipo
          );
        todoOk = 1;
    }
    return todoOk;
}


int cargarDescripcionMarcas(eMarca marcas[], int tam, int id, char descripcion[]){
int todoOk = 0;

    if(marcas && tam > 0 && id >= 500 && id <= 501 && descripcion){
     for(int i=0; i < tam; i++){

        if(marcas[i].id == id){
            strcpy(descripcion, marcas[i].descripcion);
            break;
        }
     }
     todoOk = 1;
    }
  return todoOk;
}

int cargarDescripcionTipos(eTipo tipos[], int tam, int id, char descripcion[]){
int todoOk = 0;

    if(tipos && tam > 0 && id >= 300 && id <= 301 && descripcion){
     for(int i=0; i < tam; i++){

        if(tipos[i].id == id){
            strcpy(descripcion, tipos[i].descripcion);
            break;
        }
     }
     todoOk = 1;
    }
  return todoOk;
}

int buscarNotebook(eNotebook vec[], int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(vec && tam > 0 && pIndex && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int menuModificarNotebook()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- Marca\n");
    printf("2- Tipo\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int modificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    eMarca marca;
    eTipo tipo;
    char descMarca[20];
    char descTipo[20];

    if(vec && tam > 0)
    {
        listarNotebooks(vec, tam, marcas, tamM, tipos, tamT);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una notebook con id %d\n", id);
            }
            else
            {
                mostrarNotebooks(vec[indice], marcas, tipos, tam);


                do
                {
                    switch(menuModificarNotebook())
                    {
                    case 1:
                        listarMarcas(marcas, tam);
                        cargarDescripcionMarcas(marcas, tam, id, descMarca);
                        printf("Ingrese id de nueva marca: ");
                        scanf("%d", &vec[indice].idMarca);
                        //vec[indice].idMarca = marca;
                        printf("Se ha modificado la marca\n");
                        break;
                    case 2:
                        listarTipos(tipos, tam);
                        cargarDescripcionTipos(tipos, tam, id, descTipo);
                        printf("Ingrese id de nuevo tipo: ");
                        scanf("%d", &vec[indice].idTipo);
                        //vec[indice].idTipo = tipo;
                        printf("Se ha modificado el tipo\n");
                        break;
                    case 3:
                        salir = 's';
                        break;
                    }
                    system("pause");
                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int bajaNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec && tam > 0)
    {
        listarNotebooks(vec, tam, marcas, tamM, tipos, tamT);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una notebook con id %d\n", id);
            }
            else
            {
                mostrarNotebooks(vec[indice], marcas, tipos, tam);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con exito\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar notebook\n");
        }

        todoOk = 1;
    }
    return todoOk;
}
