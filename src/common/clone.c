//
// Created by kennetsu on 1/18/21.
//
#include <common/clone.h>
#include <stdlib.h>
#include <string.h>

void *clone(void *ptr, size_t size) {
    void *clone_ptr = malloc(size);
    for (size_t i = 0; i < size; ++i) {
        memcpy(&clone_ptr[i], &ptr[i], sizeof(unsigned char));
    }
    return clone_ptr;
}
