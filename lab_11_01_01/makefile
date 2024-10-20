# Компилятор
CC := gcc

# Флаги компиляции
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Iinc -Wfloat-equal -Wfloat-conversion -Wfloat-conversion -O0 -fprofile-arcs -ftest-coverage

# Флаги линковки
LDFLAGS := -lcheck -fprofile-arcs -lpthread -lrt -Wfloat-conversion -ftest-coverage -lm
# -fprofile-arcs

# Флаги для Valgrind
VAL_FLAGS := --leak-check=full --quiet --show-leak-kinds=all --track-origins=yes

# Каталоги
OUT := out/
SRC := src/
INC := inc/
UNI_T := unit_tests/

# Дополнительные флаги для Ubuntu
ifeq ($(shell grep -o "^ID=.*" /etc/os-release | cut -d'=' -f2), ubuntu)
	LDFLAGS += -lsubunit
endif

# Список исходных файлов в каталоге SRC
SRC_FILES := $(wildcard $(SRC)*.c)

# Список объектных файлов из исходных файлов
OBJ_SRC_FILES := $(SRC_FILES:$(SRC)%.c=$(OUT)%.o)

# Список исходных файлов для юнит-тестов
UNI_FILES := $(wildcard $(UNI_T)*.c)

# Список объектных файлов для юнит-тестов
OBJ_UNI_FILES := $(UNI_FILES:$(UNI_T)%.c=$(OUT)%.o)

# Общий список объектных файлов
OBJ_FILES := $(OBJ_SRC_FILES) $(OBJ_UNI_FILES)

# Исключаем main.o из списка объектных файлов для вашего приложения
OBJ_FILES := $(filter-out $(OUT)main.o, $(OBJ_FILES))

# Компиляция исполняемого файла для юнит-тестов
unit_tests.exe :  $(OBJ_FILES)
	$(CC) -g -o $@ $^ $(LDFLAGS)
	
# Создание каталога out
.PHONY: out
out :
	mkdir out
	
# Запуск юнит-тестов
.PHONY: unit
unit : unit_tests.exe
	./unit_tests.exe

# Правило компиляции объектных файлов из исходных файлов для юнит-тестов
$(OUT)%.o: $(UNI_T)%.c
	$(CC) $(CFLAGS) -g -o $@ -c $<

# Правило компиляции объектных файлов из исходных файлов
$(OUT)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) -g -o $@ -c $<

# Очистка файлов сборки
.PHONY: clean
clean :
	find . -type f ! -name "*.sh" ! -name "*.c" ! -name "*.h" ! -name "*.txt" ! -name "*.md" ! -name "makefile*"\
	 ! -name ".gitkeep" ! -name ".gitignore" ! -name "settings.json" ! -name "launch.json" ! -name "c_cpp_properties.json" -exec rm {} \;

# Закомментированная строка для генерации зависимостей
# $(CC) -MM -Iinc $(SRC)*.c

