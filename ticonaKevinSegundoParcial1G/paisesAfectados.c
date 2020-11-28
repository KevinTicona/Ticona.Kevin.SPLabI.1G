#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "paisesAfectados.h"
#include "validaciones.h"

ePais* pais_new()
{
    ePais* nuevo = (ePais*) malloc(sizeof(ePais));

    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, "");
        nuevo->recuperados = 0;
        nuevo->infectados = 0;
        nuevo->muertos = 0;
    }

    return nuevo;
}

ePais* pais_newParams(char* idStr, char* nombre, char* recuperadosStr, char* infectadosStr, char* muertosStr)
{
    int id;
    int recuperados;
    int infectados;
    int muertos;

    int validId;
    int validRecuperados;
    int validInfectados;
    int validMuertos;

    validId = validations_isValidNumber(idStr);
    validRecuperados = validations_isValidNumber(recuperadosStr);
    validInfectados = validations_isValidNumber(infectadosStr);
    validMuertos = validations_isValidNumber(muertosStr);

    if(!validId || !validRecuperados || !validInfectados || !validMuertos)
    {
        if(!validId)
        {
            printf("\nEl Id del post es invalido. Valor recibido: %s\n", idStr);
        }
        else if (!validRecuperados)
        {
            printf("\nEl valor de Recuperados es invalido. Valor recibido: %s\n", recuperadosStr);
        }
        else if(!validInfectados)
        {
            printf("\nEl valor de Infectados es invalido. Valor recibido: %s\n", infectadosStr);
        }
        else if(!validMuertos)
        {
            printf("\nEl valor de Muertos es invalido. Valor recibido: %s\n", muertosStr);
        }

        return NULL;
    }

    id = atoi(idStr);
    recuperados = atoi(recuperadosStr);
    infectados = atoi(infectadosStr);
    muertos = atoi(muertosStr);

    ePais* newPais = pais_new();

    if(newPais != NULL)
    {
        if(
            !(!pais_setId(newPais,id) &&
              !pais_setNombre(newPais,nombre) &&
              !pais_setRecuperados(newPais,recuperados) &&
              !pais_setInfectados(newPais,infectados)&&
              !pais_setMuertos(newPais,muertos)
             ))
        {
            printf("\nOcurrio un problema al inicializar las propiedades de la lista Pandemia.\n");
            newPais = NULL;
            free(newPais);
        }
    }
    return newPais;
}

int pais_setId(ePais* this,int id)
{
    int error = -1;

    if(this != NULL && id > 0)
    {
        this->id = id;
        error = 0;
    }
    return error;
}

int pais_getId(ePais* this,int* id)
{
    int error = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL && validations_isValidName(nombre))
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }
    return error;
}

int pais_getNombre(ePais* this,char* nombre)
{
    int error = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        error = 0;
    }
    return error;
}


int pais_setRecuperados(ePais* this,int recuperados)
{
    int error = -1;

    if(this != NULL && (recuperados >= 50 || recuperados <= 1000))
    {
        this->recuperados = recuperados;
        error = 0;
    }
    return error;
}

int pais_getRecuperados(ePais* this,int* recuperados)
{
    int error = -1;

    if(this != NULL && recuperados != NULL)
    {
        *recuperados = this->recuperados;
        error = 0;
    }
    return error;
}

int pais_setInfectados(ePais* this,int infectados)
{
    int error = -1;

    if(this != NULL && (infectados >= 400 || infectados <= 2000))
    {
        this->infectados = infectados;
        error = 0;
    }
    return error;
}

int pais_getInfectados(ePais* this,int* infectados)
{
    int error = -1;

    if(this != NULL && infectados != NULL)
    {
        *infectados = this->infectados;
        error = 0;
    }
    return error;
}
int pais_setMuertos(ePais* this,int muertos){
        int error = -1;

    if(this != NULL && (muertos >= 1 || muertos <= 50))
    {
        this->muertos = muertos;
        error = 0;
    }
    return error;
}
int pais_getMuertos(ePais* this,int* muertos){
        int error = -1;

    if(this != NULL && muertos != NULL)
    {
        *muertos = this->muertos;
        error = 0;
    }
    return error;
}

int pais_MapRecuperados(void* recuperados)
{
    int retorno = -1;
    ePais* recuperadosActual = NULL;
    int aleatorio;

    if(recuperados != NULL)
    {
        recuperadosActual = (ePais*) recuperados;

        if(recuperadosActual != NULL)
        {
            //Calcular
            aleatorio = rand()%(1000)+50; // esta linea va en la funcion que
                                          //asigna el tiempo donde a es el maximo y b el minimo
            //Setear
            pais_setRecuperados(recuperadosActual,aleatorio);
            retorno = 0;
        }
    }

    return retorno;
}

int pais_MapInfectados(void* infectados)
{
    int retorno = -1;
    ePais* infectadosActual = NULL;
    int aleatorio;

    if(infectados != NULL)
    {
        infectadosActual = (ePais*) infectados;

        if(infectadosActual != NULL)
        {
            //Calcular
            aleatorio = rand()%(2000)+400; // esta linea va en la funcion que
                                          //asigna el tiempo donde a es el maximo y b el minimo
            //Setear
            pais_setInfectados(infectadosActual,aleatorio);
            retorno = 0;
        }
    }

    return retorno;
}

int pais_MapMuertos(void* muertos)
{
    int retorno = -1;
    ePais* muertosActual = NULL;
    int aleatorio;

    if(muertos != NULL)
    {
        muertosActual = (ePais*) muertos;

        if(muertosActual != NULL)
        {
            //Calcular
            aleatorio = rand()%(50)+1; // esta linea va en la funcion que
                                          //asigna el tiempo donde a es el maximo y b el minimo
            //Setear
            pais_setMuertos(muertosActual,aleatorio);
            retorno = 0;
        }
    }

    return retorno;
}

int pais_paisesExitosos(void* pExitosos)
{
    int retorno = 0;
    ePais* auxPais = NULL;

    if(pExitosos != NULL)
    {
        auxPais = (ePais*) pExitosos;

        if(auxPais->muertos < 5000)
        {
            retorno = 1;
        }
    }
    return retorno;
}


int pais_paisesEnElHorno(void* pHorno)
{
    int retorno = 0;
    ePais* auxPais = NULL;

    if(pHorno != NULL)
    {
        auxPais = (ePais*) pHorno;

        if(auxPais->infectados > (auxPais->recuperados*3))
        {
            retorno = 1;
        }
    }
    return retorno;
}


int pais_sortByInfectados(void* paisA, void* paisB)
{
    int retorno = 0;
    int auxPaisA;
    int auxPaisB;

    if(paisA != NULL && paisB != NULL)
    {
        if(
            !pais_getInfectados((ePais*)paisA, &auxPaisA) &&
            !pais_getInfectados((ePais*)paisB, &auxPaisB)
        )
        {
            if(auxPaisA > auxPaisB)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }

    }

    return retorno;
}
