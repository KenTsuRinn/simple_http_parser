//
// Created by kennetsu on 1/7/21.
//

#include <common/hash_table.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

static entry *_hash_table = NULL;

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
    while (_hash_table[prob_index].key != "\0" && strcmp(_hash_table[prob_index].key, key) != 0) {
        prob_index = (index + collid) % HASH_SIZE;
        collid++;
    }
    return prob_index;
}

static void *clone(const void *value, size_t size) {
    void *v_ptr = malloc(size);
    memcpy(v_ptr, value, size);
    return v_ptr;
}

entry *init_hash() {
    if (_hash_table != NULL)
        return _hash_table;
    _hash_table = malloc(HASH_SIZE * sizeof(entry));
    for (int i = 0; i < HASH_SIZE; ++i) {
        _hash_table[i].key = "\0";
    }
    return _hash_table;
}

void destroy_hash() {
    for (int i = 0; i < HASH_SIZE; ++i) {
        entry entry = _hash_table[i];
        if (entry.key != NULL)
            free(entry.key);
        if (entry.value != NULL)
            free(entry.value);
    }
    free(_hash_table);
}

void add_entry_to_hash(const char *key, size_t size, const void *value) {
    assert(strlen(key) > 1);
    int index = linear_probing_hash(key);
    int len = strlen(key);
    _hash_table[index].key = clone(key, sizeof(char) * len);
    _hash_table[index].value = clone(value, size);
}

void *search_entry_by_key(const char *key) {
    assert(strlen(key) > 1);
    int index = linear_probing_hash(key);
    return _hash_table[index].value;
}

void delete_entry_in_hash(const char *key) {
    assert(strlen(key) > 1);
    int index = linear_probing_hash(key);
    entry entry = _hash_table[index];
    if (entry.key != NULL)
        free(entry.key);
    if (entry.value != NULL)
        free(entry.value);
}

void update_entry_in_hash(const char *key, size_t size, const void *value) {
    assert(strlen(key) > 1);
    int index = linear_probing_hash(key);
    entry entry = _hash_table[index];
    assert(entry.key != NULL);
    assert(strcmp(entry.key, key) == 0);
    free(entry.value);
    strcpy(entry.value, clone(value, size));
}