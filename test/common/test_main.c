//
// Created by jianyuelin on 1/8/2021.
//

#include <CUnit/CUnit.h>
#include <test/test_hash_table.h>
#include <CUnit/Basic.h>

int main() {
    CU_pSuite testSuite;

    /* CUnit初期化 */
    CU_initialize_registry();
    /* Suite登録 */
    testSuite = CU_add_suite("JojoTestSuite", NULL, NULL);

    /* Test関数 */
    CU_add_test(testSuite, "test_maxi", test_maxi);
    CU_add_test(testSuite, "test_add_entry", test_add_entry);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    /* CUnit 終了処理 */
    CU_cleanup_registry();

    return CU_get_error();

}