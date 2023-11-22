

// Sorting algorithm: Bubble sort
// check pairs of elements, compare and swaps, repeats
// trying to bubble sort an integer list

#include <iostream>
#include "utils.hpp"
using namespace std;

void swapInts(int *first, int *second)
{
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void increasingOrderBubbleSort(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize-1; i++)
        for (int j = 0; j < arrSize-i-1; j++)
            if (arr[j] > arr[j + 1])
                swapInts(&arr[j], &arr[j + 1]);
}

int main()
{
    int arrSize = 100;

    cout << "Input the size of the array : ";
    cin >> arrSize;
    cout << "\n";

    int arr[arrSize], max=100, min=1;
    cout << "Enter max min values for random values in array format: (<maxInteger><space><minInteger>): ";
    cin >> max >> min;

    for(int i=0; i<arrSize; i++){
        arr[i] = randint(min, max, i);
    }

    cout << "\n\nBefore sorting: ";
    printArray(arr, arrSize);
    increasingOrderBubbleSort(arr, arrSize);
    cout << "\nAfter sorting: ";
    printArray(arr, arrSize);

    return 0;
}

/*
    int inputArr[] = {4, 2, 3, 8, 1, 3};
    int inputArrSize = 6;
    increasing sorted order

    arr: {4, 2, 3, 8, 1, 3}
    taking first two index: 0, 1
    4, 2 -> checking if 4 <= 2 # false
    swapping 2 with 4 & 4 with 2
    arr: {2, 4, 3, 8, 1, 3}

    taking next two index: 1, 2
    4, 3 -> checking if 4 <= 3 # false
    swapping 3 with 4 & 4 with 3
    arr: {2, 3, 4, 8, 1, 3}

    taking next two index: 2, 3
    4, 8 -> checking if 4 <= 8 # true
    arr: {2, 3, 4, 8, 1, 3}

    taking next two index: 3, 4
    8, 1 -> checking if 8 <= 1 # false
    swapping 8 with 1 & 1 with 8
    arr: {2, 3, 4, 1, 8, 3}

    taking next two index: 4, 5
    8, 3 -> checking if 8 <= 3 # false
    swapping 8 with 3 & 3 with 8
    arr: {2, 3, 4, 1, 3, 8}

    taking next two index: 5, 6
    but 6 is >= size of the array, so repeat gain but for size - 1 as
    the biggest element is in last


    Pseudo code (increasing order):

        arr
        arrSize
        loop i till arrSize:
            loop j till arrSize - i
                if (arr[j] > arr[j+1] && j+1 < arrSize-i) then
                    swap(arr[j], arr[j+1])

    cout << "Before sorting: ";
    printArray(inputArr, inputArrSize);
    increasingOrderBubbleSort(inputArr, inputArrSize);
    cout << "\nAfter sorting: ";
    printArray(inputArr, inputArrSize);
*/