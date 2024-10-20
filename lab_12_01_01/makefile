# make mode=debug (или release) build=stat (или dinam-comp или dinam-load)

# Компилятор
CC := gcc

# Флаги компиляции
CFLAGS := -std=c99 -Wall -Werror -Iinc
# -Wextra -Wfloat-equal -Wfloat-conversion -Wfloat-conversion -O0 -fprofile-arcs -ftest-coverage -Wpedantic

# Флаги линковки
LDFLAGS := -lcheck -Iinc -lpthread -lrt -Wfloat-conversion -lm
# -fprofile-arcs

# Флаги для Valgrind
VAL_FLAGS := --leak-check=full --quiet  --show-leak-kinds=all --track-origins=yes

# флаги компиляции для библиотек
COMP_FLAGS := 

# Каталоги
OUT := out/
SRC := src/
INC := inc/
UNI_T := unit_tests/
LIB := lib/

# Список исходных файлов в каталоге SRC
SRC_FILES := $(wildcard $(SRC)*.c)

# Список файлов-библиотек в каталоге LIB
SRC_LIB := $(wildcard $(LIB)*.c)

# Список объектных файлов из исходных файлов
OBJ_SRC_FILES := $(SRC_FILES:$(SRC)%.c=$(OUT)%.o)

# Список файлов-библиотек скомпилированных
LIB_RES := 
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

# Каталог с файлами *_args.txt
ARGS_DIR := func_tests/data

# Список файлов *_args.txt в этом каталоге
ARGS_FILES := $(wildcard $(ARGS_DIR)/*_args.txt)

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

# динамическая загрузка
ifeq ($(build), dinam-load)
	COMP_FLAGS += -ldl
	LIB_RES += lib_my.so
	CFLAGS += -DDLOAD
endif
# динамическая компановка
ifeq ($(build), dinam-comp)
	COMP_FLAGS += -L. $(LIB_NAMES)
	LIB_RES += $(patsubst lib/%_lib.c,lib%.so,$(SRC_LIB))
endif
# статика
ifeq ($(build), stat)
	COMP_FLAGS += -L. $(LIB_NAMES)
	LIB_RES += $(patsubst lib/%_lib.c,lib%.a,$(SRC_LIB))
endif

# Компиляция приложения
app.exe : $(OBJ_SRC_FILES) $(LIB_RES)
	$(CC) -o $@ $< $(COMP_FLAGS) $(LDFLAGS)
	
# Создание каталога out
.PHONY: out
out :
	mkdir out

# Запуск функциональных тестов
.PHONY: func
func : app.exe
	./func_tests/scripts/func_tests.sh
	
# Запуск юнит-тестов
.PHONY: unit
unit : unit_tests.exe
	./unit_tests.exe

# Компиляция исполняемого файла для юнит-тестов
unit_tests.exe :  $(OBJ_FILES)
	$(CC) -o $@ $^ $(LDFLAGS)

# сборка библиотеки (динамическая компиляция)
# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
lib%.so: $(LIB)%_lib.c
	$(CC) $(CFLAGS) -o $(patsubst $(LIB)%_lib.c,$(OUT)%_lib.o,$<) -fPIC -c $<
	$(CC) -o $@ -shared $(patsubst $(LIB)%_lib.c,$(OUT)%_lib.o,$<)

# динамическая загрузка
lib_my.so: $(LIB)*_lib.c
	$(CC) $(CFLAGS) -o $(patsubst $(LIB)%_lib.c,$(OUT)%_lib.o,$<) -fPIC -c $<
	$(CC) -o $@ -shared $^ $(LDFLAGS)

# сборка библиотеки (статическая)
lib%.a: $(LIB)%_lib.c
	$(CC) $(CFLAGS) -o $(patsubst $(LIB)%_lib.c,$(OUT)%_lib.o,$<) -c $<
	ar cr $@ $(patsubst $(LIB)%_lib.c,$(OUT)%_lib.o,$<)
	ranlib $@

# Правило компиляции объектных файлов из исходных файлов для юнит-тестов
$(OUT)%.o: $(UNI_T)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Правило компиляции объектных файлов из исходных файлов
$(OUT)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Запуск Valgrind для проверки утечек памяти
count := 0
.PHONY: check
check : app.exe unit_tests.exe
	for args_file in $(ARGS_FILES); do \
		count=$$((count + 1)); \
		echo "Iteration $$count: Running valgrind for $$args_file"; \
		valgrind $(VAL_FLAGS) ./app.exe $$(cat "$$args_file"); \
	done
	valgrind $(VAL_FLAGS) ./unit_tests.exe

# Очистка файлов сборки
.PHONY: clean
clean :
	find . -type f ! -name "*.sh" ! -name "*.c" ! -name "*.h" ! -name "*.txt" ! -name "*.md" ! -name "makefile*" ! -name ".gitkeep" \
	! -name "launch.json" ! -name "settings.json" ! -name "c_cpp_properties.json" ! -name ".gitignore" -exec rm {} \;
	rm file.txt

# Закомментированная строка для генерации зависимостей
# $(CC) -MM -Iinc $(SRC)*.c
