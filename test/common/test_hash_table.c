//
// Created by kennetsu on 1/8/21.
//
#include <common/hash_table.h>
#include <CUnit/CUnit.h>

void test_add_entry() {
    init_hash();
    char *key = "test";
    add_entry_to_hash(key, "i am fuck hash i");

    char *result = search_entry_by_key("test");
    CU_ASSERT(result == "i am fuck hash i")
}