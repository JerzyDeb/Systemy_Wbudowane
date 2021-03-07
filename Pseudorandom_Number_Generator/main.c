#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

void WriteArray(int tab[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%i ", tab[i]);
	}
}
void XorOperation(int tab1[], int tab2[], int TrueSize, int counter)
{
	int i;
	float numbers = pow(2,TrueSize)-1;
	int result = 0;
	int FirstXOR = tab1[tab2[counter - 1] - 1] ^ tab1[tab2[counter - 2] - 1];

	while (numbers)
	{
		FirstXOR = tab1[tab2[counter - 1] - 1] ^ tab1[tab2[counter - 2] - 1];
		for (i = counter-2;i > 0;i--)
		{
			result = FirstXOR ^ tab1[tab2[i - 1] - 1];
			FirstXOR = result;
		}
		for (i = 1; i < TrueSize; i++)
		{
			tab1[TrueSize - i] = tab1[TrueSize - (i + 1)];
		}
		tab1[0] = result;
		WriteArray(tab1, TrueSize);
		printf(" -- %i", BinaryToDecimal(tab1, TrueSize));
		printf("\n");
		numbers--;

	}
	
}
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

int* MakePointsArray(int tab[], int size, int counter)
{
	int* PointsArray = malloc(sizeof(int) * counter);
	int i;
	int j=0;

	for (i = 1; i < size; i++)
	{
		if (tab[i] == 1)
		{
			PointsArray[j] = i;
			j++;
		}
	}

	return PointsArray;
}


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
	int tab[] = { 1, 1, 1, 0, 0, 1, 1 };
	size_t size = sizeof(tab) / sizeof(tab[0]);
	int trueSize = size - 1;

	printf("Your anter array is: ");
	WriteArray(tab, size);

	int a;
	printf("\nType a number which you want to start: ");
	scanf_s("%i", &a);

	int* tab1 = DecimalToBinary(a, trueSize);
	//printf("\n");
	//WriteArray(tab1, trueSize);

	int counter = CountOnes(tab, size);
	int* tab2 = MakePointsArray(tab, size, counter);
	//WriteArray(tab2, counter);

	printf("\nYOUR PSEUDORANDOM NUMBERS:  \n");
	XorOperation(tab1, tab2, trueSize, counter);
	//printf("%f", pow(2, 6));
	//size_t size1 = sizeof(tab) / sizeof(tab[0]);
	

}