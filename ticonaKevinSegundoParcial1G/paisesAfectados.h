#ifndef PAISESAFECTADOS_H_INCLUDED
#define PAISESAFECTADOS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[100];
    int recuperados;
    int infectados;
    int muertos;
}ePais;

ePais* pais_new();
ePais* pais_newParams(char* idStr, char* nombre, char* recuperadosStr, char* infectadosStr, char* muertosStr);
int pais_setId(ePais* this,int id);
int pais_getId(ePais* this,int* id);
int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);
int pais_setRecuperados(ePais* this,int recuperados);
int pais_getRecuperados(ePais* this,int* recuperados);
int pais_setInfectados(ePais* this,int infectados);
int pais_getInfectados(ePais* this,int* infectados);
int pais_setMuertos(ePais* this,int muertos);
int pais_getMuertos(ePais* this,int* muertos);

int pais_MapRecuperados(void* recuperados);
int pais_MapInfectados(void* infectados);
int pais_MapMuertos(void* muertos);
int pais_paisesExitosos(void* pExitosos);
int pais_paisesEnElHorno(void* pHorno);
int pais_sortByInfectados(void* paisA, void* paisB);
#endif // PAISESAFECTADOS_H_INCLUDED
