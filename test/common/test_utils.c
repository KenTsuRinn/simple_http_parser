//
// Created by jianyuelin on 1/22/2021.
//
#include <test/test_utils.h>
#include <common/utils.h>
#include <string.h>
#include <CUnit/Basic.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef DEBUG
#define DEBUG_PRINT(fmt, args...)    fprintf(stderr, fmt, ## args)
#else
#define DEBUG_PRINT(fmt, args...)    /* Don't do anything in release builds */
#endif


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
    CU_ASSERT(strcmp("10000010\0", num_str) == 0)
    free(num_str);

}

void test_ptr_view(void) {
    char *str = "Hello World!\0";
    union PtrView viewer;
    viewer.c_ptr = str;
    size_t char_size = sizeof(char *);
    char ptr_literal[sizeof(char *)] = {0};
    for (size_t i = 0; i < sizeof(char *); ++i) {
        char viewer_iter = viewer.view_bytes[i];

        char_size--;
        ptr_literal[char_size] = viewer_iter;

    }

    uint32_t nHexNumber = (ptr_literal[4] << 24) | (ptr_literal[5] << 16) | (ptr_literal[6] << 8) | (ptr_literal[7]);

    char *test = (char *) nHexNumber;
    CU_ASSERT(strcmp(str, test) == 0)
}



