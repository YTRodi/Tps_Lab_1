
#include "Employee.h"

int menuGeneral()
{
    int option;
    system("cls");
    printf("  ======================================================================================\n");
    printf("||                                 ABM EMPLEADOS                                        ||\n");
    printf("  ======================================================================================\n");
    printf("||  (1)  Cargar los datos de los empleados desde el archivo data.csv (modo texto).      ||\n");
    printf("||  (2)  Cargar los datos de los empleados desde el archivo data.bin (modo binario).    ||\n");
    printf("||  (3)  Alta de empleado.                                                              ||\n");
    printf("||  (4)  Modificar datos de empleado                                                    ||\n");
    printf("||  (5)  Baja de empleado.                                                              ||\n");
    printf("||  (6)  Listar empleados.                                                              ||\n");
    printf("||  (7)  Ordenar empleados.                                                             ||\n");
    printf("||  (8)  Guardar los datos de los empleados en el archivo data.csv (modo texto).        ||\n");
    printf("||  (9)  Guardar los datos de los empleados en el archivo data.bin (modo binario).      ||\n");
    printf("||  (10) Salir.                                                                         ||\n");
    printf("  ======================================================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,10,2);
    return option;
}




/** \brief Constructor que setea los campos en vacios (en caso de strings) y en 0 en caso de numeros.
 *
 * \return Employee* Nuevo empleado ya inicializado.
 *
 */
Employee* employee_new()
{
    Employee* nuevoEmp = (Employee*)malloc(sizeof(Employee));
    if(nuevoEmp!=NULL)
    {
        nuevoEmp->id = 0;
        strcpy(nuevoEmp->nombre," ");
        nuevoEmp->horasTrabajadas = 0;
        nuevoEmp->sueldo = 0;
    }
    return nuevoEmp;
}


/** \brief Constructor con parametros.
 *
 * \param idStr char* Variable pasada por parametro, donde se va a setear el ID.
 * \param nombreStr char* Variable pasada por parametro, donde se va a setear el Nombre.
 * \param horasTrabajadasStr char* Variable pasada por parametro, donde se va a setear el HorasTrabajadas.
 * \param sueldoStr char* Variable pasada por parametro, donde se va a setear el Sueldo.
 * \return Employee* Retorna un empleado seteado.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpParam = employee_new();

    if(nuevoEmpParam!=NULL)
    {
        if(employee_setId(nuevoEmpParam,atoi(idStr))
                &&employee_setNombre(nuevoEmpParam,nombreStr)
                &&employee_setHorasTrabajadas(nuevoEmpParam,atoi(horasTrabajadasStr))
                &&employee_setSueldo(nuevoEmpParam,atoi(sueldoStr)) == 0)
        {
            employee_delete(nuevoEmpParam);
        }
    }
    return nuevoEmpParam;
}


/** \brief Elimina al empleado de memoria.
 *
 * \param this Employee* Puntero a la estructura Employee.
 * \return void No retorna nada.
 *
 */
void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}


/*int employee_setId(Employee* this,int id)
{
    int todoOk = 0;
    if(this!=NULL && id>=1 && id<=1500)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}*/

/** \brief Al recibir un id maximo o igual a 0 verifica si se trata de un nuevo maximo
 *         de ser asi lo conserva y en el caso de recibir un id negativo, calcula el id
 *         a asignar automaticamente.
 *
 * \param this Employee* Puntero a la estructura Employee.
 * \param id int Id que se va a setear.
 * \return int Retorna [1] si se seteo correctamente - [0] si hubo un error.
 *
 */
int employee_setId(Employee* this, int id)//Busca el id Maximo.
{
    int todoOk = 0;
    static int IdMaximo = -1;

    if(this != NULL)
    {
        if(id < 0)
        {
            IdMaximo++;
            this->id = IdMaximo;
        }
        else
        {
            if(id>IdMaximo)
            {
                this->id = id;
                IdMaximo = id;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



/** \brief Obtiene el id pasado por parametro.
 *
 * \param this Employee* Puntero a la estructura Employee.
 * \param id int* Id que se va a obtener.
 * \return int Retorna [-1].
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *id = this->id;
    }
    return retorno;
}


/** \brief Setea el nombre pasado por parametro.
 *
 * \param this Employee* Puntero a la estructura Employee.
 * \param nombre char* Nombre que se va a setear.
 * \return int Retorna [1] si se seteo correctamente - [0] si hubo un error.
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL && nombre !=NULL && strlen(nombre)>=2)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Obtiene el nombre pasado por parametro.
 *
 * \param this Employee* Puntero a la estructura Employee.
 * \param nombre char* Nombre que se va a obtener.
 * \return int Retorna [1] si se obtuvo correctamente - [0] si hubo un error.
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Setea las horas trabajadas pasado por parametro.
 *
 * \param this Employee* Puntero a la estructura Employee.
 * \param horasTrabajadas int Horas trabajas que se va a setear.
 * \return int Retorna [1] si se seteo correctamente - [0] si hubo un error.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if(this!=NULL && horasTrabajadas>=1 && horasTrabajadas<=1500)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Obtiene las horas trabajadas pasado por parametro.
 *
 * \param this Employee* Puntero a la estructura Employee.
 * \param horasTrabajadas int* Horas trabajadas que se van a obtener.
 * \return int Retorna [-1].
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}


/** \brief Setea el sueldo pasado por parametro.
 *
 * \param this Employee* Puntero a la estructura Employee.
 * \param sueldo int Sueldo que se va a setear.
 * \return int Retorna [1] si se seteo correctamente - [0] si hubo un error.
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if(this!=NULL && sueldo>=500 && sueldo<=200000)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Obtiene el sueldo pasado por parametro.
 *
 * \param this Employee* Puntero a la estructura Employee.
 * \param sueldo int* Sueldo que se van a obtener.
 * \return int Retorna [-1].
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
    }
    return retorno;
}


/** \brief Imprime por pantalla un empleado pasado por parametro.
 *
 * \param auxEmployee Employee* Puntero a la estructura Employee.
 * \return int Retorna [1] si esta todoOK - [0] si hubo un error.
 *
 */
int employee_ShowOneEmployee(Employee* auxEmployee)
{
    int todoOk = 0;
    if(auxEmployee!=NULL)
    {
        printf(" | %5d | %15s | %10d | %10d |\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Imprime por pantalla todos los empleados de la LinkedList.
 *
 * \param pArrayListEmployee LinkedList* Puntero a la estructura LinkedList.
 * \return int Retorna [1] si esta todoOK - [0] si hubo un error.
 *
 */
int employee_ListEmployees(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf("  ===================================================\n");
        printf("||   ID  |     NOMBRE      |   HORAS T. |   SUELDO   ||\n");
        printf("  ===================================================\n");

        for(int i=0;i<len;i++)
        {
            employee_ShowOneEmployee((Employee*)ll_get(pArrayListEmployee,i));//ll_get al devolver un void* lo casteo a Employee*.
            todoOk = 1;
        }
    }
    if(todoOk == 0)
    {
        printf("  ===================================================\n");
        printf("||  Error: No se pudo cargar la lista.               ||\n");
        printf("  ===================================================\n");
    }

    return todoOk;
}


/** \brief Menu de modificacion.
 *
 * \return int Opcion ingresada.
 *
 */
int menuModificacion()
{
    int option;

    //system("cls");
    printf("  ===================================================\n");
    printf("||  (1)  Modificar nombre.                           ||\n");
    printf("||  (2)  Modificar horas trabajadas.                 ||\n");
    printf("||  (3)  Modificar sueldo.                           ||\n");
    printf("||  (4)  Salir.                                      ||\n");
    printf("  ===================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,4,3);
    return option;
}


/** \brief Menu de ordenamiento.
 *
 * \return int Opcion ingresada.
 *
 */
int menuOrder()
{
    int option;

    //system("cls");
    printf("  ===================================================\n");
    printf("||  (1)  Ordenar por id.                             ||\n");
    printf("||  (2)  Ordenar por nombre.                         ||\n");
    printf("||  (3)  Ordenar por horas trabajadas.               ||\n");
    printf("||  (4)  Ordenar por sueldo.                         ||\n");
    printf("||  (5)  Salir.                                      ||\n");
    printf("  ===================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,5,3);
    return option;
}


/** \brief Menu de como desea ordenar.
 *
 * \return int Opcion ingresada.
 *
 */
int menuHowDoYouWantToOrder()
{
    int option;

    //system("cls");
    printf("  ===================================================\n");
    printf("||            Como desea ordenarlos?                 ||\n");
    printf("||  (1)  Ascendente. <a-z> o <min-max>.              ||\n");
    printf("||  (2)  Descendente. <z-a> o <max-min>.             ||\n");
    printf("||                                                   ||\n");
    printf("||  Nota: los ordenamientos pueden llegar a demorar  ||\n");
    printf("||  unos segundos.                                   ||\n");
    printf("  ===================================================\n");
    getInt(&option,"Elija opcion: ","Error. Reingrese\n",1,2,3);
    return option;
}


//ESTO RECIBE LA FUNCION LL_SORT (ayuda memoria).
//ll_sort(LinkedList* this,int(*pFunc)(void*)(void*),int order);

/** \brief Ordenamiento por ID.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int employee_compareById(void* employee1,void* employee2)
{
    int retorno;

    //debo castear cada employee, debido a que es un puntero a void.
    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->id > emp2->id)
    {
        retorno = -1; //si el primero es mayor al segundo.
    }
    else if(emp1->id < emp2->id)
    {
        retorno = 1;
    }
    else
    {
        //son iguales
        retorno = 0;
    }

    return retorno;
}

/** \brief Ordenamiento por nombre.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int employee_compareByName(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(strcmp(emp1->nombre,emp2->nombre)>0)//Si uso strcmpi aparece un warning por implicit declaration...
    {
        retorno = -1;
    }
    else if(strcmp(emp1->nombre,emp2->nombre)<0)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordenamiento por horas trabajadas.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int employee_compareByHT(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->horasTrabajadas > emp2->horasTrabajadas)
    {
        retorno = -1;
    }
    else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordenamiento por sueldo.
 *
 * \param employee1 void* Puntero a void.
 * \param employee2 void* Puntero a void.
 * \return int Retorna [-1] si el primero es mayor al segundo.
 * \return int Retorna [1] si el segundo es mayor al primero.
 * \return int Retorna [0] si son iguales.
 *
 */
int employee_compareBySalary(void* employee1,void* employee2)
{
    int retorno;

    Employee* emp1 = (Employee*) employee1;
    Employee* emp2 = (Employee*) employee2;

    if(emp1->sueldo > emp2->sueldo)
    {
        retorno = -1;
    }
    else if(emp1->sueldo < emp2->sueldo)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/*
--Revisar
int employee_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;
    int len = ll_len(this);

    for(int i=0;i<len;i++)
    {
        if(ll_pop(this,i)!=NULL)
        {
            employee_delete((Employee*)ll_pop(this,i));
            retorno = 0;
            //printf("lueluelue\n");
        }
    }
    if(retorno == 0)
    {
        ll_deleteLinkedList(this);
        printf("lueluelue\n");
    }


    return retorno;
}*/


//MESSAGES
/** \brief Cartel de error avisando que no se pudo abrir el archivo.
 *
 * \return void No retorna nada.
 *
 */
void errorPosterFile()
{
    printf("  ===================================================\n");
    printf("||  Error: No se pudo abrir el archivo.            ||\n");
    printf("  ===================================================\n");
}

/** \brief Cartel de error avisando que no existe empleado con ese ID.
 *
 * \return void No retorna nada.
 *
 */
void errorPosterId()
{
    printf("  ===================================================\n");
    printf("||  Error: No existe empleado con ese ID,            ||\n");
    printf("||         sera redireccionado al menu.              ||\n");
    printf("  ===================================================\n");
}

/** \brief Cartel de error avisando que no puede abrirse mas de un archivo a la vez.
 *
 * \return void No retorna nada.
 *
 */
void warningPosterFile()
{
    printf("  ===================================================\n");
    printf("||  Advertencia: No puede abrirse mas de un archivo  ||\n");
    printf("||               a la vez.                           ||\n");
    printf("  ===================================================\n");
}

/** \brief Cartel de error avisando que debe cargarse un archivo antes.
 *
 * \return void No retorna nada.
 *
 */
void errorUploadFileBefore()
{
    printf("  ===================================================\n");
    printf("||  Advertencia: Debe cargar algun archivo antes.    ||\n");
    printf("  ===================================================\n");
}

/** \brief Cartel de error avisando que ingreso una opcion invalida.
 *
 * \return void No retorna nada.
 *
 */
void errorOptionInvalid()
{
    printf("  ===================================================\n");
    printf("||  Error: usted ingreso una opcion invalida,        ||\n");
    printf("||         sera redireccionado al menu.              ||\n");
    printf("  ===================================================\n");
}

/** \brief Cartel de error avisando que la operacion fue cancelada.
 *
 * \return void No retorna nada.
 *
 */
void operationCancelled()
{
    printf("  ===================================================\n");
    printf("||  Aviso: La operacion fue cancelada,               ||\n");
    printf("||         redireccionando al menu.                  ||\n");
    printf("  ===================================================\n");
}

/*  POSTER BOCETO:

    printf("  ===================================================\n");
    printf("||                                                   ||\n");
    printf("||                                                   ||\n");
    printf("  ===================================================\n");
*/

