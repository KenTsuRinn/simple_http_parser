//
// Created by kennetsu on 1/18/21.
//

#ifndef SIMPLE_HTTP_PARSER_TEST_CLONE_H
#define SIMPLE_HTTP_PARSER_TEST_CLONE_H

typedef struct {
    int age;
    char * name;
} test_struct;
extern void test_clone_str();
extern void test_clone_struct();
extern void test_clone_long();

#endif //SIMPLE_HTTP_PARSER_TEST_CLONE_H
