#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct _our_type {
    struct _our_type *prev;
    struct _our_type *next;
    int item_number;
    int special;
} our_type;

__attribute__((visibility("hidden")))
void set_special(our_type* item) {
    item->special = 1;
}
