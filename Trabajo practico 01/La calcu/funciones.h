/**\brief Pide un numero y lo guarda.
 * \param mensaje char* guarda la direccion de memoria de donde se llame.
 * \return int retorna un entero.
 */
int pedirNumero(char *mensaje);


/** \brief Calcula la suma de dos numeros enteros.
 * \param primerNumero int primer numero entero.
 * \param segundoNumero int segundo numero entero.
 * \return int La suma de dos numeros.
 */
int sumar(int primerNumero, int segundoNumero);


/** \brief Calcula la resta de dos numeros enteros.
 * \param primerNumero int primer numero entero.
 * \param segundoNumero int segundo numero entero.
 * \return int La resta de dos numeros.
 */
int restar(int primerNumero, int segundoNumero);


/** \brief Calcula la division de dos numeros flotantes.
 * \param primerNumero int primer numero flotante.
 * \param segundoNumero int segundo numero flotante.
 * \return float La division de dos numeros..
 */
float division(int primerNumero,int segundoNumero);


/** \brief Calcula la multiplicacion de dos numeros enteros.
 * \param primerNumero int primer numero entero.
 * \param segundoNumero int segundo numero entero.
 * \return int La multiplicacion de dos numeros.
 */
int multiplicacion(int primerNumero,int segundoNumero);


/** \brief Calcula el factorial de un numero.
 * \param numero int El numero sobre el que se hara el calculo.
 * \return int El factorial del numero.
 */
long int calcularFactorial(int a);



/** \brief Muestra un menu con 5 opciones.
 * Calcula: suma,resta,division,multiplicacion y factorial de dos numeros enteros.
 * Imprime por pantalla los resultados de dichas operaciones.
 * \return void
 */
void programaParaCalculo();

