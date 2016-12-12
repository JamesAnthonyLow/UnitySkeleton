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

TEST_DIRS = $(dir $(wildcard $(TEST_PATH)*/*.c))
SOURCE_DIRS = $(patsubst $(TEST_PATH)%, $(SRC_PATH)%, $(TEST_DIRS)) 
TESTS = $(patsubst $(TEST_PATH)%/, %, $(TEST_DIRS))

##$(1)_TESTS = $(wildcard $($(1)_TEST_PATH)*.c)
define TEST_PATHS
$(1)_TEST_PATH = $(TEST_PATH)$(1)
$(1)_SRC_PATH = $(SRC_PATH)$(1)
endef

define TEST_RULES
$(1):
	@echo $($(1)_TEST_PATH)
	@echo $($(1)_SRC_PATH)
endef

$(foreach t,$(TESTS),$(eval $(call TEST_PATHS,$(t))))
$(foreach t,$(TESTS),$(eval $(call TEST_RULES,$(t))))

test_make:
	@echo $(TEST_DIRS)
	@echo $(SOURCE_DIRS)
	@echo $(TESTS)

.PHONY: % $(TESTS)
