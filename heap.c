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
  int indice = pq->size;
  
  if(indice == 0){
    pq->heapArray[indice].data = data;
    pq->heapArray[indice].priority = priority;
    pq->size++;
    return;
  }
  
  if(pq->capac == pq->size){
    int capacidad = (pq->capac * 2)+1;
    pq->heapArray = (heapElem *) realloc(pq->heapArray , sizeof(int ) * capacidad);
    if(pq->heapArray == NULL) return;
    pq->capac = capacidad;
  }

  pq->size++;
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;

  if(pq->heapArray[indice].priority < pq->heapArray[pq->size].priority)
  {
    
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
