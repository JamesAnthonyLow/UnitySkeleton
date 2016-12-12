ROOT_PATH = ./
UNITY_PATH = ./test/Unity/src/
SRC_PATH = ./src/
TEST_PATH = ./test/
BUILD_PATH = ./build/
OBJS_PATH = ./build/objs/
OUT_PATH = ./build/out/
RESULTS_PATH = ./build/results/
PATHS = $(BUILD_PATH) $(OUT_PATH) $(OBJS_PATH) $(RESULTS_PATH)
COMPILE = gcc -c
LINK = gcc


DIRS = $(dir $(wildcard $(TEST_PATH)*/*.c))

test:
	@echo $(DIRS)

.PHONY: test
