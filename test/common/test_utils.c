//
// Created by jianyuelin on 1/22/2021.
//
#include <test/test_utils.h>
#include <common/utils.h>
#include <string.h>
#include <CUnit/Basic.h>
#include <malloc.h>
#include <stdint.h>

void test_bits_view(void) {
    char a = 'A';
    union Bits b;
    b.b = a;
    char *hex_str = (char *) malloc(4 * sizeof(char));
    sprintf(hex_str, "0x%x\0", a);
    CU_ASSERT(strcmp("0x41\0", hex_str) == 0)
    free(hex_str);

    char *num_str = (char *) malloc(9 * sizeof(char));
    sprintf(num_str, "%d%d%d%d%d%d%d%d\0",
            b.bits.b7, b.bits.b6, b.bits.b5, b.bits.b4, b.bits.b3, b.bits.b2, b.bits.b1, b.bits.b0);
    CU_ASSERT(strcmp(hex_str, num_str) == 0)
    free(num_str);

}

void test_ptr_view(void) {
    unsigned char *str = "Hello World!\0";
    union PtrView viewer;
    viewer.c_ptr = str;
    size_t char_size = sizeof(unsigned char *);
    unsigned char ptr_literal[sizeof(unsigned char *) + 1] = {0};
    for (size_t i = 0; i < sizeof(unsigned char *); ++i) {
        char viewer_iter = viewer.view_bytes[i];

        char_size--;
        ptr_literal[char_size] = (unsigned char) viewer_iter;

    }

    uint64_t paquet = 0;
    for (int i = 0; i < 8; ++i) {
        paquet <<= 8;
        paquet |= (uint64_t) ptr_literal[i];
    }
    unsigned char *s = (unsigned char *) paquet;
    int cs = strlen(s);
    int sa = strlen(str);
    int temp = strcmp(str, s);
    CU_ASSERT(strcmp(str, s) == 0)
}



