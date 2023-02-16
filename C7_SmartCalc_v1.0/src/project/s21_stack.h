#ifndef SRC_INCLUDE_S21_STACH_H
#define SRC_INCLUDE_S21_STACH_H

#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <math.h>

enum {
    FALSE = 0,
    TRUE = 1
};

typedef enum {
    NUMBER = 1,
    X = 2,
    PLUS= 3,
    MINUS = 4,
    DIVIDE = 5,
    MULTIPLY = 6,
    POWER = 7,
    MODULATE = 8,
    COS = 11,
    SIN = 12,
    TAN = 13,
    ACOS = 14,
    ASIN = 15,
    ATAN = 16,
    SQRT = 17,
    LN = 18,
    LOG = 19,
    LEFT_BRACKET = 20,
    RIGHT_BRACKET = 21
} element_type;

typedef struct Node {
    double num;
    element_type type;
    struct Node* next;
} my_stack;




#endif  // SRC_INCLUDE_S21_STACH_H
