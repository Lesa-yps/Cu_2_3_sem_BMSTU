#include <stdlib.h>
#include <check.h>

#include "check_arr_lib.h"

int main(void)
{
    int n_failed;
    SRunner *runner = srunner_create(NULL);

    // добаляем тестовые наборы
    srunner_add_suite(runner, arr_lib_suite());

    // тестируем
    srunner_run_all(runner, CK_NORMAL);
    n_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
