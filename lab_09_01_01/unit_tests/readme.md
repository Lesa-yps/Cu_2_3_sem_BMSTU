# Модульные тесты для lab_09_01_01

## read_arr.c

Позитивные:

- 01 - test_read_arr_title - чтение и сортировка по названию фильма

- 02 - test_read_arr_name - чтение и сортировка по имени автора

- 03 - test_read_arr_year - чтение и сортировка по году

Негативные:

- 01 - test_read_arr_neg_year - отрицательный год

- 02 - test_read_arr_float_year - вещественный год

- 03 - test_read_arr_error_eof - в конце файла есть 2+ пустых строк

- 04 - test_read_arr_empty_str - пустая строка посреди данных

## print_arr.c

- 01 - test_print_arr - тестирование вывода массива

## find_key.c

Позитивные:

- 01 - test_find_key_name - поиск по имени автора

- 02 - test_find_key_title - поиск по названию фильма

- 03 - test_find_key_year - поиск по году

- 04 - test_find_key_not_found - значение поля не найдено

Негативные:

- 01 - test_find_key_error_place - неверное поле поиска
