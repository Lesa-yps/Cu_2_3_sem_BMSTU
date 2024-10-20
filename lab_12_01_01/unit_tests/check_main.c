#include <stdlib.h>
#include <check.h>

// подключение заголовочных файлов
#include "check_count_num.h"
#include "check_key.h"
#include "check_mysort.h"
#include "check_print_arr.h"
#include "check_read_arr.h"

int main(void)
{
    int n_failed;
    SRunner *runner = srunner_create(NULL);

    // добавили наборы тестов
    srunner_add_suite(runner, count_num_suite());
    srunner_add_suite(runner, key_suite());
    srunner_add_suite(runner, mysort_suite());
    srunner_add_suite(runner, print_arr_suite());
    srunner_add_suite(runner, read_arr_suite());

    // само тестирование
    srunner_run_all(runner, CK_NORMAL);
    n_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
