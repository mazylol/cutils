#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
    void *data;
    struct node *next;
};

struct linkedlist {
    struct node *head;
    int size;
    int typeSize;
};

struct linkedlist linkedlist_init(int typeSize);

void linkedlist_free(struct linkedlist *list);

void linkedlist_push(struct linkedlist *list, const void *element);

void linkedlist_push_int(struct linkedlist *list, const int element);

void linkedlist_push_float(struct linkedlist *list, const float element);

void linkedlist_push_double(struct linkedlist *list, const double element);

void linkedlist_push_char(struct linkedlist *list, const char element);

void linkedlist_push_string(struct linkedlist *list, const char *element);

void linkedlist_pop(struct linkedlist *list);

void linkedlist_remove(struct linkedlist *list, const int index);


#endif //LINKEDLIST_H