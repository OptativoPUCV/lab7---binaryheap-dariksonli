#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
  if(pq->size == 0) return NULL;
  return pq->heapArray->data;
}



void heap_push(Heap* pq, void* data, int priority)
{
  if(pq->size == 0){
    pq->size++;
    pq->heapArray->data = data;
    pq->heapArray->priority = priority;
    return;
  }
  if(pq->capac == pq->size){
    pq->capac = (pq->capac * 2) + 1;
  }
}


void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap * local = (Heap *) malloc(sizeof(Heap));
  if(local == NULL) return NULL;

  local->heapArray = (heapElem *) malloc(3*sizeof(heapElem));
  if(local->heapArray == NULL) return NULL;

  local->capac = 3;
  local->size = 0;
  
  return local;
}
