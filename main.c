#include <stdio.h>

#include "include/linkedlist.h"
#include "include/vector.h"

int main() {
    struct vector vec = vector_init(sizeof(int));

    vector_push_int(&vec, 10);
    vector_push_int(&vec, 20);

    for (int i = 0; i < vec.size; i++) {
        printf("%d\n", *(int *)vec.elements[i]);
    }

    vector_free(&vec);

    struct linkedlist list = linkedlist_init(sizeof(int));

    linkedlist_push_int(&list, 10);
    linkedlist_push_int(&list, 20);

    printf("%d\n", *(int *)list.head->data);
    printf("%d\n", *(int *)list.head->next->data);

    linkedlist_free(&list);

    return 0;
}
