# Компилятор
CC := gcc

# Флаги компиляции
CFLAGS := -std=c99 -Wall -Iinc
# -Wextra -Wfloat-equal -Wfloat-conversion -Wfloat-conversion -O0 -fprofile-arcs -ftest-coverage -Wpedantic -Werror 

# Флаги линковки
LDFLAGS := -lcheck -fprofile-arcs -lpthread -lrt -Wfloat-conversion -ftest-coverage -lm
# -fprofile-arcs

# Флаги для Valgrind
VAL_FLAGS := --leak-check=full --quiet  --show-leak-kinds=all --track-origins=yes

# Каталоги
OUT := out/
INC := inc/
LIB := lib/
PY := ./
UNI_T := unit_tests/

MAIN_APP := main.py

# Список файлов-библиотек в каталоге LIB
SRC_LIB := $(wildcard $(LIB)*.c)

# Список объектных файлов из исходных файлов
OBJ_SRC_FILES := $(SRC_FILES:$(SRC)%.c=$(OUT)%.o)

# Список файлов-библиотек скомпилированных
LIB_RES += $(patsubst lib/%_lib.c,lib%.so,$(SRC_LIB))
LIB_NAMES := $(patsubst lib/%_lib.c,-l%,$(SRC_LIB))

# Список объектных файлов из файлов-библиотек
OBJ_LIB := $(SRC_LIB:$(LIB)%.c=$(OUT)%.o)

# Список исходных файлов для юнит-тестов
UNI_FILES := $(wildcard $(UNI_T)*.c)

# Список объектных файлов для юнит-тестов
OBJ_UNI_FILES := $(UNI_FILES:$(UNI_T)%.c=$(OUT)%.o)

# Общий список объектных файлов
OBJ_FILES := $(OBJ_SRC_FILES) $(OBJ_UNI_FILES) $(OBJ_LIB)

# Исключаем main.o из списка объектных файлов для вашего приложения
OBJ_FILES := $(filter-out $(OUT)main.o, $(OBJ_FILES))

# Дополнительные флаги для ubuntu
ifeq ($(shell grep -o "^ID=.*" /etc/os-release | cut -d'=' -f2), ubuntu)
	LDFLAGS += -lsubunit
endif

# Отладочная сборка: добавим генерацию отладочной информации
ifeq ($(mode), debug)
	CFLAGS += -g3
endif
# Финальная сборка: исключим отладочную информацию и утверждения (asserts)
ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

# динамическая компановка
# флаги компиляции для библиотек
COMP_FLAGS += -L. $(LIB_NAMES)

# Запуск приложения
.PHONY: run
run : $(LIB_RES)
	python3 $(PY)$(MAIN_APP)
	
# Создание каталога out
.PHONY: out
out :
	mkdir out

# Запуск функциональных тестов
.PHONY: func
func : $(LIB_RES)
	./func_tests/scripts/func_tests.sh
	
# Запуск юнит-тестов
.PHONY: unit
unit : unit_tests.exe
	./unit_tests.exe

# Компиляция исполняемого файла для юнит-тестов
unit_tests.exe :  $(OBJ_FILES)
	$(CC) -o $@ $^ $(LDFLAGS)

# сборка библиотеки (динамическая)
# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
lib%.so: $(LIB)%_lib.c
	$(CC) $(CFLAGS) -o $(patsubst $(LIB)%_lib.c,$(OUT)%_lib.o,$<) -fPIC -c $<
	$(CC) -o $@ -shared $(patsubst $(LIB)%_lib.c,$(OUT)%_lib.o,$<)

# Правило компиляции объектных файлов из исходных файлов для юнит-тестов
$(OUT)%.o: $(UNI_T)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OUT)%.o: $(LIB)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Запуск Valgrind для проверки утечек памяти
count := 0
.PHONY: check
check : unit_tests.exe
	export CK_FORN=no && \
	valgrind $(VAL_FLAGS) ./unit_tests.exe

# Очистка файлов сборки
.PHONY: clean
clean :
	find . -type f ! -name "*.sh" ! -name "*.py" ! -name "*.c" ! -name "*.h" ! -name "*.txt" ! -name "*.md" ! -name "makefile*" ! -name ".gitkeep" \
	! -name "launch.json" ! -name "settings.json" ! -name "c_cpp_properties.json" ! -name ".gitignore" -exec rm {} \;
	rm file.txt

# Закомментированная строка для генерации зависимостей
# $(CC) -MM -Iinc $(SRC)*.c
