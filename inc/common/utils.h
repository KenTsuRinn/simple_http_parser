//
// Created by jianyuelin on 1/22/2021.
//

#ifndef SIMPLE_HTTP_PARSER_UTILS_H
#define SIMPLE_HTTP_PARSER_UTILS_H

#include <stddef.h>
#include <argp.h>
#include <stdlib.h>

union PtrView {
    unsigned char *c_ptr;
    unsigned char view_bytes[sizeof(unsigned char *)]
};


union Bits {
    char b;
    struct bits {
#ifdef LITTLE_ENDIAN
        unsigned int b0: 1;
        unsigned int b1: 1;
        unsigned int b2: 1;
        unsigned int b3: 1;
        unsigned int b4: 1;
        unsigned int b5: 1;
        unsigned int b6: 1;
        unsigned int b7: 1;
#else
        unsigned int b7: 1;
        unsigned int b6: 1;
        unsigned int b5: 1;
        unsigned int b4: 1;
        unsigned int b3: 1;
        unsigned int b2: 1;
        unsigned int b1: 1;
        unsigned int b0: 1;

        // reverse the order of the bit fields.
#endif
    } bits;
};

#endif //SIMPLE_HTTP_PARSER_UTILS_H
