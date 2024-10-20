#include <stdlib.h>
#include <check.h>

// подключение заголовочных файлов
#include "check_counts_mult.h"
#include "check_del_mat.h"
#include "check_add_mat.h"
#include "check_print_mat.h"
#include "check_read_mat_all.h"
#include "check_mult_mat.h"

int main(void)
{
    int n_failed;
    SRunner *runner = srunner_create(NULL);

    // добавили наборы тестов
    srunner_add_suite(runner, read_counts_mult_suite());
    srunner_add_suite(runner, del_mat_suite());
    srunner_add_suite(runner, add_mat_suite());
    srunner_add_suite(runner, print_mat_suite());
    srunner_add_suite(runner, read_mat_all_suite());
    srunner_add_suite(runner, mult_mat_suite());

    // само тестирование
    srunner_run_all(runner, CK_NORMAL);
    n_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
