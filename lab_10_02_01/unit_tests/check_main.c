#include <stdlib.h>
#include <check.h>

// подключение заголовочных файлов
#include "check_in_out.h"

int main(void)
{
    int n_failed;
    SRunner *runner = srunner_create(NULL);

    // добавили наборы тестов
    srunner_add_suite(runner, in_out_suite());

    // само тестирование
    srunner_run_all(runner, CK_NORMAL);
    n_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
