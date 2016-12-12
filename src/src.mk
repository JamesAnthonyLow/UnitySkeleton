SRC_DIRS = $(dir $(wildcard $(SRC_PATH)*/*.c))
SRCS = $(patsubst $(SRC_PATH)%/, %, $(SRC_DIRS))

define SRC_PATHS
$(1)Objs = $(BUILD_PATH)$(1)/src/objs/
$(1)Src = $(SRC_PATH)$(1)/
endef

define OBJS_VARS
$(1): $(patsubst $($(1)Src)%.c, $($(1)Objs)%.o, $(wildcard $($(1)Src)*.c))
endef

define SRC_OBJS_RULES
$($(1)Objs)%.o: $($(1)Objs) $($(1)Src)%.c
	$(COMPILE) -o $$@ $($(1)Src)$$*.c
endef

define MKDIR_RULES
$($(1)Objs):
	mkdir -p $$@
$($(1)Src):
	mkdir -p $$@
endef

define CLEAN_PATHS
CLEAN_TARGETS += $($(1)Objs)/*.o
endef

$(foreach s,$(SRCS),$(eval $(call SRC_PATHS,$(s))))
$(foreach s,$(SRCS),$(eval $(call OBJS_VARS,$(s))))
$(foreach s,$(SRCS),$(eval $(call SRC_OBJS_RULES,$(s))))
$(foreach s,$(SRCS),$(eval $(call MKDIR_RULES,$(s))))
$(foreach s,$(SRCS),$(eval $(call CLEAN_PATHS,$(s))))

test_make:
	@echo $(HelloWorld)
	@echo $(HelloWorldSrc)
	@echo $(wildcard $(HelloWorldSrc)/*.c)
	@echo $(patsubst $(HelloWorldSrc)%.c, $(HelloWorldObjs)%.o, $(wildcard $(HelloWorldSrc)*.c))

Main: $(OBJS_PATH)MyProgram.o $(HelloWorldObjs)Greeting.o
	$(LINK) -o $@.out $^

$(OBJS_PATH)%.o: $(SRC_PATH)%.c
	$(COMPILE) -o $@ $^

clean:
	-rm $(CLEAN_TARGETS) $(OBJS_PATH)*.o $(ROOT_PATH)*.out || :
