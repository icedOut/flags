/**
 * Testing the `parse_args` module with CUnit.
 *
 * @author  Philippe Chartrand, inspired from Alexandre Blondin Masse
 */
#include "parse_args.h"
#include "CUnit/Basic.h"

void test_default() {
   
}

void test_size_short_options() {
 
}

void test_size_long_options() {
   
}

int main() {
    CU_pSuite pSuite = NULL;
    if (CU_initialize_registry() != CUE_SUCCESS )
        return CU_get_error();

    // Testing arguments parsing
    pSuite = CU_add_suite("Testing arguments parsing", NULL, NULL);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (CU_add_test(pSuite, "Checking default arguments",
                    test_default) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (CU_add_test(pSuite, "Checking basic short options",
                    test_size_short_options) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (CU_add_test(pSuite, "Checking basic long options",
                    test_size_long_options) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    unsigned int num_failures = CU_get_number_of_failures();
    CU_cleanup_registry();
    return num_failures;
}
