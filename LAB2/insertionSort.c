#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "sorting.h"

//Sort the array using insertion sort.
int* insertionSort(int* arr, int size)
{
    int i; //index for our outer loop
    int key; //value on a given index.
    int j; //index that "looks" for the new key position in the sorted.

    for (i = 1; i < size; i++) //start at the second position in the array A[0,1..., n, n+1]
    {
        key = arr[i]; 
        j = i - 1; //item position -1 our current position.

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; //Move the array[j + 1]
            j = j - 1; //Go to the left in the array.

            //Visualize
            plot(arr, arr[0]);
        }
        arr[j + 1] = key;
    }

    return arr;
}

//Print all values in the given array.
void printArray(int* arr, int size) {
    for (int i = 0; i < size ; i++) {
        printf("Index %d, value %d \n", i, arr[i]);
    }
}

//Plot the values in the array. This visualizes the sorting.
void plot(int* arr, int size)
{
    for (int row = 0; row < size; ++row)
    {
        for (int column = 0; column < arr[row] / (size / 2); ++column)
        {
            printf(" % c ", '#');
        }
        printf("\n");
    }
    Sleep(1);
    system("cls");
}