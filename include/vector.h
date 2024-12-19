#ifndef VECTOR_H
#define VECTOR_H

struct vector {
    void **elements;
    int size;
    int typeSize;
};

struct vector vector_init(const int typeSize);
void vector_free(const struct vector *vec);
void vector_pop(struct vector *vec);
void vector_push(struct vector *vec, const void *element);
void vector_push_int(struct vector *vec, const int element);
void vector_push_float(struct vector *vec, const float element);
void vector_push_double(struct vector *vec, const double element);
void vector_push_char(struct vector *vec, const char element);
void vector_push_string(struct vector *vec, const char *element);

#endif //VECTOR_H
