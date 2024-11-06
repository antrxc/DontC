#ifndef STRUCTS_H
#define STRUCTS_H

#include "enums.h"


//Token Structs 
typedef struct 
{
    TypeKeyword type;
}TokenKeyword;
typedef struct 
{
    TypeLiteral type;
    int value;
}TokenLiteral;
typedef struct 
{
    TypeSeparator type;
}TokenSeparator;

#endif
