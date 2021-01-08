//
// Created by kennetsu on 1/7/21.
//

#ifndef SIMPLE_HTTP_PARSER_HASH_TABLE_H
#define SIMPLE_HTTP_PARSER_HASH_TABLE_H

#include <stddef.h>

#define HASH_SIZE 20000

typedef struct {
    char *key;
    void *value;
} entry;

extern entry *init_hash();

extern void add_entry_to_hash(const char *key, size_t size, const void *value);

extern void *search_entry_by_key(const char *key);

extern void delete_entry_in_hash(const char *key);

extern void update_entry_in_hash(const char *key, size_t size, void *value);

#endif //SIMPLE_HTTP_PARSER_HASH_TABLE_H
