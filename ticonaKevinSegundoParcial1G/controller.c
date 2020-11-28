#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"
#include "menu.h"
#include "paisesAfectados.h"


int controller_loadFromText(LinkedList* pLinkedListPaises, char* nombreDelArchivo)
{
    int status = -1;
    char path[100];

    printf("\nIngrese el nombre del archivo a leer: ");
    fflush(stdin);
    gets(path);

    FILE *pFile = fopen(path, "r");

    if (pFile == NULL)
    {
        printf("\nEl archivo en la ruta %s no existe.\n", path);
        return status;
    }

    strcpy(nombreDelArchivo,path);
    status = parser_FromText(pFile,pLinkedListPaises);
    printf("\nLei el archivo\n");
    fclose(pFile);

    return status;
}

int controller_listarPaises(LinkedList* pLinkedListPaises)
{
    if (ll_isEmpty(pLinkedListPaises) == 1)
    {
        printf("\nNo existen el archivo pandemia en el sistema. Intente cargarlas desde el menu para poder mapearlas.\n");
        return -1;
    }

    system("cls");
    menu_printPaises(pLinkedListPaises);

    return 0;
}

int controller_mapInfectados(LinkedList* pLinkedListPaises)
{
    int error = -1;
    if (ll_isEmpty(pLinkedListPaises) == 1)
    {
        printf("\nNo existen el archivo pandemia en el sistema. Intente cargarlas desde el menu para poder mapearlas.\n");
        return -1;
    }

    LinkedList* paisConInfectados = ll_map(pLinkedListPaises,pais_MapInfectados);

    if(paisConInfectados != NULL)
    {
        system("cls");
        pLinkedListPaises = paisConInfectados;
        menu_printPaises(pLinkedListPaises);
        error = 0;
    }

    return error;
}

int controller_mapRecuperados(LinkedList* pLinkedListPaises)
{
    int error = -1;
    if (ll_isEmpty(pLinkedListPaises) == 1)
    {
        printf("\nNo existen el archivo pandemia en el sistema. Intente cargarlas desde el menu para poder mapearlas.\n");
        return -1;
    }

    LinkedList* paisConRecuperados = ll_map(pLinkedListPaises,pais_MapRecuperados);

    if(paisConRecuperados != NULL)
    {
        system("cls");
        pLinkedListPaises = paisConRecuperados;
        //menu_printPaises(pLinkedListPaises);
        error = 0;
    }

    return error;
}
int controller_mapMuertos(LinkedList* pLinkedListPaises)
{
    int error = -1;
    if (ll_isEmpty(pLinkedListPaises) == 1)
    {
        printf("\nNo existen el archivo pandemia en el sistema. Intente cargarlas desde el menu para poder mapearlas.\n");
        return -1;
    }

    LinkedList* paisConMuertos = ll_map(pLinkedListPaises,pais_MapMuertos);

    if(paisConMuertos != NULL)
    {
        system("cls");
        pLinkedListPaises = paisConMuertos;
        //menu_printPaises(pLinkedListPaises);
        error = 0;
    }

    return error;
}

int controller_saveAsText(char* path, LinkedList* pLinkedListPaises)
{
    if (ll_isEmpty(pLinkedListPaises) == 1)
    {
        printf("\nPrimero deben haber Paises cargadas.\n");
        return -1;
    }

    FILE *pFile;

    pFile = fopen(path, "w");

    if (pFile == NULL || pLinkedListPaises == NULL)
    {
        return -1;
    }

    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLinkedListPaises);
    int idActual;
    char nombreActual[100];
    int recuperadosActual;
    int infectadosActual;
    int muertosActual;

    ePais* actualPais;
    Node* currentNode = pLinkedListPaises->pFirstNode;

    fprintf(pFile, "id, nombre, recuperados, infectados, muertos\n");

    while (currentNodeIndex < linkedListSize)
    {
        actualPais = (ePais*)ll_get(pLinkedListPaises, currentNodeIndex);

        pais_getId(actualPais, &idActual);
        pais_getNombre(actualPais, nombreActual);
        pais_getRecuperados(actualPais, &recuperadosActual);
        pais_getInfectados(actualPais, &infectadosActual);
        pais_getMuertos(actualPais, &muertosActual);

        fprintf(pFile, "%d,%s,%d,%d,%d\n",
                idActual,
                nombreActual,
                recuperadosActual,
                infectadosActual,
                muertosActual);

        currentNode = currentNode->pNextNode;
        currentNodeIndex++;
    }

    fclose(pFile);

    printf("\nLos cambios para la lista de Pandemia, han sido guardados correctamente.\n");

    return 0;
}
