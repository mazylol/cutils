#include "include/structures/vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector vector_init(const int typeSize) {
    struct vector vec = {};

    vec.elements = malloc(typeSize);
    vec.size = 0;
    vec.typeSize = typeSize;

    return vec;
}

void vector_free(const struct vector *vec) {
    for (int i = 0; i < vec->size; i++) {
        free(vec->elements[i]);
    }

    free(vec->elements);
}

void vector_pop(struct vector *vec) {
    if (vec->size == 0) {
        fprintf(stderr, "Vector is empty\n");
        exit(1);
    }

    free(vec->elements[vec->size - 1]);
    vec->size--;
    vec->elements = realloc(vec->elements, vec->size * vec->typeSize);
}

void vector_remove(struct vector *vec, const int index) {
    if (index < 0 || index >= vec->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }

    free(vec->elements[index]);

    for (int i = index; i < vec->size - 1; i++) {
        vec->elements[i] = vec->elements[i + 1];
    }

    vec->size--;
    vec->elements = realloc(vec->elements, vec->size * vec->typeSize);
}

void vector_push(struct vector *vec, const void *element) {
    vec->size++;
    vec->elements = realloc(vec->elements, vec->size * vec->typeSize);

    if (vec->elements == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    vec->elements[vec->size - 1] = malloc(vec->typeSize);
    memcpy(vec->elements[vec->size - 1], element, vec->typeSize);
}

void vector_push_int(struct vector *vec, const int element) {
    vector_push(vec, &element);
}

void vector_push_float(struct vector *vec, const float element) {
    vector_push(vec, &element);
}

void vector_push_double(struct vector *vec, const double element) {
    vector_push(vec, &element);
}

void vector_push_char(struct vector *vec, const char element) {
    vector_push(vec, &element);
}

void vector_push_string(struct vector *vec, const char *element) {
    vector_push(vec, element);
}