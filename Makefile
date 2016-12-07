.PHONY: Test% clobber %

export BLUE = "\033[1;34m"
export RED = "\033[1;31m"
export OFF = "\033[0m"
export ROOT_PATH = ./
export UNITY_PATH = ./test/Unity/src/
export SRC_PATH = ./src/
export TEST_PATH = ./test/
export BUILD_PATH = ./build/
export OBJS_PATH = ./build/objs/
export OUT_PATH = ./build/out/
export RESULTS_PATH = ./build/results/
export PATHS = $(BUILD_PATH) $(OUT_PATH) $(OBJS_PATH) $(RESULTS_PATH)
export COMPILE = gcc -c
export LINK = gcc

SRC_MAKE = $(MAKE) -f src/src.mk
TEST_MAKE = $(MAKE) -f test/test.mk

%: $(PATHS)
	$(SRC_MAKE) $*

Test%: $(PATHS)
	$(TEST_MAKE) $*

$(PATHS):
	mkdir $@

clobber: 
	-rm -rf $(BUILD_PATH)
