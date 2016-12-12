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
CFLAGS := -I$(UNITY_PATH) 

TEST_DIRS = $(dir $(wildcard $(TEST_PATH)*/*.c))
SOURCE_DIRS = $(patsubst $(TEST_PATH)%, $(SRC_PATH)%, $(TEST_DIRS)) 
TESTS = $(patsubst $(TEST_PATH)%/, %, $(TEST_DIRS))

define TEST_PATHS
$(1)_TEST_PATH = $(TEST_PATH)$(1)
$(1)_SRC_PATH = $(SRC_PATH)$(1)
$(1)_TESTS = $(wildcard $(TEST_PATH)$(1)/*.c)
$(1)_BUILD_PATH = $(BUILD_PATH)$(1)
$(1)_OBJS_PATH = $(BUILD_PATH)$(1)/objs
$(1)_OUT_PATH = $(BUILD_PATH)$(1)/out
$(1)_RESULTS_PATH = $(BUILD_PATH)$(1)/results
$(1)_PATHS += $(BUILD_PATH)$(1)/objs
$(1)_PATHS += $(BUILD_PATH)$(1)/out
$(1)_PATHS += $(BUILD_PATH)$(1)/results
endef

define TEST_CFLAGS
$(1)_CFLAGS = $(CFLAGS) -I$($(1)_SRC_PATH)
endef

#$(patsubst $($(1)_TEST_PATH)%.c, $($(1)_RESULTS_PATH)%.txt, $($(1)_TESTS)) 

define TEST_RULES
$(1): $($(1)_PATHS) $(patsubst $($(1)_TEST_PATH)%.c, $($(1)_OBJS_PATH)%.o, $($(1)_TESTS))
	@echo $($(1)_TEST_PATH)
	@echo $($(1)_SRC_PATH)
	@echo $($(1)_TESTS)
	@echo $($(1)_BUILD_PATH)
	@echo $($(1)_OBJS_PATH)
	@echo $($(1)_OUT_PATH)
	@echo $($(1)_RESULTS_PATH)
	@echo $($(1)_PATHS)
	@echo $($(1)_CFLAGS)
endef

define OBJECT_RULES
$($(1)_OBJS_PATH)%.o: $($(1)_TEST_PATH)%.c
	$(COMPILE) -o $$@ $$< $($(1)_CFLAGS)
endef

define MKDIR_RULES
$($(1)_BUILD_PATH):
	mkdir $$@

$($(1)_PATHS): $($(1)_BUILD_PATH)
	@-mkdir $$@ || :
endef

$(OBJS_PATH)unity.o: $(UNITY_PATH)unity.c
	$(COMPILE) -o $@ $< $(CFLAGS)

$(foreach t,$(TESTS),$(eval $(call TEST_PATHS,$(t))))
$(foreach t,$(TESTS),$(eval $(call TEST_CFLAGS,$(t))))
$(foreach t,$(TESTS),$(eval $(call TEST_RULES,$(t))))
$(foreach t,$(TESTS),$(eval $(call OBJECT_RULES,$(t))))
$(foreach t,$(TESTS),$(eval $(call MKDIR_RULES,$(t))))

.PHONY: % $(TESTS) 
