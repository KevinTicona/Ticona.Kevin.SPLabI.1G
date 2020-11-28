#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(LinkedList* pLinkedListPaises, char* nombreDelArchivo);
int controller_listarPaises(LinkedList* pLinkedListPaises);
int controller_mapRecuperados(LinkedList* pLinkedListPaises);
int controller_mapInfectados(LinkedList* pLinkedListPaises);
int controller_mapMuertos(LinkedList* pLinkedListPaises);
int controller_saveAsText(char* path, LinkedList* pLinkedListPaises);
#endif // CONTROLLER_H_INCLUDED
