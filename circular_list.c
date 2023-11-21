#include <stdlib.h>
#include "circular_list.h";

struct Circular_List{
    char character;
    struct Circular_List *next;
};