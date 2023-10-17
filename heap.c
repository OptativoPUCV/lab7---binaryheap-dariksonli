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
  if(pq->size >= pq->capac)
  {
    pq->heapArray = realloc(pq->heapArray, ((pq->capac*2)+1)* sizeof(Heap));
    pq->capac = (pq->capac * 2) + 1;
  }

  pq->heapArray[indice].data = data;
  pq->heapArray[indice].priority = priority;
  pq->size++;
  
  void * datoTemp;
  int prioridadTemp;
  int padre = (indice-1)/2;

  while(indice > 0 && pq->heapArray[indice].priority > pq->heapArray[padre].priority)
  {
    datoTemp = pq->heapArray[indice].data;
    pq->heapArray[indice].data = pq->heapArray[padre].data;
    pq->heapArray[padre].data = datoTemp;

    prioridadTemp = pq->heapArray[indice].priority;
    pq->heapArray[indice].priority = pq->heapArray[padre].priority;
    pq->heapArray[padre].priority = prioridadTemp;

    indice = padre;
    padre = (indice - 1)/2;
  }
}

void heap_pop(Heap* pq)
{
  if(pq->size == 0) return;

  pq->heapArray[0].data = pq->heapArray[pq->size - 1].data;
  pq->heapArray[0].priority = pq->heapArray[pq->size - 1].priority;
  pq->size--;

  void * aux = pq->heapArray[pq->size].data; //se guarda el ultimo elemento en aux
  pq->heapArray[0].data = aux;
  pq->heapArray[pq->size].data = NULL;
  pq->size--;
  
  int indice = 0;
  int hijoIzq = (indice*2)+1;
  int hijoDer = (indice*2)+2;
  //
  while(pq->heapArray[indice].priority < pq->heapArray[hijoIzq].priority || pq->heapArray[indice].priority < pq->heapArray[hijoDer].priority)
  {
    if(pq->heapArray[hijoIzq].priority > pq->heapArray[hijoDer].priority)
    {
      int aux2 = pq->heapArray[hijoIzq].priority;
      pq->heapArray[hijoIzq].priority = pq->heapArray[indice].priority;
      pq->heapArray[indice].priority = aux2;
      indice = hijoIzq;
      hijoIzq = (indice*2)+1;
      hijoDer = (indice*2)+2;
    }
    else{
      if(pq->heapArray[hijoIzq].priority < pq->heapArray[hijoDer].priority)
      {
        int aux3 = pq->heapArray[hijoDer].priority;
        pq->heapArray[hijoDer].priority = pq->heapArray[indice].priority;
        pq->heapArray[indice].priority = aux3;
        indice = hijoDer;
        hijoIzq = (indice*2)+1;
        hijoDer = (indice*2)+2;
      }
      if(pq->heapArray[hijoIzq].priority > pq->heapArray[hijoDer].priority) break;
    }
  }
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
