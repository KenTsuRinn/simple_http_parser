//
// Created by kennetsu on 1/8/21.
//
#include <common/hash_table.h>
#include <CUnit/CUnit.h>

void test_add_entry() {
    init_hash();
    char *key = "test";
    char *value = "i am fuck hash i";
    add_entry_to_hash(key, sizeof(char) * strlen(value), value);

    char *result = search_entry_by_key("test");
    CU_ASSERT(strcmp(result, "i am fuck hash i") == 0)
}

void test_delete_entry() {
    init_hash();
    char *key = "test";
    char *value = "i am fuck hash i";
    add_entry_to_hash(key, sizeof(char) * strlen(value), value);

    delete_entry_in_hash("test");
    char *result = search_entry_by_key("test");
    CU_ASSERT(result == NULL)
}


void test_update_entry() {
    init_hash();
    char *key = "test";
    char *value = "i am fuck hash i";
    add_entry_to_hash(key, sizeof(char) * strlen(value), value);

    char *update_value = "wang kaikai wo zai zheli ~~";
    update_entry_in_hash("test", sizeof(char) * strlen(update_value), update_value);
    char *result = search_entry_by_key("test");
    CU_ASSERT(strcmp(result, update_value) == 0)
}
