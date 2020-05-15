#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Direecion de la ubicacion del archivo.
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se cargo correctamente - [-1] Si hubo un error.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char buffer[4][30];
    int cant = 0;//cantidad de variables que nos pudo retornar.
    Employee* auxEmple;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(cant < 4)
        {
            break;
        }
        else
        {
            /***
            buffer[0] es el id;
            buffer[1] es el nombre;
            buffer[2] son las horas trabajadas;
            buffer[3] es el sueldo;
            ***/
            auxEmple = employee_newParametros((buffer[0]),buffer[1],(buffer[2]),(buffer[3]));//parseamos.

            if(auxEmple!=NULL)
            {
                ll_add(pArrayListEmployee,auxEmple);//agrego un puntero al final del linkedlist.
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param pFile FILE* Direecion de la ubicacion del archivo.
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se cargo correctamente - [-1] Si hubo un error.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmple = NULL;
    int cant = 0;

    while(!feof(pFile))
    {
        auxEmple = employee_new();

        if(auxEmple==NULL)
        {
            break;
        }

        cant = fread(auxEmple,sizeof(Employee),1,pFile);

        employee_setId(auxEmple,auxEmple->id);

        if(cant<1)//significa que estaria todo mal
        {
            break;
        }
        else
        {
            ll_add(pArrayListEmployee,auxEmple);
            retorno = 0;
        }

    }

    return retorno;
}
