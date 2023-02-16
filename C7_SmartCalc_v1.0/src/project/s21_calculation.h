#ifndef SRC_PROJECT_S21_CALCULATION_H_
#define SRC_PROJECT_S21_CALCULATION_H_

#include "stdio.h"

#include "string.h"

#include <stdlib.h>

#include <math.h>

#define TRUE 1
#define FALSE 0

typedef enum {
        LEFT_BRACKET = 1,
        RIGHT_BRACKET = 2,
        PLUS = 3,
        MINUS = 4,
        DIVIDE = 5,
        MULTIPLY = 6,
        MODULATE = 7,
        POWER = 8,
        COS = 11,
        SIN = 12,
        TAN = 13,
        ACOS = 14,
        ASIN = 15,
        ATAN = 16,
        SQRT = 17,
        LN = 18,
        LOG = 19
}
element_type;

typedef struct Stack {
    element_type type;
    struct Stack * next;
}
my_stack;

typedef struct Node {
    char info[17];
    struct Node * next;
}
my_str;

int calc(my_str * str, double * ans, double x);
int Notation(my_str ** str_pol, char * str);

#endif  // SRC_PROJECT_S21_CALCULATION_H_
