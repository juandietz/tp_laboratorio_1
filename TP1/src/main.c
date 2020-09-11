
/*
En el archivo principal o main, se ubica la logica del programa, sin incluir funciones o cadenas de caracteres,
los cuales deberan ir en un archivo aparte para luego llamar a dichas funciones cuando sea necesario utilizarlas.
*/

#include <stdio.h>
//#include <stdio ext.h>
#include <stdlib.h>
#include "operations.h"
#include "menu.h"
#include "validations.h"
#include "strings_esp.h"
//#include "strings_eng.h"
#include "constants.h"


int main()
{
	setbuf(stdout, NULL);

    int   valueA;
    int   valueB;
    int   error;
    float result;
    char  confirm;

    //IMPORTANTE: En Linux en lugar de fflush() se debe utilizar la funci�n __fpurge()


    system("cls"); //Limpiar pantalla. system("clear"); para Linux


    welcome();
    while(!scanf("%c", &confirm));
    system("cls");

    while(inputInt(&valueA, MSG_INPUT_VALUE_A, MSG_INVALID_CHAR_INPUT, -DOMAIN, DOMAIN, RETRIES) != 0)
    {
    	puts(MSG_ERROR_RETRY);
    	while(!scanf("%c", &confirm));
    }

    while(inputInt(&valueB, MSG_INPUT_VALUE_B, MSG_INVALID_CHAR_INPUT, -DOMAIN, DOMAIN, RETRIES) != 0)
    {
		puts(MSG_ERROR_RETRY);
		while(!scanf("%c", &confirm));
	}


    system("cls");



    printf("\n A=%d \t B=%d", valueA, valueB);

    printf("\n\n%s\n", MSG_CALCULATE);
	while(!scanf("%c", &confirm));

	system("cls");



	printf("\n A=%d \t B=%d", valueA, valueB);

	printf("\n----------------------------------------\n");


	if(add(valueA, valueB, &result))
	{
		printf("\n%s\n", MSG_ERROR_GENERAL);
	}else
	{
		printf("\n%s%.0f\n", MSG_PRINT_SUM, result);
	}


	if(subtract(valueA, valueB, &result))
	{
		printf("\n%s\n", MSG_ERROR_GENERAL);
	}else
	{
		printf("\n%s%.0f\n", MSG_PRINT_SUBTRACTION, result);
	}


	if((error=multiply(valueA, valueB, &result)))
	{
		if(error == -1)
		{
			printf("\n%s\n", MSG_ERROR_GENERAL);
		}else
		{
			printf("\n%s\n", MSG_ERROR_MULT_OVERFLOW);
		}
	}else
	{
		printf("\n%s%.0f\n", MSG_PRINT_MULTIPLICATION, result);
	}


	if(divide(valueA, valueB, &result))
	{
		printf("\n%s\n", MSG_ERROR_DIVISION_ZERO);
	}else
	{
		printf("\n%s%.4f\n", MSG_PRINT_DIVISION, result);
	}


	if((error=factorial(valueA, &result)))
	{
		if(error == -1)
		{
			printf("\n%s\n", MSG_ERROR_FACT_NEGATIVE);
		}else
		{
			printf("\n%s\n", MSG_ERROR_FACT_OVERFLOW);
		}
	}else
	{
		printf("\n%s%.0f\n", MSG_PRINT_FACTORIAL_A, result);
	}


	if((error=factorial(valueB, &result)))
		{
			if(error == -1)
			{
				printf("\n%s\n", MSG_ERROR_FACT_NEGATIVE);
			}else
			{
				printf("\n%s\n", MSG_ERROR_FACT_OVERFLOW);
			}
		}else
		{
			printf("\n%s%.0f\n", MSG_PRINT_FACTORIAL_B, result);
		}



	printf("\n----------------------------------------\n");


	printf("\n%s\n\t", MSG_EXIT_CONFIRM);
    while(!scanf("%c", &confirm));



    system("cls");

    puts(MSG_GOODBYE);

    return 0;
}
