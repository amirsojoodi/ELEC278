//
//  main.c
//  intheap
//
//  Created by Thomas Dean on 2024-11-01.
//

#include <stdio.h>

#define MAX_SIZE 100
typedef struct MinHeap {
    int size;
    int data[MAX_SIZE];
} MinHeap;

int insertMinHeap(MinHeap * heap, int v);
int extractMin(MinHeap * heap, int * v);
void heapify(MinHeap * heap, int parent);
void initHeap(MinHeap * heap);
void printHeap(MinHeap * heap);


int main(int argc, const char * argv[]) {
    printf("Initializing heap\n");
    MinHeap theHeap;
    initHeap(&theHeap);
    insertMinHeap(&theHeap,7);
    insertMinHeap(&theHeap,10);
    insertMinHeap(&theHeap,3);
    insertMinHeap(&theHeap,8);
    insertMinHeap(&theHeap,2);
    insertMinHeap(&theHeap,12);
    insertMinHeap(&theHeap,4);
    printHeap(&theHeap);
    int n = 1;
    int v;
    extractMin(&theHeap,&v);
    printf("value %d = %d\n", n++, v);
    printHeap(&theHeap);
    extractMin(&theHeap,&v);
    printf("value %d = %d\n", n++, v);
    printHeap(&theHeap);
    extractMin(&theHeap,&v);
    printf("value %d = %d\n", n++, v);
    printHeap(&theHeap);
    extractMin(&theHeap,&v);
    printf("value %d = %d\n", n++, v);
    printHeap(&theHeap);
    return 0;
}

void initHeap(MinHeap * heap){
    heap->size = 0;
}

void insertFixer(MinHeap* heap, int child)
{
    int parent = (child - 1) / 2;
    
    if (child == 0){
        return;
    }
 
    if (heap->data[parent] > heap->data[child]) {
        int temp = heap->data[parent];
        heap->data[parent] = heap->data[child];
        heap->data[child] = temp;
 
        // Recursively calling insertHelper
        insertFixer(heap, parent);
    }
}

int insertMinHeap(MinHeap * heap, int value){
    if (heap->size == MAX_SIZE)
        return 0;
    
    unsigned int child = heap->size++;
    heap->data[child] = value;
    
    insertFixer(heap,child);
    
    return 1;
}

int extractMin(MinHeap * heap, int * v){
    if (heap -> size == 0) return 0;
    if (heap -> size == 1) {
        heap -> size = 0;
        *v = heap->data[0];
        return 1;
    }

    *v = heap->data[0];

    heap-> data[0] = heap->data[heap->size-1];
    heap->size--;

    heapify(heap,0);
    return 1;
}

void heapify(MinHeap * heap, int parent){
    int min = parent;
    
    int left = parent * 2 + 1;
    if (left < heap->size && heap->data[left] < heap->data[min])
        min = left;
    
    int right = parent * 2 + 2;
    if (right < heap->size && heap->data[right] < heap->data[min])
        min = right;
    
    if (min != parent){
        int temp = heap->data[parent];
        heap->data[parent] = heap->data[min];
        heap->data[min] = temp;
        heapify(heap,min);
    }
}

void printHeap(MinHeap * heap){
    printf("[");
    if (heap -> size != 0){
        for (int i = 0; i < heap->size-1; i++)
            printf("%d,",heap->data[i]);
    }
    printf("%d",heap->data[heap->size-1]);
    printf("]\n");
}

