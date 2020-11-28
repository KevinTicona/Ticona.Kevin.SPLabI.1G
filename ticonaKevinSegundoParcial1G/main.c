#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "controller.h"
#include "paisesAfectados.h"
#include "menu.h"
#include "validaciones.h"

int main()
{
    srand (time(NULL));
    LinkedList* newPais = ll_newLinkedList();

    char pathPrincipal[100];
    int opcion, seleccion;
    int flagMap = 0;

    if(newPais == NULL)
    {
        printf("\nNo se consiguio espacio en memoria para la lista.\n");
        return -1;
    }

    do
    {
        menu_main();
        seleccion = validations_getOption(
                        &opcion,
                        "\nOpcion invalida, vuelva a intentar\n",
                        1,
                        7
                    );

        if(!seleccion)
        {
            switch(opcion)
            {
            case 1:
                if(!controller_loadFromText(newPais,pathPrincipal))
                {
                    printf("\nSe han cargado %d newPais desde el archivo %s\n", ll_len(newPais), pathPrincipal);
                }
                else
                {
                    printf("\nNo se ha podido cargar el archivo.\n");
                }
                break;
            case 2:
                if(!controller_listarPaises(newPais))
                {
                    printf("\nOperacion exitosa\n");
                }
                else
                {
                    printf("\nNo se ha podido cargar el archivo.\n");
                }
                break;
            case 3:
                if(!controller_mapRecuperados(newPais) && (!controller_mapInfectados(newPais)) && (!controller_mapMuertos(newPais)))
                {
                    flagMap = 1;
                    printf("\nOperacion exitosa\n");
                }
                else
                {
                    printf("\nNo se ha podido cargar el archivo.\n");
                }
                break;
            case 4:
                if(!flagMap)
                {
                    printf("\nPrimero deben mapearse los posteos.\n");
                    break;
                }
                LinkedList* pExitoso = ll_filter(newPais, pais_paisesExitosos);
                if( pExitoso != NULL)
                {
                                        system("cls");
                    printf("---------------------------------------------------\n");
                    printf("                    Paises en el Horno \n");
                    menu_printPaises(pExitoso);
                    controller_saveAsText("pExitoso.csv",pExitoso);
                    ll_deleteLinkedList(pExitoso);
                }
                else
                {
                    ll_deleteLinkedList(pExitoso);
                }
                break;
            case 5:
                if(!flagMap)
                {
                    printf("\nPrimero deben mapearse los posteos.\n");
                    break;
                }
                LinkedList* pHorno = ll_filter(newPais, pais_paisesEnElHorno);
                if( pHorno != NULL)
                {
                                        system("cls");
                    printf("---------------------------------------------------\n");
                    printf("                    Paises en el Horno \n");
                    menu_printPaises(pHorno);
                    controller_saveAsText("pHorno.csv",pHorno);
                    ll_deleteLinkedList(pHorno);
                }
                else
                {
                    ll_deleteLinkedList(pHorno);
                }
                break;
            case 6:
                if(!flagMap)
                {
                    printf("\nPrimero deben mapearse los posteos.\n");
                    break;
                }

                ll_sort(newPais,pais_sortByInfectados,1);
                controller_listarPaises(newPais);
                break;
            case 7:
                ll_deleteLinkedList(newPais);
                printf("\nSaliendo...\n");
                break;
            }
            system("pause");
        }

    }
    while (opcion != 7);

    return 0;
}
