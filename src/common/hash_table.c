//
// Created by kennetsu on 1/7/21.
//

#include <common/hash_table.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

static entry *_hash_table;

static unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

static int linear_probing_hash(const char *key) {
    int index = hash(key) % HASH_SIZE;
    if (_hash_table[index].key == "\0")
        return index;

    int collid = 1;
    int prob_index = index;
    while (_hash_table[prob_index].key != "\0") {
        prob_index = (index + collid) % HASH_SIZE;
        collid++;
    }
    return prob_index;
}

entry *init_hash() {
    _hash_table = malloc(HASH_SIZE * sizeof(entry));
    for (int i = 0; i < HASH_SIZE; ++i) {
        _hash_table[i].key = "\0";
    }
    return _hash_table;
}

void add_entry_to_hash(const char *key, void *value) {
    assert(strlen(key) > 1);
    int index = linear_probing_hash(key);
    _hash_table[index].value = value;
}

void *search_entry_by_key(const char *key) {
    assert(strlen(key) > 1);
    int index = linear_probing_hash(key);
    return _hash_table[index].value;
}