##Declare your object files here
##MYOBJ := $(patsubst %.o, $(OBJS_PATH)%.o, obj1.o obj2.o)
HELLOWORLD_OBJ := $(patsubst %.o, $(OBJS_PATH)%.o, HelloWorld.o, MyProgram.o)

##Place your source rules here
#Program: $(RT_OBJ)
#	$(LINK) -o $(ROOT_PATH)Program.out $(MYOBJ)
HelloWorld: $(HELLOWORLD_OBJ)
	$(LINK) -o $(ROOT_PATH)HelloWorld.out $(HELLOWORLD_OBJ)

$(OBJS_PATH)%.o: $(SRC_PATH)%.c
	$(COMPILE) -o $@ $<

.PHONY: clean

clean:
	-rm $(OBJS_PATH)*.o $(ROOT_PATH)*.out
