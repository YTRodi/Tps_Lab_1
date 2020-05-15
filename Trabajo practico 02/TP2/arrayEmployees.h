#define LIBRE 0
#define OCUPADO 1
#define QTY_CARACTERES 51 //CANTIDAD DE CARACTERES QUE PUEDE TENER EL ARRAY

typedef struct
{
    int id; //ES EL LEGAJO
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

/** \brief Muestra un menu de opciones.
 *
 * \return int La opcion elegida.
 */
int menuAbm();


/** \brief Inicializa el array del tipo estructura de modo que el estado isEmpty
 *         de cada posicion del array sea 1 en todas sus posiciones.
 *
 * \param listEmployee[] Array de estructura a inicializar.
 * \param len Longitud/tamaño del Array de estructura.
 * \return int Retorna [-1] si hubo un ERROR(Longitud invalida) - [0] Todo OK.
 */
int initEmployees(sEmployee listEmployee[],int len);


/** \brief Encuentra la primera posicion disponible del
           array pasado por parametro o informa si esta lleno.
 *
 * \param listEmployee[] Array del tipo estructura en donde se buscara la posicion libre.
 * \param len Longitud/tamaño del Array de estructura.
 * \return int Retorna el índice de la primera posicion disponible que encuentra.
 */
int searchFree(sEmployee listEmployee[], int len);


/** \brief Muestra por pantalla a un empleado pasado por parametro.
 *
 * \param listEmployee Empleado a ser mostrado.
 * \return void No retorna nada.
 */
void showOneEmployee(sEmployee listEmployee);


/** \brief Muestra por pantalla todo el array de empleados pasado por parametro.
 *
 * \param listEmployee[] Array del tipo estructura a ser mostrado.
 * \param len Longitud/tamaño del Array de estructura.
 * \return int Retorna [-1] si hubo un ERROR(No hay empleados que mostrar) - [0] Todo OK
 *
 */
int printEmployees(sEmployee listEmployee[],int len);


/** \brief Agrega el nuevo empleado a la primera posicion disponible
 *         del array del tipo estructura.
 *
 * \param listEmployee[] Array del tipo estructura a agregar nuevo empleado.
 * \param len Longitud/tamaño del Array de estructura.
 * \param id Numero de ID disponible para dar al nuevo empleado.
 * \param name[] Nombre del nuevo empleado.
 * \param lastName[] Apellido del nuevo empleado.
 * \param salary Salario del nuevo empleado.
 * \param sector Sector del nuevo empleado.
 * \return int Retorna [-1] si hubo un ERROR - [0] Todo OK.
 *
 */
int addEmployee(sEmployee listEmployee[],int len, int id,char name[],char lastName[],float salary, int sector);


/** \brief Crea una array del tipo estructura de empleado
 *         con los datos pasados por parametros.
 *
 * \param id Id disponible para asignar al nuevo empleado.
 * \param name[] Nombre del nuevo empleado.
 * \param lastName[] Apellido del nuevo empleado.
 * \param salary Salario del nuevo empleado.
 * \param sector Sector del nuevo empleado.
 * \return sEmployee Retorna una estructura cargada con todos los datos/valores pasados
 *                   por parametro a la función.
 */
sEmployee newEmp(int id, char name[],char lastName[],float salary,int sector);


/** \brief Pide los datos para dar de alta a un nuevo empleado
 *         y cargarlo al array del tipo estructura.
 *
 * \param listEmployee[] Array del tipo estructura donde se cargaran los datos del nuevo empleado.
 * \param len Longitud/tamaño del Array de estructura.
 * \param lastId Id disponible para asignar al nuevo empleado.
 * \return int Retorna [-1] si hubo un ERROR - [0] Todo OK.
 *
 */
int loadEmployee(sEmployee listEmployee[],int len,int lastId);


/** \brief Busca en el array del tipo estructura el empleado que coincida con el
 *         id pasado  por parametro.
 *
 * \param listEmployee[] Array del tipo estructura en el cual se buscar al empleado.
 * \param len Longitud/tamaño del Array de estructura.
 * \param id Id del empleado a buscar.
 * \return int Retorna el indice en el cual se encuentra el empledo buscado por ID
 *             o [-1] en caso de no encontrarlo.
 */
int findEmployeeById(sEmployee listEmployee[],int len, int id);


/** \brief Modifica los valores que desee del empleado por Id.
 *
 * \param listEmployee[] Array del tipo estructura en el cual se va a modificar al empleado.
 * \param len Longitud/tamaño del Array de estructura.
 * \return int Retorna [-1] si hubo un ERROR - [0] Todo OK.
 *
 */
int modifyEmployee(sEmployee listEmployee[],int len);


/** \brief Muestra un menu de opciones para modificar al empleado.
 *
 * \return int La opcion elegida.
 *
 */
int menuModif();


/** \brief Elimina el empleado de manera lógica con el Id pasado por parametro.
 *
 * \param listEmployee[] Array del tipo estructura en el cual se va a eliminar al empleado.
 * \param len Longitud/tamaño del Array de estructura.
 * \return int Retorna [-1] si hubo un ERROR - [0] Todo OK.
 *
 */
int removeEmployee(sEmployee listEmployee[],int len);


/** \brief Muestra un menu de opciones con la opciones de informe.
 *
 * \return int La opcion elegida.
 *
 */
int menuReports();


/** \brief Ordenar el array del tipo estructura de forma:
 *         -<1> Ascendente.
 *         -<2> Descendente
 *
 * \param listEmployee[] Array del tipo estructura en el cual se van a ordenar los empleados.
 * \param len Longitud/tamaño del Array de estructura.
 * \param order Recibe 1 o 2 para ordenar de forma ascendente o descendente.
 * \return int Retorna [-1] si hubo un ERROR - [0] Todo OK.
 *
 */
int sortEmployees(sEmployee listEmployee[],int len, int order);


/** \brief Muestra:
 *         -Suma total de los salarios.
 *         -Promedio de los salarios.
 *         -Los empleados que superan el salario promedio.
 *
 * \param listEmployee[] Array del tipo estructura en el cual se va a analizar y mostrar informes.
 * \param len Longitud/tamaño del Array de estructura.
 * \return void No retorna nada.
 *
 */
void printSalaryInformation(sEmployee listEmployee[],int len);


/** \brief Carga 20 empleados con sus respectivos:
 *         -Nombres.
 *         -Apellidos.
 *         -Salarios.
 *         -Sectores.
 *
 * \param listEmployee[] Array del tipo estructura de empleados.
 * \param len Longitud/tamaño del Array de estructura.
 * \param lastId Id por el cual queremos iniciar.
 * \return int Retorna el ultimo Id.
 */
int hardCodearEmployeesConId(sEmployee listEmployee[],int len, int lastId);
