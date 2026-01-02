#include "include/types.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include <stdbool.h>

Value make_null(){
    Value val;
    val.type = TYPE_NULL;
    return val;
}

Value make_int(long long value){
    Value val;
    val.type = TYPE_INTEGER;
    val.as.int_value = value;
    return  val;
}

Value make_float(double value){
    Value val;
    val.type = TYPE_FLOAT;
    val.as.float_value = value;
    return  val;
}

Value make_string(const char* str){
    Value val;
    val.type = TYPE_STRING;
    val.as.string_value = strdup(str);
    if (val.as.string_value == NULL) {
        fprintf(stderr,"Error: memory allocation error failed for string\n");
        exit(1);
    }
    return  val;
}

Value make_bool(bool value){
    Value val;
    val.type = TYPE_BOOLEAN;
    val.as.bool_value = value;
    return  val;
}


bool is_null(Value val){
    return  val.type == TYPE_NULL;
}

bool is_integer(Value val){
    return  val.type == TYPE_INTEGER;
}

bool is_float(Value val){
    return  val.type == TYPE_FLOAT;
}

bool is_string(Value val){
    return  val.type == TYPE_STRING;
}

bool is_boolean(Value val){
    return  val.type == TYPE_BOOLEAN;
}

bool is_number(Value val){
    return  val.type == TYPE_INTEGER || val.type == TYPE_FLOAT;
}

long long as_int(Value val) {
    if (val.type != TYPE_INTEGER) {
        fprintf(stderr, "Error: Value is not an integer\n");
        exit(1);
    }
    return val.as.int_value;
}

double as_float(Value val) {
    if (val.type != TYPE_FLOAT) {
        fprintf(stderr, "Error: Value is not a float\n");
        exit(1);
    }
    return val.as.float_value;
}

char* as_string(Value val) {
    if (val.type != TYPE_STRING) {
        fprintf(stderr, "Error: Value is not a string\n");
        exit(1);
    }
    return val.as.string_value;
}

bool as_bool(Value val) {
    if (val.type != TYPE_BOOLEAN) {
        fprintf(stderr, "Error: Value is not a boolean\n");
        exit(1);
    }
    return val.as.bool_value;
}



double to_number(Value val){
    switch (val.type) {
        case TYPE_INTEGER:{
            return (double)val.as.int_value;
        }
        case TYPE_FLOAT:{
            return  val.as.float_value;
        }
        case TYPE_BOOLEAN:{
            return  val.as.bool_value ?  1.0 : 0.0;
        }
        case TYPE_STRING:{
            return  atof(val.as.string_value);
        }
        case TYPE_NULL:{
            return  0.0;
        }
        default:{
            return  0.0;
        }
    }
}




bool to_boolean(Value val) {
    switch (val.type) {
        case TYPE_BOOLEAN:
            return val.as.bool_value;
        case TYPE_INTEGER:
            return val.as.int_value != 0;
        case TYPE_FLOAT:
            return val.as.float_value != 0.0;
        case TYPE_STRING:
            return strlen(val.as.string_value) > 0;
        case TYPE_NULL:
            return false;
        default:
            return false;
    }
}
char* to_string(Value val) {
    char buffer[256];

    switch (val.type) {
        case TYPE_INTEGER:
            snprintf(buffer, sizeof(buffer), "%lld", val.as.int_value);
            return strdup(buffer);
        case TYPE_FLOAT:
            snprintf(buffer, sizeof(buffer), "%.6f", val.as.float_value);
            return strdup(buffer);
        case TYPE_STRING:
            return strdup(val.as.string_value);
        case TYPE_BOOLEAN:
            return strdup(val.as.bool_value ? "true" : "false");
        case TYPE_NULL:
            return strdup("null");
        default:
            return strdup("");
    }
}



void free_value(Value val){
    if(val.type ==TYPE_STRING && val.as.string_value != NULL){
        free(val.as.string_value);
    }
}

Value copy_value(Value val){
    if(val.type == TYPE_STRING){
        return  make_string(val.as.string_value);
    }
    return  val;
}


void print_value(Value val){
    switch (val.type) {
        case TYPE_NULL:{
            printf("null");
            break;
        }
        case TYPE_INTEGER:{
            printf("%lld", val.as.int_value);
            break;
        }
        case TYPE_FLOAT:{
            printf("%.6f", val.as.float_value);
            break;
        }
        case TYPE_STRING:{
            printf("%s", val.as.string_value);
            break;
        }
        case TYPE_BOOLEAN:{
            printf("%s", val.as.bool_value ? "true" : "false");
            break;
        }
        default:{
            printf("<unknown>");
        }
    }
}
const char* type_name(Value val) {
    switch (val.type) {
        case TYPE_NULL:    return "null";
        case TYPE_INTEGER: return "integer";
        case TYPE_FLOAT:   return "float";
        case TYPE_STRING:  return "string";
        case TYPE_BOOLEAN: return "boolean";
        default:           return "unknown";
    }
}
