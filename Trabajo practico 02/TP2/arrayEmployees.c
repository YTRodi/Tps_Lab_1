#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "ArrayEmployees.h"

int menuAbm()
{
    int option;
    system("cls");
    printf("---ABM EMPLEADOS---\n\n1 - ALTA\n2 - MODIFICAR\n3 - BAJA\n4 - INFORMAR\n5 - SALIR\n");
    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida",1,5,2);
    return option;
}


int initEmployees(sEmployee listEmployee[],int len)
{
    int retorno = -1;

    for(int i = 0;i<len;i++)
    {
        listEmployee[i].isEmpty = 1;
        retorno = 0;
    }

    return retorno;
}


int searchFree(sEmployee listEmployee[], int len)
{
    int indice = -1;
    for(int i=0;i<len;i++)
    {
        if(listEmployee[i].isEmpty==OCUPADO)//status not empty
        {
            indice = i;
            break;
            //SI ENCUENTRO LUGAR LIBRE ROMPO Y SALGO DEL BUCLE
        }
    }
    return indice;
}


void showOneEmployee(sEmployee listEmployee)
{
    printf("\n%2d %11s %11s %15.2f %8d\n",
           listEmployee.id,
           listEmployee.name,
           listEmployee.lastName,
           listEmployee.salary,
           listEmployee.sector);
}


int printEmployees(sEmployee listEmployee[],int len)
{
    int retorno = -1;

    //SI EL ESTADO ESTA VACIO LO MUESTRO
    //printf("id\tnombre\tapellido       salario($)   sector\n");
    for(int i=0;i<len;i++)
    {
        if(listEmployee[i].isEmpty==0)
        {
            showOneEmployee(listEmployee[i]);
            retorno = 0;
        }
    }
    printf("\n  ID      NOMBRE    APELLIDO      SALARIO($)   SECTOR\n\n");
    if(retorno==-1)
    {
        printf("\nNo hay empleados que mostrar.\n\n");
    }

    return retorno;
}


int addEmployee(sEmployee listEmployee[],int len, int id,char name[],char lastName[],float salary, int sector)
{
    int index;
    int retorno = -1;

    index = searchFree(listEmployee,len);

    if(index == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        listEmployee[index] = newEmp(id,name,lastName,salary,sector);
        printf("\n--Alta exitosa--\n\n");
        retorno = 0;
    }

    return retorno;
}


sEmployee newEmp(int id, char name[],char lastName[],float salary,int sector)
{
    sEmployee empConteiner;

    empConteiner.id = id;
    strcpy(empConteiner.name, name);
    strcpy(empConteiner.lastName, lastName);
    empConteiner.salary = salary;
    empConteiner.sector = sector;
    empConteiner.isEmpty = 0;

    return empConteiner;
}


int loadEmployee(sEmployee listEmployee[],int len,int lastId)
{
    int allOk = 100;
    char name[QTY_CARACTERES];
    char lastName[QTY_CARACTERES];
    float salary;
    int sector;

    system("cls");
    printf("\n---Alta empleado---\n\n");

    getString(name,"Entre <2 - 35 caract.>\nIngrese nombre: ","\nERROR, debe contener entre 2 y 35 caracteres",2,35,2);
    getString(lastName,"\nEntre <2 - 35 caract.>\nIngrese apellido: ","\nERROR, debe contener entre 2 y 35 caracteres",2,35,2);
    getFloat(&salary,"\nEntre <1.0 - 10000000.0 num float.>\nIngrese salario: ","\nERROR, debe ingresar un numero",1.0,10000000.0,2);
    getInt(&sector,"\nEntre <1 - 50>\nIngrese sector: ","\nERROR, debe ingresar un numero",1,50,2);

    allOk = addEmployee(listEmployee,len,lastId,name,lastName,salary,sector);

    return allOk;
}


int findEmployeeById(sEmployee listEmployee[],int len,int id)
{
    int index = -1;//SIGNIFICA QUE NO ESTA.
    for(int i=0;i<len;i++)
    {
        if(listEmployee[i].id == id && listEmployee[i].isEmpty == LIBRE)
        {
            index = i;
            //CUANDO ENCUENTRO EL ID, ROMPO PARA SALIR DEL FOR.
            break;
        }
    }
    return index;
}


int modifyEmployee(sEmployee listEmployee[],int len)
{
    int retorno = -1;
    int index;
    int id;

    system("cls");
    printf("\n---Modificar Empleado---\n\n");
    getInt(&id,"Ingrese ID a del empleado a modificar: ","ERROR, ingrese un ID valido.\n",1,10000,2);

    index = findEmployeeById(listEmployee,len,id);

    if(index == -1)
    {
        printf("\nNo existe empleado con ese ID\n\n");
    }
    else
    {
        retorno=0;
        //MUESTO EL EMPLEADO A MODIFICAR. MUY IMPORTANTE!!!!
        showOneEmployee(listEmployee[index]);
        printf("\n  ID      NOMBRE    APELLIDO      SALARIO($)   SECTOR\n\n");

        switch(menuModif())
        {
        case 1:
            getString(listEmployee[index].name,"\nEntre <2 - 35 caract.>\nIngrese nuevo nombre: ","\nERROR, debe contener entre 2 y 35 caracteres",2,35,2);
            break;
        case 2:
            getString(listEmployee[index].lastName,"\nEntre <2 - 35 caract.>\nIngrese nuevo apellido: ","\nERROR, debe contener entre 2 y 35 caracteres",2,35,2);
            break;
        case 3:
            getFloat(&listEmployee[index].salary,"\nEntre <1.0 - 10000000.0 num float.>\nIngrese nuevo salario: ","\nERROR, debe ingresar un numero",1.0,10000000.0,2);
            break;
        case 4:
            getInt(&listEmployee[index].sector,"\nEntre <1 - 50>\nIngrese nuevo sector: ","\nERROR, debe ingresar un numero",1,50,2);
            break;
        case 5:
            printf("\nSe ha cancelado la modificacion.\n\n");
            break;
        default:
            printf("\nOpcion invalida!\n\n");
        }

    }
    return retorno;
}


int menuModif()
{
    int option;
    printf("\n*Elija que desea modificar*\n");
    printf("1 - Modificar nombre\n2 - Modificar apellido\n3 - Modificar salario\n4 - Modificar sector\n5 - Salir\n");
    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida.",1,5,2);
    return option;
}


int removeEmployee(sEmployee listEmployee[],int len)
{
    int retorno = -1;
    int index;
    int id;
    char confirma;

    system("cls");
    printf("\n---Baja Empleado---\n\n");

    printEmployees(listEmployee,len);

    getInt(&id,"Ingrese ID:","ERROR, ingrese un ID valido.\n",0,10000,2);

    index = findEmployeeById(listEmployee,len,id);

    if(index == -1)
    {
        printf("\nNo existe empleado con ese ID.\n\n");
    }
    else
    {
        //MUESTRO EL EMPLEADO A DAR DE BAJA!
        showOneEmployee(listEmployee[index]);
        printf("\n  ID      NOMBRE    APELLIDO      SALARIO($)   SECTOR\n\n");

        //getChar(&confirma,"\nConfirma baja? <s/n>: ","Error. ingrese <s/n> :",0,125,2);
        printf("\nConfirma baja? <s/n>: ");
        fflush(stdin);
        confirma = getch();

        if(confirma == 's')
        {
            listEmployee[index].isEmpty = OCUPADO;
            retorno = 0;
            printf("\n\n-Baja exitosa-\n\n");
        }
        else if(confirma == 'n')
        {
            printf("\nSe ha cancelado la operacion.\n\n");
        }
        else
        {
            printf("\nIngrese opcion valida.\n\n");
        }
    }
    return retorno;
}


int menuReports()
{
    int option;

    system("cls");
    printf("\n---Informes---\n\n");
    printf("1 - Listar empleados ordenados alfabeticamente por apellido y sector\n");
    printf("2 - Estadisticas sobre salarios\n");
    printf("3 - Mostrar lista de empleados\n");
    printf("4 - Salir\n");
    getInt(&option,"\nIngrese opcion: ","\nError. opcion no valida\n\n",1,4,2);

    return option;
}


int sortEmployees(sEmployee listEmployee[],int len, int order)
{
    int retorno = -1;

    sEmployee employeeAux;

    //ORDENARLO ALFABETICAMENTE POR APELLIDO Y SECTOR

    switch(order)
    {
        case 1:
            /*ASCENDENTE*/
            for(int i=0;i<len;i++)
            {
                for(int j=i+1;j<len;j++)
                {
                    if(listEmployee[i].sector > listEmployee[j].sector ||
                        listEmployee[i].sector == listEmployee[j].sector ||
                        listEmployee[i].lastName > listEmployee[j].lastName)
                    {
                        /*SWAP!!*/
                        employeeAux = listEmployee[i];
                        listEmployee[i] = listEmployee[j];
                        listEmployee[j] = employeeAux;
                        retorno = 0;
                    }
                }
            }
            break;

        case 2:
            /*DESCENDENTE*/
            for(int i = 0; i<len; i++)
            {
                for(int j = i+1; j<len; j++)
                {
                    if(listEmployee[i].sector < listEmployee[j].sector)
                    {
                        employeeAux = listEmployee[i];
                        listEmployee[i] = listEmployee[j];
                        listEmployee[j] = employeeAux;
                        retorno= 0;
                    }
                    else if(listEmployee[i].sector == listEmployee[j].sector)
                    {
                        if(strcmp(listEmployee[i].lastName,listEmployee[j].lastName))
                        {
                            employeeAux = listEmployee[i];
                            listEmployee[i] = listEmployee[j];
                            listEmployee[j] = employeeAux;
                            retorno= 0;
                        }
                    }
                }
            }
            break;
    }
    return retorno;
}


void printSalaryInformation(sEmployee listEmployee[],int len)
{
    int cont = 0;
    float accumulator = 0;
    float average = 0;
    int i;//VAR CONTROL
    int contHighAverage = 0;

    for(i=0;i<len;i++)
    {
        if(listEmployee[i].isEmpty==LIBRE)
        {
            cont++;
            accumulator = accumulator + listEmployee[i].salary;
        }
    }

    average = (float) accumulator/cont;

    for(i = 0; i<len; i++)
    {
        if(listEmployee[i].isEmpty == LIBRE && listEmployee[i].salary > average)
        {
            contHighAverage++;
        }
    }

    printf("\nTotal de empleados: %d\n\nSalario total de empleados: $%.2f\n\nPromedio de los salarios: $%.2f\n\nEmpleados que superan el salario promedio: %d\n\n",
           cont,
           accumulator,
           average,
           contHighAverage);

}


int hardCodearEmployeesConId(sEmployee listEmployee[],int len, int lastId)
{
    //14 + 6 = 20
    char name[] [QTY_CARACTERES] ={"Yago","Camila","Facundo","Joaquin","Humberto","Norma","Mario","David","Lucia","Hugo","Daniel","Alba","Adrian","Martin","Sara","Carla","Claudia","Valeria","Paula","Sofia"};

    char lastName[] [QTY_CARACTERES] = {"Rodi","Roy","Toro","Vasquez","Gomez","Perez","Pereyta","Torres","Medina","Acosta","Sanchez","Fernandez","Rodriguez","Molina","Cabrera","Diaz","Perez","Dominguez","Luna","Godoy"};

    float salary[] = {150000,140000,6000,5000,45000,75000,13000,41000,29000,36000,12000,4500,1000,7500,9500,46000,120000,100000,45500,4000};

    int sector[] = {2,1,48,35,28,50,41,42,34,20,14,16,44,36,48,31,5,11,22,29};


    for(int i=0; i<20 ;i++)
    {
        listEmployee[i].id = lastId;
        strcpy(listEmployee[i].name,name[i]);
        strcpy(listEmployee[i].lastName,lastName[i]);
        listEmployee[i].salary = salary[i];
        listEmployee[i].sector = sector[i];
        listEmployee[i].isEmpty = LIBRE;//CUANDO ESTE LIBRE VA A MOSTRAR LOS EMPLEADOS HARDCODEADOS.

        lastId ++;
    }
    return lastId;

}
