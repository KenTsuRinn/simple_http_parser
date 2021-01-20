//
// Created by kennetsu on 1/8/21.
//
#include <common/hash_table.h>
#include <CUnit/CUnit.h>

void test_add_entry() {
    init_hash();
    char *key = "test_add_entry";
    char *value = "i am fuck hash i";
    add_entry_to_hash(key, sizeof(char) * strlen(value), value);

    char *result = search_entry_by_key(key);
    CU_ASSERT(strcmp(result, "i am fuck hash i") == 0)
//    destroy_hash();
}

void test_delete_entry() {
    init_hash();
    char *key = "test_delete_entry";
    char *value = "i am fuck hash i";
    add_entry_to_hash(key, sizeof(char) * strlen(value), value);

    delete_entry_in_hash(key);
    char *result = search_entry_by_key(key);
    CU_ASSERT(result == NULL)
//    destroy_hash();

}


void test_update_entry() {
    init_hash();
    char *key = "test_update_entry";
    char *value = "i am fuck hash i";
    add_entry_to_hash(key, sizeof(char) * strlen(value), value);

    char *update_value = "wai kai kai wo zai zhe li";
    update_entry_in_hash(key, sizeof(char) * strlen(update_value), update_value);
    char *result = search_entry_by_key(key);
    CU_ASSERT(strcmp(result, update_value) == 0)
//    destroy_hash();

}
