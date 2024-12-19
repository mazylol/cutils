#include "include/linkedlist.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct linkedlist linkedlist_init(int typeSize) {
    struct linkedlist list = {};

    list.head = malloc(sizeof(struct node));
    list.head->data = malloc(typeSize);
    list.head->next = NULL;
    list.size = 0;
    list.typeSize = typeSize;

    return list;
}

void linkedlist_free(struct linkedlist *list) {
    struct node *current = list->head;
    struct node *next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

void linkedlist_push(struct linkedlist *list, const void *element) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = malloc(list->typeSize);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;

    memcpy(list->head->data, element, list->typeSize);
}

void linkedlist_push_int(struct linkedlist *list, const int element) {
    linkedlist_push(list, &element);
}

void linkedlist_push_float(struct linkedlist *list, const float element) {
    linkedlist_push(list, &element);
}

void linkedlist_push_double(struct linkedlist *list, const double element) {
    linkedlist_push(list, &element);
}

void linkedlist_push_char(struct linkedlist *list, const char element) {
    linkedlist_push(list, &element);
}

void linkedlist_push_string(struct linkedlist *list, const char *element) {
    linkedlist_push(list, element);
}

void linkedlist_pop(struct linkedlist *list) {
    if (list->size == 0) {
        fprintf(stderr, "List is empty\n");
        exit(1);
    }

    struct node *temp = list->head;
    list->head = list->head->next;
    free(temp->data);
    free(temp);
    list->size--;
}