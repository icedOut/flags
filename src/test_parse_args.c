/**
 * Testing the `parse_args` module with CUnit.
 *
 * @author  Philippe Chartrand, inspired from Alexandre Blondin Masse
 */
#include "parse_args.h"
#include "CUnit/Basic.h"

void test_default() {
    char *argv[] = {"bin/tp3", NULL};
    int argc = 1; 
    struct Arguments *arguments = parse_arguments(argc, argv);
    CU_ASSERT_EQUAL(arguments->show_languages,  false);
    CU_ASSERT_EQUAL(arguments->show_capitals,   false);
    CU_ASSERT_EQUAL(arguments->show_borders,    false);
    CU_ASSERT_EQUAL(arguments->show_flags,      false);
    CU_ASSERT_EQUAL(arguments->format,          TEXT);
    CU_ASSERT_EQUAL(arguments->region,          ALL);
    free_arguments(arguments);
}

void test_size_short_options() {
    char *argv[] = {"bin/tp3", "--show-languages" ,  "--show-capital" , "--show-borders" ,
                     "--show-flags" , NULL};
    int argc = 5 ;
    struct Arguments *arguments = parse_arguments(argc, argv);
    CU_ASSERT_EQUAL(arguments->show_languages,  true);
    CU_ASSERT_EQUAL(arguments->show_capitals,   true);
    CU_ASSERT_EQUAL(arguments->show_borders,    true);
    CU_ASSERT_EQUAL(arguments->show_flags,      true);
    free_arguments(arguments);
}

void test_size_long_options() {
    char *argv[] = {"bin/tp3", "--country", "can",  "--region", "oceania", "--output-filename", "test", 
                     "--output-format", "png", NULL };
     int  argc = 9 ;
     struct Arguments *arguments = parse_arguments(argc, argv);
     CU_ASSERT_STRING_EQUAL(arguments->filename, "test");
     CU_ASSERT_STRING_EQUAL(arguments->country, "can");
     CU_ASSERT_EQUAL(arguments->region, OCEANIA );
     CU_ASSERT_EQUAL(arguments->format, PNG);
     free_arguments(arguments);
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
