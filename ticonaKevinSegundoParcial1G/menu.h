#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "paisesAfectados.h"
#include "LinkedList.h"

void menu_main();
void menu_printPais(ePais* actualPais);
int menu_printPaises(LinkedList* pLinkedListPaises);

#endif // MENU_H_INCLUDED
