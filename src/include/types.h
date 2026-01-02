#ifndef TYPES_H
#define TYPES_H


#include <stdbool.h>


typedef enum{
    TYPE_NULL,
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_BOOLEAN,
} ValueType;



typedef struct{
    ValueType type;
    union{
        long long int_value;
        double float_value;
        char* string_value;
        bool bool_value;
    } as;
} Value;

#endif
