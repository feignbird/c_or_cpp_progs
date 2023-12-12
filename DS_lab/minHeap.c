// Write a program in C to implement min heap data structure using arrays.

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// almost complete binary tree pattern
// min heap: parent is smaller then its children

// leftChild if parent is at ith index = 2*i + 1
// rightChild if parent is at ith index = 2*i + 2
// parent if child is at jth index = floor((j-1)/2)

struct MinHeap {
    int *heapArr;
    int heapSize;
    int lastElementIndex;
};

typedef struct MinHeap* Mheap;


void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void minHeapify(Mheap heap){
    int currentIndex = heap->lastElementIndex;
    int parentIndex = (currentIndex-1)/2;
    while(heap->heapArr[parentIndex] > heap->heapArr[currentIndex] && parentIndex >= 0){
        swap(&(heap->heapArr[parentIndex]), &(heap->heapArr[currentIndex]));
        currentIndex = parentIndex;
        parentIndex = (currentIndex-1)/2;
    }
}

void reverseMinHeapify(Mheap heap){
    int currentIndex = 0;
    int left = 2*currentIndex + 1;
    int right = 2*currentIndex + 2;
    while(left < heap->heapSize){
        if (heap->heapArr[currentIndex] <= heap->heapArr[left] 
        && heap->heapArr[currentIndex] <= heap->heapArr[right]){
            return;
        }
        else if (heap->heapArr[currentIndex] > heap->heapArr[left]){
            swap(&(heap->heapArr[currentIndex]), &(heap->heapArr[left]));
            currentIndex = left;
        }
        else if (heap->heapArr[currentIndex] > heap->heapArr[right]){
            swap(&(heap->heapArr[currentIndex]), &(heap->heapArr[right]));
            currentIndex = right;
        }
        left = 2*currentIndex + 1;
        right = 2*currentIndex + 2;
    }
}


void insert(Mheap heap, int value){
    // 1, 43, 82, 91, 54, 64, 89
    if (heap->lastElementIndex + 1 >= heap->heapSize){
        printf("\nHeap is full.\n");
        return;
    }
    heap->heapArr[++heap->lastElementIndex] = value;
    minHeapify(heap);
}

int extractMin(Mheap heap){
    int tmp = heap->heapArr[0];
    heap->heapArr[0] = heap->heapArr[heap->lastElementIndex];
    heap->lastElementIndex--;
    reverseMinHeapify(heap);
    return tmp;
}

void printHeap(Mheap heap){
    int level = 0;
    printf("\n");
    for (int i=0; i<=heap->lastElementIndex; i++){
       if ((int)log2(i+1) != level){
            printf("\n");
            level = (int)log2(i+1);
        }
        printf(" %d ", heap->heapArr[i]);
    }
}

Mheap createHeap(int *arr, int arrSize){
    Mheap heap = (Mheap)malloc(sizeof(struct MinHeap));
    heap->heapArr = (int*)calloc(arrSize, sizeof(int));
    heap->heapSize = arrSize;
    heap->heapArr[0] = arr[0];
    heap->lastElementIndex = 0;
    for(int i=1; i<arrSize; i++){
        insert(heap, arr[i]);
    }
    return heap;
}



int main(){
    int arr[] = {4, 98, 72, 7, 72, 1, 38, 84, 38, 29};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("\narr: %x\n", arr);
    printf("\narrSize: %d\n", arrSize);
    printf("\n\nHeap creation: ");
    Mheap heaproot = createHeap(arr, arrSize);
    printHeap(heaproot);
    printf("\n\nextraction in heap: ");
    int extractedVal = extractMin(heaproot);
    printHeap(heaproot);
    printf("\nextracted value: %d\n", extractedVal);
    return 0;
}