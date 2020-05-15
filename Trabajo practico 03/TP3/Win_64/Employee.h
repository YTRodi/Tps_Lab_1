#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

int menuGeneral();
Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


//Listar
int employee_ShowOneEmployee(Employee* this);
int employee_ListEmployees(LinkedList* pArrayListEmployee);

//Menu
int menuModificacion();
int menuOrder();
int menuHowDoYouWantToOrder();

//Comparison
int employee_compareById(void* employee1,void* employee2);
int employee_compareByName(void* employee1,void* employee2);
int employee_compareByHT(void* employee1,void* employee2);
int employee_compareBySalary(void* employee1,void* employee2);

//Delete linkedList
//int employee_deleteLinkedList(LinkedList* this);

//MESSAGES
void errorPosterFile();
void errorPosterId();
void warningPosterFile();
void errorUploadFileBefore();
void errorOptionInvalid();
void operationCancelled();


#endif // employee_H_INCLUDED
