SRC_DIRS = $(dir $(wildcard $(SRC_PATH)*/*.c))
SRCS = $(patsubst $(SRC_PATH)%/, %, $(SRC_DIRS))

define SRC_PATHS
$(1)Objs = $(BUILD_PATH)$(1)/src/objs/
$(1)Src = $(SRC_PATH)$(1)/
endef

define SRC_OBJS_RULES
$($(1)Objs)%.o: $(HelloWorldObjs) $($(1)Src)%.c
	$(COMPILE) -o $$@ $$^
endef

define MKDIR_RULES
$($(1)Objs):
	mkdir -p $$@
$($(1)Src):
	mkdir -p $$@
endef

$(foreach s,$(SRCS),$(eval $(call SRC_PATHS,$(s))))
$(foreach s,$(SRCS),$(eval $(call SRC_OBJS_RULES,$(s))))
$(foreach s,$(SRCS),$(eval $(call MKDIR_RULES,$(s))))

Main: $(OBJS_PATH)MyProgram.o $(HelloWorldObjs)Greeting.o
	$(LINK) -o $@.out $^

$(OBJS_PATH)%.o: $(SRC_PATH)%.c
	$(COMPILE) -o $@ $^
