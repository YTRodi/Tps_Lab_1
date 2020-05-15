#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"

#define ELEMENTS 1000

int main()
{
    sEmployee arrayEmployee[ELEMENTS];

    int lastId = 1000;
    char exit = 'n';
    char exitSort = 'n';
    int ordenar;
    int superFlag = 0;

    initEmployees(arrayEmployee,ELEMENTS);

    /*
    DESTILDAR PARA HARDCODEAR!!
    */

    //lastId = hardCodearEmployeesConId(arrayEmployee,ELEMENTS,lastId);

    do
    {
        switch(menuAbm())
        {
            case 1:
                if(loadEmployee(arrayEmployee,ELEMENTS,lastId) == LIBRE)
                {
                    lastId++;
                    superFlag = 1;
                }
                break;

            case 2:
                if(superFlag == 1)
                {
                    modifyEmployee(arrayEmployee,ELEMENTS);
                }
                else
                {
                    printf("\nDebe cargar empleados antes.\n\n");
                }
                break;

            case 3:
                if(superFlag == 1)
                {
                    removeEmployee(arrayEmployee,ELEMENTS);
                }
                else
                {
                    printf("\nDebe cargar empleados antes.\n\n");
                }
                break;

            case 4:
                if(superFlag == 1)
                {
                    do
                    {
                        switch(menuReports())
                        {
                        case 1:
                            getInt(&ordenar,"\n--Ordenar listado--\n\nDe forma ascendente <1>\nDe forma descendente <2>\n\nIngrese opcion: ", "ERROR. ingrese numero valido\n",1,2,3);
                            sortEmployees(arrayEmployee,ELEMENTS,ordenar);
                            break;
                        case 2:
                            printSalaryInformation(arrayEmployee,ELEMENTS);
                            break;
                        case 3:
                            printEmployees(arrayEmployee,ELEMENTS);
                            break;
                        case 4:
                            printf("Confirma salir? <s/n>: ");
                            fflush(stdin);
                            exitSort = getch();
                            break;
                        default:
                            printf("...Redireccionando al menu...\n\n");
                        }
                        system("pause");
                    }while(exitSort == 'n');
                }
                else
                {
                    printf("\nDebe cargar empleados antes.\n\n");
                }
                break;

            case 5:
                printf("Confirma salir? <s/n>: ");
                fflush(stdin);
                exit = getche();
                break;

            default:
                printf("\n\n...Redireccionando al menu...\n\n");
        }
        system("pause");
    }while(exit=='n');
    return 0;
}


