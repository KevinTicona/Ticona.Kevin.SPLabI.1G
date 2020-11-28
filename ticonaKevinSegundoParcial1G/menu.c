#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "paisesAfectados.h"
#include "LinkedList.h"

void menu_main()
{
    system("cls");
    printf("                  Paises Afectados por el virus Covid-19                   \n");
    printf("--------------------------------------------------------------------------\n");
    printf("1. Cargar archivo.\n");
    printf("2. Imprimir lista.\n");
    printf("3. Asignar estadisticas.\n");
    printf("4. Filtrar por paises exitosos.\n");
    printf("5. Filtrar por paises en el horno.\n");
    printf("6. Ordenar por nivel de infeccion.\n");
    printf("7. Mostrar mas castigado.\n");
    printf("8. Salir.\n");
    printf("\n\n");
}


void menu_printPais(ePais* actualPais)
{
    int idActual;
    int recuperadosActual;
    int infectadosActual;
    int muertosActual;
    char nombre[100];

    pais_getId(actualPais,&idActual);
    pais_getNombre(actualPais,nombre);
    pais_getRecuperados(actualPais,&recuperadosActual);
    pais_getInfectados(actualPais,&infectadosActual);
    pais_getMuertos(actualPais,&muertosActual);

    printf("\n%4d     %20s             %8d           %8d         %8d     \n",
           idActual,
           nombre,
           recuperadosActual,
           infectadosActual,
           muertosActual);
}

int menu_printPaises(LinkedList* pLinkedListPaises)
{
    int currentNodeIndex = 0;
    int linkedListSize = ll_len(pLinkedListPaises);

    ePais* actualPais;
    Node* actualNode = pLinkedListPaises->pFirstNode;

    printf("                       Listado de Paises                                  \n");
    printf("ID             Nombre                    Recuperados          Infectados          Muertos \n");
    printf("-------------------------------------------------------------------------------------------\n");

    while (currentNodeIndex < linkedListSize)
    {
        actualPais = (ePais*)ll_get(pLinkedListPaises, currentNodeIndex);

        menu_printPais(actualPais);

        actualNode = actualNode->pNextNode;
        currentNodeIndex++;
    }

    return 0;
}

