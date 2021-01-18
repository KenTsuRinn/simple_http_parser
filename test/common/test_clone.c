//
// Created by kennetsu on 1/18/21.
//
#include <common/clone.h>
#include <CUnit/CUnit.h>
#include <stdlib.h>
#include <test/test_clone.h>

//TODO: 字符串克隆失败
void test_clone_str() {
    char *src = "learn memory model";
    size_t len = strlen(src);
    char *dest = clone(src, len);
    CU_ASSERT(strcmp(src, dest) == 0)
    free(dest);

}

void test_clone_struct() {
    test_struct mick = (test_struct) {
            .age    = 10,
            .name = "test"
    };
    test_struct *dest = clone(&mick, sizeof(mick));
    CU_ASSERT(strcmp(dest->name, mick.name) == 0)
    CU_ASSERT(dest->age == mick.age)
    free(dest);
}

void test_clone_long() {
    long src = 84746373;
    long *dest = clone(&src, sizeof src);
    CU_ASSERT(*dest == src)
    free(dest);
}
