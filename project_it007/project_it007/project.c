#include <stdio.h>
#include <stdlib.h>
#define N 10

void functionInput(int ar[N][N], int size);
void makeArray1D(int ar[N][N], int size);

int main()
{
	printf("Task: Make a one-dimentional array D[N] made out of all elements larger that an eneted number P, "
		"all taken from beneath the main diagonal of a two-dimentional array. "
		"After, the elements of D[N] are to be sorted.\n");
	printf("Made by Ivan Tsanev\n");
	
	int a[N][N], n, i, j;

	printf("\nInputting 2D array:\n");
	do
	{
		printf("Enter array size n: ");
		scanf("%d", &n);
	} while (n <= 0 || n > N);

	functionInput(a, n);
	makeArray1D(a, n);

	system("pause");
	return 0;
}

void functionInput(int ar[N][N], int size)
{
	int i, j;
	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			do
			{
				printf("Enter element [%d][%d]: ", i, j);
				scanf("%d", &ar[i][j]);
			} while (ar[i][j] < -1000 || ar[i][j] > 1000);

		}
	}

	printf("\nOutputting 2D array:\n");
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{

			printf("A[%d][%d]: %d  ", i, j, ar[i][j]);
		}
		printf("\n");
	}
}

void makeArray1D(int ar[N][N], int size)
{
	int  d[N * N], p, i, j;
	int index_d = 0;
	int size_d = 0;

	printf("\nEntering number p, filling and sorting 1D array: \n");
	printf("Enter random number p: ");
	scanf("%d", &p);
	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i > j && ar[i][j] > p)
			{
				d[index_d] = ar[i][j];
				index_d++;
				size_d++;
			}
		}
	}

	printf("\nUnsorted 1D array: \t");
	for (i = 0; i < size_d; i++)
	{
		printf("D[%d]: %d  ", i, d[i]);
	}

	//Sorting 1D array
	for (i = 0; i < size_d; i++)
	{
		for (j = i; j < size_d; j++)
		{ 
			if (d[i] > d[j])
			{
				d[j] += d[i];
				d[i] = d[j] - d[i];
				d[j] -= d[i];
			}
		}
	}

	printf("\nSorted 1D array: \n");
	for (i = 0; i < size_d; i++)
	{
		printf("D[%d]: %d  ", i, d[i]);
	}
}