
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se cargo correctamente - [-1] Si hubo un error.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f = NULL;
    int retorno = -1;
    int controlCarga;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        f = fopen(path,"r");//abro

        if(f!=NULL)
        {
            //parseo
            controlCarga = parser_EmployeeFromText(f,pArrayListEmployee);
            {
                if(controlCarga != -1)
                {
                    retorno = 0;
                    fclose(f);//cierro
                }
            }
        }
        else
        {
            errorPosterFile();
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se cargo correctamente - [-1] Si hubo un error.
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int retorno = -1;
    int controlCarga;
    f = fopen(path,"rb");//abro

    if(f!=NULL && pArrayListEmployee!=NULL)
    {
        //parseo
        controlCarga = parser_EmployeeFromBinary(f,pArrayListEmployee);
        if(controlCarga != -1)
            retorno = 0;
    }
    else
    {
        errorPosterFile();
    }

    fclose(f);//cierro

    return retorno;
}

/** \brief Alta de empleados.
 *
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se dio de alta correctamente - [-1] Si hubo un error.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    //int auxId = 0;
    char auxNombre[40];
    int auxHorasTrabajadas = 0;
    int auxSueldo = 0;
    Employee* auxEmple = employee_new();

    system("cls");
    printf("  ===================================================\n");
    printf("||                  ALTA EMPLEADO                    ||\n");
    printf("  ===================================================\n");

    if(auxEmple!=NULL)
    {
        if(getNombreOApellido(auxNombre,"\n<2-40 caract>\nIngrese nombre:","Error.Reingrese\n",2,40,2)!=-1)
        {
            if(getInt(&auxHorasTrabajadas,"\n<1-1000>\nIngrese horas trabajadas por mes:","Error.Reingrese\n",1,1000,2)!=-1)
            {
                if(getInt(&auxSueldo,"\n<500-200000>\nIngrese sueldo:","Error.Reingrese\n",500,200000,2)!=-1)
                {
                    employee_setId(auxEmple,-1);
                    employee_setNombre(auxEmple,auxNombre);
                    employee_setHorasTrabajadas(auxEmple,auxHorasTrabajadas);
                    employee_setSueldo(auxEmple,auxSueldo);

                    if(!ll_add(pArrayListEmployee,auxEmple))//los agrego al final del linkedlist.
                    {
                        printf("  ===================================================\n");
                        printf("||                -- Alta exitosa --                 ||\n");
                        printf("  ===================================================\n");
                        retorno = 0;
                    }
                }
            }
        }

    }
    if(retorno == -1)
    {
        errorOptionInvalid();
    }
    return retorno;
}

/** \brief Modificar datos de empleado.
 *
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se modifico correctamente - [-1] Si hubo un error.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int idAMod;
    Employee* this;
    int len = ll_len(pArrayListEmployee);

    system("cls");
    printf("  ===================================================\n");
    printf("||                MODIFICAR EMPLEADO                 ||\n");
    printf("  ===================================================\n");


    if(pArrayListEmployee!=NULL)
    {
        //employee_ListEmployees(pArrayListEmployee);

        getInt(&idAMod,"\nIngrese ID a modificar: ","Error.Reingrese\n",1,1500,2);

        for(int i=0; i<len; i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee,i); //como consigo el elemento, lo casteo a Employee.

            if(this->id == idAMod)
            {
                printf("  ===================================================\n");
                printf("||   ID  |     NOMBRE      |   HORAS T. |   SUELDO   ||\n");
                printf("  ===================================================\n");

                employee_ShowOneEmployee(this);

                printf("  ===================================================\n");

                switch(menuModificacion())
                {
                case 1:
                    if(getNombreOApellido(this->nombre,"<2-40 caract>\nIngrese nuevo nombre:","Error.Reingrese\n",2,40,2)!=-1)
                    {
                        retorno = 0;
                        printf("  ===================================================\n");
                        printf("||            -- Modificacion exitosa --             ||\n");
                        printf("  ===================================================\n");
                    }
                    break;

                case 2:
                    if(getInt(&this->horasTrabajadas,"\n<1-1000>\nIngrese nuevas horas trabajadas:","Error.Reingrese\n",1,1000,2)!=-1)
                    {
                        retorno = 0;
                        printf("  ===================================================\n");
                        printf("||            -- Modificacion exitosa --             ||\n");
                        printf("  ===================================================\n");
                    }
                    break;

                case 3:
                    if(getInt(&this->sueldo,"\n<500-200000>\nIngrese nuevo sueldo:","Error.Reingrese\n",500,200000,2)!=-1)
                    {
                        retorno = 0;
                        printf("  ===================================================\n");
                        printf("||            -- Modificacion exitosa --             ||\n");
                        printf("  ===================================================\n");
                    }
                    break;

                case 4:
                    operationCancelled();
                    retorno = 0;
                    break;

                default:
                    errorOptionInvalid();
                }
            }
        }
    }
    if(retorno == -1)
    {
        errorPosterId();
    }

    return retorno;
}

/** \brief Baja de empleado.
 *
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se dio de baja correctamente - [-1] Si hubo un error.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int idABajar;
    Employee* this;
    int len = ll_len(pArrayListEmployee);
    char confirma;

    system("cls");
    printf("  ===================================================\n");
    printf("||                  BAJA EMPLEADO                    ||\n");
    printf("  ===================================================\n");


    if(pArrayListEmployee!=NULL)
    {
        //employee_ListEmployees(pArrayListEmployee);

        getInt(&idABajar,"\nIngrese ID a dar de baja: ","Error.Reingrese\n",1,1500,2);

        for(int i=0; i<len; i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee,i); //como consigo el elemento, lo casteo a Employee.

            if(this->id == idABajar)
            {
                printf("  ===================================================\n");
                printf("||   ID  |     NOMBRE      |   HORAS T. |   SUELDO   ||\n");
                printf("  ===================================================\n");

                //Muestro el empleado a dar de baja...
                employee_ShowOneEmployee(this);

                printf("  ===================================================\n");

                printf("\nconfirma baja? <s/n>: ");
                fflush(stdin);
                scanf("%c",&confirma);
                confirma = tolower(confirma);
                printf("\n");

                if(confirma == 's')
                {
                    if(!ll_remove(pArrayListEmployee,i))
                    {
                        printf("  ===================================================\n");
                        printf("||                -- Baja exitosa --                 ||\n");
                        printf("  ===================================================\n");
                        retorno = 0;
                        break;
                    }
                    else
                    {
                        printf("\nNo se pudo eliminar al empleado.\n");
                        retorno = 0;
                        //break;
                    }
                }
                else if(confirma == 'n')
                {
                    operationCancelled();
                    retorno = 0;
                }
                else
                {
                    errorOptionInvalid();
                    retorno = 0;
                }
            }
        }
    }
    if(retorno == -1)
    {
        errorPosterId();
    }

    return retorno;
}

/** \brief Listar empleados.
 *
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se dio de baja correctamente - [-1] Si hubo un error.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(employee_ListEmployees(pArrayListEmployee))
    {
        retorno = 0;
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se ordeno correctamente - [-1] Si hubo un error.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    system("cls");
    printf("  ===================================================\n");
    printf("||                 ORDENAR EMPLEADOS                 ||\n");
    printf("  ===================================================\n");
    switch(menuOrder())
    {
    case 1:
        switch(menuHowDoYouWantToOrder())
        {
        case 1://ascendente
            ll_sort(pArrayListEmployee,employee_compareById,0);
            retorno = 0;
            printf("\n..::Ordenamiento por Id efecutado con exito::..\n\n");
            break;

        case 2://descendente
            ll_sort(pArrayListEmployee,employee_compareById,1);
            retorno = 0;
            printf("\n..::Ordenamiento por Id efecutado con exito::..\n\n");
            break;

        default:
            errorOptionInvalid();
            printf("  ===================================================\n");
            printf("||  Error: usted ingreso una opcion invalida,        ||\n");
            printf("||         sera redireccionado al menu.              ||\n");
            printf("  ===================================================\n");
        }
        break;//fin case 1

    case 2:
        switch(menuHowDoYouWantToOrder())
        {
        case 1://ascendente
            ll_sort(pArrayListEmployee,employee_compareByName,0);
            retorno = 0;
            printf("\n..::Ordenamiento por Nombre efecutado con exito::..\n\n");
            break;

        case 2://descendente
            ll_sort(pArrayListEmployee,employee_compareByName,1);
            retorno = 0;
            printf("\n..::Ordenamiento por Nombre efecutado con exito::..\n\n");
            break;
        }
        break;//fin case 2

    case 3:
        switch(menuHowDoYouWantToOrder())
        {
        case 1://ascendente
            ll_sort(pArrayListEmployee,employee_compareByHT,0);
            retorno = 0;
            printf("\n..::Ordenamiento por Horas trabajadas efecutado con exito::..\n\n");
            break;

        case 2://descendente
            ll_sort(pArrayListEmployee,employee_compareByHT,1);
            retorno = 0;
            printf("\n..::Ordenamiento por Horas trabajadas efecutado con exito::..\n\n");
            break;
        }
        break;//fin case 3

    case 4:
        switch(menuHowDoYouWantToOrder())
        {
        case 1://ascendente
            ll_sort(pArrayListEmployee,employee_compareBySalary,0);
            retorno = 0;
            printf("\n..::Ordenamiento por Salario efecutado con exito::..\n\n");
            break;

        case 2://descendente
            ll_sort(pArrayListEmployee,employee_compareBySalary,1);
            retorno = 0;
            printf("\n..::Ordenamiento por Salario efecutado con exito::..\n\n");
            break;
        }
        break;//fin case 4

    case 5:
        operationCancelled();
        retorno = 0;
        break;

    default:
        errorOptionInvalid();
    }

    return retorno;
    //return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se cargo correctamente - [-1] Si hubo un error.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    //int todoOk = 0;
    FILE* auxText;
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmple;

    int auxId;
    char auxNombre[150];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pArrayListEmployee!=NULL && len>0 && path!=NULL)
    {
        auxText = fopen(path,"w");

        if(auxText==NULL)
        {
            printf("\nNo se pudo abrir el archivo.\n");
            system("pause");
            return retorno;
        }
        else
        {
            fprintf(auxText,"id,nombre,horasTrabajadas,sueldo\n");

            for(int i=0; i<len; i++)
            {

                auxEmple = (Employee*)ll_get(pArrayListEmployee,i);

                if(auxEmple!=NULL)
                {
                    employee_getId(auxEmple,&auxId);
                    employee_getNombre(auxEmple,auxNombre);
                    employee_getHorasTrabajadas(auxEmple,&auxHorasTrabajadas);
                    employee_getSueldo(auxEmple,&auxSueldo);
                    fprintf(auxText,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                    retorno = 0;
                }

            }
            fclose(auxText);

        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* Direecion de la ubicacion del archivo.
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [0] si se cargo correctamente - [-1] Si hubo un error.
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* auxBin;
    int len = ll_len(pArrayListEmployee);

    if(len>0 && path!=NULL && pArrayListEmployee!=NULL)
    {
        auxBin = fopen(path,"wb");
        if(auxBin!=NULL)
        {
            for(int i=0; i<len; i++)
            {
                fwrite(ll_get(pArrayListEmployee,i),sizeof(Employee),1,auxBin);
            }
        }

        fclose(auxBin);
        retorno = 0;
    }
    return retorno;
}
