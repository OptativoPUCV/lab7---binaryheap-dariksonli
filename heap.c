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

  //si esta vacio insertar altiro
  if(indice == 0){
    pq->heapArray[indice].data = data;
    pq->heapArray[indice].priority = priority;
    pq->size++;
    return;
  }
  //si arreglo esta lleno aumentar capacidad
  if(pq->capac == pq->size)
  {
    int capacidad = (pq->capac * 2)+1;
    pq->heapArray = (heapElem *) realloc(pq->heapArray , sizeof(int ) * capacidad);
    if(pq->heapArray == NULL) return;
  }

  pq->size++;
  indice++;
  pq->heapArray[indice].data = data;
  pq->heapArray[indice].priority = priority;

  if(pq->heapArray[indice].priority < pq->heapArray[pq->size].priority)//si el nuevo elemento es menor que el padre
  {
    heapElem aux = pq->heapArray[indice];//se guarda el elemento en aux
    pq->heapArray[indice] = pq->heapArray[indice];//se guarda el nuevo elemento en el padre
    pq->heapArray[indice] = aux;//se guarda el aux en el padre
    indice = (indice-1)/2;//se vuelve a llamar a la funcion con el nuevo indice
    heap_push(pq, data, priority);
    return;
  }
  
  /*while(pq->heapArray[indice].priority > pq->heapArray[(indice-1)/2].priority)
  {
    heapElem aux = pq->heapArray[indice];
    pq->heapArray[indice] = pq->heapArray[(indice-1)/2];
    pq->heapArray[(indice-1)/2] = aux;
    indice = (indice-1)/2;
    if(indice == 0) break;
  }*/
  
  
}


void heap_pop(Heap* pq)
{
  void * aux = pq->heapArray[pq->size].data;
  pq->heapArray[0].data = aux;

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
