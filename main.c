#include <stdio.h>

#include "include/vector.h"

int main() {
    struct vector vec = vector_init(sizeof(int));

    vector_push_int(&vec, 10);
    vector_push_int(&vec, 20);

    for (int i = 0; i < vec.size; i++) {
        printf("%d\n", *(int *)vec.elements[i]);
    }

    vector_free(&vec);

    return 0;
}
