#include<iostream>
#include<random>
#include<ctime>
#include<stdlib.h>
#include "utils.hpp"
using namespace std;

void printArray(int *arr, int arrSize){
    cout << "[";
    for(int i=0; i<arrSize; i++)
        cout << " " << arr[i] << (i!=arrSize-1?", ":" ");
    cout << "]" << endl;
}

template int randint<int>(int min, int max, int seed);
template <class T>
T randint(T min, T max, int seed){
    min = abs(min);
    max = abs(max);
    if (min > max){
        T tmp = min;
        min = max;
        max = tmp;
    }
    long seedVal = time(0)+seed*time(0);
    cout << "seedVal: " << seedVal << endl;
    default_random_engine randomEngine(seed*time(0));
    uniform_int_distribution<int> distribution;
    int rawRand = distribution(randomEngine);
    cout << "rawRand: " << rawRand << endl;
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    cout << "(rawRand % max): " << (rawRand % max) << "\n";
    cout << "((max-min-1)/(max-1)): " << ((double)(max-min-1)/(double)(max-1)) << "\n";
    return static_cast<T>((rawRand % max)*((double)(max-min-1)/(double)(max-1)) + min);
}