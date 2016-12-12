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

test_make:
	@echo $(HelloWorldObjs)Greeting.o
	@echo $(HelloWorldSrc)Greeting.c

SRC_DIRS = $(dir $(wildcard $(SRC_PATH)*/*.c))
SRCS = $(patsubst $(SRC_PATH)%/, %, $(SRC_DIRS))

define SRC_PATHS
$(1)Objs = $(BUILD_PATH)$(1)/src/objs/
$(1)Src = $(SRC_PATH)$(1)/
endef

$(foreach s,$(SRCS),$(eval $(call SRC_PATHS,$(s))))

Main: $(OBJS_PATH)MyProgram.o $(HelloWorldObjs)Greeting.o
	$(LINK) -o $@.out $^

$(HelloWorldObjs)%.o: $(HelloWorldSrc)%.c
	$(COMPILE) -o $@ $^
