##Declare your object files here
##MYOBJ := $(patsubst %.o, $(OBJS_PATH)%.o, obj1.o obj2.o)

##Place your source rules here
#Program: $(RT_OBJ)
#	$(LINK) -o $(ROOT_PATH)Program.out $(MYOBJ)
HelloWorld: 
	$(LINK) -o $(ROOT_PATH)HelloWorld.out $(HELLOWORLD_OBJ)

$(OBJS_PATH)%.o: $(SRC_PATH)%.c
	$(COMPILE) -o $@ $<

HelloWorldObjs:
	@echo $(HelloWorld_OBJS)

define SRC_DIR_OBJS
$(1)_OBJS = $(patsubst %.c, %.o, $(wildcard $(SRC_PATH)$(1)/*.c))
endef

SRC_DIRS = $(dir $(wildcard $(SRC_PATH)*/*.c))
SRCS = $(patsubst $(SRC_PATH)%/, %, $(SRC_DIRS))

$(foreach d,$(SRCS),$(eval $(call SRC_DIR_OBJS,$(d))))

.PHONY: clean

clean:
	-rm $(OBJS_PATH)*.o $(ROOT_PATH)*.out
