#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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
	int *tab = malloc(sizeof(int) * size); //Decalre a size of dynamic array
	int i;
	int j = size-1;

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

//Find a K-th number 
int FindK(int tab[], int size, int k)
{
	int i;
	int number = 0;
	for (i = size; i >= k; i--)
	{
		number = tab[i-1]; //A number in binary tab on the k-th position from right
	}

	return number;
}

//Make a right shift by n
int RightShift(int a, int n)
{
	a = a >> n; 
	return a;
}

//Make a left shift by n
int LeftShift(int a, int n)
{
	a = a << n;
	return a;
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

	int k = 0;

	printf("\n\nType a k-th number, which you want to see: ");
	scanf_s("%i", &k); //Input a k-th number

	int knumber = FindK(tab, size, k); //K-th number of general number
	printf("Your k-th number of %i is: %i",a,knumber);

	char d;

	printf("\n\nChoose a direction to the left/right shift. Type 'r' or 'l': ");
	scanf_s(" %c", &d,1); //Input a direction to shift

	int n = 0;

	printf("Type how much you want to shift: ");
	scanf_s("%i", &n); //Input how much to shift

	int a1 = 0; //Number after left/right shift

	if (d == 'r') //If direction is right
		a1 = RightShift(a, n);
	if (d == 'l') //If direction is left
		a1 = LeftShift(a, n);

	printf("\nYour number in decimal after shift is: %i", a1);
	return 0;
}