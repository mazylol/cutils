#ifndef VECTOR_H
#define VECTOR_H

struct vector {
    void **elements;
    int size;
    int typeSize;
};

struct vector vector_init(int typeSize);

void vector_free(const struct vector *vec);

void vector_pop(struct vector *vec);

void vector_remove(struct vector *vec, int index);

void vector_push(struct vector *vec, const void *element);

void vector_push_int(struct vector *vec, int element);

void vector_push_float(struct vector *vec, float element);

void vector_push_double(struct vector *vec, double element);

void vector_push_char(struct vector *vec, char element);

void vector_push_string(struct vector *vec, const char *element);

#endif // VECTOR_H
