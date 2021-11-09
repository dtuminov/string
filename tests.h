#ifndef PROJECT_TESTS_H
#define PROJECT_TESTS_H

#include "string.h"

typedef enum {OK, error} Errors;

void run_all_tests();
Errors test_strlen();
Errors test_strcpy();
Errors test_strchr();
Errors test_strdup();
Errors test_memcpy();
Errors test_strstr();
Errors test_memset();
Errors test_memchr();
#endif