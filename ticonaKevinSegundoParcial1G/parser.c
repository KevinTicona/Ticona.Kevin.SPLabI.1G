#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "paisesAfectados.h"

int parser_FromText(FILE* pFile, LinkedList* this)
{
    int amountOfDataRead;
    char id[2000];
    char nombre[2000];
    char recuperados[2000];
    char infectados[2000];
    char muertos[20000];

    if (pFile != NULL && this == NULL  )
    {
        return -1;
    }

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,recuperados,infectados,muertos);

    do
    {
        amountOfDataRead = fscanf(
                               pFile,
                               "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                               id,
                               nombre,
                               recuperados,
                               infectados,
                               muertos
                           );

        if (amountOfDataRead == 5)
        {
            ePais* newPais = pais_newParams(id,nombre,recuperados,infectados,muertos);

            if (newPais != NULL)
            {
                ll_add(this, newPais);
            }
        }
        else
        {
            printf("\nHubo un problema al leer los datos de una linea del archivo. La misma sera ignorada\n");
        }

    }
    while (!feof(pFile));

    return 0;
}



