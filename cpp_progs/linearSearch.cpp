#include<iostream>
using namespace std;

void printArray(int *arr, int arrSize){
    cout << "[";
    for(int i=0; i<arrSize; i++)
        cout << " " << arr[i] << (i!=arrSize-1?", ":" ");
    cout << "]" << endl;
}

int linearSearch(int *arr, int arrSize, int value, bool fromLast=false){
    int i = fromLast?arrSize-1:0;
    if(fromLast) while(arr[i]!=value && i>=0)i--;
    else while(arr[i]!=value && i < arrSize)i++;
    if (i>=arrSize) return -1;
    return i;
}


int main(){
    int arrSize;
    cout << "Please enter the length of the array you want to make: ";
    cin >> arrSize;
    cout << endl;

    int arr[arrSize];
    for (int i=0; i<arrSize; i++){
        cout << "Enter number at index "<< i << " : ";
        cin >> arr[i];
        cout << endl;
    }

    printArray(arr, arrSize);

    int val;
    cout << "\n\nEnter an integer value to search in the array: ";
    cin >> val;
    cout << "\nValue entered: " << val << endl;
    cout << endl;

    bool searchStartPoint;
    cout << "Enter 0 to start search from start & 1 to start search from last : ";
    cin >> searchStartPoint;
    cout << "\nStart point: " << (searchStartPoint?"Last":"Start") << endl;
    cout << endl;

    int valFoundIndex = linearSearch(arr, arrSize, val, searchStartPoint);
    if(valFoundIndex==-1)
        cout << "Value " << val << " not found in array ";
    else cout << "\nValue " << val << " found at index " << valFoundIndex << " using linear search method from " << (searchStartPoint?"Last":"Start") << " in array ";
    printArray(arr, arrSize);
    cout << endl;
}