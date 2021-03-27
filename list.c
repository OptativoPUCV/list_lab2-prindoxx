#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList(){

  List* list = (List*) malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
     return list;
}

void * firstList(List * list) {
  if (list->head && list->head->data){
    list->current = list->head;
    return (void*)list->head->data;
  }
    return NULL;
}

void * nextList(List * list) {
  if (list == NULL) return NULL;
  if (list->head == NULL) return NULL;
  if (list->current == NULL) return NULL;
  if (list->current->next == NULL) return NULL;
  if (list->head == list->tail){
    return (void*) list->head->data;
  }
  list->current = list->current->next;
    return (void*) list->current->data;
}

void * lastList(List * list) {
  if (list->tail && list->tail->data){
    list->current = list->tail;
    return (void*) list->tail->data;
  }
    return NULL;
}

void * prevList(List * list) {
  if (list == NULL) return NULL;
  if (list->tail == NULL) return NULL;
  if (list->current == NULL) return NULL;
  if (list->current->prev == NULL) return NULL;
  if (list->head == list->tail){
    return (void*) list->head->data;
  }
  list->current = list->current->prev;
    return (void*) list->current->data;
}

void pushFront(List * list, const void * data) {
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  void * aux;

  if ( list == NULL ) return NULL;

  if ( list->head == NULL ) return NULL;

  if ( list->head == list->tail ) {

    aux = (void*) list->head->data;

    free(list->head);

    return aux;

  } else {

    aux = (void*) list->current->data;

    if ( (list->current->next != NULL) && (list->current->prev!=NULL)) {
      
      list->current->prev->next = list->current->next;
      list->current->next->prev = list->current->prev;

      free(list->current);

      return aux;

    } else {
      if(list->current->next == NULL){
        list->current->prev->next = NULL;
        list->tail = list->current->prev;

        free(list->current);

        return aux;
      } else{

        list->current->next->prev = NULL;
        list->head = list->current->next;

        free(list->current);

        return aux;
      }
      

    }

    
  }
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}