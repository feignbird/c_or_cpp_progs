#include<stdio.h>

// Insertion in the array
// deletion from the array
/*
#define typename(x) _Generic((x),                                                     \
            _Bool: "_Bool",                  unsigned char: "unsigned char",          \
             char: "char",                     signed char: "signed char",            \
        short int: "short int",         unsigned short int: "unsigned short int",     \
              int: "int",                     unsigned int: "unsigned int",           \
         long int: "long int",           unsigned long int: "unsigned long int",      \
    long long int: "long long int", unsigned long long int: "unsigned long long int", \
            float: "float",                         double: "double",                 \
      long double: "long double",                   char *: "pointer to char",        \
           void *: "pointer to void",                int *: "pointer to int",         \
          default: "other")
*/


// Gets the last filled index of array
int lastFilledIndex(int *arr, int size){
    int last_filled_index = 0;
    for(int i=size-1; i>=0; i--){
        if (arr[i]!=0){
            last_filled_index = i;
            break;
        }
    }
    return last_filled_index;
}

// reference of A, integer value, integer index, integer size
void insert(int *arr, int value, int index, int size){
    int last_filled_index = lastFilledIndex(arr, size);
    for(int j=last_filled_index+1; j>index; j--){
        arr[j] = arr[j-1];
    }
    arr[index] = value;
}

void delete(int *arr, int index, int size){
    int last_filled_index = lastFilledIndex(arr, size);
    if (index >= 0 && index < size){
        for(int k=index; k<last_filled_index; k++){
            arr[k] = arr[k+1];
        }
        arr[last_filled_index] = 0;
    }
}

void printArray(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d, ", arr[i]);
    }
}

// assuming NULL is 0

int main(){
    int A[10] = {124, 158, 92, 82, 234};

    int sizeOfArr = sizeof(A)/sizeof(A[0]);
    printf("sizeOfArr: %d\n\n", sizeOfArr);

    printf("Inserting value %d at index %d in the arr of size %d", 91, 2, sizeOfArr);
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

    return 0;
}