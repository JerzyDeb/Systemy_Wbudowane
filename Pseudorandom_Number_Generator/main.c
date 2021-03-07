#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

//Write an array:
void WriteArray(int tab[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%i ", tab[i]);
	}
}

//XOR operations and shifts the bits on the right side: 
void XorOperation(int tab1[], int tab2[], int TrueSize, int counter)
{
	int i;
	float numbers = pow(2,TrueSize)-1; //A number of randoms numbers (max 2^6-1 = 63)
	int result = 0;
	int FirstXOR; 

	while (numbers) //While numbers are not zero
	{
		FirstXOR = tab1[tab2[counter - 1] - 1] ^ tab1[tab2[counter - 2] - 1]; ////XOR operation on two last bits

		for (i = counter-2;i > 0;i--)//XOR operation from 3rd operation
		{
			result = FirstXOR ^ tab1[tab2[i - 1] - 1]; //Result of XOR operation
			FirstXOR = result;
		}

		for (i = 1; i < TrueSize; i++)
		{
			tab1[TrueSize - i] = tab1[TrueSize - (i + 1)]; //Shift bits by one place on the right side
		}

		tab1[0] = result; //First element in the array is the last XOR result
		WriteArray(tab1, TrueSize); //Write a full array
		printf(" || %i", BinaryToDecimal(tab1, TrueSize)); //Write a array in decimal
		printf("\n");
		numbers--; //Numbers-1

	}
}

//Counting ones in the starting array:
int CountOnes(int tab[], int size)
{
	int i;
	int counter = 0;

	for (i = 1; i < size; i++)
	{
		if (tab[i] == 1)
			counter++;
	}

	return counter;
}

//Making an array with points, where are the ones
int* MakePointsArray(int tab[], int size, int counter)
{
	int* PointsArray = malloc(sizeof(int) * counter); //Declare a size of dynamic array (Number of ones)
	int i;
	int j=0;

	for (i = 1; i < size; i++)
	{
		if (tab[i] == 1) //If in the starting table is one
		{
			PointsArray[j] = i; //The point of this one is getting to the new array
			j++;
		}
	}

	return PointsArray;
}

//Conversion to the binary
int* DecimalToBinary(int number, int size)
{
	int* tab = malloc(sizeof(int) * size); //Decalre a size of dynamic array
	int j = size-1;
	int i;

	for (i = 0;i < size;i++)
	{
		tab[i] = 0;
	}

	while (number) //While number is not 0
	{
		tab[j] = number & 1; //AND operation on the last element 
		number >>= 1; //Right shift by one ("Decrease" number) 
		j--;
	}

	return tab;
}

//Conversion to the decimal
int BinaryToDecimal(int tab[], int size)
{
	int i;
	int number=0;
	for (i = 0;i < size;i++)
	{
		number += (pow(2, i) * tab[(size-1)-i]); 
	}

	return number;
}

int main()
{
	int tab[] = { 1, 1, 1, 0, 0, 1, 1 }; //Starting array
	size_t size = sizeof(tab) / sizeof(tab[0]); //Size of starting array
	int trueSize = size - 1; //New array must have a smallest size by one

	printf("Your anter array is: ");
	WriteArray(tab, size);

	int a;
	printf("\nType a number which you want to start: ");
	scanf_s("%i", &a); //Number, which you can start generate

	int* tab1 = DecimalToBinary(a, trueSize); //Conversion your number to binary

	int counter = CountOnes(tab, size); //Number of ones
	int* tab2 = MakePointsArray(tab, size, counter); //Array with points

	printf("\nYOUR PSEUDORANDOM NUMBERS:  \n");
	XorOperation(tab1, tab2, trueSize, counter); //Let's generate
}