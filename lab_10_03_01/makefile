# компилятор
CC := gcc
# флаги компиляции
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -g -fprofile-arcs -ftest-coverage
CFLAGS_RELEASE := -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion
# флаги компоновки
LDFLAGS := -fprofile-arcs -ftest-coverage -lcheck -lpthread -lrt -lm
ifeq ($(shell grep -o "^ID=.*" /etc/os-release | cut -d'=' -f2), ubuntu)
	LDFLAGS += -lsubunit
endif
LDFLAGS_RELEASE := -lm

# определнеи директорий
SRC_DIR := src
INC_DIR := inc
TEST_DIR := unit_tests
OUT_DIR := out

# определение файлов исходного кода и объектных файлов
APP_SRC := $(wildcard $(SRC_DIR)/*.c)
APP_OBJ := $(APP_SRC:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)
APP_DEP := $(APP_OBJ:.o=.d)

UNIT_TEST_SRC := $(wildcard $(TEST_DIR)/check_*.c)
UNIT_TEST_OBJ := $(UNIT_TEST_SRC:$(TEST_DIR)/%.c=$(OUT_DIR)/%.o)
UNIT_TEST_DEP := $(UNIT_TEST_OBJ:.o=.d)

# определение исполняемых файлов
APP_EXEC := app.exe
UNIT_TEST_EXEC := unit_tests.exe

#
all: $(UNIT_TEST_EXEC)

# app
$(APP_EXEC): $(APP_OBJ)
	$(CC) -Iinc -o $@ $^ $(LDFLAGS)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c $(OUT_DIR)/%.d | $(OUT_DIR)
	$(CC) -Iinc $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.d: $(SRC_DIR)/%.c | $(OUT_DIR)
	$(CC) -Iinc $(CFLAGS) -MM -MT '$@ $(@:.d=.o)' $< -MF $@

-include $(APP_DEP)

# unit_tests
unit: $(UNIT_TEST_EXEC)
	./unit_tests.sh

$(UNIT_TEST_EXEC): $(UNIT_TEST_OBJ) $(filter-out $(OUT_DIR)/main.o, $(APP_OBJ))
	$(CC) -Iinc -o $@ $^ $(LDFLAGS)

$(OUT_DIR)/%.o: $(TEST_DIR)/%.c $(OUT_DIR)/%.d | $(OUT_DIR)
	$(CC) -Iinc $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.d: $(TEST_DIR)/%.c | $(OUT_DIR)
	$(CC) -Iinc $(CFLAGS) -MM -MT '$@ $(@:.d=.o)' $< -MF $@

-include $(UNIT_TEST_DEP)

# func_tests
# func: $(APP_EXEC)
# 	./func_tests/scripts/func_tests.sh

# code coverage
cov:
	../common/src/collect_coverage.sh


# other

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR) $(APP_EXEC) $(UNIT_TEST_EXEC) ./*.gcov

release: CFLAGS := $(CFLAGS_RELEASE)
release: LDFLAGS := $(LDFLAGS_RELEASE)
release: $(APP_EXEC)

debug: $(APP_EXEC)

re:
	make clean && make all

.PHONY: all clean unit func cov
