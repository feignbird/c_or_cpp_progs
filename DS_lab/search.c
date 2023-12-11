#include<stdio.h>


void printArray(int *arr, int arrSize){
    printf("[");
    for(int i=0; i<arrSize; i++)
        printf(" %d %s", arr[i], (i!=arrSize-1?", ":" "));
    printf("]");
}

int linearSearch(int *arr, int arrSize, int value, int fromLast){
    int i = fromLast?arrSize-1:0;
    if(fromLast) while(arr[i]!=value && i>=0)i--;
    else while(arr[i]!=value && i < arrSize)i++;
    if (i>=arrSize) return -1;
    return i;
}

int binarySearch(int *arr, int start, int end, int value){
    if (start>=end && arr[end] != value)
        return -1;
    int checkAtIndex = (start+end)/2;
    if (value == arr[checkAtIndex]) return checkAtIndex;
    else if (value < arr[checkAtIndex]) return binarySearch(arr, start, checkAtIndex-1, value);
    else return binarySearch(arr, checkAtIndex+1, end, value);
}

void exploreLinearSearch(){
    int arrSize;
    printf("Please enter the length of the array you want to make: ");
    scanf("%d", &arrSize);
    printf("\n");

    int arr[arrSize];
    for (int i=0; i<arrSize; i++){
        printf("Enter number at index %d : ", i);
        scanf("%d", &arr[i]);
        printf("\n");
    }

    printArray(arr, arrSize);

    int val;
    printf("\n\nEnter an integer value to search in the array: ");
    scanf("%d", &val);
    printf("\nValue entered: %d\n", val);

    int searchStartPoint;
    printf("\n\nEnter 0 to start search from start & 1 to start search from last : ");
    scanf("%d", &searchStartPoint);
    printf("\nStart point: %s \n", (searchStartPoint?"Last":"Start"));

    int valFoundIndex = linearSearch(arr, arrSize, val, searchStartPoint);
    if(valFoundIndex==-1)
        printf("Value %d not found in array ", val);
    else printf("Value %d found at index %d using linear search method from %s in array ", val, valFoundIndex, (searchStartPoint?"Last":"Start"));
    printArray(arr, arrSize);
}

void exploreBinarySearch(){
    int arrSize;
    printf("Please enter the length of the array you want to make: ");
    scanf("%d", &arrSize);
    printf("\n");

    int arr[arrSize];
    for (int i=0; i<arrSize; i++){
        printf("Enter number at index %d : ", i);
        scanf("%d", &arr[i]);
        printf("\n");
    }

    printArray(arr, arrSize);

    int val;
    printf("\n\nEnter an integer value to search in the array: ");
    scanf("%d", &val);
    printf("\nValue entered: %d\n", val);

    int valFoundIndex = binarySearch(arr, 0, arrSize-1, val);
    if(valFoundIndex==-1)
        printf("Value %d not found in array ", val);
    else printf("Value %d found at index %d using binary search method on sorted array ", val, valFoundIndex);
    printArray(arr, arrSize);
}

int main(){
    printf("############### Linear Search ###############\n");
    exploreLinearSearch();
    printf("\n\n\n\n");
    printf("############### Binary Search ###############\n");
    printf("NOTE: ENTERED VALUES IN ARRAY SHOULD BE IN SORTED ASCENDING ORDER");
    exploreBinarySearch();
    return 0;
}