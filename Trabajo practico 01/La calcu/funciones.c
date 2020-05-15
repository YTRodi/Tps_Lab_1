#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int pedirNumero(char *mensaje)
{
    int numero;
    printf(mensaje);
    scanf("%d",&numero);
    return numero;
}

int sumar(int primerNumero, int segundoNumero)
{
    int resultado;
    resultado = primerNumero + segundoNumero;
    return resultado;
}


int restar(int primerNumero, int segundoNumero)
{
    int resultado;
    resultado = primerNumero - segundoNumero;
    return resultado;
}


float division(int primerNumero, int segundoNumero)
{
    float resultado;
    resultado = (float) primerNumero / segundoNumero;
    return resultado;
}


int multiplicacion(int primerNumero, int segundoNumero)
{
    float resultado;
    resultado = primerNumero * segundoNumero;
    return resultado;
}

long int calcularFactorial(int a)
{
    long int factorial = 1;//1 es el elementro neutro.
    int i;//variable de control.

    for(i=a; i>=1; i--)
    {
        factorial = factorial * i;
    }

    return factorial;
}


void programaParaCalculo()
{
    int flag1 = 0;//X.
    int flag2 = 0;//y.
    int flag3 = 0;//Operacion.
    int option;
    int number1;
    int number2;

    int sumResult;//Resultado de la suma.
    int subtractionResult;//Resultado de la resta.
    float divisionResult;//Resultado de la division.
    int multiplicationResult;//Resultado de la multiplicacion.
    long int factorialResult_A;//Resultado del factorial A.
    long int factorialResult_B;//Resultado del factorial B.

    do
    {
        //Menú.
        printf("-------------------------------\n");
        printf(".....:::: Calculadora ::::.....\n");
        printf("-------------------------------\n");


        if(flag1==1)
        {
            printf("1.Ingresar 1er operando(A=%d):\n",number1);
        }
        else
        {
            printf("1.Ingresar 1er operando(A=x):\n");
        }

        if(flag2==1)
        {
            printf("2.Ingresar 2do operando(B=%d):\n",number2);
        }
        else
        {
            printf("2.Ingresar 2do operando(B=y):\n");
        }
        printf("3.Calcular todas las operaciones:\n");
        printf("4.Informar resultados:\n");
        printf("5.Salir:\n");
        printf("Elija que operacion desea realizar: ");
        scanf("%d",&option);



        switch(option)
        {
            //Lógica.
            case 1:// pido 1er numero.
                number1=pedirNumero("Ingrese 1er operando:");
                system("cls");
                flag1=1;
                break;

            case 2:// pido 2do numero.
                number2=pedirNumero("Ingrese 2do operando:");
                system("cls");
                flag2=1;
                break;

            case 3://Valido y realizo el calculo de operaciones.
                if(flag1==1 && flag2==1)
                {
                    flag3 = 1;

                    sumResult = sumar(number1,number2);
                    subtractionResult = restar(number1,number2);
                    divisionResult = division(number1,number2);
                    multiplicationResult = multiplicacion(number1,number2);
                    factorialResult_A = calcularFactorial(number1);
                    factorialResult_B = calcularFactorial(number2);

                    system("cls");
                    printf("---Las operaciones fueron calculadas---\n");
                }
                else
                {
                    system("cls");
                    printf("Error - ingrese los dos operandos\n");
                    system("pause");
                    system("cls");
                }
                break;

            case 4://Valido y muestro un informe de los calculos hechos.
                if(flag1==1 && flag2==1 && flag3 == 1)
                {
                    printf("\nInforme:\n");
                    printf("a) El resultado de la suma de %d+%d es: %d \n",number1,number2,sumResult);
                    printf("b) El resultado de la resta de %d-%d es: %d \n",number1,number2,subtractionResult);
                    if(number2==0)
                    {
                        printf("c) No se pudo realizar la division (divisor = 0)\n");
                    }
                    else
                    {
                        printf("c) El resultado de la division de %d/%d es: %.2f \n",number1,number2,divisionResult);
                    }

                    printf("d) El resultado de la multiplicacion de %d*%d es: %d \n",number1,number2,multiplicationResult);

                    if(number1<0 && number2<0)
                    {
                        printf("e) Imposible calcular el factorial de un numero negativo.<A = %d>\n",number1);
                        printf("e) Imposible calcular el factorial de un numero negativo.<A = %d>\n",number2);
                    }
                    else if (number1 == 0 && number2 == 0)
                    {
                        factorialResult_A = 1;
                        factorialResult_B = 1;
                        printf("e) El factorial de %d es: %ld\n",number1,factorialResult_A);
                        printf("e) El factorial de %d es: %ld\n",number2,factorialResult_B);
                    }
                    else
                    {
                        printf("e) El factorial de %d es: %ld\n",number1,factorialResult_A);
                        printf("e) El factorial de %d es: %ld\n",number2,factorialResult_B);
                    }

                    system("pause");
                    system("cls");
                }
                else
                {
                    system("cls");
                    printf("Error - Ingresa los operandos y calcula las operaciones\n");
                    system("pause");
                    system("cls");
                }
                break;


            case 5://Salir del programa.
                system("cls");
                printf("---Gracias por usar la calculadora---\n");
                break;

            default://Valido si no ingresa una de las opciones del menú.
                system("cls");
                printf("Ingrese una opcion correcta.\n");
                system("pause");
                system("cls");
        }


    }while(option!=5);
}




