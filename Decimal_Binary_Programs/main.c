#include <stdio.h>
#include <stdlib.h>

//Get a size of 'binary' array
int GetSize(int number)
{
	int i = 0; //Length a number in binary system

	while (number) //While number is not 0 
	{
		number >>= 1; //Right shift by one ("Decrease" number) 
		i++;
	}

	return i;
}

//Write an array:
void WriteArray(int tab[], int size) 
{
	int i;

	for ( i = 0; i < size; i++)
	{	
		printf("%i ", tab[i]);
	}
}

//Conversion to the binary
int * DecimalToBinary(int number, int size)
{
	int *tab = malloc(sizeof(int) * 5); //Decalre a size of dynamic array
	int i = 0;

	while (number) //While number is not 0
	{
		tab[i] = number & 1; //AND operation on the last element 
		number >>= 1; //Right shift by one ("Decrease" number) 
		i++;
	}

	return tab;
}

int main()
{
	int a = 0;

	printf("Type a number in decimal: ");
	scanf_s("%i", &a); //Input a number in decimal

	int size = GetSize(a); //A size of dynamic array 'tab'
	int* tab = DecimalToBinary(a, size); //Array with binary numbers

	printf("Your number in binary is: ");
	WriteArray(tab, size); //Write an array (Number in binary)

	return 0;
}