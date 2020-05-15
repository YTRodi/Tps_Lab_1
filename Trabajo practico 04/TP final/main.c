#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char exit;
    int loadedData = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menuGeneral())
        {
            case 1:
                if(loadedData == 0)
                {
                    if(controller_loadFromText("data.csv",listaEmpleados)==0)
                    {
                        printf("\nArchivo de TEXTO cargado correctamente.\n\n");
                        loadedData = 1;
                    }
                    else
                    {
                        printf("\nNombre del archivo inexistente.\n\n");
                    }
                }
                else
                {
                    printf("\nLos datos ya estan cargados.\n\n");
                }

                break;

            case 2:
                if(loadedData == 0)
                {
                    if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
                    {
                        printf("\nArchivo BINARIO cargado correctamente.\n\n");
                        loadedData = 1;
                    }
                    else
                    {
                        printf("\nNombre del archivo inexistente.\n\n");
                    }
                }
                else
                {
                    printf("\nLos datos ya estan cargados.\n\n");
                }

                break;

            case 3:
                if(loadedData==1)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 4:
                if(loadedData==1)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 5:
                if(loadedData==1)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 6:
                if(loadedData==1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 7:
                if(loadedData==1)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    errorUploadFileBefore();
                }

                break;

            case 8:
                if(loadedData==1)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                    printf("  ===================================================\n");
                    printf("||  Datos guardados con exito en el archivo de     ||\n");
                    printf("||        TEXTO.                                   ||\n");
                    printf("  ===================================================\n");
                }
                else
                {
                    errorUploadFileBefore();
                }
                break;

            case 9:
                if(loadedData==1)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);

                    printf("  ===================================================\n");
                    printf("||  Datos guardados con exito en el archivo        ||\n");
                    printf("||        BINARIO.                                 ||\n");
                    printf("  ===================================================\n");
                }
                else
                {
                    errorUploadFileBefore();
                }
                break;

            case 10:
                printf("\nConfirma salir? <s/n>: ");
                fflush(stdin);
                scanf("%c",&exit);
                exit = tolower(exit);
                printf("\n\n");
                break;

            default:
                errorOptionInvalid();

        }
        system("pause");
    }
    while(exit != 's');
    return 0;
}

