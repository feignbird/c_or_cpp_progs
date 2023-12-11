#include<stdio.h>

// prints the array [ a , b , c , ...]
void printArray(int *arr, int arrSize){
    printf("[");
    for(int i=0; i<arrSize; i++)
        printf(" %d %s", arr[i], (i!=arrSize-1?", ":" "));
    printf("]");
}

// Gets the last filled index of the array
int lastFilledIndex(int *arr, int size){
    int i, last_filled_index = 0;
    for(i=size-1; i>=0 && arr[i]==0; i--)
        last_filled_index = i-1;
    return last_filled_index;
}

// Insert at a position in the array
void insert(int *arr, int value, int index, int size){
    int last_filled_index = lastFilledIndex(arr, size);
    for(int j=last_filled_index+1; j>index; j--)
        arr[j] = arr[j-1];
    arr[index] = value;
}

// Delete a value at a position in the array
void delete(int *arr, int index, int size){
    int last_filled_index = lastFilledIndex(arr, size);
    if (index >= 0 && index < size){
        for(int k=index; k<last_filled_index; k++){
            arr[k] = arr[k+1];
        }
        arr[last_filled_index] = 0;
    }
}


int main(){
    // assuming NULL is 0
    int A[10] = {124, 158, 92, 82, 234};

    int sizeOfArr = sizeof(A)/sizeof(A[0]);
    printf("sizeOfArr: %d\n\n", sizeOfArr);
    printArray(A, sizeOfArr);

    printf("\nInserting value %d at index %d in the arr of size %d", 91, 2, sizeOfArr);
    printf("\nOriginal array : ");
    printArray(A, sizeOfArr);
    insert(A, 91, 2, sizeOfArr); // call as reference
    printf("\nModified array : ");
    printArray(A, sizeOfArr);

    printf("\n\nDeleting at index %d in the arr of size %d", 2, sizeOfArr);
    printf("\nOriginal array : ");
    printArray(A, sizeOfArr);
    delete(A, 2, sizeOfArr); // call as reference
    printf("\nModified array : ");
    printArray(A, sizeOfArr);
}