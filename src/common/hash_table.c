//
// Created by kennetsu on 1/7/21.
//

#include <common/hash_table.h>
#include <malloc.h>
#include <string.h>

static entry *_hash_table;

entry *init_hash() {
    _hash_table = malloc(HASH_SIZE * sizeof(entry));
    for (int i = 0; i < _hash_table; ++i) {
        strcpy(_hash_table[i].key, "\0");
    }
    return _hash_table;
}

void add_entry_to_hash(const char *key, void *value) {
    return;
}
