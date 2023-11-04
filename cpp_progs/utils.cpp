#include<iostream>
#include "utils.hpp"
using namespace std;

void printArray(int *arr, int arrSize){
    cout << "[";
    for(int i=0; i<arrSize; i++)
        cout << " " << arr[i] << (i!=arrSize-1?", ":" ");
    cout << "]" << endl;
}