#include<iostream>
using namespace std;

void printArray(int *arr, int arrSize){
    cout << "[";
    for(int i=0; i<arrSize; i++)
        cout << " " << arr[i] << (i!=arrSize-1?", ":" ");
    cout << "]" << endl;
}

int binarySearch(int *arr, int start, int end, int value){
    cout << "\nstart: " << start << endl;
    cout << "end: " << end << endl;
    cout << "value: " << value << endl;
    if (start>=end && arr[end] != value)
        return -1;
    int checkAtIndex = (start+end)/2;// + ((start+end)%2==0?0:1);
    cout << "checkAtIndex: " << checkAtIndex << endl;
    cout << endl;
    if (value == arr[checkAtIndex]) return checkAtIndex;
    else if (value < arr[checkAtIndex]) return binarySearch(arr, start, checkAtIndex-1, value);
    else return binarySearch(arr, checkAtIndex+1, end, value);
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

    /*
        bool searchStartPoint;
    cout << "Enter 0 to start search from start & 1 to start search from last : ";
    cin >> searchStartPoint;
    cout << "\nStart point: " << (searchStartPoint?"Last":"Start") << endl;
    cout << endl;
    */

    int val;
    cout << "\n\nEnter an integer value to search in the array: ";
    cin >> val;
    cout << "\nValue entered: " << val << endl;
    cout << endl;

    int valFoundIndex = binarySearch(arr, 0, arrSize-1, val);
    if(valFoundIndex==-1)
        cout << "Value " << val << " not found in array ";
    else cout << "\nValue " << val << " found at index " << valFoundIndex << " using binary search method " << "on sorted array ";
    printArray(arr, arrSize);
    cout << endl;
}