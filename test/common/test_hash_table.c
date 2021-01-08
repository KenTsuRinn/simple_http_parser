//
// Created by kennetsu on 1/8/21.
//
#include <common/hash_table.h>
#include <CUnit/CUnit.h>
#include <malloc.h>

int maxi(int i1, int i2) {
    return (i1 > i2) ? i1 : i2;
}

void test_maxi() {
    CU_ASSERT(maxi(0, 2) == 2);
    CU_ASSERT(maxi(0, -2) == 0);
    CU_ASSERT(maxi(2, 2) == 2);
}

void test_add_entry() {
    init_hash();
    char *key = (char *) malloc(12 * sizeof(char));
    key = "test";
    add_entry_to_hash(key, "i am fuck hash i");

    CU_ASSERT( search_entry_by_key("test") == "i am fuck hash i")
}